/*
 * Signal.cpp
 *
 *  Created on: Jul 4, 2017
 *      Author: alex
 */

#include "Signal.h"

Signal::Signal()
{
	// TODO Auto-generated constructor stub
}

Signal::~Signal()
{
	// TODO Auto-generated destructor stub
}

StackedLanguageManager::Stack* Signal::getStack(std::string name)
{
	return owner->m_memorySpace[name];
}

void Signal::makeStack(std::string name)
{
	owner->newStack(name);
}
