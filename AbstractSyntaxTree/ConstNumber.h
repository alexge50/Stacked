/*
 * ConstNumber.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_CONSTNUMBER_H_
#define SRC_ABSTRACT_SYNTAX_TREE_CONSTNUMBER_H_

#include "Expression.h"

class ConstNumber: public Expression
{
public:
	ConstNumber();
	virtual ~ConstNumber();

	virtual void Run(StackedLanguageManager*) override;

	void Number(int);

private:
	int m_value;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_CONSTNUMBER_H_ */
