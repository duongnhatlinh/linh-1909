#ifndef student_h
#define student_h
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "draw.h"
using namespace std;

class undergradute
{
public:
    string id;
    string name;
    string sex;
    string dateBirth;
    string contryside;
    string classRoom;
    float math;
    float physics;
    float chemistry;
    float gradeMedium;
    string Classification;
    float getGradeMedium();
    string getClassification();
};
//=============================================
string makeId(undergradute sv);
undergradute enterInformation();
int printGraduate(undergradute sv[], int amount);
void Standard_Name(string &a);
//==============================================
float undergradute::getGradeMedium()
{
    float x = (math + physics + chemistry) / 3;
    x= (round(x * 100)) / 100;
    return x;
}

string undergradute::getClassification()
{
    if (getGradeMedium() >= 8)
        return Classification = "excellent";
    else if (getGradeMedium() >= 6.5)
        return Classification = "good";
    else if (getGradeMedium() >= 5)
        return Classification = "average";
    else
        return Classification = "weak";
}

void Standard_Name(string &a)
{
    // xoa kt dau va cuoi
    while (a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }
    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1);
    }
    // xoa kt giua
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ' && a[i + 1] == ' ')
        {
            a.erase(a.begin() + i + 1);
        }
    }
    // chuan hoa ki tu
    if (a[0] >= 97 && a[0] <= 122)
    {
        a[0] -= 32;
    }
    for (int i=1; i < a.length(); i++)
    {
        if(a[i] == ' ')
        {
            i++;
            if(a[i] >= 97 && a[i] <= 122)
            {
                a[i] -= 32;
            }
        }
        else
        {
            if (a[i] >= 65 && a[i] <= 90)
            {
                a[i] += 32;
            }
        }
    }
}
void Standard_Class(string &a)
{
    while (a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }
    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1);
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 97 && a[i] <= 122)
        {
            a[i] -= 32;
        }
    }
}
undergradute enterInformation()
{
    undergradute sv;
    draw_Frame_INFORMATION();
    gotoxy(10, 11);
    cout << " ENTER ID:             ";
    gotoxy(71, 11);
    cout << "(Ex: 10095)";
    gotoxy(10, 14);
    cout << " ENTER NAME:           ";
    gotoxy(71, 14);
    cout << "(Ex: Duong Dinh Nhat Linh)";
    gotoxy(10, 17);
    cout << " ENTER SEX:            ";
    gotoxy(71, 17);
    cout << "(Ex: Nam or Nu)";
    gotoxy(10, 20);
    cout << " ENTER BIRTHDAY:       ";
    gotoxy(71, 20);
    cout << "(Ex: 19/09/2002)";
    gotoxy(10, 23);
    cout << " ENTER COUNTRYSIZE:    ";
    gotoxy(71, 23);
    cout << "(Ex: Ha Noi)";
    gotoxy(10, 26);
    cout << " ENTER CLASS:          ";
    gotoxy(71, 26);
    cout << "(Ex: CNTT)";
    gotoxy(10, 29);
    cout << " ENTER GRADE MATH:     ";
    gotoxy(10, 32);
    cout << " ENTER GRADE PHYSICS:  ";
    gotoxy(10, 35);
    cout << " ENTER GRADE CHEMISTRY:";
    //---------------------
    gotoxy(42, 11);
    cin.ignore();
    getline(cin, sv.id);
    gotoxy(42, 14);
    getline(cin, sv.name);
    gotoxy(42, 17);
    getline(cin, sv.sex);
    gotoxy(42, 20);
    getline(cin, sv.dateBirth);
    gotoxy(42, 23);
    getline(cin, sv.contryside);
    gotoxy(42, 26);
    getline(cin, sv.classRoom);
    gotoxy(42, 29);
    cin >> sv.math;
    gotoxy(42, 32);
    cin >> sv.physics;
    gotoxy(42, 35);
    cin >> sv.chemistry;
    sv.Classification = sv.getClassification();
    return sv;
}
int printStudent(undergradute a[], int amount, int x, int y)
{
    system("cls");
    draw_Frame(x + 70, y - 4, 40, 1);
    gotoxy(85, y - 3);
    cout << "INFORMATION STUDENTS" << endl;
    if (amount == 0)
    {
        gotoxy(12, 9);
        cout << "EMPTY LIST!!!!   ======>> PRESS ANY BUTTON TO CONTINUE..." << endl;
        return 0;
    }
    gotoxy(x + 2, y + 1);
    cout << "STT";
    gotoxy(x + 11, y + 1);
    cout << "ID";
    gotoxy(x + 32, y + 1);
    cout << "NAME";
    gotoxy(x + 55, y + 1);
    cout << "CLASS";
    gotoxy(x + 71, y + 1);
    cout << "CONTRYSIDE";
    gotoxy(x + 92, y + 1);
    cout << "BIRTHDAY";
    gotoxy(x + 110, y + 1);
    cout << "SEX";
    gotoxy(x + 121, y + 1);
    cout << "MATH";
    gotoxy(x + 132, y + 1);
    cout << "PHYSICAL";
    gotoxy(x + 143, y + 1);
    cout << "CHEMISTRY";
    gotoxy(x + 157, y + 1);
    cout << "MEDIUM";
    gotoxy(x + 167, y + 1);
    cout << "CLASSIFICATION";
    display_Frame_Student(x, y, amount);
    for (int i = 0; i < amount; i++)
    {
        gotoxy(x + 2, y + 4 + 3 * i);
        cout << i + 1;
        gotoxy(x + 8, y + 4 + 3 * i);
        cout << a[i].id;
        gotoxy(x + 20, y + 4 + 3 * i);
        Standard_Name(a[i].name);
        cout << a[i].name;
        gotoxy(x + 54, y + 4 + 3 * i);
        Standard_Class(a[i].classRoom);
        cout << a[i].classRoom;
        gotoxy(x + 72, y + 4 + 3 * i);
        Standard_Name(a[i].contryside);
        cout << a[i].contryside;
        gotoxy(x + 90, y + 4 + 3 * i);
        cout << a[i].dateBirth;
        gotoxy(x + 110, y + 4 + 3 * i);
        Standard_Name(a[i].sex);
        cout << a[i].sex;
        gotoxy(x + 122, y + 4 + 3 * i);
        cout << a[i].math;
        gotoxy(x + 134, y + 4 + 3 * i);
        cout << a[i].physics;
        gotoxy(x + 146, y + 4 + 3 * i);
        cout << a[i].chemistry;
        gotoxy(x + 158, y + 4 + 3 * i);
        cout << a[i].getGradeMedium();
        gotoxy(x + 172, y + 4 + 3 * i);
        cout << a[i].Classification << endl;
    }
    return 0;
}

#endif