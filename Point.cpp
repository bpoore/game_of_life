/*********************************************************************
** Author: Elizabeth Poore
** Date: April 6, 2015
** Description: Point.cpp is the Point class implementation file
*********************************************************************/
#include "Point.hpp"

Point::Point() // Default constructor
{ xCoord = 0, yCoord = 0;}
	
Point::Point(int x, int y) // Constructor
{
	setXCoord(x), setYCoord(y);
}

/*********************************************************************
**                     Set Functions
*********************************************************************/
void Point::setXCoord(int x) 
{
	xCoord = x;
}

void Point::setYCoord(int y)
{
	yCoord = y;
}

/*********************************************************************
**                     Get Functions
*********************************************************************/
int Point::getXCoord() 
{
	return xCoord;
}

int Point::getYCoord() 
{
	return yCoord;
}