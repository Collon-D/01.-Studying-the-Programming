#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/* Declare the const variable */
#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77
#define ESC   27

int x = 0, y = 0;

enum CURSORTYPE { NOCURSOR, NORMALCURSOR, SOLIDCURSOR };

/* -------------------------- */



/* Declare the function */

void gotoxy(int x, int y);                              // Set console cursor position.
void SetConsoleCursorType(enum CURSORTYPE c);           // Set console cursor type.
void Movement(int _nkey);                                        // if you press Arrow keys, then Player move.

/* -------------------- */

int main(void)
{
    return 0;
}

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleCursorType(enum CURSORTYPE c)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    switch(c) {
    case(NOCURSOR):
        cursorInfo.bVisible = FALSE;
        cursorInfo.dwSize = 1;
        break;
    case(NORMALCURSOR):
        cursorInfo.bVisible = TRUE;
        cursorInfo.dwSize = 20;
        break;
    case(SOLIDCURSOR):
        cursorInfo.bVisible = TRUE;
        cursorInfo.dwSize = 100;
        break;
    }

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Movement(int _nkey)
{
    if (_kbhit()) {
        gotoxy(x, y);
        printf(" ");

        switch(_nkey) {
        case(UP):
            if (y > 0) {
                y--;
                break;
            }
        case(DOWN):
            if (y < 24) {
                y++;
                break;
            }
        case(LEFT):
            if (x > 0) {
                x--;
                break;
            }
        case(RIGHT):
            if (x < 80) {
                x++;
                break;
            }
        }
        gotoxy(x, y);
        printf("@");
    }
}

