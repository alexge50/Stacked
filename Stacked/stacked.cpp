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

#include <Stacked/StackedInterpreter.h>
#include <Stacked/StackedLanguageManager.h>
#include <Stacked/AbstractSyntaxTree/Program.h>

#include <Stacked/Error.h>
#include <Stacked/Stream/FileStream.h>

#include "CommandLineArguments.h"
#include "Signals.h"

#include <stdlib.h>
#include <stdio.h>

void printCopyrightPlate()
{
	printf("Stacked  Copyright (C) 2017  alexge50\n\
\n\
This program comes with ABSOLUTELY NO WARRANTY; \n\
This is free software, and you are welcome to redistribute it\n\
Under certain conditions; \n\n\n");
}

void checkConfiguration(Configuration *);


int main(int argc, char *argv[])
{
	Configuration config;

	try {
        config = ParseCommandLineArguments(argc, argv);
        checkConfiguration(&config);

        printCopyrightPlate();
        printf("%s:\n", config.file.c_str());

        FileStream *file = new FileStream;

        bool ok = file->OpenFile(std::string(config.file));

        if (ok != true) {
            printf("The file you told me to run does not exist.");
            return 0;
        }

        StackedInterpreter interp;

        interp.setStream(file);
        Program *program = interp.program();

        if (config.execute)
        {
            StackedLanguageManager langManager;
            FILE *fin, *fout, *debugFile;

            if(config.inputFile == std::string(""))
                fin = stdin;
            else
            {
                fin = fopen(config.inputFile.c_str(), "r");
                printf(": input from %s \n", config.inputFile.c_str());
            }

            if(config.outputFile == std::string(""))
                fout = stdout;
            else
            {
                fout = fopen(config.outputFile.c_str(), "w");
                printf(": output to %s \n", config.outputFile.c_str());
            }

            if(config.debug)
            {
                if(config.outputFile == std::string(""))
                    debugFile = stderr;
                else
                {
                    debugFile = fopen(config.debugFile.c_str(), "w");
                    printf(": debug output set to %s \n", config.debugFile.c_str());
                }
            }
            else debugFile = NULL;

            langManager.addSignal("system", (Signal *) new SyscallSignal());
            langManager.addSignal("scan", (Signal *) new InputSignal(fin));
            langManager.addSignal("print", (Signal *) new OutputSignal(fout));
            langManager.addSignal("debug", (Signal *) new DebugSignal());

            langManager.setDebugFile(debugFile);

            program->Run(&langManager);

            if(fin != stdin) fclose(fin);
            if(fout != stdout) fclose(fout);
            if(debugFile != NULL && debugFile != stderr) fclose(debugFile);

        }
    } catch(std::string& e) {
		printf("%s\n", e.c_str());
        return 0;
	} catch (Error &error) {
        printf("%s", error.getPrintableString().c_str());
        return -1;
    }
    catch(ErrorList &error) {
        printf("%s", error.getPrintableString().c_str());
        return -1;
    }

	return 0;
}

void checkConfiguration(Configuration *c)
{
	if(c->file == std::string(""))
		throw std::string("Error: file to run not specified. Specify the file to run using '--file' option; use '--help' option for more information");
}
