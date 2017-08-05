/*
 * While.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_WHILE_H_
#define SRC_ABSTRACT_SYNTAX_TREE_WHILE_H_

#include "InstructionBlock.h"
#include "Comparation.h"

class While: public InstructionBlock
{
public:
	While();
	virtual ~While();

	virtual void Run(StackedLanguageManager*) override;

	void Condition(Comparation* );

private:
	Comparation* m_condition;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_WHILE_H_ */
