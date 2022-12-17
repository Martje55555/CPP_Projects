#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

char keys[10];	
int keyPos[10][2];	
int score = 0; 

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void drawBorder(){  
	for(int i=0; i<SCREEN_WIDTH; i++){ 
		gotoxy(i,SCREEN_HEIGHT); std::cout<<"±";
	}
	
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(0,i); std::cout<<"±";
		gotoxy(SCREEN_WIDTH,i); std::cout<<"±";
	}
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(WIN_WIDTH,i); std::cout<<"±";
	}
}

void genAlphabet(int ind){
	keys[ind] = 65+rand()%25;
	keyPos[ind][0] = 2 + rand()%(WIN_WIDTH-2);
	keyPos[ind][1] = 1;
}
void drawAlphabet(int ind){
	if( keyPos[ind][0] != 0 ){
		gotoxy(keyPos[ind][0], keyPos[ind][1]);   std::cout<<keys[ind];  
	} 
}
void eraseAlphabet(int ind){
	if( keyPos[ind][0] != 0 ){
		gotoxy(keyPos[ind][0], keyPos[ind][1]);   std::cout<<" ";  
	}
}
void resetAlphabet(int ind){
	eraseAlphabet(ind);
	genAlphabet(ind);
}

void gameover(){
	system("cls");
	std::cout<<std::endl;
	std::cout<<"\t\t--------------------------"<<std::endl;
	std::cout<<"\t\t-------- Game Over -------"<<std::endl;
	std::cout<<"\t\t--------------------------"<<std::endl<<std::endl;
	std::cout<<"\t\tPress any key to go back to menu.";
	getch();
}
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);std::cout<<"Score: "<<score<<std::endl;
}

void instructions(){
	
	system("cls");
	std::cout<<"Instructions";
	std::cout<<"\n----------------";
	std::cout<<"\n On Left side you will see falling characters ";
	std::cout<<"\n You have to keep them away from touching floor";
	std::cout<<"\n Press respective key from keyboard to keep playing";
	std::cout<<"\n\n Press 'escape' to exit";
	std::cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	score = 0;
	for(int i=0; i<10; i++){
		keyPos[i][0] = keyPos[i][1] = 1;	
	}
	 
	system("cls"); 
	drawBorder(); 
	updateScore();
	
	for(int i=0; i<10; i++)
		genAlphabet(i); 
	
	gotoxy(WIN_WIDTH + 5, 2);std::cout<<"Typing Tutor";
	gotoxy(WIN_WIDTH + 6, 4);std::cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);std::cout<<"----------";
	
	gotoxy(18, 5);std::cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);std::cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			for(int i=0; i<10; i++){
				if( ch == keys[i] || ch-32 == keys[i] ){
					resetAlphabet(i);
					score++;
					updateScore();
				}
			}
			if(ch==27){
				break;
			}
		} 
		
		for(int i=0; i<10; i++)
			drawAlphabet(i);  
			
		Sleep(300); 
		
		for(int i=0; i<10; i++){
			eraseAlphabet(i);  
			keyPos[i][1] += 1;
			if( keyPos[i][1] > SCREEN_HEIGHT ){
				gameover();
				return;
			}
		}
	}
}

int main()
{
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); std::cout<<" -------------------------- "; 
		gotoxy(10,6); std::cout<<" |     TYPING  TUTOR      | "; 
		gotoxy(10,7); std::cout<<" --------------------------";
		gotoxy(10,9); std::cout<<"1. Start Game";
		gotoxy(10,10); std::cout<<"2. Instructions";	 
		gotoxy(10,11); std::cout<<"3. Quit";
		gotoxy(10,13); std::cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}