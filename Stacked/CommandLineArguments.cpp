/*
 *   CommandLineArguments.cpp
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


#include "CommandLineArguments.h"
#include <unistd.h>
#include <getopt.h>

#include <sstream>

static struct option longOptions [] = {
		{"help", no_argument, 0, 'h'},
		{"file", required_argument, 0, 'f'},
		{"no-exec", no_argument, 0, 257},
        {"output-file", required_argument, 0, 258},
        {"input-file", required_argument, 0, 259},
        {"debug", required_argument, 0, 260},
        {"debug-file", required_argument, 0, 261},
		{0, 0, 0, 0}
};

std::string GetWarrantyString(char *string);

std::string GetConditionsString(char *string);

Configuration ParseCommandLineArguments(int argc, char *argv[])
{
	Configuration config;
	int optionCharacter;
	int optionIndex;

	/*default value*/
	config.execute = true;
    config.outputFile = "";
    config.inputFile = "";
    config.file = "";
    config.debugLevel = DEBUG_OFF;
    config.debugFile = "";

	while((optionCharacter = getopt_long(argc, argv, ":f:h", longOptions, &optionIndex)) != -1)
	{
		switch (optionCharacter)
		{
			case 'h':
				throw GetHelpString(argv[0]);

            case 'f':
                config.file = std::string(optarg);
                break;


            case 257: //--no-exec
				config.execute = false;
				break;

            case 258://--output-file
                config.outputFile = std::string(optarg);
                break;

            case 259://--input-file
                config.inputFile = std::string(optarg);
                break;

            case 260://--debug
            {
                std::string soptarg = std::string(optarg);
                if (soptarg == std::string("on"))
                    config.debugLevel = DEBUG_ON;
                else if (soptarg == std::string("off"))
                    config.debugLevel = DEBUG_OFF;
                else if (soptarg == std::string("verbose"))
                    config.debugLevel = DEBUG_VERBOSE;
                break;
            }

            case 261://--debug-file
                config.debugFile = std::string(optarg);
                break;

			case ':':
				throw std::string(argv[0]) + std::string(": option '-" ) + std::string(1, (char)optopt) + "' requires an argument; use '--help' option for more information";
				break;

			case '?':
			default:
                throw std::string(argv[0]) + std::string(": option '-" ) + std::string(1, (char)optopt) + "' is invalid; use '--help' option for more information";
                break;
		}

	}

	return config;

}


std::string GetHelpString(char * name)
{
	std::stringstream helpString;

	helpString << "Usage: " << name << " --file <file name> [options]\n"
			   << "Options: \n"
			   << "\t--file (-f)            Sets the file to be interpreted and executed, it is mandatory\n"
			   << "\t--no-exec              Interprets the code, but does not execute it\n"
               << "\t--output-file <file>   The output generated by the program is printed into the specified file; by default, output is printed to stdout\n"
               << "\t--input-file <file>    The input demanded by the program is scanned from specified file; by default, input is scanned from stdin\n"
               << "\t--debug                Enables the debug log of the program running\n"
               << "\t--debug-file <file>    The debug log generated is printed into the specified file; by default, it is printed to stderr\n";

    return helpString.str();
}


