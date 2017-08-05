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
	int left, right;

	if(m_left != NULL)
	{
		m_left->Run(languageManager);
		left = m_left->Result();
	}
	else left = 1;

	if(m_right != NULL)
	{
		m_right->Run(languageManager);
		right = m_right->Result();
	}
	else right = 1;

	m_result = left / right;
}
