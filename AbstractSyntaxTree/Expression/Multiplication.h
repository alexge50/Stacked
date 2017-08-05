/*
 * Multiplication.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MULTIPLICATION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MULTIPLICATION_H_

#include "../Expression.h"

class Multiplication: public Expression
{
public:
	Multiplication();
	virtual ~Multiplication();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MULTIPLICATION_H_ */
