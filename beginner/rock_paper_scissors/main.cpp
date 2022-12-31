/*********************************************************************
* Rock Paper Scissors                                                *
*********************************************************************/
#include <iostream>
#include <time.h>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

char getComputerOption() {
    // seed the random number generator
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if(num==1) return 'r';
    if(num==2) return 'p';
    if(num==3) return 's';
    return 'r';
}

char getUserOption() {
    char c;
    std::cout << "Rock, Paper and Scissors Game!" << std::endl;
    std::cout << "Choose one of the following options"  << std::endl;
    std::cout << "-----------------------------------"  << std::endl;
    std::cout << "(r) for rock " << std::endl << "(p) for paper" << std::endl << "(s) for scissors " << std::endl;
    std::cin >> c;
    
    while (c!='r' && c!='p' && c!='s') {
        std::cout << "Please enter one of the following options only. " << std::endl;
        std::cout << "(r) for rock " << std::endl << "(p) for paper" << std::endl << "(s) for scissors " << std::endl;
        std::cin >> c;
    }

    return c;
}

void showSelectedOption(char option) {
    if (option == 'r')
        std::cout << "Rock" << std::endl;
    if (option == 'p')
        std::cout << "Paper" << std::endl;
    if (option == 's')
        std::cout << "Scissors" << std::endl;
}

void chooseWinner(char userChoice, char compChoice) {
    if (userChoice == ROCK && compChoice == PAPER)
        std::cout << "Computer Wins! Paper wraps Rock."<< std::endl;
    else if (userChoice == PAPER && compChoice == SCISSORS)
        std::cout << "Computer Wins! Scissors cut Paper."<< std::endl;
    else if (userChoice == SCISSORS && compChoice == ROCK)
        std::cout << "Computer Wins! Rock smashes Scissors."<< std::endl;
    else if (userChoice == ROCK && compChoice == SCISSORS)
        std::cout << "You Win! Rock smashes Scissors."<< std::endl;
    else if (userChoice == PAPER && compChoice == ROCK)
        std::cout << "You Win! Paper wraps Rock."<< std::endl;
    else if (userChoice == SCISSORS && compChoice == PAPER)
        std::cout << "You Win! Scissors cut Paper."<< std::endl;
    else
        std::cout << "Tie. Play again win the Game." << std::endl;
}

int main() {
    char userChoice, compChoice; 
    userChoice = getUserOption();
    std::cout << "Your choice is: "<< std::endl;
    showSelectedOption(userChoice);
    
    std::cout << "Computer's choice is: "<< std::endl;
    compChoice = getComputerOption();
    showSelectedOption(compChoice);
    std::system("cls");
    chooseWinner(userChoice, compChoice);

    return 0;
}