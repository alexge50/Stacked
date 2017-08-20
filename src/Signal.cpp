/*
 *   Signal.cpp
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


#include <Signal.h>

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
