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
	stream = NULL;
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

void StackedInterpreter::setStream(IStream* s)
{
	stream = s;
}

bool StackedInterpreter::line()
{
	char x;
	removeSpaces();
	x = stream->GetCurrentByte();
	//printf("%c\n", x);

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
	whileBlockStartPosition = stream->GetCurrentPosition();
	readUntil(']');
	whileBlockEndPosition = stream->GetCurrentPosition();

	stream->SetPosition(whileBlockStartPosition);

	stream->Advance();
	removeSpaces();

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();

		char x = stream->GetCurrentByte();
		int value;

		if(x == '>')
			value = this->greaterThanInstruction();
		else if(x == '<')
			value = this->lessThanInstruction();
		else if(x == '=')
			value = this->equalInstruction();

		removeSpaces();
		if(stream->GetCurrentByte() != ':')
			return;
		stream->Advance();
		removeSpaces();

		if(value == 1)
		{
			while(stream->GetCurrentByte() != ']')
			{
				line();
			}
			stream->SetPosition(whileBlockStartPosition);

		}
		else
		{
			stream->SetPosition(whileBlockEndPosition);
			stream->Advance();
		}
	}
	else
	{
		printf("expected condition\n");
	}
}

void StackedInterpreter::ifBlock()
{
	ifBlockStartPosition = stream->GetCurrentPosition();
	readUntil('}');
	ifBlockEndPosition = stream->GetCurrentPosition();

	stream->SetPosition(ifBlockStartPosition);

	stream->Advance();
	removeSpaces();

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();

		char x = stream->GetCurrentByte();
		int value;

		if(x == '>')
			value = this->greaterThanInstruction();
		else if(x == '<')
			value = this->lessThanInstruction();
		else if(x == '=')
			value = this->equalInstruction();

		removeSpaces();
		if(stream->GetCurrentByte() != ':')
			return;
		stream->Advance();
		removeSpaces();

		if(value == 1)
		{
			while(stream->GetCurrentByte() != '}')
			{
				line();
			}
			stream->Advance();
		}
		else
		{
			stream->SetPosition(ifBlockEndPosition);
			stream->Advance();
		}
	}
	else
	{
		printf("expected condition\n");
	}
}


void StackedInterpreter::newInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	manager.newStack(name);
}

int StackedInterpreter::nextInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	return manager.nextElement(name);
}

void StackedInterpreter::popInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	manager.popStack(name);
}

void StackedInterpreter::pushInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();
	int x;

	removeSpaces();
	x = mathBlock();

	manager.pushStack(name, x);
}

void StackedInterpreter::resetInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	manager.resetStack(name);
}

void StackedInterpreter::signalInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	manager.signal(name);
}

bool StackedInterpreter::greaterThanInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	return manager.greaterThanOperation(name1, name2);
}

bool StackedInterpreter::lessThanInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	return manager.lessThanOperation(name1, name2);
}

bool StackedInterpreter::equalInstruction()
{
	stream->Advance();
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

	while(isalnum(stream->GetCurrentByte()))
	{
		x = x + stream->GetCurrentByte();
		stream->Advance();
	}

	return x;
}

int StackedInterpreter::number()
{
	int x = 0;
	removeSpaces();


	while(isdigit(stream->GetCurrentByte()))
	{
		x = ( stream->GetCurrentByte() - '0' ) + x * 10;
		stream->Advance();
	}

	return x;
}



int StackedInterpreter::expression()
{
	int t1 = 0, t2 = 0;
	int sign = 1;

	if(stream->GetCurrentByte() == '(')
		stream->Advance();
	else
	{
		printf("syntax error %d %c\n", __LINE__, stream->GetCurrentByte());
		return 0;
	}

	removeSpaces();
	t1 = term();
	removeSpaces();
	if(stream->GetCurrentByte() == '+' || stream->GetCurrentByte() == '-')
	{
		sign = stream->GetCurrentByte() == '+' ? 1 : -1;
		stream->Advance();
		removeSpaces();
		t2 = term();
	}

	removeSpaces();
	if(stream->GetCurrentByte() == ')')
		stream->Advance();
	else
	{
		printf("syntax error %d %c\n", __LINE__, stream->GetCurrentByte());
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
	if(stream->GetCurrentByte() == '*' || stream->GetCurrentByte() == '/' || stream->GetCurrentByte() == '%')
	{
		sign = stream->GetCurrentByte();
		stream->Advance();
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
	if(stream->GetCurrentByte() == '(')
	{
		x = expression();
	}
	else if(isdigit(stream->GetCurrentByte()))
	{
		x =  number();
	}
	else if(stream->GetCurrentByte() == '"')
	{
		x = nextInstruction();
	}
	else
	{
		printf("syntax error %d %c\n", __LINE__, stream->GetCurrentByte());
		return 0;
	}

	return x;
}

void StackedInterpreter::removeSpaces()
{
	while(stream->GetCurrentByte() == ' ' || stream->GetCurrentByte() == '\t' || stream->GetCurrentByte() == '\n')
		stream->Advance();
}

void StackedInterpreter::readUntil(char c)
{
	while(stream->GetCurrentByte() != c)
		stream->Advance();
}
