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
= default;

StackedLanguageManager::~StackedLanguageManager()
= default;

void StackedLanguageManager::newStack(std::string name)
{
    m_memorySpace[name] = new Stack();
}


int StackedLanguageManager::nextElement(std::string name)
{
    assertStackExistence(name);

    return m_memorySpace[name]->nextElement();
}

void StackedLanguageManager::resetStack(std::string name)
{
    assertStackExistence(name);

    m_memorySpace[name]->i = static_cast<int>(m_memorySpace[name]->stack.size() - 1);
}

void StackedLanguageManager::popStack(std::string name)
{
    assertStackExistence(name);

    m_memorySpace[name]->stack.pop_back();
    m_memorySpace[name]->i = static_cast<int>(min(m_memorySpace[name]->i, m_memorySpace[name]->stack.size() - 1));
}

void StackedLanguageManager::pushStack(std::string name, int value)
{
    assertStackExistence(name);

    m_memorySpace[name]->stack.push_back(value);
    m_memorySpace[name]->i = static_cast<int>(m_memorySpace[name]->stack.size() - 1);
}

bool StackedLanguageManager::greaterThanOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    return m_memorySpace[name1]->top() > m_memorySpace[name2]->top();
}

bool StackedLanguageManager::lessThanOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    return m_memorySpace[name1]->top() < m_memorySpace[name2]->top();
}

bool StackedLanguageManager::equalOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    return m_memorySpace[name1]->top() == m_memorySpace[name2]->top();
}

bool StackedLanguageManager::notEqualOperation(std::string name1, std::string name2)
{
    assertStackExistence(name1);
    assertStackExistence(name2);

    return m_memorySpace[name1]->top() != m_memorySpace[name2]->top();
}

bool StackedLanguageManager::notEmptyOperation(std::string name)
{
    assertStackExistence(name);

    return !m_memorySpace[name]->empty();
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
}


Signal* StackedLanguageManager::configureSignal(Signal* x)
{
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

void StackedLanguageManager::call(std::string) {

}

void StackedLanguageManager::addCall(std::string) {

}

void StackedLanguageManager::internalAddSignal(std::string name, Signal *signal)
{
    m_signalMap[name] = configureSignal(signal);
}

bool StackedLanguageManager::isInMemory(std::string name) {
    return m_memorySpace.find(name) != m_memorySpace.end();
}

Stack *StackedLanguageManager::getStack(std::string name) {
    return m_memorySpace[name];
}
