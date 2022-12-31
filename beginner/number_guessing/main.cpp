/*********************************************************************
* Number Guessing                                                    *
*********************************************************************/
#include<iostream>
#include<time.h>

int randNumGen(int upper, int lower);

int main() {
	// Seeds the random generator
	srand(static_cast<int>(time(NULL)));

	int guess;
	int numGuesses = 0;
	int number = randNumGen(100, 1);
	int correct = false;

	while (correct, numGuesses < 5) {
		std::cout << "Guess the number the computer randomly picked between 1 - 100: ";
		std::cin >> guess;

		if (guess == number) {
			numGuesses = 5;
			std::cout << "You guessed right, you win!" << std::endl << std::endl;
			
			correct = true;
			continue;
		}
		else if (guess > number)
			std::cout << "Sorry, your guess is too high" << std::endl << std::endl;
		else if (guess < number)
			std::cout << "Sorry, your guess is too low" << std::endl << std::endl;

		if (numGuesses == 4) {
			std::cout << "Sorry you lost. The number is: " << number << std::endl;
			correct = true;
		}
		++numGuesses;
	}

	system("pause");
    return 0;
}

int randNumGen(int upper, int lower) {
	return rand() % (upper - lower + 1) + lower;
}