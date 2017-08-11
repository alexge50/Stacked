/*
 *   StackedInterpreter.h
 *   Copyright (C) 2017  alexge50
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */




#ifndef STACKEDINTERPRETER_H_
#define STACKEDINTERPRETER_H_

#include <map>
#include <string>
#include <functional>
#include "StackedLanguageManager.h"
#include "Stream/IStream.h"

#include "AbstractSyntaxTree.h"

class StackedInterpreter
{
public:
	StackedInterpreter();
	virtual ~StackedInterpreter();

	void setStream(IStream*);

	Program *program();

	Expression* mathBlock();
	Instruction* whileBlock();
	Instruction* ifBlock();

	Instruction* line();// parse a line

private:


	Instruction* newInstruction();
	Expression* nextInstruction();
	Instruction* popInstruction();
	Instruction* pushInstruction();
	Instruction* resetInstruction();
	Instruction* signalInstruction();
	Instruction* nullInstruction();

	Comparation* greaterThanInstruction();
	Comparation* lessThanInstruction();
	Comparation* equalInstruction();
	Comparation* notEqualInstruction();
	Comparation* notEmptyInstruction();

	/*more parsing functions*/
	std::string string();
	int number();

	Expression* expression();
	Expression* term();
	Expression* factor();

	void removeSpaces();
	void readUntil(char c);

private:
	IStream *stream;

private:
	typedef std::function<Instruction*(void)> InstructionDelegate;
	typedef std::function<Comparation*(void)> ComparativeInstructionDelegate;

	StackedLanguageManager manager;
	std::map<char, InstructionDelegate> InstructionMap;
	std::map<char, ComparativeInstructionDelegate> ComparativeInstructionMap;
};

#endif /* STACKEDINTERPRETER_H_ */
