#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void drawBoard(char board[][3]);
char checkWinner3by3(char board[][3]);
int counter = 0;

int main()
{
    // This array of chars represents the game board, and it holds the content
    // of each space. By default all spaces are set to a blank space.
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    
    // The current player. Because X plays first, initialize to X
    char player = 'X';
	
    // The winner. either 'X', 'O', or 't' if it's a tie.
    // Or a blank space if the game has not finished.
    char winner = ' ';
	
    // These variables will hold the number of the row and column selected
    // by the players.
    int row;
    int column;
	
    // boolean variables used to verify if the move is valid.
    bool is_move;
    bool is_row;
    bool is_column;

    cout<<"************ TIC TAC TOE ************\n";

    // The game loops again and again until the game is over
    while(winner == ' ')
    {
		//set the boolean variables back to false for a new turn.
        is_move = false; 
        is_row = false;
        is_column = false;
		
        //draw the board.
        drawBoard(board);
				
        // If the game is not yet over show who`s the next player to move
        cout << "Player ";
        if(player == 'X')
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }
        cout << "'s turn:" << endl;

        // Loop until the player selects a valid space for their move
        is_move = false;
        while(!is_move)
        {  
            // Loop until the player selects a valid row
            // Assume the user inputs a valid integer
            is_row = false;
            while(!is_row)
            {
                cout << "Row: ";
                cin >> row;
                if(row == 1 || row == 2 || row == 3)
                {
                    is_row = true;
                }
                else
                {
                    cout << endl << "Invalid row!" << endl;
                }
            } // end of input row loop
            
            // Loop until the player selects a valid column
            // Assume the user inputs a valid integer
            is_column = false;
            while(!is_column)
            {
                cout << "Column: ";
                cin >> column;
                if(column == 1 || column == 2 || column == 3)
                {
                    is_column = true;
                }
                else
                {
                    cout << endl << "Invalid column!" << endl;
                }
            } // end of input column loop
			
            // If the space is empty, mark the chosen space and swich players
            if(board[row-1][column-1] == ' ')
            {
                // Mark the space and end the player's turn
                board[row-1][column-1] = player;
                is_move = true;
                
                // Switch to the other player
                if(player == 'X')
                {
                    player = 'O';
                }
                else
                {
                    player = 'X';
                }
            } // end of marking space and changing players
            
            // If the space is occupied
            else
            {
                cout<<"The selected space is occupied!" << endl;
                cout << "Select a different space:" << endl << endl;
                drawBoard(board);
            }
        } // end of player's move loop
        
        cout << endl; // for nice output formatting
        
        //check if the player won.
        winner = checkWinner3by3(board);
		
        //If there's a winner
        if(winner == 'X' || winner == 'O')
        {
            drawBoard(board);
            
            //Display congratulations message
            cout<<"Congratulations! Player ";
            if(winner == 'X')
            {
                cout << 1;
            }
            else
            {
                cout << 2;
            }
            cout<<" is the winner!"<<endl;
        }
        else if(winner == 'T')
        {
            drawBoard(board);
            
            //Display a message if it`s tie
            cout << "It's a tie!" << endl;
        }
        
    } // End of player's turn loop
	cout << endl;
    system("pause");
    return 0;
}

// Prints the game board
// We know the board is 3 by 3 so we don't need to have the number of rows as
// a parameter.
void drawBoard(char board[][3]) {
	counter++;
	
	int i;
	int j;

	//Draw the top line of the board
	cout << setw(5) << "1" << setw(4) << "2" << setw(4) << "3";
	string row = "  +---+---+---+";
    //Draw the rows of the board and the lines under the rows(MUST use a loop)
	cout << endl;
	cout << row << endl;

	for (j = 0; j <= 2; j++) {
		cout << j + 1 << " |";
		for (i = 0; i <= 2; i++)
		{
		cout << " " << board[j][i] << " |";
		}
		cout << endl;
		cout << row  << endl;
	}
}

// Checks the whole board if there is a winner.
// We know the board is 3 by 3 so we don't need to have the number of rows as
// a parameter.

char checkWinner3by3(char board[][3]) {
	char user = ' ';

	//Check all rows (MUST use a loop)
	for (int a = 0; a <= 2; a++) {
		if (board[a][0] == 'X' && board[a][1] == 'X' && board[a][2] == 'X') {
			user = 'X';
		}
		else if (board[a][0] == 'O' && board[a][1] == 'O' && board[a][2] == 'O') {
			user = 'O';
		}
		else {
			//check all columns 
			for (int m = 0; m <= 2; m++) {
				if (board[0][m] == 'X' && board[1][m] == 'X' && board[2][m] == 'X') {
					user = 'X';
				}
				else if (board[0][m] == 'O' && board[1][m] == 'O' && board[2][m] == 'O') {
					user = 'O';
				}
			}
		}
	}

	//Check diagional from upper left to lower right
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'O') {
		user = 'X';
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		user = 'O';
	}

	//Check diagional from upper right to lower left

	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
		user = 'X';
	}
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		user = 'O';
	}

	//Otherwise, if all spaces are filled, the game is a tie
	if (counter == 9 && user != 'O' && user != 'X') {
		user = 'T';
    }

	//If none of the conditions above are true, return a blank space
	return user;
};
