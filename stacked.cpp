/*
 *   stacked.cpp
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
#include "StackedLanguageManager.h"
#include "AbstractSyntaxTree/Program.h"

#include "Error.h"
#include "Signals.h"
#include "Stream/FileStream.h"

#include <stdlib.h>
#include <stdio.h>

void print_help(char * name)
{
	printf("This program shall be used as follows:\n"
		   "%s <filename to be interpreted> \n", name);
}

int main(int argc, char *argv[])
{
	printf("Stacked  Copyright (C) 2017  alexge50\n\
\n\
This program comes with ABSOLUTELY NO WARRANTY; \n\
This is free software, and you are welcome to redistribute it\n\
Under certain conditions; \n\n\n");



	if(argc != 2)
	{
		print_help(argv[0]);
		return 0;
	}

	printf("%s:\n", argv[1]);

	FileStream *file = new FileStream;

	bool ok = file->OpenFile(std::string(argv[1]));

	if(ok != true)
	{
		printf("The file you told me to run does not exist.");
		return 0;
	}

	try
	{
		StackedInterpreter interp;
		StackedLanguageManager langManager;

		interp.setStream(file);
		Program *program = interp.program();

		langManager.addSignal<OutputSignal>("print");
		langManager.addSignal<InputSignal>("scan");
		langManager.addSignal<SyscallSignal>("system");
		langManager.addSignal<DebugSignal>("debug");

		program->Run(&langManager);
	}
	catch (Error &error)
	{
		printf("%s", error.getPrintableString().c_str());
	}
	catch(ErrorList &error)
	{
		printf("%s", error.getPrintableString().c_str());
	}

	return 0;
}
