#include "file.h"
#include "update.h"
#include "sort.h"
#include "search.h"
#include "draw.h"
#include "student.h"
#include "statistic.h"
#include "theme.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#define MAX 100
using namespace std;

string menu[6] = {"Update", "Display", "Sort", "Search", "Statistics", "Exit"};
string update[4] = {"Insert", "Change", "Delete", "Return"};
string display[3] = {"Console", "File", "Return"};
string sort[3] = {"Selection", "Quicksort", "Return"};
string search[3] = {"Search Name", "Search ID", "Return"};
string statistics[3] = {"Search Name", "Search ID", "Return"};
string elementSort[4] = {"Sort Name", "Sort Class", "Sort GradeMedium", "Return"};
class Menu
{
private:
  int size;
  string *option;
  string title;

public:
  Menu(int, string *, string);
  int printMenu(string *, int, int, int, int);
};
Menu::Menu(int s, string *op, string ti)
{
  size = s;
  title = ti;
  option = new string[size];
  for (int i = 0; i < size; i++)
  {
    option[i] = op[i];
  }
}
int Menu::printMenu(string ds[], int n, int x, int y, int width)
{
  system("cls");
  int focus = 0;
  while (true)
  {
    Nocursortype();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    draw_Frame(x-5 , y-4 , width +10, (n+1)*3);
    gotoxy(x+ 5, y-3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Title);
    cout << title << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
    for(int i = 0; i< n; i++)
      {
        if(focus == i)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
        }
        else 
        {
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
        }
      }
    int ch = getch();
    switch (ch)
    {
    case 72:
      if (focus == 0)
        focus = n ;
      focus--;
      for(int i = 0; i< n; i++)
      {
        if(focus == i)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
        }
        else 
        {
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
        }
      }
      break;
    case 80:
      if (focus == n-1)
        focus = -1;
      focus++;
      for(int i = 0; i< n; i++)
      {
        if(focus == i)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Special);
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Normal);
        }
        else 
        {
          multiple_frame(x, y, width, n, i);
          gotoxy(x+ 3, y + 1 + 3*i);
          cout << ds[i];
        }
      }
      break;
    case 13:
      return focus;
      break;
    }
  }
}
void exit_menu(undergradute sv[], int amount, int x, int y);
// ============= Interface ====================
void Theme();
// ================= Menu =====================
int do_Menu_Main(undergradute sv[], int amount);
int menu_Update(undergradute sv[], int amount);
int menu_Display(undergradute sv[], int amount);
int menu_Sort(undergradute sv[], int amount);
int menu_Search(undergradute sv[], int amount);
int menu_Statistics(undergradute sv[], int n);
int sub_Menu_Select_Sort(undergradute sv[], int amount);
int sub_Menu_Quick_Sort(undergradute sv[], int amount);
// =============== Creat Menu ==================
int menu_Update(undergradute sv[], int amount)
{
  Menu Update(4, update, "UPDATE");
  switch (Update.printMenu(update, 4, 80, 10, 20))
  {
  case 0:
  {
    insertGraduate(sv, amount);
    return menu_Update(sv, amount);
    break;
  }
  case 1:
  {
    changeGraduate(sv, amount);
    return menu_Update(sv, amount);
    break;
  }
  case 2:
  {
    deleteGraduate(sv, amount);
    return menu_Update(sv, amount);
    break;
  }
  case 3:
  {
    do_Menu_Main(sv, amount);
    break;
  }
  }
}
int menu_Display(undergradute sv[], int amount)   
{
  Menu Display(3, display, "DISPLAY");
  switch (Display.printMenu(display, 3, 80, 10, 20))
  {
  case 0:
  {
    printStudent(sv, amount, 6, 5);
    getch();
    return menu_Display(sv, amount);
    break;
  }
  case 1:
  {
    writeFile(sv, amount);
    return menu_Display(sv, amount);
    break;
  }
  case 2:
  {
    do_Menu_Main(sv, amount);
    break;
  }
  }
}
int menu_Sort(undergradute sv[], int amount)
{
  Menu Sort(3, sort, "SORT");
  switch (Sort.printMenu(sort, 3, 80, 10, 20))
  {
  case 0:
  {
    sub_Menu_Select_Sort(sv, amount);
    break;
  }
  case 1:
  {
    sub_Menu_Quick_Sort(sv, amount);
    break;
  }
  case 2:
  {
    do_Menu_Main(sv, amount);
    break;
  }
  }
}
int sub_Menu_Select_Sort(undergradute sv[], int amount)
{
  Menu Select_Sort(4, elementSort, "SELECT SORT");
  switch (Select_Sort.printMenu(elementSort, 4, 80, 10, 20))
  {
  case 0:
  {
    SelectionSortName(sv, amount);
    do_Menu_Main(sv, amount);
    break;
  }
  case 1:
  {
    SelectionSortClass(sv, amount);
    do_Menu_Main(sv, amount);
    break;
  }
  case 2:
  {
    SelectionSortGradeMedium(sv, amount);
    do_Menu_Main(sv, amount);
    break;
  }
  case 3:
  {
    menu_Sort(sv, amount);
    break;
  }
  }
}
int sub_Menu_Quick_Sort(undergradute sv[], int amount)
{
  Menu Quick_Sort(4, elementSort, "Quick SORT");
  switch (Quick_Sort.printMenu(elementSort, 4, 80, 10, 20))
  {
  case 0:
  {
    QuickSortName(sv, 0, amount - 1);
    do_Menu_Main(sv, amount);
    break;
  }
  case 1:
  {
    QuickSortClass(sv, 0, amount - 1);
    do_Menu_Main(sv, amount);
    break;
  }
  case 2:
  {
    QuickSortGradeMedium(sv, 0, amount - 1);
    do_Menu_Main(sv, amount);
    break;
  }
  case 3:
  {
    menu_Sort(sv, amount);
    break;
  }
  }
}
int menu_Search(undergradute sv[], int amount)
{
  Menu Search(3, search, "SEARCH");
  switch (Search.printMenu(search, 3, 80, 10, 20))
  {
    case 0:
    {
      int x = 1;
      while(x == 1)
      {
        if(search_student(sv, amount, 5, 3)==0)
          x=0;
      }
      return menu_Search(sv, amount);
      break;
    }
    case 1:
    {
      binarySearch_ID(sv, amount);
      return menu_Search(sv, amount);
      break;
    }
    case 2:
    {
      do_Menu_Main(sv, amount);
      break;
    }
  }
}
int menu_Statistics(undergradute sv[], int amount)
{
  Menu Statistics(3, statistics, "STATISTICS");
  table_Statistics_Student(sv, amount, 40, 8);
  graphic_Statistics_Student(sv, amount, 40, 50);
  do_Menu_Main(sv, amount);
}
void exit_menu(undergradute sv[], int amount, int x, int y)
{
  int focus = 1;
    draw_Frame(x, y, 33, 6);
    gotoxy(x+3, y+1);
    cout << "Do you want to exit and save";
    gotoxy(x+6, y+2);
    cout << "changes to file ?";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    draw_Frame(x+3, y+4, 10, 1);
    gotoxy(x+6, y+5);
    cout << "YES";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            draw_Frame(x+3, y+4, 10, 1);
            gotoxy(x+6, y+5);
            cout << "YES";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            draw_Frame(x+19, y+4, 10, 1);
            gotoxy(x+23, y+5);
            cout << "NO";
            focus = 1;
            break;
        }
        case 77:
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            draw_Frame(x+3, y+4, 10, 1);
            gotoxy(x+6, y+5);
            cout << "YES";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            draw_Frame(x+19, y+4, 10, 1);
            gotoxy(x+23, y+5);
            cout << "NO";
            focus = 0;
            break;
        }
        case 13:
        {
            if(focus == 1)
            {
                writeFile(sv, amount);
                exit(0);
            }
            else
            {
                exit(0);
            }
            break;
        }
        }
    }
}
int do_Menu_Main(undergradute sv[], int amount)
{
  Menu menu_Main(6, menu, "MAIN MENU");
  switch (menu_Main.printMenu(menu, 6, 80, 10, 20))
  {
  case 0:
  {
    menu_Update(sv, amount);
    break;
  }
  case 1:
  {
    menu_Display(sv, amount);
    break;
  }
  case 2:
  {
    menu_Sort(sv, amount);
    break;
  }
  case 3:
  {
    menu_Search(sv, amount);
    break;
  }
  case 4:
  {
    menu_Statistics(sv, amount);
    break;
  }
  case 5:
  {
    exit_menu(sv, amount, 70, 29);
    break;
  }
  }
}
void Theme()
{
  resizeConsole(1500,1000);
  system("cls");
  themes();
  undergradute sv[MAX];
  int amount = readFile(sv);
  do_Menu_Main(sv, amount);
}
int main()
{
  Theme();
}