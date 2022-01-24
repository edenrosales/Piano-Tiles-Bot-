// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//This program is really dumb and I want to improve it in the future. 
//The device handle is getting the entire screen and I want it to just get the specified window. This would make it so that the window can 
//be anywhere in the screen and this bot would still work. However, this is NOT the case, and the game must be on the right side of the window, 
//taking up half of the screen on that side.
//
//PLAN ON UPDATING THIS IN THE FUTURE TO BE COMPATIBLE WITH A MOVING GAME WINDOW

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
void gotoxy(int x, int y)//places the cursor at the (x,y) coordinate 
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void LeftClick() {
    INPUT iNPUT;
    iNPUT.type = INPUT_MOUSE;
    iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &iNPUT, sizeof(iNPUT));
    ZeroMemory(&iNPUT, sizeof(iNPUT));
    iNPUT.type = INPUT_MOUSE;
    iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &iNPUT, sizeof(iNPUT));
}
using namespace std; 
int main()
{
    HRGN clippingSpace = CreateRectRgn(0, 0, 1915, 1080);
    LPCSTR pianoTilesWindow ="Piano White Master!";
    HWND hWND = FindWindowA(NULL, pianoTilesWindow);
    while (1) {
        while (hWND == 0) {
            hWND = FindWindowA(NULL, pianoTilesWindow);
            cout << "start game" << endl;
        }
        if (GetAsyncKeyState(VK_NUMPAD1))//to get the cursor location
        {
            POINT p; 
            GetCursorPos(&p);
            ScreenToClient(hWND, &p);
            cout << "X Coordinate: " << p.x << " Y Coodinate: " << p.y<<endl; 
            Sleep(150);
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) {//gets the color of the cursor location 
            HDC hDC = GetDC(NULL);
            POINT p; 
            GetCursorPos(&p);
            COLORREF color = GetPixel(hDC, p.x, p.y);
            ReleaseDC(NULL, hDC);
            cout << "X Coordinate: " << p.x << " Y Coodinate: " << p.y<<endl; 
            cout << "Color: " << color << endl;
            cout << "Red: " << (int)GetRValue(color) << "| Green: " << (int)GetGValue(color) << "| Blue: " << (int)GetBValue(color) << endl;
            Sleep(150);
        }
        if (GetAsyncKeyState(VK_NUMPAD3)) {//starts the bot 
            HDC hDC = GetDC(NULL);
            while (1) {
                if (GetAsyncKeyState(VK_NUMPAD0)) {//exits 
                    ReleaseDC(NULL, hDC);
                    break;
                }
                COLORREF col1 = GetPixel(hDC, 1182, 590);
                COLORREF col2 = GetPixel(hDC, 1343, 590);
                COLORREF col3 = GetPixel(hDC, 1506, 590);
                COLORREF col4 = GetPixel(hDC, 1671, 590);
                if (((int)GetRValue(col1) == 59) && ((int)GetGValue(col1) == 56) && ((int)GetBValue(col1) == 63)) {
                    cout << "Simulating mouse input on column 1"<<endl;
                    SetCursorPos(1182, 590);
                    /*MoveToEx(hDC, 1182, 590,NULL);*/
                    LeftClick();
                    /*Sleep(50);*/
                }
                if (((int)GetRValue(col2) == 59) && ((int)GetGValue(col2) == 56) && ((int)GetBValue(col2) == 63)) {
                    cout << "Simulating mouse input on column 2" << endl;
                    SetCursorPos(1343, 590);
                    /*MoveToEx(hDC, 1343, 590, NULL);*/
                    LeftClick();
                    /*Sleep(50);*/
                }
                if (((int)GetRValue(col3) == 59) && ((int)GetGValue(col3) == 56) && ((int)GetBValue(col3) == 63)) {
                    cout << "Simulating mouse input on column 3" << endl;
                    SetCursorPos(1506, 590);
                    /*MoveToEx(hDC, 1506, 590, NULL);*/
                    LeftClick();
                    /*Sleep(50);*/
                }
                if (((int)GetRValue(col4) == 59) && ((int)GetGValue(col4) == 56) && ((int)GetBValue(col4) == 63)) {
                    cout << "Simulating mouse input on column 4" << endl;
                    SetCursorPos(1671, 590);
                    /*MoveToEx(hDC, 1671, 590, NULL);*/
                    LeftClick();
                   /* Sleep(50);*/
                }
            }
        }
        if (GetAsyncKeyState(VK_NUMPAD7)) {
            HDC hDC = GetDC(0);
            MoveToEx(hDC, 693, 635, NULL);
            LeftClick();
            ReleaseDC(hWND, hDC);
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_NUMPAD0)) {//exits 
            exit(0);
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
