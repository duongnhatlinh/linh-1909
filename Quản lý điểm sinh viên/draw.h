#ifndef draw_h
#define draw_h
#include <iostream>
#include <windows.h>
#define NONE_COLOR 1
#define CURSOR_COLOR 2
#define FRAME_COLOR 3
#define TITLE_COLOR 4
using namespace std;

// ===================== Tự định nghĩa=============================
const char gocTT = char(218);	  
const char gocTD = char(192);	  
const char gocPT = char(191);	  
const char gocPD = char(217);	  
const char gachNgang = char(196); 
const char gachDoc = char(179);	  
const char gachQT = 58;			  
const char gachQP = 58;			  
const char gachGiuaQT = 58;		  
const char gachGiuaQD = 58;
// ================================================================
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void Cursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// ham khung
void draw_Frame(int x, int y, int width, int height)
{

	gotoxy(x, y);
	cout << gocTT;
	gotoxy(x + width - 1, y);
	cout << gocPT;
	gotoxy(x, y + 1 + height);
	cout << gocTD;
	gotoxy(x + width - 1, y + 1 + height);
	cout << gocPD;
	for (int  i= 0; i < width - 2; i++)
	{
		gotoxy(x + 1+i, y);
		cout << gachNgang;
		gotoxy(x + 1+ i, y + height + 1);
		cout << gachNgang;
	}
	for (int j = 0; j < height; j++)
	{
		gotoxy(x, y + 1 + j);
		cout << gachDoc;
		gotoxy(x + width - 1, y + 1 + j);
		cout << gachDoc;
	}
}
void draw_Frame_INFORMATION()
{
	draw_Frame(9, 10, 30, 1);
	draw_Frame(9, 13, 30, 1);
	draw_Frame(9, 16, 30, 1);
	draw_Frame(9, 19, 30, 1);
	draw_Frame(9, 22, 30, 1);
	draw_Frame(9, 25, 30, 1);
	draw_Frame(9, 28, 30, 1);
	draw_Frame(9, 31, 30, 1);
	draw_Frame(9, 34, 30, 1);
	//----------------------------
	draw_Frame(40, 10, 30, 1);
	draw_Frame(40, 13, 30, 1);
	draw_Frame(40, 16, 30, 1);
	draw_Frame(40, 19, 30, 1);
	draw_Frame(40, 22, 30, 1);
	draw_Frame(40, 25, 30, 1);
	draw_Frame(40, 28, 30, 1);
	draw_Frame(40, 31, 30, 1);
	draw_Frame(40, 34, 30, 1);
}
// frame information student
void frame_Row_Student(int x, int y)
{

	gotoxy(x, y);
	cout << gocTT;
	gotoxy(x + 6, y);
	cout << gachGiuaQD;
	gotoxy(x + 18, y);
	cout << gachGiuaQD;
	gotoxy(x + 50, y);
	cout << gachGiuaQD;
	gotoxy(x + 65, y);
	cout << gachGiuaQD;
	gotoxy(x + 85, y);
	cout << gachGiuaQD;
	gotoxy(x + 105, y);
	cout << gachGiuaQD;
	gotoxy(x + 117, y);
	cout << gachGiuaQD;
	gotoxy(x + 129, y);
	cout << gachGiuaQD;
	gotoxy(x + 141, y);
	cout << gachGiuaQD;
	gotoxy(x + 153, y);
	cout << gachGiuaQD;
	gotoxy(x + 165, y);
	cout << gachGiuaQD;
	gotoxy(x + 182, y);
	cout << gocPT;

	gotoxy(x, y + 2);
	cout << gocTD;
	gotoxy(x + 6, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 18, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 50, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 65, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 85, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 105, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 117, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 129, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 141, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 153, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 165, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 182, y + 2);
	cout << gocPD;

	for (int i = 0; i <= 182; i++)
	{

		if (i != 0 && i != 6 && i != 18 && i != 50 && i != 65 && i != 85 && i != 105 && i != 117 && i != 129 && i != 141 && i != 153 && i != 165 && i != 182)
		{
			gotoxy(x + i, y);
			cout << gachNgang;
			gotoxy(x + i, y + 2);
			cout << gachNgang;
		}
		else
		{
			gotoxy(x + i, y + 1);
			cout << gachDoc;
		}
	}
}
void display_Frame_Student(int x, int y, int row)
{

	for (int i = 0; i <= row; i++)
	{
		frame_Row_Student(x, y + i * 3);
	}

	cout << endl;
}
// frame statistics
void frame_Row_Statistics(int x, int y)
{
	gotoxy(x, y);
	cout << gocTT;
	gotoxy(x + 6, y);
	cout << gachGiuaQD;
	gotoxy(x + 18, y);
	cout << gachGiuaQD;
	gotoxy(x + 30, y);
	cout << gachGiuaQD;
	gotoxy(x + 42, y);
	cout << gachGiuaQD;
	gotoxy(x + 54, y);
	cout << gachGiuaQD;
	gotoxy(x + 66, y);
	cout << gachGiuaQD;
	gotoxy(x + 78, y);
	cout << gocPT;

	gotoxy(x, y + 2);
	cout << gocTD;
	gotoxy(x + 6, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 18, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 30, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 42, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 54, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 66, y + 2);
	cout << gachGiuaQT;
	gotoxy(x + 78, y + 2);
	cout << gocPD;

	for (int i = 0; i <= 78; i++)
	{

		if (i != 0 && i != 6 && i != 18 && i != 30 && i != 42 && i != 54 && i != 66 && i != 78)
		{
			gotoxy(x + i, y);
			cout << gachNgang;
			gotoxy(x + i, y + 2);
			cout << gachNgang;
		}
		else
		{
			gotoxy(x + i, y + 1);
			cout << gachDoc;
		}
	}
}
void display_Frame_Statistics(int x, int y, int row)
{

	for (int i = 0; i <= row; i++)
	{
		frame_Row_Statistics(x, y + i * 3);
	}
	cout << endl;
}
// graphic
void graphic_Student(int x, int y)
{
	gotoxy(x, y);
	cout << gocTD;
	for (int i = 0; i <= 100; i++)
	{
		if (i != 0)
		{
			gotoxy(x + i, y);
			cout << gachNgang;
		}
	}
	for(int i = 0; i <=19; i++)
	{
			gotoxy(x, y-20+i);
			cout << gachDoc;
	}
}

void multiple_frame(int x, int y, int width ,int row, int b)
{
    int a = y;
    for (int i = 0; i < row; i++)
    {
        a = a + 3 * (i);
        if (i == b)
            draw_Frame(x, a, width, 1);
        a = y;
    }
}
#endif