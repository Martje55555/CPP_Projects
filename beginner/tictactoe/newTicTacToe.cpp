/*********************************************************************
* Tic-Tac-Toe                                                        *
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <set>

void drawTTTBoard(char board[][3]);
char checkTTTWinner(char board[][3], char player);
int counter = 0;

int main()
{
   char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
   char player = 'X';
   bool won = false;
   std::set<int> rows = {1, 2, 3};
   std::set<int> cols = {1, 2, 3};
   int row;
   int col;
   bool is_move;
   bool is_row;
   bool is_col;

   std::cout << "************ Tic-Tac-Toe ************\n";
   while (won != true) {
       is_move = false;
       is_row = false;  
       is_col = false;

       drawTTTBoard(board);
        if (counter == 9 && won == false) {
           drawTTTBoard(board);
           std::cout << "It's a tie!" << std::endl;
           break;
       }
       std::cout << "Player " << player << "'s turn:" << std::endl;
      
       while (!is_move) {
           while (!is_row) {
               std::cout << "Row: ";
               std::cin >> row;
               auto row_is_valid = rows.find(row);
               if (row_is_valid != rows.end()) {
                   is_row = true;
               }
               else {
                   std::cout << std::endl << "Invalid row!";
                   std::cout << std::endl;
               }
           }

           while (!is_col) {
               std::cout << "Column: ";
               std::cin >> col;
               auto col_is_valid = cols.find(col);
               if (col_is_valid != cols.end()) {
                   is_col = true;
               }
               else {
                   std::cout << std::endl << "Invalid column!";
                   std::cout << std::endl;
               }
           }
         
           if (board[row-1][col-1] == ' ') {
               board[row-1][col-1] = player;
               is_move = true;
               counter++;
           }
           else {
               std::cout<<"That space is already filled!" << std::endl;
               std::cout << "Select another space:" << std::endl;
               std::cout << std::endl;
               is_row = false;
               is_col = false;
               drawTTTBoard(board);
               continue;
           }
       }
     
       std::cout << std::endl;
       won = checkTTTWinner(board, player);
       if (won == true) {
           drawTTTBoard(board);
           std::cout<<"Congratulations! Player '"
               << player << "' is the winner!"<<std::endl;
       }
       else if (counter == 9 && won == false) {
           drawTTTBoard(board);
           std::cout << "It's a tie!" << std::endl;
           break;
       }
       else {
           if (player == 'X') {
               player = 'O';
           }
           else {
               player = 'X';
           }
       }
   }

   std::cout << std::endl;
   system("pause");
   return 0;
}

void drawTTTBoard(char board[][3]) {
   int i;
   int j;
   std::cout << std::setw(5) << "1" << std::setw(4)
             << "2" << std::setw(4) << "3";
   std::string row = "  +---+---+---+";
   std::cout << std::endl;
   std::cout << row << std::endl;
   for (i = 0; i <= 2; i++) {
       std::cout << i + 1 << " |";
       for (j = 0; j <= 2; j++) {
           std::cout << " " << board[i][j] << " |";
       }
       std::cout << std::endl;
       std::cout << row  << std::endl;
   }
   std::cout << "Counter: " << counter << std::endl;
}

char checkTTTWinner(char board[][3], char player) {
   bool won = false;
  
   // Check rows
   for (int a = 0; a <= 2; a++) {
       if (board[a][0] == player &&
           board[a][1] == player && board[a][2] == player) {
               won = true;
               return won;
       }
   }

   // Check cols
   for (int m = 0; m <= 2; m++) {
       if (board[0][m] == player &&
           board[1][m] == player && board[2][m] == player) {
               won = true;
               return won;
       }
   }
  
   // Check diagonals
   if (board[0][0] == player &&
       board[1][1] == player && board[2][2] == player) {
           won = true;
           return won;
   }

   if (board[0][2] == player &&
       board[1][1] == player && board[2][0] == player) {
           won = true;
           return won;
   }

   return won;
}