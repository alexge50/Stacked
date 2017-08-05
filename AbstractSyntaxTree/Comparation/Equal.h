/*
 *   AbstractSyntaxTree/Comparation/Equal.h
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


#ifndef SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_
#define SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_

#include "../Comparation.h"

class Equal: public Comparation
{
public:
	Equal();
	virtual ~Equal();

	virtual void Run(StackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACT_SYNTAX_TREE_COMPARATION_EQUAL_H_ */
