#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x ,int y){
	COORD c = { x,y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x,int y) {
	system("cls");
}
void draw_ship(int x, int y) {
	erase_ship(x, y);
	gotoxy(x, y);
	printf("<--|--0--|--> ");
}
int main() {
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' and x >= 1) { draw_ship(--x, y); }
			if (ch == 'd' and x <= 80) { draw_ship(++x, y); }
			if (ch == 'w' and y >= 1) { draw_ship(x, --y); }
			if (ch == 's' and y <= 23) { draw_ship(x,++y); }
			fflush(stdin);
		}
		Sleep(100);
	} while (ch!='x');
	return 0;
}