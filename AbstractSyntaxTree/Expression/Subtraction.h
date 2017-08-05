/*
 * Subtraction.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_SUBTRACTION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_SUBTRACTION_H_

#include "../Expression.h"

class Subtraction: public Expression
{
public:
	Subtraction();
	virtual ~Subtraction();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_SUBTRACTION_H_ */
