/*
 * MyLang.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: alex
 */

#include "StackedLanguageManager.h"
#include "Signal.h"

#include <stdio.h>

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
}

int StackedLanguageManager::nextElement(std::string name)
{
	//printf("%s", name.c_str());
	//fflush(stdout);

	return m_memorySpace[name]->nextElement();
}

void StackedLanguageManager::resetStack(std::string name)
{
	//delete m_memorySpace[name];
	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;
}

void StackedLanguageManager::popStack(std::string name)
{

	m_memorySpace[name]->stack.pop_back();
	m_memorySpace[name]->i = min(m_memorySpace[name]->i, m_memorySpace[name]->stack.size() - 1);
	//.erase (m_memorySpace[name]->stack.end());
}

void StackedLanguageManager::pushStack(std::string name, int value)
{
	//printf("%d added to %s\n", value, name.c_str());
	m_memorySpace[name]->stack.push_back(value);
	m_memorySpace[name]->i = m_memorySpace[name]->stack.size() - 1;
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


bool StackedLanguageManager::isInMemory(std::string name)
{
	return m_memorySpace.find(name) != m_memorySpace.end();
}


void StackedLanguageManager::signal(std::string name)
{
	m_signalMap[name]->main();
}

/*
template<typename T>
void StackedLanguageManager::addSignal<T>(std::string name)
{
	m_signalMap[name] = (Signal*) new T(this);
}*/


Signal* StackedLanguageManager::configureSignal(Signal* x)
{
	x->owner = this;
	x->init();
	return x;
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
