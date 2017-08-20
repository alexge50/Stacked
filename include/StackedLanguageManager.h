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

class Signal;

// this is the class that is my language
class StackedLanguageManager
{
public:
	struct Stack
	{
		std::vector<int> stack;
		int i;

		Stack();

		int nextElement();
		int top();
		bool empty();
	};
public:
	StackedLanguageManager();
	virtual ~StackedLanguageManager();


	/*stack operations*/
	void newStack(std::string);
	int nextElement(std::string);

	void resetStack(std::string);
	void popStack(std::string);
	void pushStack(std::string, int value);

	bool greaterThanOperation(std::string, std::string);
	bool lessThanOperation(std::string, std::string);
	bool equalOperation(std::string, std::string);
	bool notEqualOperation(std::string, std::string);
	bool notEmptyOperation(std::string);

	/*functions operations*/
	void call(std::string); //unavailable
	void signal(std::string);

	/* utility functions */
	void addCall(std::string); //unavailable

	template<typename T>
	void addSignal(std::string name)
	{
			m_signalMap[name] = configureSignal((Signal*) new T());
	}


	/* Interpreter Utilities */
	bool isInMemory(std::string);


private:
	//this is memory space of the language
	std::map<std::string, Stack*> m_memorySpace;
	std::map<std::string, Signal*> m_signalMap;

	Signal* configureSignal(Signal*);

private:
	void assertStackExistence(std::string);
	void assertSignalExistence(std::string);

	friend class Signal;
};

#endif /* STACKEDLANGUAGEMANAGER_H_ */