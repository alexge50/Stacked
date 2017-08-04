/*
 * InstructionBlock.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTIONBLOCK_H_
#define SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTIONBLOCK_H_

#include "Instruction.h"

#include <vector>

class InstructionBlock: public Instruction
{
public:
	InstructionBlock();
	virtual ~InstructionBlock();

	virtual void Run(StackedLanguageManager*) override;

	std::vector<Instruction*>* GetInstructionBlock();

protected:
	void RunInstructionBlock(StackedLanguageManager* );
	std::vector<Instruction*> m_instructionList;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTIONBLOCK_H_ */
