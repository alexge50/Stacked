/*
 * CommandLineArguments.h
 *
 *  Created on: Aug 18, 2017
 *      Author: alex
 */

#ifndef SRC_COMMANDLINEARGUMENTS_H_
#define SRC_COMMANDLINEARGUMENTS_H_

#include <string>

struct Configuration
{
	std::string file;
	bool execute;
};

Configuration ParseCommandLineArguments(int argc, char *argv[]);
std::string GetHelpString(char * name);

#endif /* SRC_COMMANDLINEARGUMENTS_H_ */
