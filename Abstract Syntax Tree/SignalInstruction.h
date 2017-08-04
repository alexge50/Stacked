/*
 * SignalInstruction.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_ABSTRACT_SYNTAX_TREE_SIGNALINSTRUCTION_H_
#define SRC_ABSTRACT_SYNTAX_TREE_SIGNALINSTRUCTION_H_

#include "Instruction.h"

class SignalInstruction: public Instruction
{
public:
	SignalInstruction();
	virtual ~SignalInstruction();

	virtual void Run(StackedLanguageManager*) override;

	void Argument(std::string);

private:
	std::string m_signalName;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_SIGNALINSTRUCTION_H_ */
