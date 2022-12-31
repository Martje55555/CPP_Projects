/*********************************************************************
* Flappy Bird Game                                                   *
*********************************************************************/
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int pipePos[3];
int gapPos[3];
int pipeFlag[3];
char bird[2][6] = { '/','-','-','o','\\',' ',
					'|','_','_','_',' ','>' };
int birdPos = 6;
int score = 0;

void goToCoord(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setCursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void drawBorder() { 
	
	for(int i=0; i<SCREEN_WIDTH; i++) {
		goToCoord(i,0);
		std::cout << "±";
		goToCoord(i,SCREEN_HEIGHT);
		std::cout << "±";
	}
	
	for(int i=0; i<SCREEN_HEIGHT; i++) {
		goToCoord(0,i);
		std::cout << "±";
		goToCoord(SCREEN_WIDTH,i);
		std::cout << "±";
	}
	for(int i=0; i<SCREEN_HEIGHT; i++) {
		goToCoord(WIN_WIDTH,i);
		std::cout << "±";
	}
}

void genPipe(int ind) {
	gapPos[ind] = 3 + rand()%14; 
}

void drawPipe(int ind) {
	if( pipeFlag[ind] == true ) {
		for(int i=0; i<gapPos[ind]; i++) { 
			goToCoord(WIN_WIDTH-pipePos[ind],i+1);
			std::cout << "***"; 
		}
		for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++) { 
			goToCoord(WIN_WIDTH-pipePos[ind],i+1);
			std::cout << "***"; 
		}
	} 
}
void erasePipe(int ind) {
	if( pipeFlag[ind] == true ) {
		for(int i=0; i<gapPos[ind]; i++) { 
			goToCoord(WIN_WIDTH-pipePos[ind],i+1);
			std::cout << "   "; 
		}
		for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++) { 
			goToCoord(WIN_WIDTH-pipePos[ind],i+1);
			std::cout << "   "; 
		}
	}
}

void drawBird() {
	for(int i=0; i<2; i++) {
		for(int j=0; j<6; j++) {
			goToCoord(j+2,i+birdPos);
			std::cout << bird[i][j];
		}
	}
}
void eraseBird() {
	for(int i=0; i<2; i++) {
		for(int j=0; j<6; j++) {
			goToCoord(j+2,i+birdPos);
			std::cout << " ";
		}
	}
}

int collision() {
	if( pipePos[0] >= 61  ) {
		if( birdPos<gapPos[0] || birdPos >gapPos[0]+GAP_SIZE ) {
			return 1;
		}
	}
	return 0;
}

void gameover() {
	system("cls");
	std::cout << std::endl;
	std::cout << "\t\t--------------------------" << std::endl;
	std::cout << "\t\t-------- Game Over -------" << std::endl;
	std::cout << "\t\t--------------------------" << std::endl << std::endl;
	std::cout << "\t\tPress any key to go back to menu.";
	getch();
}

void updateScore() {
	goToCoord(WIN_WIDTH + 7, 5);
	std::cout << "Score: " << score << std::endl;
}

void instructions() {
	system("cls");
	std::cout << "Instructions";
	std::cout << "\n----------------";
	std::cout << "\n Press spacebar to make bird fly";
	std::cout << "\n\nPress any key to go back to menu";
	getch();
}

void play() {
	birdPos = 6;
	score = 0;
	pipeFlag[0] = 1; 
	pipeFlag[1] = 0;
	pipePos[0] = pipePos[1] = 4;
	
	system("cls"); 
	drawBorder();
	genPipe(0);
	updateScore();
	
	goToCoord(WIN_WIDTH + 5, 2);
	std::cout << "FLAPPY BIRD";
	goToCoord(WIN_WIDTH + 6, 4);
	std::cout << "----------";
	goToCoord(WIN_WIDTH + 6, 6);
	std::cout << "----------";
	goToCoord(WIN_WIDTH + 7, 12);
	std::cout << "Control ";
	goToCoord(WIN_WIDTH + 7, 13);
	std::cout << "-------- ";
	goToCoord(WIN_WIDTH + 2, 14);
	std::cout << " Spacebar = jump";
	
	goToCoord(10, 5);
	std::cout << "Press any key to start";
	getch();
	goToCoord(10, 5);
	std::cout << "                      ";
	
	while(1) {
		if(kbhit()) {
			char ch = getch();
			if(ch==32) {
				if( birdPos > 3 )
					birdPos-=3;
			} 
			if(ch==27) {
				break;
			}
		}
		
		drawBird();
		drawPipe(0);
		drawPipe(1);
		if( collision() == 1 ) {
			gameover();
			return;
		}
		Sleep(100);
		eraseBird();
		erasePipe(0);
		erasePipe(1);
		birdPos += 1;
		
		if( birdPos > SCREEN_HEIGHT - 2 ){
			gameover();
			return;
		}
		
		if( pipeFlag[0] == 1 )
			pipePos[0] += 2;
		
		if( pipeFlag[1] == 1 )
			pipePos[1] += 2;
		
		if( pipePos[0] >= 40 && pipePos[0] < 42 ) {
			pipeFlag[1] = 1;
			pipePos[1] = 4;
			genPipe(1);
		}
		if( pipePos[0] > 68 ) {
			score++;
			updateScore();
			pipeFlag[1] = 0;
			pipePos[0] = pipePos[1];
			gapPos[0] = gapPos[1];
		}
		
	}
}

int main() {
	setCursor(0,0); 
	srand( (unsigned)time(NULL)); 
	do {
		system("cls");
		goToCoord(10,5); std::cout << " -------------------------- "; 
		goToCoord(10,6); std::cout << " |      Flappy Bird       | "; 
		goToCoord(10,7); std::cout << " --------------------------";
		goToCoord(10,9); std::cout << "1. Start Game";
		goToCoord(10,10); std::cout << "2. Instructions";	 
		goToCoord(10,11); std::cout << "3. Quit";
		goToCoord(10,13); std::cout << "Select option: ";
		char op = getche();

		if( op=='1')
			play();
		else if( op=='2')
			instructions();
		else if( op=='3') {
			std::cout << "\n";
			exit(0);
		}
		
	} while(1);
	return 0;
}