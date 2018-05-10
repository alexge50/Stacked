/*
 *   DebugStackedLanguageManager.h
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

#ifndef STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H
#define STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H


#include <Stacked/IStackedLanguageManager.h>
#include <Stacked/StackedLanguageManager.h>

enum DebugLevel
{
    DEBUG_OFF = 0,
    DEBUG_ON = 1,
    DEBUG_VERBOSE = 2
};

class DebugStackedLanguageManager : public IStackedLanguageManager
{
public:
    DebugStackedLanguageManager(FILE *debugFile, DebugLevel debugLevel):
        m_debugFile(debugFile),
        m_debugLevel(debugLevel)
    {}

    virtual ~DebugStackedLanguageManager() = default;

    /*stack operations*/
    virtual void newStack(std::string);
    virtual int nextElement(std::string);

    virtual void resetStack(std::string);
    virtual void popStack(std::string);
    virtual void pushStack(std::string, int value);

    virtual bool greaterThanOperation(std::string, std::string);
    virtual bool lessThanOperation(std::string, std::string);
    virtual bool equalOperation(std::string, std::string);
    virtual bool notEqualOperation(std::string, std::string);
    virtual bool notEmptyOperation(std::string);

    /*functions operations*/
    virtual void call(std::string); //unavailable
    virtual void signal(std::string);

    /* utility functions */
    virtual void addCall(std::string); //unavailable

    virtual bool isInMemory(std::string);
    virtual Stack* getStack(std::string);

    virtual void internalAddSignal(std::string name, Signal*);

private:
    StackedLanguageManager m_manager;
    FILE *m_debugFile;
    DebugLevel m_debugLevel;
};


#endif //STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H
