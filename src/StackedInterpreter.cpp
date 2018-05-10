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


#include <Stacked/StackedInterpreter.h>
#include <stdio.h>
#include <ctype.h>

#include <Stacked/Stream/IStream.h>

#define EOF_INDICATOR ((Instruction*)-1)

StackedInterpreter::StackedInterpreter()
{
	stream = NULL;

	InstructionMap['%'] = std::bind(&StackedInterpreter::newInstruction, this);
	InstructionMap['"'] = std::bind(&StackedInterpreter::nextInstruction, this);
	InstructionMap['?'] = std::bind(&StackedInterpreter::resetInstruction, this);
	InstructionMap['-'] = std::bind(&StackedInterpreter::popInstruction, this);
	InstructionMap['+'] = std::bind(&StackedInterpreter::pushInstruction, this);
	InstructionMap['!'] = std::bind(&StackedInterpreter::signalInstruction, this);
	InstructionMap['['] = std::bind(&StackedInterpreter::whileBlock, this);
	InstructionMap['{'] = std::bind(&StackedInterpreter::ifBlock, this);
	InstructionMap[']'] = std::bind(&StackedInterpreter::nullInstruction, this);
	InstructionMap['}'] = std::bind(&StackedInterpreter::nullInstruction, this);

	ComparativeInstructionMap['<'] = std::bind(&StackedInterpreter::lessThanInstruction, this);
	ComparativeInstructionMap['='] = std::bind(&StackedInterpreter::equalInstruction, this);
	ComparativeInstructionMap['>'] = std::bind(&StackedInterpreter::greaterThanInstruction, this);
	ComparativeInstructionMap['n'] = std::bind(&StackedInterpreter::notEqualInstruction, this);
	ComparativeInstructionMap['e'] = std::bind(&StackedInterpreter::notEmptyInstruction, this);

}

StackedInterpreter::~StackedInterpreter() = default;

void StackedInterpreter::setStream(IStream* s)
{
	stream = s;
}

Program* StackedInterpreter::program()
{
	Program *program = new Program;

	int j = 0;
	Instruction *i;
	while((i = line()) != EOF_INDICATOR)
		program->GetInstructionBlock()->push_back(i), j ++;

	//printf("%d operations parsed\n", program->GetInstructionBlock()->size());

	if(!errorList.isEmpty())
		throw errorList;

	return program;
}

Instruction* StackedInterpreter::line()
{
	char x;
	removeSpaces();
	x = stream->GetCurrentByte();

	if(x == EOF)
		return EOF_INDICATOR;

	if(InstructionMap.find(x) != InstructionMap.end())
		return InstructionMap[x]();
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		if(x == '(' || ComparativeInstructionMap.find(x) != ComparativeInstructionMap.end())
			errorList.addError(Error(ParsingError, line, column, std::string("Parsing error, instruction '") + x + "' not expected; line discarded"));
		else errorList.addError(Error(ParsingError, line, column, std::string("undefined instruction '") + x + "'; line discarded"));

		readUntil('\n');

		return (Instruction*)new InvalidInstruction();
	}

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

	StreamPosition whilePosition = stream->GetCurrentPosition();
	bool invalid = false;

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();
	}
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected condition statement"));

		invalid = true;
		//return (Instruction*)new InvalidInstruction();
	}

	char x = stream->GetCurrentByte();
	Comparation *condition;


	if(ComparativeInstructionMap.find(x) != ComparativeInstructionMap.end())
		condition = ComparativeInstructionMap[x]();
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		if(x == '(' || InstructionMap.find(x) != InstructionMap.end())
			errorList.addError(Error(ParsingError, line, column, "expected comparing instruction"));
		else errorList.addError(Error(ParsingError, line, column, std::string("undefined instruction '") + x + "'"));
			condition =  NULL;
		invalid = true;
	}

	removeSpaces();
	if(stream->GetCurrentByte() != ':')
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected  ':'"));

		invalid = true;
	}
	else
		stream->Advance();
	removeSpaces();

	While *instruction = new While();

	instruction->Condition(condition);

	Instruction *whileInstruction = line();
	while(whileInstruction != NULL && whileInstruction != EOF_INDICATOR && stream->GetCurrentByte() != ']')
	{
		instruction->GetInstructionBlock()->push_back(whileInstruction);
				whileInstruction = line();
	}

	if(whileInstruction == EOF_INDICATOR)
	{
		int line = whilePosition.line;
		int column = whilePosition.column;
		errorList.addError(Error(ParsingError, line, column, "while not ended"));

		invalid = true;
	}

	stream->Advance();

	if(invalid)
		return (Instruction*) new InvalidInstruction();
	return instruction;
}

Instruction* StackedInterpreter::ifBlock()
{
	stream->Advance();
	removeSpaces();

	StreamPosition ifPosition = stream->GetCurrentPosition();
	bool invalid = false;

	if(stream->GetCurrentByte() == ':')
	{
		stream->Advance();
		removeSpaces();
	}
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected condition statement"));

		invalid = true;
		//return (Instruction*)new InvalidInstruction();
	}

	char x = stream->GetCurrentByte();
	Comparation *condition;


	if(ComparativeInstructionMap.find(x) != ComparativeInstructionMap.end())
		condition = ComparativeInstructionMap[x]();
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		if(x == '(' || InstructionMap.find(x) != InstructionMap.end())
			errorList.addError(Error(ParsingError, line, column, "expected comparing instruction"));
		else errorList.addError(Error(ParsingError, line, column, std::string("undefined instruction '") + x + "'"));
			condition =  NULL;
		invalid = true;
	}

	removeSpaces();
	if(stream->GetCurrentByte() != ':')
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected  ':'"));

		invalid = true;
	}
	else
		stream->Advance();
	removeSpaces();

	If *instruction = new If();

	instruction->Condition(condition);

	Instruction *ifInstruction = line();
	while(ifInstruction != NULL && ifInstruction != EOF_INDICATOR && stream->GetCurrentByte() != ']')
	{
		instruction->GetInstructionBlock()->push_back(ifInstruction);
		ifInstruction = line();
	}

	if(ifInstruction == EOF_INDICATOR)
	{
		int line = ifPosition.line;
		int column = ifPosition.column;
		errorList.addError(Error(ParsingError, line, column, "if not ended"));

		invalid = true;
	}

	stream->Advance();

	if(invalid)
		return (Instruction*) new InvalidInstruction();
	return instruction;
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

Instruction* StackedInterpreter::nullInstruction()
{
	return NULL;
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


Expression* StackedInterpreter::expression()
{
	Expression *t1 = NULL, *t2 = NULL;
	int sign = 1;

	if(stream->GetCurrentByte() == '(')
		stream->Advance();
	else
	{
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "syntax error, expression must be put inside '()'. expected expression"));
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
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected ')'\n"));
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
		int line = stream->GetCurrentPosition().line;
		int column = stream->GetCurrentPosition().column;
		errorList.addError(Error(ParsingError, line, column, "expected numeric constant or result from \""));
	}

	return x;
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
