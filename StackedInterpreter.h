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

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <string>
#include "StackedLanguageManager.h"

class StackedInterpreter
{
public:
	StackedInterpreter();
	virtual ~StackedInterpreter();

	void init();

	bool openFile(std::string);

	int mathBlock();

	bool line();// parse a line

private:


	void newInstruction();
	int nextInstruction();
	void popInstruction();
	void pushInstruction();
	void resetInstruction();
	void signalInstruction();

	bool greaterThanInstruction();
	bool lessThanInstruction();
	bool equalInstruction();

	/*more parsing functions*/
	std::string string();
	int number();

	int expression();
	int term();
	int factor();

	void removeSpaces();

private:
	FILE *fin;
	volatile char currentChar;
	volatile int numberCharRead;
	void nextChar();

private:
	StackedLanguageManager manager;
};

#endif /* INTERPRETER_H_ */
