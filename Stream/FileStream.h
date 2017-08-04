/*
 * FileStream.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_STREAM_FILESTREAM_H_
#define SRC_STREAM_FILESTREAM_H_

#include "IStream.h"
#include <stdio.h>
#include <string>

class FileStream: public IStream
{
public:
	FileStream();
	virtual ~FileStream();

public:
	virtual char GetCurrentByte()override;
	virtual void Advance()override;

public:
	virtual unsigned long int GetCurrentPosition()override;
	virtual void SetPosition(unsigned long int)override;

public:
	bool OpenFile(std::string);
	void CloseFile();

private:
	FILE *fin;
	char currentChar;
};

#endif /* SRC_STREAM_FILESTREAM_H_ */
