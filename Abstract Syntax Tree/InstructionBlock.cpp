/*
 * InstructionBlock.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "InstructionBlock.h"

#include <stdio.h>

InstructionBlock::InstructionBlock()
{
	// TODO Auto-generated constructor stub

}

InstructionBlock::~InstructionBlock()
{
	// TODO Auto-generated destructor stub
}

void InstructionBlock::Run(StackedLanguageManager* languageManager)
{
	RunInstructionBlock(languageManager);
}

void InstructionBlock::RunInstructionBlock(StackedLanguageManager* languageManager)
{
	for(int i = 0; i < m_instructionList.size(); i++)
	{
		if(m_instructionList[i] != NULL)
			m_instructionList[i]->Run(languageManager);
		else printf("error, <NULL> instruction\n");
	}
}

std::vector<Instruction*>* InstructionBlock::GetInstructionBlock()
{
	return &m_instructionList;
}
