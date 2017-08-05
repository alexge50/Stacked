/*
 * GreaterThan.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_GREATERTHAN_H_
#define SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_GREATERTHAN_H_

#include "../Comparation.h"

class GreaterThan: public Comparation
{
public:
	GreaterThan();
	virtual ~GreaterThan();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_GREATERTHAN_H_ */
