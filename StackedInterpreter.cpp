/*
 * Interpreter.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: alex
 */

#include "StackedInterpreter.h"
#include <stdio.h>
#include <ctype.h>

#include "Signals.h"

StackedInterpreter::StackedInterpreter()
{
	// TODO Auto-generated constructor stub
	numberCharRead = 0;
	fin = NULL;
	currentChar = 0;
}

StackedInterpreter::~StackedInterpreter()
{
	// TODO Auto-generated destructor stub
}

void StackedInterpreter::init()
{
	manager.addSignal<OutputSignal>("print");
	manager.addSignal<InputSignal>("scan");
	manager.addSignal<SyscallSignal>("system");
	manager.addSignal<DebugSignal>("debug");
}

bool StackedInterpreter::openFile(std::string filename)
{
	fin = fopen(filename.c_str(), "r");
	nextChar();

	return fin != NULL;
}

bool StackedInterpreter::line()
{
	char x;
	removeSpaces();
	x = currentChar;

	if(x == EOF)
		return 1;

	//printf("%c\n", currentChar);

	if(x == '(')
	{
		//printf("here");
		printf("%d\n", mathBlock());
	}
	else if(x == '%')
	{
		this->newInstruction();
	}
	else if(x == '"')
	{
		//printf("%d\n", this->nextInstruction());
		this->nextInstruction();
	}
	else if(x == '?')
	{
		this->resetInstruction();
	}
	else if(x == '-')
	{
		this->popInstruction();
	}
	else if(x == '+')
	{
		this->pushInstruction();
	}
	else if(x == '!')
	{
		this->signalInstruction();
	}
	else if(x == '>')
	{
		//printf("%d\n", this->greaterThanInstruction());
		this->greaterThanInstruction();
	}
	else if(x == '<')
	{
		//printf("%d\n", this->lessThanInstruction());
		this->lessThanInstruction();
	}
	else if(x == '=')
	{
		//printf("%d\n", this->equalInstruction());
		this->equalInstruction();
	}
	else if(x == '[')
	{
		whileBlock();
	}
	else if(x == '{')
	{
		ifBlock();
	}

	removeSpaces();

	return 0;
}

int StackedInterpreter::mathBlock()
{
	return expression();
}

void StackedInterpreter::whileBlock()
{
	whileBlockStartPosition = ftell(fin);
	readUntil(']');
	whileBlockEndPosition = ftell(fin);


	fseek(fin, whileBlockStartPosition, SEEK_SET);

	nextChar();
	removeSpaces();

	if(currentChar == ':')
	{
		nextChar();
		removeSpaces();

		char x = currentChar;
		int value;

		if(x == '>')
			value = this->greaterThanInstruction();
		else if(x == '<')
			value = this->lessThanInstruction();
		else if(x == '=')
			value = this->equalInstruction();

		removeSpaces();
		if(currentChar != ':')
			return;
		nextChar();
		removeSpaces();

		if(value == 1)
		{
			while(currentChar != ']')
			{
				line();
			}
			fseek(fin, whileBlockStartPosition, SEEK_SET);
			currentChar = '[';
		}
		else
		{
			fseek(fin, whileBlockEndPosition, SEEK_SET);
			nextChar();
		}
	}
	else
	{
		printf("expected condition\n");
	}
}

void StackedInterpreter::ifBlock()
{
	ifBlockStartPosition = ftell(fin);
	readUntil('}');
	ifBlockEndPosition = ftell(fin);


	fseek(fin, ifBlockStartPosition, SEEK_SET);

	nextChar();
	removeSpaces();

	if(currentChar == ':')
	{
		nextChar();
		removeSpaces();

		char x = currentChar;
		int value;

		if(x == '>')
			value = this->greaterThanInstruction();
		else if(x == '<')
			value = this->lessThanInstruction();
		else if(x == '=')
			value = this->equalInstruction();

		removeSpaces();
		if(currentChar != ':')
			return;
		nextChar();
		removeSpaces();

		if(value == 1)
		{
			while(currentChar != '}')
			{
				line();
			}
			nextChar();
		}
		else
		{
			fseek(fin, ifBlockEndPosition, SEEK_SET);
			nextChar();
		}
	}
	else
	{
		printf("expected condition\n");
	}
}


void StackedInterpreter::newInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();

	manager.newStack(name);
}

int StackedInterpreter::nextInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();

	return manager.nextElement(name);
}

void StackedInterpreter::popInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();

	manager.popStack(name);
}

void StackedInterpreter::pushInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();
	int x;

	removeSpaces();
	x = mathBlock();

	manager.pushStack(name, x);
}

void StackedInterpreter::resetInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();

	manager.resetStack(name);
}

void StackedInterpreter::signalInstruction()
{
	nextChar();
	removeSpaces();

	std::string name = string();

	manager.signal(name);
}

bool StackedInterpreter::greaterThanInstruction()
{
	nextChar();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	return manager.greaterThanOperation(name1, name2);
}

bool StackedInterpreter::lessThanInstruction()
{
	nextChar();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	return manager.lessThanOperation(name1, name2);
}

bool StackedInterpreter::equalInstruction()
{
	nextChar();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	return manager.equalOperation(name1, name2);
}

/*more parsing functions*/
std::string StackedInterpreter::string()
{
	std::string x;

	while(isalnum(currentChar))
	{
		x = x + currentChar;
		nextChar();
	}

	return x;
}

int StackedInterpreter::number()
{
	int x = 0;
	removeSpaces();


	while(isdigit(currentChar))
	{
		x = ( currentChar - '0' ) + x * 10;
		nextChar();
	}

	return x;
}



int StackedInterpreter::expression()
{
	int t1 = 0, t2 = 0;
	int sign = 1;

	if(currentChar == '(')
		nextChar();
	else
	{
		printf("syntax error %d %c\n", __LINE__, currentChar);
		return 0;
	}

	removeSpaces();
	t1 = term();
	removeSpaces();
	if(currentChar == '+' || currentChar == '-')
	{
		sign = currentChar == '+' ? 1 : -1;
		nextChar();
		removeSpaces();
		t2 = term();
	}

	removeSpaces();
	if(currentChar == ')')
		nextChar();
	else
	{
		printf("syntax error %d %c\n", __LINE__, currentChar);
		//return 0;
	}

	return t1 + sign * t2;
}

int StackedInterpreter::term()
{
	int f1 = 1, f2 = 1;
	int sign = '*';

	removeSpaces();
	f1 = factor();
	removeSpaces();
	if(currentChar == '*' || currentChar == '/' || currentChar == '%')
	{
		sign = currentChar;
		nextChar();
		removeSpaces();
		f2 = factor();
	}

	if(sign == '*')
		return f1 * f2;
	else if(sign == '/') return f1 / f2;
	else if(sign == '%') return f1 % f2;

	return 0;
}

int StackedInterpreter::factor()
{
	int x;
	if(currentChar == '(')
	{
		x = expression();
	}
	else if(isdigit(currentChar))
	{
		x =  number();
	}
	else if(currentChar == '"')
	{
		x = nextInstruction();
	}
	else
	{
		printf("syntax error %d %c\n", __LINE__, currentChar);
		return 0;
	}

	return x;
}

void StackedInterpreter::removeSpaces()
{
	while(currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
		nextChar();
}

void StackedInterpreter::readUntil(char c)
{
	while(currentChar != c)
		nextChar();
}

void StackedInterpreter::nextChar()
{
	currentChar = fgetc(fin);
}

