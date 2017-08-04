/*
 * SignalInstruction.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "SignalInstruction.h"

SignalInstruction::SignalInstruction()
{
	// TODO Auto-generated constructor stub

}

SignalInstruction::~SignalInstruction()
{
	// TODO Auto-generated destructor stub
}

void SignalInstruction::Run(StackedLanguageManager *manager)
{
	manager->signal(m_signalName);
}

void SignalInstruction::Argument(std::string name)
{
	m_signalName = name;
}
