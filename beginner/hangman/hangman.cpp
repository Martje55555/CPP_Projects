#include <stdlib.h> // for random
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm> // for find
#include <string>

int randNumGen(int upper, int lower);

int main() {
    // variables
    std::string wordBank[10] { "spiderman", "cheese", "simon", "word", "hello", "world", "python", "elliot", "ruby", "hangman"};
    srand(static_cast<int>(time(NULL)));
    int num = randNumGen(10, 1);
    std::string answer = wordBank[num-1];
    std::vector<int> foundCharIndexes;
    int foundCount = 0;
    int lives = 5;
    
    // game loop
    while (foundCount < (answer.size()-1) && lives > 0) {
        // output no of lives
        std::cout << " \nYou currently have: " << lives << " lives." << std::endl;
        
        foundCount = 0; // reset before searching word
        // print out current set of letters
        for (int i = 0; i < answer.length(); ++i) {
            // if the vector contrains this characters index
            if (std::find (foundCharIndexes.begin(), foundCharIndexes.end(), i) != foundCharIndexes.end()) {
                // it has been found
                std::cout << answer[i] << " "; // so print the char
                foundCount++; // and add one to the count
            }
            else {
                // it hasn't been found
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
        
        // get the users choice
        char userChoice = ' ';
        bool found = false;
        std::cout << "Choose a character..." << std::endl;
        std::cin >> userChoice;
    
        // for each character in the answer string
        for (int i = 0; i < answer.length(); i++) {
            // if the users choice is valid
            if (userChoice == answer[i]) {
                // say we found a valid choice
                found = true;
                // log its index in our vector
                foundCharIndexes.push_back(i);
            }
        }
        // alter lives if appliable
        if (found == false)
            lives--;
    }
        
    // output game concluison
    if (lives != 0)
        std::cout << "\nCongrats you found the word!" << std::endl;
    else
        std::cout << "\nOh no, you failed :( !" << std::endl;
        std::cout << "\nThe word was: " << answer << std::endl;

    return 0;
}

int randNumGen(int upper, int lower) {
	return rand() % (upper - lower + 1) + lower;
}