/*
 * If.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_IF_H_
#define SRC_ABSTRACT_SYNTAX_TREE_IF_H_

#include "InstructionBlock.h"
#include "Comparation.h"

class If: public InstructionBlock
{
public:
	If();
	virtual ~If();

	virtual void Run(StackedLanguageManager*) override;

	void Condition(Comparation* );

private:
	Comparation* m_condition;

};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_IF_H_ */
