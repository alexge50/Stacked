/*
 * PopStack.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "PopStack.h"

PopStack::PopStack()
{
	// TODO Auto-generated constructor stub

}

PopStack::~PopStack()
{
	// TODO Auto-generated destructor stub
}

void PopStack::Run(StackedLanguageManager *manager)
{
	manager->popStack(m_stackName);
}

void PopStack::Argument(std::string name)
{
	m_stackName = name;
}
