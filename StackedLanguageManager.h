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

#ifndef MYLANG_H_
#define MYLANG_H_

#include <map>
#include <vector>
#include <string>

// this is the class that is my language
class StackedLanguageManager
{
	struct Stack
	{
		std::vector<int> stack;
		int i;

		Stack() { i = 0; };

		int nextElement()
		{
			if(i < stack.size())
				return stack[i--];
			else
				return -1;
		}
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

	/*functions operations*/
	void call(std::string); //unavailable
	void signal(std::string); //unavailable

	/* utility functions */
	void addCall(std::string); //unavailable
	void addSignal(std::string); //unavailable


	/* Interpreter Utilities */
	bool isInMemory(std::string);
private:
	//this is memory space of the language
	std::map<std::string, Stack> m_memorySpace;
};

#endif /* MYLANG_H_ */
