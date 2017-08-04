/*
 * Comparation.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_H_

#include "Instruction.h"

class Comparation: public Instruction
{
public:
	Comparation();
	virtual ~Comparation();

	virtual void Run(StackedLanguageManager*) = 0;

	void Arguments(std::string, std::string);
	bool Result();

protected:
	std::string m_left, m_right;
	bool m_result;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_H_ */
