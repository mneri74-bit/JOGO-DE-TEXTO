#include <stdio.h>
#include <conio.h>
#include <windows.h>


// Função para posicionar o cursor (substitui gotoxy)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

