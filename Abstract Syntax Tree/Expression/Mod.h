/*
 * Mod.h
 *
 *  Created on: Aug 5, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MOD_H_
#define SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MOD_H_

#include "../Expression.h"

class Mod: public Expression
{
public:
	Mod();
	virtual ~Mod();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_EXPRESSION_MOD_H_ */
