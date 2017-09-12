/*
 *   StackedLanguageManager.h
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


#ifndef STACKEDLANGUAGEMANAGER_H_
#define STACKEDLANGUAGEMANAGER_H_

#include <map>
#include <vector>
#include <string>
#include "Signal.h"

// this is the class that is my language
class IStackedLanguageManager
{
public:
	virtual ~IStackedLanguageManager() = default;


	/*stack operations*/
	virtual void newStack(std::string) = 0;
	virtual int nextElement(std::string) = 0;

	virtual void resetStack(std::string) = 0;
	virtual void popStack(std::string) = 0;
	virtual void pushStack(std::string, int value) = 0;

	virtual bool greaterThanOperation(std::string, std::string) = 0;
	virtual bool lessThanOperation(std::string, std::string) = 0;
	virtual bool equalOperation(std::string, std::string) = 0;
	virtual bool notEqualOperation(std::string, std::string) = 0;
	virtual bool notEmptyOperation(std::string) = 0;

	/*functions operations*/
	virtual void call(std::string) = 0; //unavailable
	virtual void signal(std::string) = 0;

	/* utility functions */
	virtual void addCall(std::string) = 0; //unavailable
	virtual void addSignal(std::string name, Signal *signal)
    {
        signal->owner = this;
        internalAddSignal(name, signal);
    }

    virtual bool isInMemory(std::string) = 0;
    virtual Stack* getStack(std::string) = 0;

    virtual void internalAddSignal(std::string name, Signal*) = 0;

protected:
	friend class Signal;
};

#endif /* STACKEDLANGUAGEMANAGER_H_ */
