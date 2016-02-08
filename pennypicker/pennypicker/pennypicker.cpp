// pennypicker.cpp
// Author: Matthew Tinn
// Date: 08/02/2016
// A direct transfer of one of my old university projects
// Originally written on 17/12/2011

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Ouput the Number of Pennies left in the bag
void numPenniesLeft(int numOfPenniesLeft)
{
	cout << "\nThe number of pennies left in the bag is: " << endl;

	for (int numPennyCount = numOfPenniesLeft; numPennyCount <= numOfPenniesLeft && numPennyCount > 0; numPennyCount--)
	{
		// Ouput a series of O characters to make an ASCII art like display of the penny bag
		cout << "O";
	}

	cout << "\n" << numOfPenniesLeft << endl;
}

// Player removes pennies from the bag
int playerRemovePennies(int &numPennies)
{
	int penniesTakenOut = 0;
	bool inputAccepted = false;

	while (!inputAccepted)
	{
		cout << "\nIt's the player's turn." << endl;
		cout << "Enter how many pennies to take out:    ";
		cin >> penniesTakenOut;

		if (penniesTakenOut >= 1 && penniesTakenOut <= 5) 
		{
			//Player can take out 1 - 5 pennies at a time
			// For each less than 5, only accept input if the number of pennies that 
			// the player wants to take out is less than or equal to the number of pennies left
			if (numPennies > 4)
			{
				inputAccepted = true;
			}
			else
			{
				if (numPennies == 4)
				{
					if (penniesTakenOut <= 4) // There can't be negative pennies
					{
						inputAccepted = true;
					}
				}
				else if (numPennies == 3)
				{
					if (penniesTakenOut <= 3)
					{
						inputAccepted = true;
					}
				}
				else if (numPennies == 2)
				{
					if (penniesTakenOut <= 2)
					{
						inputAccepted = true;
					}
				}
				else if (numPennies == 1)
				{
					if (penniesTakenOut <= 1)
					{
						inputAccepted = true;
					}
				}
			}

			if (inputAccepted)
			{
				numPennies = numPennies - penniesTakenOut;
			}
			else
			{
				cout << "You have tried to take out more pennies than you have left." << endl;
			}
		}
		else
		{
			cout << "Invalid input. Enter a number from 1 to 5." << endl;
		}
	}

	numPenniesLeft(numPennies);

	return numPennies;
}

// Computer player removes pennies from the bag
int comRemovePennies(int &comNumPennies)
{
	int comPenniesTakenOut = 0;

	if (comNumPennies >= 7)
	{ // If the number of pennies the computer has is >= 7, randomly take out between 1 to 5 pennies
		srand((unsigned)time(0));
		comPenniesTakenOut = (rand() % 5) + 1; 
	}
	else if (comNumPennies == 6) // When less than 7 coins remain always take out enough to leave player with last coin
	{
		comPenniesTakenOut = 5;
	}
	else if (comNumPennies == 5)
	{
		comPenniesTakenOut = 4;
	}
	else if (comNumPennies == 4)
	{
		comPenniesTakenOut = 3;
	}
	else if (comNumPennies == 3)
	{
		comPenniesTakenOut = 2;
	}
	else if (comNumPennies == 2 || comNumPennies == 1)
	{
		comPenniesTakenOut = 1;
	}

	comNumPennies = comNumPennies - comPenniesTakenOut;
	
	numPenniesLeft(comNumPennies);

	return comNumPennies;
}


// Main Game Loop
void main()
{
	int numberOfPennies = 25; // Number of pennies in the bag
	int playerTimesWon = 0; // How many times has the player won?
	int comTimesWon = 0; // How many times has the computer won?
	int numberOfGames = 1; // What game number are we on?
	char playerTurn = ' '; // Whose turn is it?
	char exitChar = ' '; // Used for waiting for player input for exit
	
	cout << "PENNY PICKER" << endl;
	cout << "Be the player not to grab the last coin." << endl;
	cout << "When prompted enter a number between 1 and 5 to remove that number of coins." << endl;

	while (numberOfGames <= 5)
	{
		numberOfPennies = 25;

		cout << "\nCurrent Score:" << endl;
		cout << "Player - " << playerTimesWon << endl;
		cout << "Computer - " << comTimesWon << endl;
		cout << "\nStarting game " << numberOfGames << "..." << endl;

		while (numberOfPennies > 0)
		{
			playerTurn = 'p';

			if (playerTurn == 'p')
			{
				playerRemovePennies(numberOfPennies);
			}
			
			if (numberOfPennies > 0)
			{
				playerTurn = 'c';
			}

			if (playerTurn = 'c')
			{
				cout << "\nIt's the computer's turn." << endl;
				cout << "The computer chooses how many pennies to withdraw." << endl;
				comRemovePennies(numberOfPennies);
			}
		}

		if (playerTurn == 'p')
		{
			cout << "You lose..." << endl;
			comTimesWon++;
		}
		else
		{
			cout << "You won!" << endl;
			playerTimesWon++;
		}

		numberOfGames++;
	}

	cout << "\nGAME, SET AND MATCH!" << endl;
	cout << "\nPlayer won " << playerTimesWon << " games." << endl;
	cout << "Computer won " << comTimesWon << " games." << endl;

	if (playerTimesWon > comTimesWon)
	{
		cout << "You beat the computer by " << (playerTimesWon = comTimesWon) << " games." << endl;
	}
	else
	{
		cout << "The computer beat you by " << (comTimesWon - playerTimesWon) << " games." << endl;
	}

	cout << "That's the end of the game. Press any key and enter to exit.    ";
	cin >> exitChar;
}