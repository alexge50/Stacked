/*
 * PushStack.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "PushStack.h"

PushStack::PushStack()
{
	// TODO Auto-generated constructor stub

}

PushStack::~PushStack()
{
	// TODO Auto-generated destructor stub
}

void PushStack::Run(StackedLanguageManager *manager)
{
	m_value->Run(manager);
	int value = m_value->Result();
	manager->pushStack(m_stackName, value);
}

void PushStack::Arguments(std::string name, Expression *value)
{
	m_stackName = name;
	m_value = value;
}
