/*********************************************************************
** Author: Elizabeth Poore
** Date: April 6, 2015
** Description: Gridd.hpp is the Grid class implementation file
*********************************************************************/
#include <iostream>

#include "Grid.hpp" // Class Grid declaration file

Grid::Grid() // Class Grid constructor
{
	for (int x=0; x<HEIGHT; x++)
	{
		for (int y=0; y<WIDTH; y++)
		{
			grid[x][y] = false;
		}
	}
}

/*********************************************************************
**                    Grid::fixed Function
** Description: This function sets cells to live for a simple fixed
** oscillator.
** Parameters: Input parameter is a Point object to determine where to place
** the oscillator. The function does not return any values.
** Pre-Conditions: A valid Point to be passed to the function
** Post-Conditions: Point object needs to be within array size parameters/
*********************************************************************/
void Grid::fixed(Point point)
{
	int x = point.getXCoord();
	int y = point.getYCoord();
	grid[y+OFFSET][x+OFFSET] = true;
	grid[y+OFFSET][x+1+OFFSET] = true;
	grid[y+OFFSET][x+2+OFFSET] = true;
}

/*********************************************************************
**                    Grid::glider Function
** Description: This function sets cells to live for a glider
** Parameters: Input parameter is a Point object to determine where to place
** the glider. The function does not return any values.
** Pre-Conditions: A valid Point to be passed to the function
** Post-Conditions: Point object needs to be within array size parameters.
*********************************************************************/
void Grid::glider(Point point)
{
	int x = point.getXCoord();
	int y = point.getYCoord();
	grid[y+2+OFFSET][x+OFFSET] = true;
	grid[y+2+OFFSET][x+1+OFFSET] = true;
	grid[y+2+OFFSET][x+2+OFFSET] = true;
	grid[y+OFFSET][x+1+OFFSET] = true;
	grid[y+1+OFFSET][x+2+OFFSET] = true;
}

/*********************************************************************
**                    Grid::gliderGun Function
** Description: This function sets cells to live for a glider gun
** Parameters: None. Due to the size of the glider gun, have opted to not
** allow the user to change its location so that the formation is visible.
** Pre-Conditions: None.
** Post-Conditions: None. 
*********************************************************************/
void Grid::gliderGun()
{
	grid[6+OFFSET][2+OFFSET] = true;
	grid[7+OFFSET][2+OFFSET] = true;
	grid[6+OFFSET][3+OFFSET] = true;
	grid[7+OFFSET][3+OFFSET] = true;

	grid[4+OFFSET][14+OFFSET] = true;
	grid[4+OFFSET][15+OFFSET] = true;
	grid[5+OFFSET][13+OFFSET] = true;
	grid[5+OFFSET][17+OFFSET] = true;
	grid[6+OFFSET][12+OFFSET] = true;
	grid[7+OFFSET][12+OFFSET] = true;
	grid[8+OFFSET][12+OFFSET] = true;
	grid[9+OFFSET][13+OFFSET] = true;
	grid[10+OFFSET][14+OFFSET] = true;
	grid[10+OFFSET][15+OFFSET] = true;
	grid[9+OFFSET][17+OFFSET] = true;
	grid[8+OFFSET][18+OFFSET] = true;
	grid[7+OFFSET][16+OFFSET] = true;
	grid[7+OFFSET][18+OFFSET] = true;
	grid[7+OFFSET][19+OFFSET] = true;
	grid[6+OFFSET][18+OFFSET] = true;
	grid[5+OFFSET][17+OFFSET] = true;

	grid[4+OFFSET][22+OFFSET] = true;
	grid[5+OFFSET][22+OFFSET] = true;
	grid[6+OFFSET][22+OFFSET] = true;
	grid[4+OFFSET][23+OFFSET] = true;
	grid[5+OFFSET][23+OFFSET] = true;
	grid[6+OFFSET][23+OFFSET] = true;
	grid[3+OFFSET][24+OFFSET] = true;
	grid[7+OFFSET][24+OFFSET] = true;
	grid[2+OFFSET][26+OFFSET] = true;
	grid[3+OFFSET][26+OFFSET] = true;
	grid[7+OFFSET][26+OFFSET] = true;
	grid[8+OFFSET][26+OFFSET] = true;

	grid[4+OFFSET][36+OFFSET] = true;
	grid[5+OFFSET][36+OFFSET] = true;
	grid[4+OFFSET][37+OFFSET] = true;
	grid[5+OFFSET][37+OFFSET] = true;
}

