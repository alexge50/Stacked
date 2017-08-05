/*
 * Addition.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_ADDITION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_ADDITION_H_

#include "../Expression.h"

class Addition: public Expression
{
public:
	Addition();
	virtual ~Addition();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_ADDITION_H_ */
