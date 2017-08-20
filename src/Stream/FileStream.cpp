/*
 *   Stream/FileStream.cpp
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



#include <Stream/FileStream.h>

FileStream::FileStream()
{
	// TODO Auto-generated constructor stub

}

FileStream::~FileStream()
{
	// TODO Auto-generated destructor stub
}


char FileStream::GetCurrentByte()
{
	return currentChar;
}

void FileStream::Advance()
{
	currentChar = fgetc(fin);

	if(currentChar == '\n')
	{
		position.line ++;
		position.column = 1;
	}
	else position.column ++;
}

StreamPosition FileStream::GetCurrentPosition()
{
	return position;
}


bool FileStream::OpenFile(std::string s)
{
	fin = fopen(s.c_str(), "r");
	if(fin != NULL) currentChar = fgetc(fin);

	position.line = 1;
	position.column = 1;

	return fin != NULL;
}

void FileStream::CloseFile()
{
	fclose(fin);
}

