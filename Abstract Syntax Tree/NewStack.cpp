/*
 * NewStack.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "NewStack.h"

NewStack::NewStack()
{
	// TODO Auto-generated constructor stub

}

NewStack::~NewStack()
{
	// TODO Auto-generated destructor stub
}

void NewStack::Run(StackedLanguageManager *manager)
{
	manager->newStack(m_stackName);
}

void NewStack::Argument(std::string name)
{
	m_stackName = name;
}
