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
	// TODO Auto-generated constructor stub

}

StackedLanguageManager::~StackedLanguageManager()
{
	// TODO Auto-generated destructor stub
}

void StackedLanguageManager::newStack(std::string name)
{
	m_memorySpace[name] = new Stack();
#if DEBUG == 1
	printf("declared new stack: %s\n", name.c_str());
#endif
}

int StackedLanguageManager::nextElement(std::string name)
{
	//printf("%s", name.c_str());
	//fflush(stdout);
	int x = m_memorySpace[name]->nextElement();

#if DEBUG == 1
	printf("requested next element from '%s', returning: %d\n", name.c_str(), x);
#endif

	return x;
}

void StackedLanguageManager::resetStack(std::string name)
{
	//delete m_memorySpace[name];
	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;
#if DEBUG == 1
	printf("resetted stack '%s'\n", name.c_str());
#endif
}

void StackedLanguageManager::popStack(std::string name)
{

	m_memorySpace[name]->stack.pop_back();
	m_memorySpace[name]->i = min(m_memorySpace[name]->i, m_memorySpace[name]->stack.size() - 1);
#if DEBUG == 1
	printf("popped from stack '%s'\n", name.c_str());
#endif
}

void StackedLanguageManager::pushStack(std::string name, int value)
{
	//printf("%d added to %s\n", value, name.c_str());
	if(m_memorySpace[name] == NULL)
	{
		printf("%s was not defined\n", name.c_str());
		return ;
	}

	m_memorySpace[name]->stack.push_back(value);
	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;

#if DEBUG == 1
	printf("pushed %d into %s\n", value, name.c_str());
#endif
}

bool StackedLanguageManager::greaterThanOperation(std::string name1, std::string name2)
{
	return m_memorySpace[name1]->top() > m_memorySpace[name2]->top();
}

bool StackedLanguageManager::lessThanOperation(std::string name1, std::string name2)
{
	return m_memorySpace[name1]->top() < m_memorySpace[name2]->top();
}

bool StackedLanguageManager::equalOperation(std::string name1, std::string name2)
{
	return m_memorySpace[name1]->top() == m_memorySpace[name2]->top();
}

bool StackedLanguageManager::notEqualOperation(std::string name1, std::string name2)
{
	return m_memorySpace[name1]->top() != m_memorySpace[name2]->top();
}

bool StackedLanguageManager::notEmptyOperation(std::string name)
{
	return !m_memorySpace[name]->empty();
}


bool StackedLanguageManager::isInMemory(std::string name)
{
	return m_memorySpace.find(name) != m_memorySpace.end();
}


void StackedLanguageManager::signal(std::string name)
{
#if DEBUG == 1
	printf("called signal: %s\n", name.c_str());
#endif
	m_signalMap[name]->main();
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
