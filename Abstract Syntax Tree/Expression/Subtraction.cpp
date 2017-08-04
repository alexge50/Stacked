/*
 * Subtraction.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
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
	m_left->Run(languageManager);
	m_right->Run(languageManager);
	m_result = m_left->Result() - m_right->Result();
}