/*********************************************************************
**                    Grid::userDefined Function
** Description: This function sets selected cells to live. 
** Parameters: The function accepts to int arguments representing 
** x an y coorinates.
** Pre-Conditions: Valid x an y coordinates are passed.
** Post-Conditions: Coordinates are within array boundaries.
*********************************************************************/
void Grid::userDefined(int x, int y)
{
	grid[x+OFFSET][y+OFFSET] = true; // User is unaware of ghost cells, add OFFSET to coordinates
}

/*********************************************************************
**                    Grid::next Function
** Description: This function contains the logic to update the grid to 
** the next grid based on the current grid.
** Parameters: None.
** Pre-Conditions: The grid set-up prior to the function call.
** Post-Conditions: The updated grid after the function call. 
*********************************************************************/
void Grid::next()
{
	// Temporary grid to hold a copy of the next grid
	bool temp_grid[HEIGHT][WIDTH]; 

	// Initialize grid values to false (dead)
	for (int x=0; x<HEIGHT; x++)
	{
		for (int y=0; y<WIDTH; y++)
		{
			temp_grid[x][y] = false;
		}
	}
	
	// Determine changes to contents at grid indices		
	for (int x=1; x<(HEIGHT-1); x++) // Don't consider edge of grid as it will try to check indices outside of the array
	{
		for (int y=1; y<(WIDTH-1); y++)
		{
			int count = 0;
			if (grid[x-1][y-1])
				count++;
			if (grid[x-1][y])
				count++;
			if (grid[x-1][y+1])		
				count++;
			if (grid[x][y-1])
				count++;
			if (grid[x][y+1])
				count++;
			if (grid[x+1][y-1])
				count++;
			if (grid[x+1][y])
				count++;
			if (grid[x+1][y+1])
				count++;

			// Determine if a cell is live or dead based on its count value
			if (count < 2 || count > 3)
				temp_grid[x][y] = false;
			else if (count == 2 && grid[x][y])
				temp_grid[x][y] = true;
			else if (count == 3)
				temp_grid[x][y] = true;
		}
	}
	
	// Replace the values in the grid with the values from the temp grid		
	for (int x=0; x<HEIGHT; x++)
	{
		for (int y=0; y<WIDTH; y++)
		{
			grid[x][y] = temp_grid[x][y];
		}
	}
}

/*********************************************************************
**                    Grid::next Function
** Description: This function prints the visibile portion of the grid to 
** the screen when called. It assigns live cells as '*' and dead cells as ' '.
** Parameters: None.
** Pre-Conditions: Instantiated grid object to call the function.
** Post-Conditions: None.
*********************************************************************/
void Grid::print()
{
	for (int x=OFFSET; x<(HEIGHT-OFFSET); x++)
	{
		for (int y=OFFSET; y<(WIDTH-OFFSET); y++)
		{
			if (grid[x][y] == true)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

/*********************************************************************
**                    Grid::clear Function
** Description: This function resets a grid object to the default values of false.
** Parameters: None.
** Pre-Conditions: Instantiated grid object to call the function.
** Post-Conditions: Cells of a grid are all set to false after the funciton call.
*********************************************************************/
void Grid::clear()
{
	for (int x=0; x<HEIGHT; x++)
	{
		for (int y=0; y<WIDTH; y++)
		{
			grid[x][y] = false;
		}
	}
}
