#include<stdio.h>
#include<windows.h>
#include<conio.h>
char ch1 = '.';
char keyx1;
int checkShoot = 1;
int x;
int y;
int x1;
int y1;
char ch = '.';
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
void bullet(int x, int y) {
	
	gotoxy(x, y); 
	setcolor(0, 3); 
	printf(" ");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
	
}

void erase_first_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 4);
	printf(" ");

}

void shoot(int x1, int y1) {
	checkShoot = 1;
	while (1) {
		if (checkShoot==1) {
			erase_first_bullet(x1 + 3, y1);
			bullet(x1 + 3, --y1);
			checkShoot += 1;
		}
		else {
			erase_bullet(x1 + 3, y1);
			bullet(x1 + 3, --y1);
		}
		
		Sleep(100);

	}
}
void check(int x, int y) {
	if (x==x1 && y==y1 ) {
		printf("  ");
	}

}

int main() {
	setcursor(1);
	object(10, 12);
	object(5, 2);
	object(80, 6);
	object(30, 15);
	object(65, 1);
	setcolor(2, 4);
	char ch = '.';
	int x = 38, y = 20;
	draw_ship(x, y);
	//rocket(x, y);

	char keyx = '.';

	

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
			else if (ch == 'i') {
				shoot(x, y);
			}
			fflush(stdin);

		}


		else if (!_kbhit || keyx == 'a' || keyx == 'd' || keyx == 's') {

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

			else if (keyx == 's') {
				setcolor(2, 4);
				draw_ship(x, y);
			}
			/*else if (keyx == 'i') {


				if (y ==0 ) {
					erase_bullet(x + 3, y);
					y = 20;
					continue;
				}
				else {
				 erase_bullet(x + 3, y--);

				 bullet(x + 3, --y);

				}

			}*/
			
				fflush(stdin);

			}
			//rocket(x, y);
			Sleep(100);
		} while (ch != 'x');

		return 0;

	}