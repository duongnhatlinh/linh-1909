#ifndef search_h
#define search_h
#include "student.h"
#include "sort.h"
#include "draw.h"
#include "file.h"
#include <iostream>
#include <string.h>
#define color_Normal 7
#define color_Special 1
#define color_Title 4
using namespace std;

int search_student(undergradute sv[], int amount, int x, int y);
int exit_search(undergradute sv[], int amount, int x, int y);
//====================== Search ID ====================
int binarySearchID(undergradute a[], int left, int right, string x)
{
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (a[middle].id.compare(x) == 0)
            return middle;
        if (x.compare(a[middle].id) > 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
int binarySearch_ID(undergradute sv[], int n)
{
    system("cls");
    draw_Frame(80, 1, 30, 1);
    gotoxy(90,2);
    cout << "SEARCH ID";
    SelectionSortID(sv, n);
    string id1;
    draw_Frame(10,5, 30, 1);
    gotoxy(12,6);
    cout << "PLEASE ENTER ID: ";
    getline(cin, id1);
    undergradute temp;
    int x = binarySearchID(sv, 0, n - 1, id1);
    if (x >= 0)
    {
        temp = sv[x];
        printStudent(&temp, 1, 5, 10);
        gotoxy(12, 30);
        cout << "======>>> PRESS ANY BUTTON TO CONTINUE...." << endl;
        getch();
    }
    else
    {
        gotoxy(12, 12);
        cout << "ID DO NOT EXIST !!!!  ======>>> PRESS ANY BUTTON TO CONTINUE...." << endl;
        getch();
        return 0;
    }
    return 0;
}
// ==============Search Name======================
void Lowercase(string &a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
        {
            a[i] += 32;
        }
    }
}

int exit_search(undergradute sv[], int amount, int x, int y)
{
    int focus = 1;
    draw_Frame(x, y, 33, 6);
    gotoxy(x+4, y+1);
    cout << "Do you want to continue";
    gotoxy(x+8, y+2);
    cout << "searching?";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
    draw_Frame(x+3, y+4, 10, 1);
    gotoxy(x+6, y+5);
    cout << "YES";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
    draw_Frame(x+19, y+4, 10, 1);
    gotoxy(x+23, y+5);
    cout << "NO";
    while (true)
    {
        int ch = getch();
        switch (ch)
        {
        case 75:
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
            draw_Frame(x+3, y+4, 10, 1);
            gotoxy(x+6, y+5);
            cout << "YES";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
            draw_Frame(x+19, y+4, 10, 1);
            gotoxy(x+23, y+5);
            cout << "NO";
            focus = 1;
            break;
        }
        case 77:
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
            draw_Frame(x+3, y+4, 10, 1);
            gotoxy(x+6, y+5);
            cout << "YES";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
            draw_Frame(x+19, y+4, 10, 1);
            gotoxy(x+23, y+5);
            cout << "NO";
            focus = 0;
            break;
        }
        case 13:
        {
            if(focus == 0)
            {
                return 0;

            }
            else 
            {
                return 1;
            }
            break;
        }
        }
    }
}
int search_student(undergradute sv[], int amount, int x, int y)
{
    system("cls");
    Nocursortype();
    draw_Frame(x+75, y - 2, 20, 1);
    gotoxy(x+78, y-1);
    cout << "SEARCH STUDENT";
    draw_Frame(x - 2, y - 1, 50, 1);
    gotoxy(x, y);
    cout << "ENTER NAME: ";
    int k = 0;
    string s = "";
    int a = 0;
    undergradute m[100];
    int focus = -1;
    while (true)
    {
        int ch = getch();
        for (int i = 0; i <= a; i++)
        {
            gotoxy(x + 10, y + 3 + 3 * i);
            cout << "                                                         \n                                                                  \n                                                            ";
        }
        switch (ch)
        {
        case 72:
        {
            if (focus == -1 || focus == 0)
                focus = a;
            focus--;
            for (int i = 0; i < a; i++)
            {
                if (focus == i)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
                    multiple_frame(x + 10, y + 3, 25, a, i);
                    multiple_frame(x+40, y+3, 10, a, i);
                    gotoxy(x + 13, y + 4 + 3 * i);
                    cout << m[i].name;
                    gotoxy(x+43, y+4+3*i);
                    cout << m[i].sex;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
                }
                else
                {
                    multiple_frame(x + 10, y + 3, 25, a, i);
                    multiple_frame(x+40, y+3, 10, a, i);
                    gotoxy(x + 13, y + 4 + 3 * i);
                    cout << m[i].name;
                    gotoxy(x+43, y+4+3*i);
                    cout << m[i].sex;
                }
            }
            break;
        }
        case 80:
        {
            if (focus == a - 1)
                focus = -1;
            focus++;
            for (int i = 0; i < a; i++)
            {
                if (focus == i)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
                    multiple_frame(x + 10, y + 3, 25, a, i);
                    multiple_frame(x+40, y+3, 10, a, i);
                    gotoxy(x + 13, y + 4 + 3 * i);
                    cout << m[i].name;
                    gotoxy(x+43, y+4+3*i);
                    cout << m[i].sex;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
                }
                else
                {
                    multiple_frame(x + 10, y + 3, 25, a, i);
                    multiple_frame(x+40, y+3, 10, a, i);
                    gotoxy(x + 13, y + 4 + 3 * i);
                    cout << m[i].name;
                    gotoxy(x+43, y+4+3*i);
                    cout << m[i].sex;
                }
            }
            break;
        }
        case 13:
        {
            undergradute temp;
            a = 0;
            s = "";
            if(focus == -1)
                focus = 0;
            if(m[focus].name == "")
            {
                temp = sv[0];
            } else
            {
                temp = m[focus];
            }
            printStudent(&temp, 1, x + 1, y + 5);
            getch();
            if(exit_search(sv, amount, 70, 18) == 0)
                return 0;
            else
                return 1;
            break;
        }
        default:
        {
            if (ch == 8 && s != "")
            {
                k--;
                s.pop_back();
                gotoxy(x + 12 + k, y);
                cout << " ";
            }
            if (ch != 224 && ch != 8)
            {
                focus = -1;
                gotoxy(x + 12 + k, y);
                cout << char(ch);
                s = s + char(ch);
                k++;
            }
            a = 0;
            for (int i = 0; i < amount; i++)
            {
                int temp1 = sv[i].name.find(s);
                Lowercase(sv[i].name);
                int temp2 = sv[i].name.find(s);
                if ((temp1 >= 0 || temp2 >= 0) && s != "")
                {
                    gotoxy(x + 13, y + 4 + 3 * a);
                    Standard_Name(sv[i].name);
                    cout << sv[i].name;
                    gotoxy(x+43, y+4+3*a);
                    cout << sv[i].sex;
                    m[a] = sv[i];
                    a++;
                }
            }
            for (int i = 0; i < a; i++)
            {
                multiple_frame(x + 10, y + 3, 25, a, i);
                multiple_frame(x+40, y+3, 10, a, i);
            }
        }
        break;
        }
    }
}
#endif
