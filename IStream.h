/*
 * IStream.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#ifndef SRC_STREAM_ISTREAM_H_
#define SRC_STREAM_ISTREAM_H_

class IStream
{
public:
	IStream();
	virtual ~IStream();

public:
	virtual char GetCurrentByte();
	virtual void Advance();

public:
	virtual unsigned long int GetCurrentPosition();
	virtual void SetPosition(unsigned long int);
};

#endif /* SRC_STREAM_ISTREAM_H_ */
