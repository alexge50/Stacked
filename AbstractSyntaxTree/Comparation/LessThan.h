/*
 * LessThan.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_LESSTHAN_H_
#define SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_LESSTHAN_H_

#include "../Comparation.h"

class LessThan: public Comparation
{
public:
	LessThan();
	virtual ~LessThan();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_LESSTHAN_H_ */
