/*
 *   Signal.h
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


#ifndef SRC_SIGNAL_H_
#define SRC_SIGNAL_H_

#include <string>
#include "Stack.h"

class IStackedLanguageManager;

class Signal
{
public:
	Signal();
	virtual ~Signal();

public:
	virtual void init() = 0;
	virtual void main() = 0;

public:
	Stack* getStack(std::string);
	void makeStack(std::string);

protected:

	IStackedLanguageManager *owner;

protected:
	friend class IStackedLanguageManager;

};

#endif /* SRC_SIGNAL_H_ */
