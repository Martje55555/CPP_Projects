#include<iostream>
#include<iomanip>
#include<string>

void drawBoard(char board[][3]);
char checkWinner3by3(char board[][3]);
int counter = 0;

int main() {
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char player = 'X';
    char winner = ' ';
    int row;
    int column;
    bool is_move;
    bool is_row;
    bool is_column;

    std::cout<<"************ TIC TAC TOE ************\n";

    while(winner == ' ') {
		//set the boolean variables back to false for a new turn.
        is_move = false; 
        is_row = false;
        is_column = false;
		
        drawBoard(board);
        std::cout << "Counter: " << counter << std::endl;
				
        std::cout << "Player ";
        if(player == 'X') {
            std::cout << 1;
        }
        else {
            std::cout << 2;
        }
        std::cout << "'s turn:" << std::endl;

        while(!is_move) {
            while(!is_row) {
                std::cout << "Row: ";
                std::cin >> row;
                if(row == 1 || row == 2 || row == 3) {
                    is_row = true;
                }
                else {
                    std::cout << std::endl << "Invalid row!" << std::endl;
                }
            }

            while(!is_column) {
                std::cout << "Column: ";
                std::cin >> column;
                if(column == 1 || column == 2 || column == 3) {
                    is_column = true;
                }
                else {
                    std::cout << std::endl << "Invalid column!" << std::endl;
                }
            }
			
            if(board[row-1][column-1] == ' ')
            {
                board[row-1][column-1] = player;
                is_move = true;
                
                // Switch to the other player
                if(player == 'X') {
                    player = 'O';
                }
                else {
                    player = 'X';
                }
            }
            else
            {
                std::cout<<"The selected space is occupied!" << std::endl;
                std::cout << "Select a different space:" << std::endl << std::endl;
                drawBoard(board);
            }
        }
        
        std::cout << std::endl;
        
        winner = checkWinner3by3(board);
		
        if(winner == 'X' || winner == 'O')
        {
            drawBoard(board);
            std::cout<<"Congratulations! Player ";
            if(winner == 'X')
                std::cout << 1;
            else
                std::cout << 2;
            std::cout<<" is the winner!"<<std::endl;
        }
        else if(winner == 'T')
        {
            drawBoard(board);
            std::cout << "It's a tie!" << std::endl;
        }
        
    }
	std::cout << std::endl;
    system("pause");
    return 0;
}

void drawBoard(char board[][3]) {
	counter++;
	int i;
	int j;

	std::cout << std::setw(5) << "1" << std::setw(4) << "2" << std::setw(4) << "3";
	std::string row = "  +---+---+---+";
	std::cout << std::endl;
	std::cout << row << std::endl;

	for (j = 0; j <= 2; j++) {
		std::cout << j + 1 << " |";
		for (i = 0; i <= 2; i++) {
		    std::cout << " " << board[j][i] << " |";
		}
		std::cout << std::endl;
		std::cout << row  << std::endl;
	}
}

char checkWinner3by3(char board[][3]) {
	char user = ' ';

	//Check all rows
	for (int a = 0; a <= 2; a++) {
		if (board[a][0] == 'X' && board[a][1] == 'X' && board[a][2] == 'X') {
			user = 'X';
		}
		else if (board[a][0] == 'O' && board[a][1] == 'O' && board[a][2] == 'O') {
			user = 'O';
		}
	}
    //check all columns 
    for (int m = 0; m <= 2; m++) {
        if (board[0][m] == 'X' && board[1][m] == 'X' && board[2][m] == 'X') {
            user = 'X';
        }
        else if (board[0][m] == 'O' && board[1][m] == 'O' && board[2][m] == 'O') {
            user = 'O';
        }
    }

	//Check diagional from upper left to lower right
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		user = 'X';
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		user = 'O';
	}

	//Check diagional from upper right to lower left

	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
		user = 'X';
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		user = 'O';
	}

	//Otherwise, if all spaces are filled, the game is a tie
	if (counter == 9 && user != 'O' && user != 'X') {
		user = 'T';
    }

	//If none of the conditions above are true, return a blank space
	return user;
};
