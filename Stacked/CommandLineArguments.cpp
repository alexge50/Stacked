/*
 * CommandLineArguments.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: alex
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
        {"debug", no_argument, 0, 260},
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
    config.debug = false;
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
                config.debug = true;
                break;

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

	helpString << "Usage: %s --file <file name> [options]\n"
			   << "Options: \n"
			   << "	--file (-f)		     Sets the file to be interpreted and executed, it is mandatory\n"
			   << "	--no-exec   		 Interprets the code, but does not execute it\n";

	return helpString.str();
}
