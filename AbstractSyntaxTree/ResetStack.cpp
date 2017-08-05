/*
 * ResetStack.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "ResetStack.h"

ResetStack::ResetStack()
{
	// TODO Auto-generated constructor stub

}

ResetStack::~ResetStack()
{
	// TODO Auto-generated destructor stub
}

void ResetStack::Run(StackedLanguageManager *manager)
{
	manager->resetStack(m_stackName);
}

void ResetStack::Argument(std::string name)
{
	m_stackName = name;
}
