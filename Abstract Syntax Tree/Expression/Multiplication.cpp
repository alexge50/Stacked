/*
 * Multiplication.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Multiplication.h"

Multiplication::Multiplication()
{
	// TODO Auto-generated constructor stub

}

Multiplication::~Multiplication()
{
	// TODO Auto-generated destructor stub
}

void Multiplication::Run(StackedLanguageManager* languageManager)
{
	m_left->Run(languageManager);
	m_right->Run(languageManager);
	m_result = m_left->Result() * m_right->Result();
}
