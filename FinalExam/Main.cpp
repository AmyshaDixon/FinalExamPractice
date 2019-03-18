/* Authors: Amy Dixon, Ken Meerdink
* Date: 02.15.2019
* Purpose: This program in Main.cpp simulates a deck of 52 
*				 playing cards that allows a user to display and/or
*				 shuffle the desk.
*/

#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

// Constants
const int DECK_SIZE = 52;
const array<string, DECK_SIZE> cards {
         "AH", "AC", "AD", "AS",
	     "2H", "2C", "2D", "2S",
	     "3H", "3C", "3D", "3S",
	     "4H", "4C", "4D", "4S",
	     "5H", "5C", "5D", "5S",
	     "6H", "6C", "6D", "6S",
	     "7H", "7C", "7D", "7S",
	     "8H", "8C", "8D", "8S",
	     "9H", "9C", "9D", "9S",
	     "10H", "10C", "10D", "10S",
         "JH", "JC", "JD", "JS",
         "QH", "QC", "QD", "QS",
         "KH", "KC", "KD", "KS", };

// Properties
void initializeDeck(array<const string *, DECK_SIZE> * deck);
void displayDeck(array<const string *, DECK_SIZE> deck);
void shuffleDeck(array<const string *, DECK_SIZE> * deck);
void printMenu();

int main() {
	// Variables
	int userChoice = -1;
	array<const string *, DECK_SIZE> deck;

	// Create deck
	initializeDeck(&deck);

	// Display menu options
	while (userChoice != 0) {
		printMenu();
		cin >> userChoice;
		if (userChoice == 1) {
			displayDeck(deck);
		}
		else if (userChoice == 2) {
			shuffleDeck(&deck);
		}
	}

	// Keep window open
	system("pause");

	// Exit
	return EXIT_SUCCESS;
}

void initializeDeck(array<const string *, DECK_SIZE> * deck) {
	for (size_t i = 0; i < DECK_SIZE; ++i) {
		(*deck)[i] = &cards[i];
	}
}

void printMenu() {
	cout << "0 - Quit" << endl;
	cout << "1 - Display deck" << endl;
	cout << "2 - Shuffle deck" << endl;
}

void displayDeck(array<const string *, DECK_SIZE> deck) {
	for (size_t i = 0; i < DECK_SIZE; ++i) {
		if ((*deck[i]).size() <= 2) { // Makes spacing a little better
			cout << *deck[i] << "  "; // Addes two spaces after
		}
		else {
			cout << *deck[i] << " "; // Adds one space after
		}

		if (i != 0 && i % 13 == 0) { // Display in rows
			cout << endl;
		}
	}

	cout << endl << endl;
}

void shuffleDeck(array<const string *, DECK_SIZE> * deck) {
	// Variables
	int j;

	// Create random object
	static default_random_engine engine(static_cast<unsigned int>(time(0)));

	// Shuffle
	for (size_t i = DECK_SIZE - 1; i >= 1; --i) {
		// Create random range	
		uniform_int_distribution<unsigned int> randomInt(0, i);

		j = randomInt(engine); 

		swap((*deck)[i], (*deck)[j]);
	}

	cout << "Shuffled" << endl << endl;
}