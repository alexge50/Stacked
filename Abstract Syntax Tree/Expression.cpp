/*
 * Expression.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: alex
 */

#include "Expression.h"

Expression::Expression()
{
	// TODO Auto-generated constructor stub

}

Expression::~Expression()
{
	// TODO Auto-generated destructor stub
}

void Expression::Operands(Expression* left, Expression* right)
{
	m_left = left;
	m_right = right;
}

int Expression::Result()
{
	return m_result;
}
