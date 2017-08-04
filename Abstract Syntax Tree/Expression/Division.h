/*
 * Division.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_DIVISION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_DIVISION_H_

#include "../Expression.h"

class Division: public Expression
{
public:
	Division();
	virtual ~Division();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_DIVISION_H_ */
