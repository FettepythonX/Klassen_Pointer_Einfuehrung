#include "cursorpos.h"
void set_cursor(size_t y, size_t x)
{
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    csbiInfo.dwCursorPosition.X=x;
    csbiInfo.dwCursorPosition.Y=y;
    SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}