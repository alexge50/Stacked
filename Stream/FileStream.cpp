/*
 * FileStream.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "FileStream.h"

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
}

unsigned long int FileStream::GetCurrentPosition()
{
	return ftell(fin);
}

void FileStream::SetPosition(unsigned long int x)
{
	fseek(fin, x - 1, SEEK_SET);
	Advance();
}


bool FileStream::OpenFile(std::string s)
{
	fin = fopen(s.c_str(), "r");
	if(fin != NULL) currentChar = fgetc(fin);
	return fin != NULL;
}

void FileStream::CloseFile()
{
	fclose(fin);
}

