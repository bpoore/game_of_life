/*********************************************************************
** Author: Elizabeth Poore
** Date: April 6, 2015
** Description: Point.hpp is the Point class specification file
*********************************************************************/
#ifndef POINT_HPP
#define POINT_HPP

// Point class declaration
class Point
{
	private: 
	int xCoord, yCoord;

	public:
	Point();
	Point(int, int);
	void setXCoord(int);
	void setYCoord(int);
	int getXCoord(); 
	int getYCoord(); 
};
#endif
