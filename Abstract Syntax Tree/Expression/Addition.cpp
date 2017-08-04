/*
 * Addition.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Addition.h"

Addition::Addition()
{
	// TODO Auto-generated constructor stub

}

Addition::~Addition()
{
	// TODO Auto-generated destructor stub
}

void Addition::Run(StackedLanguageManager* languageManager)
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

	m_result = left + right;
}
