#include<iostream>
#include<time.h>

//Prototype
int randNumGen(int upper, int lower);

int main() {
// Declares variable number to hold a random (whole) number
	int number;
// Declares variable guess to hold the (whole) number guessed by the user
	int guess;

// Declares variable correct that holds boolean values and initialize it to false
	bool correct;
	

// Declares variable numGuesses to hold the (whole) number used to keep track of the
// number of guesses made by the user and initialize it to zero
	int numGuesses = 0;

// Seeds the random generator
	srand(static_cast<int>(time(NULL)));
// Calls function randNumGen() to generate a random number between 1 and 100 and
// assign the value returned to number
	number = randNumGen(100, 1);
// Uses a COUNTER-CONTROLLED combined with a FLAG-CONTROLLED LOOP to let the user guess a
// number until her/him guesses it correctly or uses the five chances allowed to guess
// the number generated above
// As the user provides a guess the program indicates whether the guess was correct or
// if it was too low or too high to help her/him. If the user runs out of guesses it shows
// her/him the correct number
	correct = false;
	while (correct, numGuesses < 5) {
		std::cout << "Guess the number the computer randomly picked between 1 - 100: ";
		std::cin >> guess;

		if (guess == number) {
			numGuesses = 5;
			std::cout << "You guessed right, you win!" << std::endl << std::endl;
			
			correct = true;
			continue;
		}
		else if (guess > number) {
			std::cout << "Sorry, your guess is too high" << std::endl << std::endl;
		}
		else if (guess < number) {
			std::cout << "Sorry, your guess is too low" << std::endl << std::endl;
			
		}
		if (numGuesses == 4) {
			std::cout << "Sorry you lost. The number is: " << number << std::endl;
			correct = true;
		}
		++numGuesses;
	}

	system("pause");
    return 0;
}

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using the expression:

int randNumGen(int upper, int lower) {
	return rand() % (upper - lower + 1) + lower;
}