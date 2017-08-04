/*
 * Equal.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Equal.h"

Equal::Equal()
{
	// TODO Auto-generated constructor stub

}

Equal::~Equal()
{
	// TODO Auto-generated destructor stub
}

void Equal::Run(StackedLanguageManager* languageManager)
{
	m_result = languageManager->equalOperation(m_left, m_right);
}
