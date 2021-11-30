#include "menu.h"

MenuItem::MenuItem(const char* name, MenuItem* prev, void* arg, uint32_t argMax, MenuItem* parent)
{
	name_ = name;

	if (arg)
		argument = arg;

	argumentMax = argMax;

	if (prev)
	{
		prevItem = prev;
		prevItem->nextItem = this;
	}

	if (parent)
	{
		parentItem = parent;
		if (!parent->childItem)
			parent->childItem = this;
	}
}

const char* MenuItem::name()
{
	return name_;
}

MenuItem* MenuItem::next()
{
	return nextItem;
}

MenuItem* MenuItem::getChild()
{
	return childItem;
}

MenuItem* MenuItem::getNthChild(uint8_t n)
{
	if (childItem)
	{
		MenuItem* p = childItem;
		for (uint8_t i = 0; (i < n) && p->nextItem; i++)
			p = p->nextItem;
		return p;
	}
	else
		return 0;
}

void* MenuItem::arg()
{
	return argument;
}

uint32_t MenuItem::argMax()
{
	return argumentMax;
}
