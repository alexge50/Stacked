/*
 * Comparation.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Comparation.h"

Comparation::Comparation()
{
	// TODO Auto-generated constructor stub

}

Comparation::~Comparation()
{
	// TODO Auto-generated destructor stub
}

void Comparation::Arguments(std::string left, std::string right)
{
	m_left = left;
	m_right = right;
}

bool Comparation::Result()
{
	return m_result;
}
