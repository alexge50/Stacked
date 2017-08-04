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
	m_left->Run(languageManager);
	m_right->Run(languageManager);
	m_result = m_left->Result() + m_right->Result();
}
