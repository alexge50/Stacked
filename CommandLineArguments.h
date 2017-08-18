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
};

Configuration ParseCommandLineArguments(int argc, char *argv[]);

#endif /* SRC_COMMANDLINEARGUMENTS_H_ */
