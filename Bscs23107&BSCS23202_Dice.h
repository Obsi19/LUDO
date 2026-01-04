#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;



class Dice {
public:
	// Constructor
	Dice() {
		// Seed the random number generator
		srand(time(0));
	}

	// Roll the dice and return the result
	int roll() {
		// Generate a random number between 1 and 6 (inclusive)
		return (rand() % 6) + 1;
	}

	// Display the result of the dice roll
	void displayResult(int result) {
		for (int i = 0; i < 80; i++)
			cout << " "; 
		std::cout << "You rolled: " << endl;
	

		if (result == 1)
		{
			for (int i = 0; i < 80; i++)
				cout << " ";
			cout << " |       |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " ";
			cout << " |   *   |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " ";
			cout << " |       |" << endl;
		}

		else if (result == 2)
		{
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |     * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |       |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *     |" << endl;
		}

		else if (result == 3)
		{
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |     * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |   *   |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *     |" << endl;
		}

		else if (result == 4)
		{
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |       |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
		}

		else if (result == 5)
		{
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " |   *   |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
		}

		else if (result == 6)
		{
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
			for (int i = 0; i < 80; i++)
				cout << " "; cout << " | *   * |" << endl;
		}
	}
};

	

