/*
 * ConstNumber.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "ConstNumber.h"

ConstNumber::ConstNumber()
{
	// TODO Auto-generated constructor stub

}

ConstNumber::~ConstNumber()
{
	// TODO Auto-generated destructor stub
}

void ConstNumber::Run(StackedLanguageManager*)
{
	m_result = m_value;
}

void ConstNumber::Number(int value)
{
	m_value = value;
}
