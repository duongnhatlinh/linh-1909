#ifndef file_h
#define file_h
#include "student.h"
#include <fstream>

//=============================================
int readFile(undergradute sv[], char fileName[]);
int writeFile(undergradute sv[], int amount, char fileName[]);
//=============================================
int readFile(undergradute sv[])
{
    ifstream filein;
    int amount = 0;
    filein.open("danhsachsinhvien.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        getch();
        return -1;
    }
    while (!filein.eof())
    {
        getline(filein, sv[amount].id, ',');
        getline(filein, sv[amount].name, ',');
        getline(filein, sv[amount].sex, ',');
        getline(filein, sv[amount].dateBirth, ',');
        getline(filein, sv[amount].contryside, ',');
        getline(filein, sv[amount].classRoom, ',');
        filein >> sv[amount].math;
        filein.ignore();
        filein >> sv[amount].physics;
        filein.ignore();
        filein >> sv[amount].chemistry;
        filein.ignore();
        sv[amount].getClassification();
        amount++;
    }
    amount--;
    filein.close();
    return amount; 
}
int writeFile(undergradute sv[], int amount)
{
    ofstream fileout;
    fileout.open("danhsachsinhvien.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        getch();
        return -1;
    }
    for (int i = 0; i < amount; i++)
    {
        fileout << sv[i].id << ',' << sv[i].name << ','
                << sv[i].sex << ',' << sv[i].dateBirth << ','
                << sv[i].contryside << ',' << sv[i].classRoom << ','
                << sv[i].math << ',' << sv[i].physics << ','
                << sv[i].chemistry << endl;
    }
    fileout.close();
}
#endif