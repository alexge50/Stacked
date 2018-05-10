/*
 *   AbstractSyntaxTree/Comparation/NotEqual.h
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


#ifndef SRC_ABSTRACTSYNTAXTREE_COMPARATION_NOTEQUAL_H_
#define SRC_ABSTRACTSYNTAXTREE_COMPARATION_NOTEQUAL_H_

#include <Stacked/AbstractSyntaxTree/Comparation.h>

class NotEqual: public Comparation
{
public:
	NotEqual() = default;
	virtual ~NotEqual() = default;

	virtual void Run(IStackedLanguageManager*) override;
};

#endif /* SRC_ABSTRACTSYNTAXTREE_COMPARATION_NOTEQUAL_H_ */
