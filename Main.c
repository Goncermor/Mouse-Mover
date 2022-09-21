#include <stdio.h>
#include <windows.h>

POINT Point;
POINT DefaultPoint;

void clearconsole() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}


int main() {
    HWND STD_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
    clearconsole();
    SetConsoleTextAttribute(STD_HANDLE, 11);
    printf("    ______\n   / ____/___  ____  ________  _________ ___  ____  _____\n  / / __/ __ \\/ __ \\/ ___/ _ \\/ ___/ __ `__ \\/ __ \\/ ___/\n / /_/ / /_/ / / / / /__/  __/ /  / / / / / / /_/ / /\n \\____/\\____/_/ /_/\\___/\\___/_/  /_/ /_/ /_/\\____/_/\n\n");
    SetConsoleTextAttribute(STD_HANDLE, 15);
    printf("  Goncermor Mouse Mover V1\n\n");
    for (int  i = 0; i < 4; i++) {
        printf("  Starting in %d", i);
        Sleep(1000);
        gotoxy(0,8);
    }
    GetCursorPos(&Point);
    GetCursorPos(&DefaultPoint);
    while (1) {
        for (int  i = 0; i < 100; i += 5) {
             Point.x = DefaultPoint.x + i;
             Point.y = DefaultPoint.y + i;
             SetCursorPos(Point.x ,Point.y);
             gotoxy(0,8);
            printf("  Current Loc: X = %d, Y = %d", Point.x, Point.y);
             Sleep(20);
        }
         Sleep(1000);
        for (int  i = 0; i < 100; i += 2) {
            Point.x = DefaultPoint.x - i;
            Point.y = DefaultPoint.y - i;
            SetCursorPos(Point.x ,Point.y);
            gotoxy(0,8);
            printf("  Current Loc: X = %d, Y = %d", Point.x, Point.y);
            Sleep(20);
        }
    }
    return 0;
}


