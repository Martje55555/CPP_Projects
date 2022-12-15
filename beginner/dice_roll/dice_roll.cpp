#include <iostream>
#include <ctime>
#include <cstdlib>

//The following function outputs a basic greeting to the user
void greeting(int pnum) {
	if(pnum == 1) {
		std::cout << "Please press \"ENTER\" to roll the die.";
	} else {
		std::cout << "Please press \"ENTER\" again to roll the second die.";
	}
	std::cin.ignore();
}

//The following function simulates a die roll
int dieroll(void) {
	int ran;
	srand(time(NULL));
	ran = rand()%6+1;
	std::cout << "You rolled a " << ran << "." << std::endl;
	return ran;
}

//The following adds the 1st and 2nd roll together
int dice(int firstDie, int secondDie) {
    std::cout << "Your total so far is: " << secondDie + firstDie << std::endl;
    return secondDie + firstDie;
}

// Checks if player won / lost / can keep rolling.
int results(int total) {
	if (total == 7 || total == 11) {
		std::cout << "You won! Congratulations!";
		return 0;
	} else if (total == 2 || total == 3 || total == 12) {
                std::cout << "You lose. Try again.";
                return 0;
   	} else {
		std::cout << "You may continue to roll." << std::endl << std::endl;
		return 1;
	}
}

// Main Funtion
int main(void) {
	int counter, total, seconddie, firstdie;
	char secondstart;
	
	do {
		greeting(1);
   		firstdie = dieroll();
   		greeting(2);
	   	seconddie = dieroll();
	   	total = dice(firstdie, seconddie);
	} while(results(total)!=0);
	
	std::cin.ignore();
	return 0;
}