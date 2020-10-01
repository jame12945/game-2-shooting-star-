#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = {x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void eraseship(int x,int y) {
	gotoxy(x, y); printf(" ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void object(int x,int y){
	setcolor(0, 8);
	gotoxy(x, y); printf("  ");
}



int main() {
	//setcursor(0);
	object(10,12);
	object(5, 2);
	object(80, 6);
	object(30, 15);
	object(65, 1);
	setcolor(2, 4);
	char ch = '.';
	int x = 38, y = 20;
	draw_ship(x, y);
	int direction1;
	int direction2;
	int direction3;
	char keyx = '.';

	//while (ch != 'x') {
	do {
		if (_kbhit()) {
			ch = _getch();//press
				if (ch == 'a') {


					if (x == 0) {
						continue;
					}
					else {
						setcolor(2, 4);
						draw_ship(--x, y);
						setcolor(0, 0);
						printf(" ");
						keyx = 'a';
					}//end a

				}
				
					
				else if (ch == 'd') {

					if (x == 113) {
						continue;
					}
					else {

						setcolor(0, 0);
						eraseship(x, y);
						setcolor(2, 4);
						draw_ship(++x, y);
						keyx = 'd';
					}
				}
			
				else if (ch == 's') {
				setcolor(2, 4);
				draw_ship(x, y);
				keyx = 's';

			}
			fflush(stdin);
		}
			

		else if(!_kbhit || keyx=='a' || keyx=='d' || keyx=='s'){

			if (keyx == 'a') {
				
				
				if (x == 0) {
					continue;
				}
				else {
					setcolor(2, 4);
					draw_ship(--x, y);
					setcolor(0, 0);
					printf(" ");
				}

			}
					

			else if (keyx == 'd') {

				if (x == 113) {
					continue;
				}
				else {
					setcolor(0, 0);
					eraseship(x, y);
					setcolor(2, 4);
					draw_ship(++x, y);
				}

			}

			else if (ch == 's') {
				setcolor(2, 4); 
				draw_ship(x, y);
			}
			fflush(stdin);
		
		}
		Sleep(50);
		} while (ch != 'x');
		return 0;

	}

