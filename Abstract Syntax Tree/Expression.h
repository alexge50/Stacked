/*
 * Expression.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_H_

#include "Instruction.h"

class Expression: public Instruction
{
public:
	Expression();
	virtual ~Expression();

	virtual void Run(StackedLanguageManager*) = 0;

	void Operands(Expression* , Expression*);
	int Result();

protected:
	Expression *m_left, *m_right;
	int m_result;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_H_ */
