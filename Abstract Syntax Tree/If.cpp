/*
 * If.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "If.h"

If::If()
{
	// TODO Auto-generated constructor stub

}

If::~If()
{
	// TODO Auto-generated destructor stub
}

void If::Run(StackedLanguageManager* languageManager)
{
	m_condition->Run(languageManager);

	if(m_condition->Result())
		RunInstructionBlock(languageManager);
}

void If::Condition(Comparation* condition)
{
	m_condition = condition;
}
