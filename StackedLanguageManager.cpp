/*
 * MyLang.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: alex
 */

#include "StackedLanguageManager.h"

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
	m_memorySpace[name] = Stack();
}

int StackedLanguageManager::nextElement(std::string name)
{
	//printf("%s", name.c_str());
	//fflush(stdout);

	return m_memorySpace[name].nextElement();
}

void StackedLanguageManager::resetStack(std::string name)
{
	//delete m_memorySpace[name];
	m_memorySpace[name].i = m_memorySpace[name].stack.size() - 1;
}

void StackedLanguageManager::popStack(std::string name)
{

	m_memorySpace[name].stack.pop_back();
	m_memorySpace[name].i = min(m_memorySpace[name].i, m_memorySpace[name].stack.size() - 1);
	//.erase (m_memorySpace[name]->stack.end());
}

void StackedLanguageManager::pushStack(std::string name, int value)
{
	//printf("%d added to %s\n", value, name.c_str());
	m_memorySpace[name].stack.push_back(value);
	m_memorySpace[name].i = m_memorySpace[name].stack.size() - 1;
}

bool StackedLanguageManager::isInMemory(std::string name)
{
	return m_memorySpace.find(name) != m_memorySpace.end();
}

