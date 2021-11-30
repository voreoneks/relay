#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "defines.h"
#include "Button.h"
#include "i2c.h"
#include "SSD1306.h"
#include "stm32l0xx_it.h"
#include "menu.h"
#include "rcc.h"
#include "flash.h"

#define FLASH_START 0x08080000

const char txtOff[] = " OFF";
const char txtOn[] = " ON";

constexpr uint8_t itemsPerScreen = 6;

ScreenID screen = STATUS;
uint8_t initSuccess = 0, editVal = 0, parameter = 0;
uint32_t pulseCounter = 0;

void bt_defaultAction(uint32_t btNum);
void bt_longAction(uint32_t btNum);
void bt_doubleLongAction();

void bt0_action()
{
	bt_defaultAction(0);
}

void bt1_action()
{
	bt_defaultAction(1);
}

void bt0_longAction()
{
	bt_longAction(0);
}

void bt1_longAction()
{
	bt_longAction(1);
}


void setOutput(bool state)
{
	if (state)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
	else
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
}

bool getOutputState()
{
	return LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_4);
}

/* Private variables ---------------------------------------------------------*/
Button buttons[2] = { {GPIOA, 5, bt0_action, true},
                      {GPIOA, 6, bt1_action, true}};
Button* bt = buttons;
Settings set;
Settings set_flash;
uint32_t tim2MaxDelay, tim2CountDelay = 0;
uint16_t tim2MaxDuration = 0; 
uint16_t tim2CountDuration = 0;
uint32_t statusScreenUpdatePeriod = 100;
uint8_t updateStatusFlag = 0;

MenuItem* selectedItem = 0;
MenuItem startupItem;
MenuItem backButton(" <..");
MenuItem inversePolarity(" ÈÍÂÅÐÑ", 0, &set.polarity, 1, &startupItem);
MenuItem pulseMode(" ÈÌÏ-Ñ", &inversePolarity, &set.pulseModeEnabled, 1);
MenuItem repeatMode(" ÏÎÂÒÎÐ", &pulseMode, &set.outputRepetition, 1000);
MenuItem t1val(" T1", &repeatMode, &set.t1, 999);
MenuItem t2val(" T2", &t1val, &set.t2, 999);
MenuItem delayHour(" TD ×ÀÑ", &t2val, &set.outputDelayH, 999);
MenuItem delayMin(" TD ÌÈÍ", &delayHour, &set.outputDelayM, 59);
MenuItem delaySec(" TD ÑÅÊ", &delayMin, &set.outputDelayS, 59);

void drawMenu(MenuItem& head, uint8_t selectedNum)
{	
	static uint8_t scrolls = 0;
	if (head.getChild())
	{
		SSD1306_COLOR color = White;
		uint8_t backButtonExist = 0;
		uint8_t offsetY = 1;
		MenuItem* child = 0;

		// Clear entire screen
		SSD1306_Fill(Black);

		// If target item not visible yet then scrolldown or scrollup to it
		if (selectedNum < scrolls)
			scrolls = selectedNum;
		else if (selectedNum >= (scrolls + itemsPerScreen))
			scrolls = selectedNum + 1 - itemsPerScreen;

		// If we have no scroll then we should put "back" button in the top of menu
		if (scrolls == 0)
		{
			if (selectedNum == 0)
				color = Black;
			SSD1306_WriteString8Bit(0, offsetY, (uint8_t*)backButton.name(), Font_7x9, color);
			backButtonExist = 1;
			offsetY += 10;
		}

		// Get first visible item in menu and if "Back" button isnt visible,
		// then we should get additional item to replace "Back" button
		child = head.getNthChild(scrolls - !backButtonExist);

		for (uint8_t i = scrolls; i < (scrolls + itemsPerScreen - backButtonExist); i++)
		{
			if (child)
			{
				// If item was selected, inverse its color
				color = ((i + backButtonExist) == selectedNum) ? Black : White;
				SSD1306_WriteString8Bit(0, (i - scrolls) * 10 + offsetY, (uint8_t*)child->name(), Font_7x9, color);
				child = child->next();
			}
		}

		SSD1306_UpdateScreen();
	}
}

