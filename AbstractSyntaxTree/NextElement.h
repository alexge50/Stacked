/*
 * NextElement.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_NEXTELEMENT_H_
#define SRC_ABSTRACT_SYNTAX_TREE_NEXTELEMENT_H_

#include "Expression.h"

class NextElement: public Expression
{
public:
	NextElement();
	virtual ~NextElement();

	virtual void Run(StackedLanguageManager*) override;

	void Argument(std::string);

protected:
	std::string m_stackName;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_NEXTELEMENT_H_ */
