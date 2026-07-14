#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
// legendas de cores pra facilitar minha vida
#define PRETO 0
#define AZUL_ESCURO 1
#define VERDE_ESCURO 2
#define CIANO_ESCURO 3
#define VERMELHO_ESCURO 4
#define ROXO 5
#define AMARELO_ESCURO 6
#define PADRAO 7
#define CINZA_ESCURO 8
#define AZUL_CLARO 9
#define VERDE_CLARO 10
#define CIANO_CLARO 11
#define VERMELHO_CLARO 12
#define ROSA_MAGENTA 13
#define AMARELO_CLARO 14 
#define BRANCO 15

// A função gotoxy serve para posicionar o cursor do terminal na coluna x e linha y permitindo mudar o local onde os printf vão ocorrer
void gotoxy(int x, int y) {
    if( x>=0 && y>=0){
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}
void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    srand(time(NULL));
    int onda= 1;
    int coordX[26];
    int coordY[26];
    char palavras[26][50];
    int controle=0;
    FILE *dicio;
    dicio= fopen("dicionario.txt", "r");
    if (dicio==NULL){
        printf("erro dicionario aberto incorretamente");
        return 1;
    }
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(h, &info);
        int x= (info.dwSize.X)/2; 
        int y =(info.dwSize.Y)/2;
    while (1)
    {
        int tempo= clock();
        tempo=tempo/CLOCKS_PER_SEC;
        // função de esclher palavras e coloca-las no char
       for (int i=0; i<3; i++){
            gotoxy(x,y);
            textcolor(VERMELHO_CLARO);
            printf("ONDA %d", onda);
            Sleep(500);
            gotoxy(x,y);
            textcolor(VERMELHO_CLARO);
            printf("onda %d", onda);
            Sleep(500);
    }
        textcolor(PADRAO);
        gotoxy(x,y);
        printf("                                     ");
        /*coordX[controle]=rand()/(x*2-strlen(palavras[controle]));
        coordY[controle]=0;*/
    
    }
    
    
}
