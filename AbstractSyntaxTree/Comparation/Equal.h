/*
 * Equal.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_
#define SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_

#include "../Comparation.h"

class Equal: public Comparation
{
public:
	Equal();
	virtual ~Equal();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_ */
