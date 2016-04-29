/*********************************************************************
** Author: Elizabeth Poore
** Date: April 6, 2015
** Description: This program implements Conway's Game of Life. There is 
** a matrix of cells where each generation determines the next based 
** upon how many neighboring cells a cell has in it's current state.
*********************************************************************/
#include "Point.hpp"
#include "Grid.hpp"
#include <iostream>

void menu(); // Function prototypes 
bool run();
Point getCoord();

int main()
{
	Grid grid; // Create an object of class Grid

	std::cout << "\n\nWelcome to Conway's Game of Life!" << std::endl;
	std::cout << "This 'game' is an example of cellular automaton." << std::endl;
	std::cout << "The world is represented as a grid of cells, " << std::endl;
	std::cout << "live cells are represented with a '*' and dead ' '." << std::endl;
	std::cout << "Every cell has eight neighbors. The neighbors are the cells " << std::endl;
	std::cout << "directly above, below, left, right, diagonally above on the" << std::endl;
	std::cout << "left and right as well as diagonally below on the left and right.\n" << std::endl;
	std::cout << "The rules are: " << std::endl;
	std::cout << "1. If a live cell has 0 or 1 neighbors, it dies of loneliness." << std::endl;
	std::cout << "2. If a live cell has more than 3 neighbors, it dies of overcrowding." << std::endl;
	std::cout << "3. If an empty cell has exactly three occupied neighbor cells, there" << std::endl;
	std::cout << "is a birth of a new cell to replace the empty cell." << std::endl; 
	std::cout << "4. Births and deaths are instantaneous and occur at the changes of generation.\n\n" << std::endl;

	int selection; // Value to hold user input selection
	
	do
	{
		menu(); // Function prints menu to screen
		std::cin >> selection; // Get user selection

		while (selection <1 || selection >5) // If selection isn't valid, prompt user to input a new selection
		{
			std::cout << "Selection is out of range. Please make a valid selection." << std::endl;
			std::cin >> selection;
		}	

		if (selection == 1) // Selection for simple fixed oscillator
		{
			Point point = getCoord(); // Declare and instantiate Point object
			grid.fixed(point); // Pass point to fixed function of Grid class
			grid.print(); // Prints initial grid formation
			while(run()) // Run simulation until the user quits
			{
				grid.next();
				grid.print();
			}
			grid.clear(); // Clear grid for next potential simulation
		}
		if (selection == 2) // Selection for glider
		{
			Point point = getCoord();
			grid.glider(point);
			grid.print();
			while(run())
			{
				grid.next();
				grid.print();
			}
			grid.clear();
		}
		if (selection == 3) // Selection for glider gun
		{
			grid.gliderGun();
			grid.print();
			while(run())
			{
				grid.next();
				grid.print();
			}
			grid.clear();
		}
		if (selection == 4) // Selection allows user to manually enter coordinates
		{
			char selection;
			do
			{
				int x, y;
				std::cout << "Enter the x coordinate: " << std::endl;
				std::cin >> x;
				std::cout << "Enter the y coordinate: " << std::endl;
				std::cin >> y;
				grid.userDefined(x, y);
				std::cout << "Press 'y' to stop enter another set of coordinates or press any other key to continue." << std::endl;
				std::cin >> selection;
			} while (selection == 'y');
			
			grid.print();
			while(run())
			{
				grid.next();
				grid.print();
			}	
			grid.clear();
		}

	} while (selection != 5);


	return 0;
}

/*********************************************************************
**                     menu Function
** Description: This function prints to the screen a menu for the user to
** be able to read and make a selction from.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: None.
*********************************************************************/
void menu()
{
	std::cout << "Please make a selection from the following menu: " << std::endl;
	std::cout << "1. View a fixed simple oscillator." << std::endl;
	std::cout << "2. View a glider." << std::endl;
	std::cout << "3. View a glider gun" << std::endl;
	std::cout << "4. Manually input coordinates." << std::endl;
	std::cout << "5. Exit program." << std::endl;
}

/*********************************************************************
**                     getCoord Function
** Description: This function gets an input coordinate from the user, returning
** an object of the Point class.
** Parameters: Input none, the function returns a Point object.
** Pre-Conditions: None.
** Post-Conditions: Input values within the function must allow a value 
** of type Point to be returned. 
*********************************************************************/
Point getCoord()
{
	int x, y;
	std::cout << "Enter the coordinates for the starting point (top-left = (0, 0))" << std::endl;
	std::cout << "Enter the x coordinate in the range of 0-39: " << std::endl;
	std::cin >> x;
	
	while (x <0 || x >39) // If selection isn't valid, prompt user to input a new selection
	{
		std::cout << "Selection is out of range. Please make a valid selection." << std::endl;
		std::cin >> x;
	}	
	
	std::cout << "Enter the y coordinate in the range of 0-19: " << std::endl;
	std::cin >> y;
	while (y <0 || y >19) // If selection isn't valid, prompt user to input a new selection
	{
		std::cout << "Selection is out of range. Please make a valid selection." << std::endl;
		std::cin >> y;
	}	
	
	Point point(x, y);
	return point;
}

/*********************************************************************
**                     run Function
** Description: This is a simple bool function which keeps the simulation
** going until the user wants to end it. 
** Parameters: Input none, the function returns a bool.
** Pre-Conditions: None.
** Post-Conditions: None.
*********************************************************************/
bool run()
{
	std::cout << "Generations will change by pressing 'c' followed by enter to continue." << std::endl;
	std::cout << "Pressing another character followed by enter will end the simulation." << std::endl;
	
	char selection;
	std::cin >> selection;

	while (selection == 'c')
	{
		return true;
	}

	return false;
}