void drawStatus()
{
	bool out = getOutputState();
	uint32_t timeToSwitch = 0, h = 0, m = 0, s = 0;
	
	if (LL_TIM_IsEnabledCounter(TIM2))
	{
		if ((tim2CountDelay < tim2MaxDelay) || (tim2CountDuration == 0))
			timeToSwitch = tim2MaxDelay - tim2CountDelay;
		else
		{
			if (tim2CountDuration <= set_flash.t1)
				timeToSwitch = set_flash.t1 - tim2CountDuration;
			else
				timeToSwitch = set_flash.t2 - (tim2CountDuration - set_flash.t1);
		}
		h = timeToSwitch / 3600;
		timeToSwitch -= h * 3600;
		m = timeToSwitch / 60;
		timeToSwitch -= m * 60;
		s = timeToSwitch;
	}
	
	SSD1306_Fill(Black);
	SSD1306_WriteString8Bit(out ? 15 : 12, 0, (uint8_t*)(out ? txtOn : txtOff), Font_7x9, White);
	SSD1306_WriteString8Bit(7, 14, (uint8_t*)"× :", Font_7x9, White);
	SSD1306_WriteNum8Bit(23, 14, h % 3600, 3, Font_7x9, White);
	SSD1306_WriteString8Bit(7, 28, (uint8_t*)"Ì :", Font_7x9, White);
	SSD1306_WriteNum8Bit(30, 28, m, 2, Font_7x9, White);
	SSD1306_WriteString8Bit(7, 42, (uint8_t*)"Ñ :", Font_7x9, White);
	SSD1306_WriteNum8Bit(30, 42, s, 2, Font_7x9, White);
	SSD1306_WriteString8Bit(7, 56, (uint8_t*)"Ï :", Font_7x9, White);
	if (set_flash.outputRepetition < 1000)
		SSD1306_WriteNum8Bit(23, 56, set_flash.outputRepetition - pulseCounter, 3, Font_7x9, White);
	else
		SSD1306_WriteString8Bit(33, 56, (uint8_t*)"\x5B", Font_7x9, White);
	SSD1306_UpdateScreen();
}

void drawValueEdit(bool isBool)
{
	SSD1306_Fill(Black);
	uint32_t val = false;
	MenuItem* item = selectedItem;

	if (item)
	{
		if (item->arg())
		{
			if (isBool)
				val = *(uint8_t*)item->arg();
			else
				val = *(uint32_t*)item->arg();
		}

		if (isBool)
			SSD1306_WriteString8Bit(val ? 15 : 12, 20, (uint8_t*)(val ? txtOn : txtOff), Font_7x9, Black);
		else
		{
			if (val < 1000)
				SSD1306_WriteNum16Bit(0, 15, val, 3, Font_16x26, Black);
			else
			{
				SSD1306_WriteString16Bit(16, 15, (uint8_t*)"\x3A", Font_16x26, Black);
				SSD1306_WriteString16Bit(32, 15, (uint8_t*)"\x2B", Font_16x26, Black);
				SSD1306_WriteString16Bit(0, 15, (uint8_t*)"\x2B", Font_16x26, Black);
			}
		}
	}

	SSD1306_UpdateScreen();
}

void returnToStatus()
{
	FlashWrite(FLASH_START, (uint8_t*)&set, sizeof(set));
	parameter = 0;
	screen = STATUS;
	drawStatus();
}

void editValueCallback(bool increase, bool isBool)
{
	if (selectedItem)
	{
		if (isBool)
		{
			*(uint8_t*)selectedItem->arg() ^= 1;
		}
		else
		{
			uint32_t val = *(uint32_t*)selectedItem->arg();
			if ((val == 0) && !increase)
				val = selectedItem->argMax();
			else
				val = (val + increase * 2 - 1);
			if (val > selectedItem->argMax())
				val = 0;
			*(uint32_t*)selectedItem->arg() = val;
		}
		drawValueEdit(parameter < 3);
	}
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* MCU Configuration--------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

	/* RCC_IRQn interrupt configuration */
	NVIC_EnableIRQ(RCC_IRQn);

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_I2C1_Init();
	MX_GPIO_Init();
	MX_TIM2_Init();

	LL_TIM_ClearFlag_UPDATE(TIM2);
	LL_TIM_EnableIT_UPDATE(TIM2);

//	set_flash.polarity = 0;
//	set_flash.outputDelayS = 0;
//	set_flash.outputRepetition = 0;
//	set_flash.pulseModeEnabled = 0;
//	set_flash.t1 = 0;
//	set_flash.t2 = 0;
//	
//	FlashWrite(FLASH_START, (uint8_t*)&set_flash, sizeof(set_flash));
	FlashRead(FLASH_START, (uint8_t*)&set_flash, sizeof(set_flash));
	set = set_flash;
	
	if (set_flash.pulseModeEnabled == 0)
		set_flash.outputRepetition = 0;
	
	buttons[0].setLongPressingAction(1000, bt0_longAction);
	buttons[1].setLongPressingAction(1000, bt1_longAction);
	Button::setInactivityAction(10000, returnToStatus);
	buttons[0].setRepeatTime(10);
	buttons[1].setRepeatTime(10);
	Button::setDoubleLongPressAction(bt_doubleLongAction, buttons[0], buttons[1]);
	
	setOutput(set_flash.polarity);
 	start();
	
	LL_mDelay(10);
	
	InitOLED();	
	SSD1306_WriteString8Bit(20, 25, (uint8_t*)"DL", Font_7x9, White);
	SSD1306_UpdateScreen();
	LL_mDelay(2000);
	drawStatus();
	initSuccess = 1;

	while (1);
}


