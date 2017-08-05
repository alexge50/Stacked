/*
 * Mod.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: alex
 */

#include "Mod.h"

#include <stdlib.h>

Mod::Mod()
{
	// TODO Auto-generated constructor stub

}

Mod::~Mod()
{
	// TODO Auto-generated destructor stub
}

void Mod::Run(StackedLanguageManager* languageManager)
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

	m_result = left % right;

}
