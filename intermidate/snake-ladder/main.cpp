/*********************************************************************
* Snakes and Ladder                                                  *
*********************************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void drawLine(int n, char ch);
void board();
void gameScore(char name1[], char name2[], int p1, int p2);
void playDice(int & score);
int randNumGen(int upper, int lower);

void main() {
    int player1 = 0, player2 = 0, lastPos;
    char player1Name[80], player2Name[80];
    system("cls");
    
    drawLine(50, '=');
    std::cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
    drawLine(50, '=');
    std::cout << "\n\n\nEnter Name of player 1: ";
    std::cin >> player1Name;
    std::cout << "\n\n\nEnter Name of player 2: ";
    std::cin >> player2Name;
    while (player1 <= 100 && player2 <= 100) {
        board();
        gameScore(player1Name, player2Name, player1, player2);
        std::cout << "\n\n--->" << player1Name << " Now your Turn >> Press any key to play ";
        getch();
        lastPos = player1;
        playDice(player1);
        if (player1 < lastPos)
            std::cout << "\n\aOops!! Snake found !! You are at postion " << player1 << "\n";
        else if (player1 > lastPos + 6) {
            std::cout << "\nGreat!! you got a ladder !! You are at position " << player1;
            std::cout << "\n\n--->" << player2Name << " Now your Turn >> Press any key to play ";
        }

        std::cout << "\n\n--->" << player2Name << " Now your Turn >> Press any key to play ";
        getch();
        lastPos = player2;
        playDice(player2);

        if (player2 < lastPos)
            std::cout << "\n\n\aOops!! Snake found !! You are at position " << player2 << "\n";
        else if (player2 > lastPos + 6)
            std::cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
        getch();
    }

    system("cls");
    std::cout << "\n\n\n";
    drawLine(50, '+');
    std::cout << "\n\n\t\tRESULT\n\n";
    drawLine(50, '+');
    std::cout << std::endl;
    gameScore(player1Name, player2Name, player1, player2);
    std::cout << "\n\n\n";

    if (player1 >= player2)
        std::cout << player1Name << " !! You are the winner of the game\n\n";
    else
        std::cout << player2Name << " !! You are the winner of the game\n\n";
    drawLine(50, '+');
    getch();
}

void drawLine(int n, char ch) {
    for (int i = 0; i < n; i++)
        std::cout << ch;
}

void board() {
    system("cls");
    std::cout << "\n\n";
    drawLine(50, '-');
    std::cout << "\n\t\tSNAKE AT POSITION\n";
    drawLine(50, '-');
    std::cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
    drawLine(50, '-');
    std::cout << "\n\t\t LADDER AT POSITION\n";
    drawLine(50, '-');
    std::cout << "\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    drawLine(50, '-');
    std::cout << std::endl;
}

void gameScore(char name1[], char name2[], int p1, int p2) {
    std::cout << "\n";
    drawLine(50, '~');
    std::cout << "\n\t\tGAME STATUS\n";
    drawLine(50, '~');
    std::cout << "\n\t--->" << name1 << " is at position " << p1 << std::endl;
    std::cout << "\t--->" << name2 << " is at position " << p2 << std::endl;
    drawLine(50, '_');
    std::cout << std::endl;
}

void playDice(int & score) {
    // seed random number generator
	srand(static_cast<int>(time(NULL)));
    int dice = randNumGen(6, 1);
    std::cout << "\nYou got " << dice << " Point !! ";
    score = score + dice;
    std::cout << "Now you are at position " << score;
    switch (score) 
	{
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 54:
        score = 93;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
    }
}

int randNumGen(int upper, int lower) {
	return rand() % (upper - lower + 1) + lower;
}