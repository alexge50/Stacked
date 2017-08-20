/*
 *   Stream/FileStream.h
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


#ifndef SRC_STREAM_FILESTREAM_H_
#define SRC_STREAM_FILESTREAM_H_

#include <Stream/IStream.h>
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
	virtual StreamPosition GetCurrentPosition() override;

public:
	bool OpenFile(std::string);
	void CloseFile();

private:
	FILE *fin;
	char currentChar;
	StreamPosition position;
};

#endif /* SRC_STREAM_FILESTREAM_H_ */
