/*
 * GreaterThan.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "GreaterThan.h"

GreaterThan::GreaterThan()
{
	// TODO Auto-generated constructor stub

}

GreaterThan::~GreaterThan()
{
	// TODO Auto-generated destructor stub
}

void GreaterThan::Run(StackedLanguageManager* languageManager)
{
	m_result = languageManager->greaterThanOperation(m_left, m_right);
}
