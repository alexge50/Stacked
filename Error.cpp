/*
 *   Error.cpp
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

#include "Error.h"

#include <sstream>

Error::Error(ErrorType errorType, int line, int column, std::string message)
{
	// TODO Auto-generated constructor stub
	m_errorType = errorType;
	m_line = line;
	m_column = column;
	m_message = message;
}

Error::~Error()
{
	// TODO Auto-generated destructor stub
}

std::string Error::getPrintableString()
{
	std::string errorTypes[2] = {"Parsing Error", "Runtime Error"};
	std::stringstream ss;

	ss << errorTypes[m_errorType] << " - " << "(l: " << m_line << ", c: "<< m_column << "): " << m_message << std::endl;

	return ss.str();
}
