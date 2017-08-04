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
	virtual char GetCurrentByte() = 0;
	virtual void Advance() = 0;

public:
	virtual unsigned long int GetCurrentPosition() = 0;
	virtual void SetPosition(unsigned long int) = 0;
};

#endif /* SRC_STREAM_ISTREAM_H_ */
