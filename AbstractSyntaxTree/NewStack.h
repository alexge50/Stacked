/*
 * NewStack.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_NEWSTACK_H_
#define SRC_ABSTRACT_SYNTAX_TREE_NEWSTACK_H_

#include "Instruction.h"

class NewStack: public Instruction
{
public:
	NewStack();
	virtual ~NewStack();

	virtual void Run(StackedLanguageManager *manager) override;

	void Argument(std::string);

private:
	std::string m_stackName;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_NEWSTACK_H_ */
