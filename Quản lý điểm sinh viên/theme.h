#ifndef theme_h
#define theme_h
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include "draw.h"
using namespace std;

void themes()
{
    gotoxy(80, 1);
    cout << "HOC VIEN KY THUAT QUAN SU" << endl;
    gotoxy(80, 2);
    cout << "KHOA CONG NGHE THONG TIN" << endl;
    gotoxy(40, 13);
    cout << " _________  _    _  _    _   _____     _________     _      ______      _____  __     _   _________  _________  " << endl;
    gotoxy(40,14);
    cout << "|___   ___|| |  | || |  | | / ____|   |___   ___|   / \\    |  ___ \\    / ____||  \\   | | |___   ___||___   ___| " << endl;
    gotoxy(40,15);
    cout << "    | |    | |__| || |  | || |            | |      / _ \\   |  |__) |  | |     | |\\\\  | |     | |        | |     " << endl;
    gotoxy(40,16);
    cout << "    | |    |  __  || |  | || |            | |     / __  \\  |  ____/   | |     | | \\\\ | |     | |        | |     " << endl;
    gotoxy(40,17);
    cout << "    | |    | |  | || |__| || |____        | |    / /  \\  \\ | |        | |____ | |  \\\\| |     | |        | |     " << endl;
    gotoxy(40,18);
    cout << "    |_|    |_|  |_|\\_____/  \\_____|       |_|   /_/    \\__\\|_|         \\_____||_|   \\__|     |_|        |_|     " << endl;
    
    gotoxy(30, 20);
    cout << "                                                                                   *                                                   **         " << endl;
    gotoxy(30, 21);
    cout << " 88888    888888   88888888   888    88                                          *                                                    *  *        " << endl;
    gotoxy(30, 22);
    cout << " 88   88  88          88     88 88   88  0  ***    **   **    * *   *     ****   **    *** *   *    ****  * **   * *   *   *      * * **** **   * "  << endl;
    gotoxy(30, 23);
    cout << "8888   88 888888      88    88   88  88     *  *  *  *  *  *  * *****     *     *  *  *    *****    *     * * *  * *****    *    *  * **** * *  * " << endl;
    gotoxy(30, 24);
    cout << " 88   88  88          88   888888888 88  0  *  * * ** * *   * * *   *       *  * ** * *    *   *      *   * *  * * *   *     *  *   * *    *  * * " << endl;
    gotoxy(30, 25);
    cout << " 88888    888888      88   88     88 88     ***  *    * *    ** *   *     **** *    *  *** *   *    ***** * *   ** *   *      **    * **** *   ** " << endl;

    gotoxy(75, 27);
    cout << "GIAO VIEN PHU TRACH: Tong Minh Duc" << endl;
    gotoxy(110, 35);
    cout << "HOC VIEN: Duong Dinh Nhat Linh" << endl;
    gotoxy(110, 36);
    cout << "LOP     : An Ninh He Thong Thong Tin" << endl;
    gotoxy(110, 37);
    cout << "DON VI  : C156 " << endl;
    gotoxy(80, 40);
    cout << "Enter to continue ==>> " << endl;
    getch();
}
#endif
