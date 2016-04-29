/*********************************************************************
** Author: Elizabeth Poore
** Date: April 6, 2015
** Description: Grid.hpp is the Grid class specification file
*********************************************************************/
#ifndef GRID_HPP
#define GRID_HPP

#include "Point.hpp"

// Grid class declaration
const int HEIGHT = 40; // Size includes 10 ghost rows above and below the printed output
const int WIDTH = 60; // Size includes 10 ghost columns to the left and right of the printed output

const int OFFSET = 10; // Offset to account for ghost rows and columns

class Grid
{
	private:
	bool grid[HEIGHT][WIDTH];

	public:
	Grid();
	void fixed(Point point);
	void glider(Point point);
	void gliderGun();
	void userDefined(int x, int y);
	void next();
	void print();
	void clear();
};
#endif 


