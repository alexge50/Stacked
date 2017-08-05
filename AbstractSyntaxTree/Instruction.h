/*
 * Instruction.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTION_H_

#include "../StackedLanguageManager.h"

class Instruction
{
public:
	Instruction();
	virtual ~Instruction();

public:
	virtual void Run(StackedLanguageManager*) = 0;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_INSTRUCTION_H_ */
