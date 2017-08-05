/*
 * LessThan.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "LessThan.h"

LessThan::LessThan()
{
	// TODO Auto-generated constructor stub

}

LessThan::~LessThan()
{
	// TODO Auto-generated destructor stub
}

void LessThan::Run(StackedLanguageManager* languageManager)
{
	m_result = languageManager->lessThanOperation(m_left, m_right);
}
