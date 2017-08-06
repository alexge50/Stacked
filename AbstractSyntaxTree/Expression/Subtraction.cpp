/*
 *   AbstractSyntaxTree/Expression/Subtraction.cpp
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



#include "Subtraction.h"

Subtraction::Subtraction()
{
	// TODO Auto-generated constructor stub

}

Subtraction::~Subtraction()
{
	// TODO Auto-generated destructor stub
}

void Subtraction::Run(StackedLanguageManager* languageManager)
{
	int left, right;

	if(m_left != NULL)
	{
		m_left->Run(languageManager);
		left = m_left->Result();
	}
	else left = 0;

	if(m_right != NULL)
	{
		m_right->Run(languageManager);
		right = m_right->Result();
	}
	else right = 0;

	m_result = left - right;
}
