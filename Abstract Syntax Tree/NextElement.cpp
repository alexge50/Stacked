/*
 * NextElement.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "NextElement.h"

NextElement::NextElement()
{
	// TODO Auto-generated constructor stub

}

NextElement::~NextElement()
{
	// TODO Auto-generated destructor stub
}

void NextElement::Run(StackedLanguageManager* languageManager)
{
	m_result = languageManager->nextElement(m_stackName);
}

void NextElement::Argument(std::string name)
{
	m_stackName = name;
}
