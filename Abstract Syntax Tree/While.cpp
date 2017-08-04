/*
 * While.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "While.h"

While::While()
{
	// TODO Auto-generated constructor stub

}

While::~While()
{
	// TODO Auto-generated destructor stub
}

void While::Run(StackedLanguageManager* languageManager)
{
	m_condition->Run(languageManager);

	while(m_condition->Result())
	{
		RunInstructionBlock(languageManager);
		m_condition->Run(languageManager);
	}
}

void While::Condition(Comparation* condition)
{
	m_condition = condition;
}
