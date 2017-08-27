/*
 *   StackedLanguageManager.cpp
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


#define DEBUG 0

#include <Stacked/StackedLanguageManager.h>
#include <Stacked/Signal.h>
#include <Stacked/Error.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

StackedLanguageManager::StackedLanguageManager()
{
    debugFile = NULL;
}

StackedLanguageManager::~StackedLanguageManager()
{
}

void StackedLanguageManager::newStack(std::string name)
{
	m_memorySpace[name] = new Stack();

    if(debugFile != NULL) fprintf(debugFile, "created new stack '%s'\n", name.c_str());
}


int StackedLanguageManager::nextElement(std::string name)
{
    assertStackExistence(name);

	int x = m_memorySpace[name]->nextElement();

    if(debugFile != NULL) fprintf(debugFile, "next element on stack '%s' returned the value %d\n", name.c_str(), x);

	return x;
}

void StackedLanguageManager::resetStack(std::string name)
{
    assertStackExistence(name);

	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;

    if(debugFile != NULL) fprintf(debugFile, "reset the stack '%s'\n", name.c_str());
}

void StackedLanguageManager::popStack(std::string name)
{
    assertStackExistence(name);

	m_memorySpace[name]->stack.pop_back();
	m_memorySpace[name]->i = min(m_memorySpace[name]->i, m_memorySpace[name]->stack.size() - 1);

    if(debugFile != NULL) fprintf(debugFile, "popped from stack '%s'\n", name.c_str());
}

void StackedLanguageManager::pushStack(std::string name, int value)
{
    assertStackExistence(name);

	m_memorySpace[name]->stack.push_back(value);
	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;

    if(debugFile != NULL) fprintf(debugFile, "pushed %d in the stack '%s'\n", value, name.c_str());
}

bool StackedLanguageManager::greaterThanOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    bool x = m_memorySpace[name1]->top() > m_memorySpace[name2]->top();

    if(debugFile != NULL)
        fprintf(debugFile, "greater than operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");

	return x;
}

bool StackedLanguageManager::lessThanOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    if(debugFile != NULL) fprintf(debugFile, "");

	bool x = m_memorySpace[name1]->top() < m_memorySpace[name2]->top();

    if(debugFile != NULL)
        fprintf(debugFile, "less than operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");

    return x;
}

bool StackedLanguageManager::equalOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    bool x = m_memorySpace[name1]->top() == m_memorySpace[name2]->top();

    if(debugFile != NULL)
        fprintf(debugFile, "equal operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");

    return x;
}

bool StackedLanguageManager::notEqualOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    bool x = m_memorySpace[name1]->top() != m_memorySpace[name2]->top();

    if(debugFile != NULL)
        fprintf(debugFile, "not equal operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");

    return x;
}

bool StackedLanguageManager::notEmptyOperation(std::string name)
{
    assertStackExistence(name);

	bool x = !m_memorySpace[name]->empty();

    if(debugFile != NULL) fprintf(debugFile, "not empty operation on '%s' returned %s\n", name.c_str(), x ? "true" : "false");

    return x;
}


/*
bool StackedLanguageManager::isInMemory(std::string name)
{
	return m_memorySpace.find(name) != m_memorySpace.end();
}*/


void StackedLanguageManager::signal(std::string name)
{
    assertSignalExistence(name);

	m_signalMap[name]->main();

    if(debugFile != NULL) fprintf(debugFile, "called signal '%s'\n", name.c_str());
}


Signal* StackedLanguageManager::configureSignal(Signal* x)
{
	x->owner = this;
	x->init();
	return x;
}

void StackedLanguageManager::assertStackExistence(std::string x)
{
	if(m_memorySpace.find(x) == m_memorySpace.end())
		throw Error(RuntimeError, -1, -1, std::string("stack '") + x + "' was not defined");
}

void StackedLanguageManager::assertSignalExistence(std::string x)
{
	if(m_signalMap.find(x) == m_signalMap.end())
		throw Error(RuntimeError, -1, -1, std::string("signal '") + x + "' was not registered");
}

void StackedLanguageManager::addSignal(std::string name, Signal *signal)
{
    m_signalMap[name] = configureSignal(signal);
}

void StackedLanguageManager::setDebugFile(FILE *f)
{
    debugFile = f;
}

/***********/

StackedLanguageManager::Stack::Stack()
{
	i = 0;
};

int StackedLanguageManager::Stack::nextElement()
{
	if(i < stack.size())
		return stack[i--];
	else
		return -1;
}

int StackedLanguageManager::Stack::top()
{
	if(stack.size() != 0)
		return stack[stack.size() - 1];
	else
		return -1;
}

bool StackedLanguageManager::Stack::empty()
{
	return stack.size() == 0;

}
