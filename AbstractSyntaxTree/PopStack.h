/*
 * PopStack.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_POPSTACK_H_
#define SRC_ABSTRACT_SYNTAX_TREE_POPSTACK_H_

#include "Instruction.h"

class PopStack: public Instruction
{
public:
	PopStack();
	virtual ~PopStack();

	virtual void Run(StackedLanguageManager *manager) override;

	void Argument(std::string);

private:
	std::string m_stackName;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_POPSTACK_H_ */
