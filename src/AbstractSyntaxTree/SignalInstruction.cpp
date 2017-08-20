/*
 *   AbstractSyntaxTree/SignalInstruction.cpp
 *   Copyright (C) 2017  alexge50
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include <AbstractSyntaxTree/SignalInstruction.h>

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