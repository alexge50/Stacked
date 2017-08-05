/*
 * Program.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_PROGRAM_H_
#define SRC_ABSTRACT_SYNTAX_TREE_PROGRAM_H_

#include "InstructionBlock.h"

class Program: public InstructionBlock
{
public:
	Program();
	virtual ~Program();
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_PROGRAM_H_ */
