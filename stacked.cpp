/*
 *   Stacked
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

#include <iostream>

#include "StackedInterpreter.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("    Stacked  Copyright (C) 2017  alexge50\n\
\n\
    This program comes with ABSOLUTELY NO WARRANTY; \n\
    This is free software, and you are welcome to redistribute it\n\
    under certain conditions; \n\n\n");

	printf("main.stack:\n");
	StackedInterpreter interp;

	interp.openFile("main.stack");

	while(interp.line() != true) ;

	return 0;
}
