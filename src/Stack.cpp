/*
 *   Stack.cpp
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

#include "Stacked/Stack.h"

/***********/

Stack::Stack()
{
    i = 0;
};

int Stack::nextElement()
{
    if(i < stack.size())
        return stack[i--];
    else
        return -1;
}

int Stack::top()
{
    if(stack.size() != 0)
        return stack[stack.size() - 1];
    else
        return -1;
}

bool Stack::empty()
{
    return stack.size() == 0;

}