/*
 *   Error.h
 *   Copyright (C) 2017 alexge50
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
#ifndef SRC_ERROR_H_
#define SRC_ERROR_H_

#include <string>
#include <vector>

enum ErrorType
{
	ParsingError = 1,
	RuntimeError = 2
};

class Error
{
public:
	Error(ErrorType, int line, int column, std::string message);
	virtual ~Error();

public:
	std::string getPrintableString();

	bool operator<(const Error&);

private:
	ErrorType m_errorType;
	int m_line, m_column;
	std::string m_message;
};

class ErrorList
{
public:
	ErrorList();
	virtual ~ErrorList();

	void addError(Error);
	std::string getPrintableString();
	bool isEmpty();

private:
	std::vector<Error> m_errorList;
};

#endif /* SRC_ERROR_H_ */
