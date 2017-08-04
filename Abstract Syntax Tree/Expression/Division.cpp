/*
 * Division.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Division.h"

Division::Division()
{
	// TODO Auto-generated constructor stub

}

Division::~Division()
{
	// TODO Auto-generated destructor stub
}

void Division::Run(StackedLanguageManager* languageManager)
{
	m_left->Run(languageManager);
	m_right->Run(languageManager);
	m_result = m_left->Result() / m_right->Result();
}
