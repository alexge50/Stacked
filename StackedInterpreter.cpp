/*
 *   StackedInterpreter.cpp
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

void StackedInterpreter::setStream(IStream* s)
{
	stream = s;
}

Program* StackedInterpreter::program()
{
	int j = 0;
	Program *program = new Program;
	Instruction *i;
	while((i = line()) != NULL)
		program->GetInstructionBlock()->push_back(i), j ++;

	//printf("this program %d has instructions\n", j);

	return program;
}

Instruction* StackedInterpreter::line()
{
	char x;
	removeSpaces();
	x = stream->GetCurrentByte();

	if(x == EOF)
		return NULL;


	if(x == '(')
	{
		return mathBlock();
	}
	else if(x == '%')
	{
		return this->newInstruction();
	}
	else if(x == '"')
	{
		return this->nextInstruction();
	}
	else if(x == '?')
	{
		return this->resetInstruction();
	}
	else if(x == '-')
	{
		return this->popInstruction();
	}
	else if(x == '+')
	{
		return this->pushInstruction();
	}
	else if(x == '!')
	{
		return this->signalInstruction();
	}
	else if(x == '>')
	{
		return this->greaterThanInstruction();
	}
	else if(x == '<')
	{
		return this->lessThanInstruction();
	}
	else if(x == '=')
	{
		return this->equalInstruction();
	}
	else if(x == 'n')
	{
		return this->notEqualInstruction();
	}
	else if(x == 'e')
	{
		return this->notEmptyInstruction();
	}
	else if(x == '[')
	{
		return whileBlock();
	}
	else if(x == '{')
	{
		return ifBlock();
	}
	//else return NULL;

	removeSpaces();

	return 0;
}

Expression* StackedInterpreter::mathBlock()
{
	return expression();
}

Instruction* StackedInterpreter::whileBlock()
{
	stream->Advance();
	removeSpaces();

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();

		char x = stream->GetCurrentByte();
		Comparation *condition;

		if(x == '>')
			condition = this->greaterThanInstruction();
		else if(x == '<')
			condition = this->lessThanInstruction();
		else if(x == '=')
			condition = this->equalInstruction();
		else if(x == 'n')
			condition = this->notEqualInstruction();
		else if(x == 'e')
			condition = this->notEmptyInstruction();

		removeSpaces();
		if(stream->GetCurrentByte() != ':')
		{
			printf("condition statement was not ended\n");
			return NULL;
		}
		stream->Advance();
		removeSpaces();

		While *instruction = new While();

		instruction->Condition(condition);

		Instruction *whileInstruction = line();
		while(whileInstruction != NULL && stream->GetCurrentByte() != ']')
		{
			instruction->GetInstructionBlock()->push_back(whileInstruction);
			whileInstruction = line();
		}
		stream->Advance();

		return instruction;
	}
	else
	{
		printf("expected condition\n");
			return NULL;
	}

	return NULL;
}

Instruction* StackedInterpreter::ifBlock()
{
	stream->Advance();
	removeSpaces();

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();

		char x = stream->GetCurrentByte();
		Comparation *condition;

		if(x == '>')
			condition = this->greaterThanInstruction();
		else if(x == '<')
			condition = this->lessThanInstruction();
		else if(x == '=')
			condition = this->equalInstruction();
		else if(x == 'n')
			condition = this->notEqualInstruction();
		else if(x == 'e')
			condition = this->notEmptyInstruction();

		removeSpaces();
		if(stream->GetCurrentByte() != ':')
		{
			printf("condition statement was not ended\n");
			return NULL;
		}
		stream->Advance();
		removeSpaces();

		If *instruction = new If();

		instruction->Condition(condition);

		Instruction *ifInstruction = line();
		while(ifInstruction != NULL && stream->GetCurrentByte() != ']')
		{
			instruction->GetInstructionBlock()->push_back(ifInstruction);
			ifInstruction = line();
		}

		stream->Advance();

		return instruction;

	}
	else
	{
		printf("expected condition\n");
			return NULL;
	}

	return NULL;
}


Instruction* StackedInterpreter::newInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	NewStack *instruction = new NewStack;

	instruction->Argument(name);

	return instruction;
}

Expression* StackedInterpreter::nextInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	NextElement *instruction = new NextElement;

	instruction->Argument(name);

	return instruction;
}


Instruction*StackedInterpreter::popInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	PopStack *instruction = new PopStack;

	instruction->Argument(name);

	return instruction;
}

Instruction* StackedInterpreter::pushInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();
	Expression *x;

	removeSpaces();
	x = mathBlock();

	PushStack *instruction = new PushStack;

	instruction->Arguments(name, x);

	return instruction;
}

Instruction* StackedInterpreter::resetInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	ResetStack *instruction = new ResetStack;

	instruction->Argument(name);

	return instruction;
}

Instruction* StackedInterpreter::signalInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	SignalInstruction *instruction = new SignalInstruction();

	instruction->Argument(name);

	return instruction;
}

Comparation* StackedInterpreter::greaterThanInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	Comparation *instruction = new GreaterThan();

	instruction->Arguments(name1, name2);

	return instruction;
}

Comparation* StackedInterpreter::lessThanInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	Comparation *instruction = new LessThan();

	instruction->Arguments(name1, name2);

	return instruction;
}

Comparation* StackedInterpreter::equalInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	Comparation *instruction = new Equal();

	instruction->Arguments(name1, name2);

	return instruction;
}

Comparation* StackedInterpreter::notEqualInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name1 = string();
	removeSpaces();
	std::string name2 = string();

	Comparation *instruction = new NotEqual();

	instruction->Arguments(name1, name2);

	return instruction;
}

Comparation* StackedInterpreter::notEmptyInstruction()
{
	stream->Advance();
	removeSpaces();

	std::string name = string();

	NotEmpty *instruction = new NotEmpty;

	instruction->Arguments(name, std::string(""));

	return instruction;
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



Expression* StackedInterpreter::expression()
{
	Expression *t1 = NULL, *t2 = NULL;
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

	Expression *instruction;

	if(sign == +1)
		instruction = new Addition();
	else if(sign == -1)
		instruction = new Subtraction();

	instruction->Operands(t1, t2);

	return instruction;
}

Expression* StackedInterpreter::term()
{
	Expression *f1 = NULL, *f2 = NULL;
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

	Expression *instruction;

	if(sign == '*') instruction = new Multiplication();
	else if(sign == '/') instruction = new Division();
	else if(sign == '%') instruction = new Mod();

	instruction->Operands(f1, f2);

	return instruction;
}

Expression* StackedInterpreter::factor()
{
	Expression *x;
	if(stream->GetCurrentByte() == '(')
	{
		x = expression();
	}
	else if(isdigit(stream->GetCurrentByte()))
	{
		ConstNumber *y = new ConstNumber();
		y->Number(number());
		x = y;
	}
	else if(stream->GetCurrentByte() == '"')
	{
		x = nextInstruction();
	}
	else
	{
		printf("syntax error %d %c\n", __LINE__, stream->GetCurrentByte());
		return NULL;
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