void bt_defaultAction(uint32_t btNum)
{
	switch (screen)
	{
	case STATUS:
		break;
	case SETTINGS:
		if (!btNum ? (parameter > 0) : (parameter < 8))
			parameter += 1 - 2 * !btNum;
		else
			parameter = !btNum ? 8 : 0;
		drawMenu(startupItem, parameter);
		break;
	case PARAMETER:
		editValueCallback(!btNum, parameter < 3);
		break;
	default:
		break;
	}
}

void bt_longAction(uint32_t btNum)
{
	switch (screen)
	{
	case STATUS:
		if (!btNum)
		{
			drawMenu(startupItem, 0);
			screen = SETTINGS;
		}
		break;
	case SETTINGS:
		selectedItem = startupItem.getNthChild(parameter - 1);
		if (!btNum)
		{	
			if (parameter)
			{
				drawValueEdit(parameter < 3);
				screen = PARAMETER;	
			}
			else
			{
				FlashWrite(FLASH_START, (uint8_t*)&set, sizeof(set));
				drawStatus();
				screen = STATUS;
			}
		}
		break;
	case PARAMETER:
		bt[0].enableAutoRepeat(true);
		bt[1].enableAutoRepeat(true);
		break;
	default:
		break;
	}
}

void bt_doubleLongAction()
{
	switch (screen)
	{
	case STATUS:
		break;
	case SETTINGS:
		break;
	case PARAMETER:
		bt[0].enableAutoRepeat(false);
		bt[1].enableAutoRepeat(false);
		drawMenu(startupItem, parameter);
		screen = SETTINGS;		
		break;
	default:
		break;
	}
}


void start()
{
	tim2MaxDelay = set_flash.outputDelayS + (set_flash.outputDelayM * 60) + (set_flash.outputDelayH * 3600) - 1; 
	if (tim2MaxDelay > 3599999)
		tim2MaxDelay = 0;
	TIM2->CR1 |= TIM_CR1_CEN;
}

// Callback executed after delay TD after relay input signal occurs
void TIM2_Callback()
{
	if (tim2CountDelay < tim2MaxDelay)
		tim2CountDelay++;
	else 
	{
		if (set_flash.pulseModeEnabled)
		{
			if (tim2CountDuration == 0)
			{
				setOutput(!set_flash.polarity);
				pulseCounter++;
			}
			else if (tim2CountDuration == set_flash.t1)
				setOutput(set_flash.polarity);
			
			if (tim2CountDuration == set_flash.t1 + set_flash.t2)
			{
				tim2CountDuration = 0;
				setOutput(!set_flash.polarity);
				pulseCounter++;
			}
			
			if (set_flash.outputRepetition == 1000)
				pulseCounter = 0;
			
			tim2CountDuration++;
			
			if (pulseCounter == set_flash.outputRepetition + 1)
			{
				if (pulseCounter > set_flash.outputRepetition)
					pulseCounter = set_flash.outputRepetition;
				TIM2->CR1 &= ~TIM_CR1_CEN;
				setOutput(!set_flash.polarity);
				statusScreenUpdatePeriod = 10000;
				updateStatusFlag = 1;
			}
			
		}
		else
			setOutput(!set_flash.polarity);
	}
}

