#pragma once

#include "stdint.h"

class MenuItem
{
public:
	MenuItem(const char* name = 0, MenuItem* prev = 0, void* arg = 0, uint32_t argMax = 0, MenuItem* parent = 0);
	const char* name();
	MenuItem* next();
	MenuItem* getChild();
	MenuItem* getNthChild(uint8_t n);
	void* arg();
	uint32_t argMax();

private:
	const char* name_;
	uint8_t id = 0;
	bool isFolder = false;
	MenuItem* nextItem = 0, * prevItem = 0, * parentItem = 0, * childItem = 0;
	void* argument = 0;
	uint32_t argumentMax = 0;
};
