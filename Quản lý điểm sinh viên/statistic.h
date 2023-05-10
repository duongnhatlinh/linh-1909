#ifndef statistic_h
#define statistic_h
#include "draw.h"
#include "file.h"
#include <math.h>
using namespace std;

int temp[4];
// ======================= TABLE ======================
// function do percent
float do_Percent(int a, int b)
{
    float x = (float)a / b;
    return (round(x * 100));
}
// table statistics
void table_Statistics(int x, int y)
{
    gotoxy(x + 2, y + 1);
    cout << "STT";
    gotoxy(x + 10, y + 1);
    cout << "CLASS";
    gotoxy(x + 21, y + 1);
    cout << "AMOUNT";
    gotoxy(x + 32, y + 1);
    cout << "EXCELLENT";
    gotoxy(x + 46, y + 1);
    cout << "GOOD";
    gotoxy(x + 57, y + 1);
    cout << "AVERAGE";
    gotoxy(x + 70, y + 1);
    cout << "WEAK";
    display_Frame_Statistics(x, y, 7);
}
void check_Class(undergradute sv[], int n, string cl, int temp[])
{
    int a = 0, ag = 0, ak = 0, at = 0, ay = 0;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].classRoom.compare(cl) == 0)
        {
            a++;
            if (sv[i].Classification.compare("excellent") == 0)
            {
                ag++;
            }
            else if (sv[i].Classification.compare("good") == 0)
            {
                ak++;
            }
            else if (sv[i].Classification.compare("average") == 0)
            {
                at++;
            }
            else if (sv[i].Classification.compare("weak") == 0)
            {
                ay++;
            }
        }
    }
    int p1 = do_Percent(ag, a), p2 = do_Percent(ak, a), p3 = do_Percent(at, a), p4;
    p4 = 100 - p1 - p2 - p3;
    temp[0] = a;
    temp[1] = p1;
    temp[2] = p2;
    temp[3] = p3;
    temp[4] = p4;
}
void out_Percent(undergradute sv[], int n, string cl, int x, int y)
{
    int temp[5];
    check_Class(sv, n, cl, temp);
    // cout class
    gotoxy(x + 10, y + 1);
    cout << cl;
    // cout amount class
    gotoxy(x + 21, y + 1);
    cout << temp[0];
    // cout percent excellent
    gotoxy(x + 32, y + 1);
    cout << temp[1] << "%";
    // cout percent good
    gotoxy(x + 46, y + 1);
    cout << temp[2] << "%";
    // cout percent average
    gotoxy(x + 57, y + 1);
    cout << temp[3] << "%";
    // cout percent weak
    gotoxy(x + 70, y + 1);
    cout << temp[4] << "%";
}
void table_Statistics_Student(undergradute sv[], int n, int x, int y)
{
    system("cls");
    draw_Frame(60, 1, 30, 1);
    gotoxy(66, 2);
    cout << "STATISTIC STUDENT" << endl;
    gotoxy(x + 25, y - 2);
    cout << "TABLE STATISTIC" << endl;
    for (int i = 1; i <= 7; i++)
    {
        gotoxy(x + 2, y + 1 + 3 * i);
        cout << i;
    }

    table_Statistics(x, y);
    out_Percent(sv, n, "CNTT", x, y + 3);
    out_Percent(sv, n, "BDATTT", x, y + 6);
    out_Percent(sv, n, "ANHTTT", x, y + 9);
    out_Percent(sv, n, "PTDL", x, y + 12);
    out_Percent(sv, n, "KTPM", x, y + 15);
    out_Percent(sv, n, "HTTT", x, y + 18);
    out_Percent(sv, n, "MMT&TTDL", x, y + 21);
    // getch();
}
// ====================== GRAPHIC ======================
void color_frame_graph(int m, int p, int x, int y)
{
    for (int i = 0; i <= p; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m);
        gotoxy(x, y - p + i);
        cout << "  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    }
}
void sub_graph(int a, int b, int c, int d, int x, int y)
{
    color_frame_graph(20, a, x, y);
    color_frame_graph(120, b, x + 2, y);
    color_frame_graph(80, c, x + 4, y);
    color_frame_graph(200, d, x + 6, y);
}
void out_sub_graph(undergradute sv[], int n, string cl, int x, int y)
{
    int temp[5];
    check_Class(sv, n, cl, temp);
    sub_graph(round(temp[1] / 10), round(temp[2] / 10), round(temp[3] / 10), round(temp[4] / 10), x, y);
}
void graphic_Statistics_Student(undergradute sv[], int n, int x, int y)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    for (int i = 0; i < 90; i++)
    {
        gotoxy(x + i, y);
        if (i >= 2 && i <= 9 || i >= 14 && i <= 21 || i >= 26 && i <= 33 || i >= 38 && i <= 45 || i >= 50 && i <= 57 || i >= 62 && i <= 69 || i >= 74 && i <= 81)
        {
            continue;
        }
        cout << "_";
    }
    gotoxy(x + 90, y);
    cout << "\\";
    gotoxy(x + 90, y + 1);
    cout << "/";
    for (int i = 1; i <= 10; i++)
    {
        gotoxy(x, y - 10 + i);
        cout << "|";
    }
    gotoxy(x + 1, y - 10);
    cout << "\\";
    gotoxy(x - 1, y - 10);
    cout << "/";
    out_sub_graph(sv, n, "CNTT", x + 2, y);
    out_sub_graph(sv, n, "BDATTT", x + 14, y);
    out_sub_graph(sv, n, "ANHTTT", x + 26, y);
    out_sub_graph(sv, n, "PTDL", x + 38, y);
    out_sub_graph(sv, n, "KTPM", x + 50, y);
    out_sub_graph(sv, n, "HTTT", x + 62, y);
    out_sub_graph(sv, n, "MMT&TTDL", x + 74, y);
    // caption
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    gotoxy(x+40, y-11);
    cout << "STUDENT SCORE GRAPH";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(x + 4, y + 1);
    cout << "CNTT";
    gotoxy(x + 15, y + 1);
    cout << "BDATTT";
    gotoxy(x + 27, y + 1);
    cout << "ANHTTT";
    gotoxy(x + 40, y + 1);
    cout << "PTDL";
    gotoxy(x + 52, y + 1);
    cout << "KTPM";
    gotoxy(x + 64, y + 1);
    cout << "HTTT";
    gotoxy(x + 74, y + 1);
    cout << "MMT&TTDL";
    gotoxy(x + 92, y + 1);
    cout << "(Class)";
    gotoxy(x - 4, y - 10);
    cout << "(%)";
    gotoxy(x + 105, y - 8);
    cout << "NOTE: ";
    gotoxy(x + 108, y - 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 20);
    cout << "  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    gotoxy(x + 112, y - 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "Excellent";
    gotoxy(x + 108, y - 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 120);
    cout << "  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    gotoxy(x + 112, y - 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "Good";
    gotoxy(x + 108, y - 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
    cout << "  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    gotoxy(x + 112, y - 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "Average";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
    gotoxy(x + 108, y);
    cout << "  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    gotoxy(x + 112, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "Weak";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    getch();
}
#endif