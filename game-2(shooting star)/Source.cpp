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
int main() {
	//setcursor(0);
	setcolor(2, 4);
	char ch = '.';
	int x = 38, y = 20;
	draw_ship(x, y);
	int direction1;
	int direction2;
	int direction3;

	while (ch != 'x') {
		//do {
		if (_kbhit()) {
			ch = _getch();//press
			/*if (ch == 'a') {
				setcolor(2, 4); draw_ship(--x, y); setcolor(0, 0); printf(" "); }
			if (ch == 'd') {
				setcolor(0, 0); eraseship(x , y); setcolor(2, 4); draw_ship(++x, y);
			}
			if (ch == 's') {
				setcolor(2, 4); draw_ship(x, y);
			}
			fflush(stdin);
		}*/
			if (ch == 'a') {
				direction1 = --x;
			}
			else if (ch == 'd') {
				direction2 = ++x;
			}
			else if (ch == 's') {
				direction3 = x;
			}// direction
		}
		if (direction1 ) {
			setcolor(2, 4); draw_ship(--x, y); setcolor(0, 0); printf(" ");

		}
		if (direction2 ) {
			setcolor(0, 0); eraseship(x, y); setcolor(2, 4); draw_ship(++x, y);

		}
		if (direction3) {
			draw_ship(x, y);

		}

		Sleep(100);
	}
		//} while (ch != 'x');
		return 0;

	}

