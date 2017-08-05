/*
 * PushStack.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_PUSHSTACK_H_
#define SRC_ABSTRACT_SYNTAX_TREE_PUSHSTACK_H_

#include "Instruction.h"
#include "Expression.h"

class PushStack: public Instruction
{
public:
	PushStack();
	virtual ~PushStack();

	virtual void Run(StackedLanguageManager *manager) override;

	void Arguments(std::string, Expression*);

private:
	std::string m_stackName;
	Expression *m_value;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_PUSHSTACK_H_ */
