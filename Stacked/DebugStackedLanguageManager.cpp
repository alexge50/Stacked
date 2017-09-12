/*
 *   DebugStackedLanguageManager.cpp
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

#include "DebugStackedLanguageManager.h"

DebugStackedLanguageManager::DebugStackedLanguageManager(FILE *debugFile, DebugLevel debugLevel)
{
    m_debugFile = debugFile;
    m_debugLevel = debugLevel;
}

void DebugStackedLanguageManager::newStack(std::string name)
{
    m_manager.newStack(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%% %s\n", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "created new stack '%s'\n", name.c_str());
    }
}

int DebugStackedLanguageManager::nextElement(std::string name)
{
    int x = m_manager.nextElement(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%d == \"%s \n", x, name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "next element on stack '%s' returned the value %d\\n", name.c_str(), x);
    }

    return x;
}

void DebugStackedLanguageManager::resetStack(std::string name)
{
    m_manager.resetStack(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "? %s\n", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "reset the stack '%s'\n", name.c_str());
    }
}

void DebugStackedLanguageManager::popStack(std::string name)
{
    m_manager.popStack(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "- %s\n", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "popped from stack '%s'\n", name.c_str());
    }
}

void DebugStackedLanguageManager::pushStack(std::string name, int value)
{
    m_manager.pushStack(name, value);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "+ %s (%d)\n", name.c_str(), value);
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "pushed %d in the stack '%s'\n", value, name.c_str());
    }
}

bool DebugStackedLanguageManager::greaterThanOperation(std::string name1, std::string name2)
{
    bool x = m_manager.greaterThanOperation(name1, name2);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%s == > %s %s\n", x ? "true" : "false" , name1.c_str(), name2.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "greater than operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");
    }

    return x;
}

bool DebugStackedLanguageManager::lessThanOperation(std::string name1, std::string name2)
{
    bool x = m_manager.lessThanOperation(name1, name2);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%s == < %s %s\n", x ? "true" : "false", name1.c_str(), name2.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "less than operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");
    }

    return x;
}

bool DebugStackedLanguageManager::equalOperation(std::string name1, std::string name2)
{
    bool x = m_manager.equalOperation(name1, name2);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%s == = %s %s\n", x ? "true" : "false", name1.c_str(), name2.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "equal operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");
    }

    return x;
}

bool DebugStackedLanguageManager::notEqualOperation(std::string name1, std::string name2)
{
    bool x = m_manager.notEqualOperation(name1, name2);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%s == n %s %s\n", x ? "true" : "false", name1.c_str(), name2.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "not equal operation between '%s' and '%s' returned %s\n", name1.c_str(), name2.c_str(), x ? "true" : "false");
    }

    return x;
}

bool DebugStackedLanguageManager::notEmptyOperation(std::string name)
{
    bool x = m_manager.notEmptyOperation(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "%s == e %s\n", x ? "true" : "false", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "not empty operation on '%s' returned %s\n", name.c_str(), x ? "true" : "false");
    }

    return x;
}

void DebugStackedLanguageManager::call(std::string name)
{
    m_manager.call(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "called function '%s'\n", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "called function '%s'\n", name.c_str());
    }
}

void DebugStackedLanguageManager::signal(std::string name)
{
    m_manager.signal(name);

    if(m_debugFile != NULL && m_debugLevel != DEBUG_OFF)
    {
        if(m_debugLevel == DEBUG_ON)
            fprintf(m_debugFile, "! %s\n", name.c_str());
        else if(m_debugLevel == DEBUG_VERBOSE)
            fprintf(m_debugFile, "called signal '%s'\n", name.c_str());
    }
}

void DebugStackedLanguageManager::addCall(std::string name)
{
    m_manager.addCall(name);
}

bool DebugStackedLanguageManager::isInMemory(std::string name)
{
    return m_manager.isInMemory(name);
}

Stack *DebugStackedLanguageManager::getStack(std::string name)
{
    return m_manager.getStack(name);
}

void DebugStackedLanguageManager::internalAddSignal(std::string name, Signal *signal)
{
    m_manager.internalAddSignal(name, signal);
}
