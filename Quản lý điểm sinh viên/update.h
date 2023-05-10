#ifndef update_h
#define update_h
#include "student.h"
#include "draw.h"

void insertGraduate(undergradute *sv, int &amount)
{
    system("cls");
    int temp;
    draw_Frame(35, 1, 30, 1);
    gotoxy(40, 2);
    cout << "INSERT STUDENT" << endl;
    draw_Frame(9, 3, 20, 1);
    gotoxy(10, 4);
    cout << "ADD STUDENT: ";
    cin >> temp;
    int i = 0;
    while (temp != 0)
    {
        system("cls");
        draw_Frame(35, 1, 30, 1);
        gotoxy(40, 2);
        cout << "INSERT STUDENT" << endl;
        gotoxy(20, 8);
        cout << "PLEASE ENTER INFORMATION STUDENTS " << i+1 << endl;
        sv[amount] = enterInformation();
        amount++;
        i++;
        gotoxy(12, 39);
        temp--;
    }
    cout << "INSERT STUDENTS SUCCEESSFULLY.  ======>>> PRESS ANY BUTTON TO CONTINUE.... " << endl;
    getch();
}
int changeGraduate(undergradute *sv, int amount)
{
    system("cls");
    string temp;
    draw_Frame(30, 2, 40, 1);
    gotoxy(35, 3);
    cout << "CHANGE INFORMATION STUDENT" << endl;
    draw_Frame(10, 6, 20, 1);
    gotoxy(12, 7);
    cout << "ENTER ID: ";
    cin >> temp;
    for (int i = 0; i < amount; i++)
    {
        if (temp == sv[i].id)
        {
            sv[i] = enterInformation();
            gotoxy(12, 39);
            cout << "CHANGE UNDERGRADUTE SUCCEESSFULLY.  ======>>> PRESS ANY BUTTON TO CONTINUE.... " << endl;
            getch();
            return 0;
        }
    }
    gotoxy(12, 13);
    cout << "ID DO NOT EXIST !!!!  ======>>> PRESS ANY BUTTON TO COUNTINUE...." << endl
         << endl;
    getch();
    return 0;
}
int deleteGraduate(undergradute *sv, int &amount)
{
    system("cls");
    draw_Frame(30, 2, 40, 1);
    gotoxy(35, 3);
    cout << "DELETE INFORMATION STUDENT" << endl;
    if (amount == 0)
    {
        gotoxy(12, 7);
        cout << "LIST DO NOT EXIST!!!  ======>>> PRESS ANY BUTTON TO CONTINUE....";
        system("pause");
        return 0;
    }
    string temp;
    draw_Frame(10, 6, 20, 1);
    gotoxy(12, 7);
    cout << "ENTER ID: ";
    cin >> temp;
    for (int i = 0; i < amount; i++)
    {
        if (temp == sv[i].id)
        {
            for (int j = i; j < amount; j++)
            {
                sv[j] = sv[j + 1];
            }
            amount--;
            gotoxy(12, 10);
            cout << "DELETE STUDENT SUCCEESSFULLY.  ======>>> PRESS ANY BUTTON TO CONTINUE...." << endl;
            getch();
            return 0;
        }
    }
    gotoxy(12, 13);
    cout << "ID DO NOT EXIST !!!!  ======>>> PRESS ANY BUTTON TO CONTINUE...." << endl;
    getch();
    return 0;
}
#endif