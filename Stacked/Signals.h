/*
 *   Signals.h
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




#ifndef SRC_SIGNALS_H_
#define SRC_SIGNALS_H_

#include <Stacked/Signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class OutputSignal: Signal
{
    FILE *fout;
public:

    OutputSignal(FILE *f)  {  fout = f;  }
    ~OutputSignal() {}

	virtual void init() override
	{
		makeStack("output");
	}

	virtual void main() override
	{
		StackedLanguageManager::Stack *output = getStack("output");

		for(int i = output->stack.size() - 1; i >= 0; i--)
		{
			fprintf(fout, "%c", output->stack[i]);
			output->stack.pop_back();
		}
	}
};

class InputSignal: Signal
{
    FILE *fin;
public:

    InputSignal(FILE *f)  {  fin = f;  }
    ~InputSignal() {}

	virtual void init() override
	{
		makeStack("input");
	}

	virtual void main() override
	{
		StackedLanguageManager::Stack *input = getStack("input");
		char buffer[1000];
		int i = 0;

		fscanf(fin, "%s", buffer);

		while(buffer[i] != '\0')
		{
			input->stack.push_back((int)(buffer[i]));
			i++;
		}

	}
};

class SyscallSignal: Signal
{
public:

	virtual void init() override
	{
		makeStack("system");
	}

	virtual void main() override
	{
		StackedLanguageManager::Stack *_syscall = getStack("system");
		std::string callString;

		for(int i = _syscall->stack.size() - 1; i >= 0; i--)
		{
			callString = callString + (char)_syscall->stack[i];
			_syscall->stack.pop_back();
		}

		system(callString.c_str());
	}
};


class DebugSignal: Signal
{
public:
	virtual void init() override
	{

	}

	virtual void main() override
	{
		printf("stuff\n");
	}
};


#endif /* SRC_SIGNALS_H_ */
