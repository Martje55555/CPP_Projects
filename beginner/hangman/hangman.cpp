/*********************************************************************
* Hangman                                                            *
*********************************************************************/
#include <stdlib.h> // for random
#include <time.h>  // for seeding
#include <iostream>
#include <vector>  // to hold the wordbank
#include <algorithm> // for find
#include <string>

int randNumGen(int upper, int lower);

int main() {
    std::string wordBank[4] { "hello", "world", "python", "ruby" };

    // seed the random generator
    srand(static_cast<int>(time(NULL)));
    // random number from 1-4
    int num = randNumGen(4, 1);
    std::string answer = wordBank[num-1];
    std::vector<int> foundCharIndexes;
    int foundCount = 0;
    int lives = 5;
    
    while (foundCount < (answer.size()) && lives > 0) {
        std::cout << " \nYou currently have: " << lives << " lives." << std::endl;
        
        foundCount = 0;

        for (int i = 0; i < answer.length(); ++i) {
            auto exists = std::find(foundCharIndexes.begin(), foundCharIndexes.end(), i);

            if (exists != foundCharIndexes.end()) {
                std::cout << answer[i] << " ";
                foundCount++;
            }
            else
                std::cout << "_ ";
        }
        std::cout << std::endl;
        
        char userChoice = ' ';
        bool found = false;
        std::cout << "Choose a character..." << std::endl;
        std::cin >> userChoice;
    
        for (int i = 0; i < answer.length(); i++) {
            if (userChoice == answer[i]) {
                found = true;
                foundCharIndexes.push_back(i);
            }
        }
        if (found == false)
            lives--;
    }
        
    if (lives != 0)
        std::cout << "\nCongrats you found the word!\nThe word was: " << answer << std::endl;
    else {
        std::cout << "\nOh no, you failed :( !" << std::endl;
        std::cout << "\nThe word was: " << answer << std::endl;
    }
    return 0;
}

int randNumGen(int upper, int lower) {
	return rand() % (upper - lower + 1) + lower;
}