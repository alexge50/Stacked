/*
 * CommandLineArguments.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: alex
 */

#include "CommandLineArguments.h"
#include <unistd.h>
#include <getopt.h>

static struct option longOptions [] = {
		{"file", required_argument, 0, 'f'},
		{0, 0, 0, 0}
};

Configuration ParseCommandLineArguments(int argc, char *argv[])
{
	Configuration config;
	int optionCharacter;
	int optionIndex;

	while((optionCharacter = getopt_long(argc, argv, ":f:", longOptions, &optionIndex)) != -1)
	{
		switch (optionCharacter)
		{
			case 'f':
				config.file = std::string(optarg);
				break;

			case ':':
				throw std::string(argv[0]) + std::string(": option '-" ) + std::string(1, (char)optopt) + "' requires an argument";
				break;

			case '?':
			default:
				throw std::string(argv[0]) + std::string(": option '-" ) + std::string(1, (char)optopt) + "' is invalid";
				break;
		}

	}

	return config;

}
