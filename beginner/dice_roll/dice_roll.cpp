/*********************************************************************
* Dice Roll Simulator                                                *
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

void greeting(int pnum) {
	if(pnum == 1)
		std::cout << "Please press \"ENTER\" to roll the die.";
	else
		std::cout << "Please press \"ENTER\" again to roll the second die.";
	std::cin.ignore();
}

int rollDie(void) {
	int ran;
	srand(time(NULL));
	ran = rand()%6+1;
	std::cout << "You rolled a " << ran
		<< "." << std::endl;
	return ran;
}

int diceTotal(int firstDie, int secondDie) {
    std::cout << "Your total so far is: "
		<< secondDie + firstDie << std::endl;
    return secondDie + firstDie;
}

int results(int total) {
	if (total == 7 || total == 11) {
		std::cout << "You won! Congratulations!";
		return 0;
	}
	else if (total == 2 || total == 3 || total == 12) {
		std::cout << "You lose. Try again.";
        return 0;
   	}
	else {
		std::cout << "You may continue to roll."
			<< std::endl << std::endl;
		return 1;
	}
}

int main(void) {
	int counter, total, secondDie, firstDie;
	char secondstart;

	do {
		greeting(1);
   		firstDie = rollDie();
   		greeting(2);
	   	secondDie = rollDie();
	   	total = diceTotal(firstDie, secondDie);
	} while(results(total)!=0);
	
	std::cin.ignore();
	return 0;
}