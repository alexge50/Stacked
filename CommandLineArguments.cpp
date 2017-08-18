/*
 * CommandLineArguments.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: alex
 */

#include "CommandLineArguments.h"
#include <unistd.h>
#include <getopt.h>

#include <stdio.h>

static struct option longOptions [] = {
		{"file", required_argument, 0, 'f'},
		{"help", no_argument, 0, 'h'},
		{"no-exec", no_argument, 0, 257},
		{0, 0, 0, 0}
};

Configuration ParseCommandLineArguments(int argc, char *argv[])
{
	Configuration config;
	int optionCharacter;
	int optionIndex;

	/*default value*/
	config.execute = true;

	while((optionCharacter = getopt_long(argc, argv, ":f:h", longOptions, &optionIndex)) != -1)
	{
		switch (optionCharacter)
		{
			case 'f':
				config.file = std::string(optarg);
				break;

			case 'h':
				throw GetHelpString(argv[0]);
				break;

			case 257: //--no-exec
				config.execute = false;
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
	char helpString[2048];

	sprintf(helpString, "Usage: %s --file <file name> [options]\n", name);
	sprintf(helpString, "Options: ");
	sprintf(helpString, "	--file (-f)		     Sets the file to be interpreted and executed, it is mandatory\n");
	sprintf(helpString, "	--no-exec   		 Interprets the code, but does not execute it\n");

	return std::string(helpString);
}
