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
int gotoxy(int x, int y) {
    if( x>=0 && y>=0){
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        return 0;
    }
    return 1;
}
void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setup(int onda,int x[], int y[], char matriz[26][50], int meiox, int meioy){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(h, &info);
    for(int i=0; i<26; i++){
        strcpy(matriz[i],"#");
        x[i]=rand()%info.dwSize.X;
        y[i]=rand()/*não sei como colocar isso*/;
        if (x[i]){

        }
    }

        for (int i=0; i<3; i++){
        gotoxy(meiox, meioy);
        textcolor(VERMELHO_ESCURO);
        printf("ONDA %d", onda);
        Sleep(500);
        gotoxy(meiox, meioy);
        textcolor(VERMELHO_CLARO);
        printf("onda %d", onda);
        Sleep(500);
        }
        textcolor(PADRAO);
        gotoxy(meiox, meioy);
            printf("       ");
}
//<3 
void placar(int display, int score, int onda, int vidas){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(h, &info); 
    gotoxy(0, info.dwSize.Y-3);
    textcolor(VERMELHO_CLARO);
    if (display){
        for (int i=0; i<info.dwSize.X; i++){
            printf("#");}}
    gotoxy(0, info.dwSize.Y-2);
    printf("score: %d", score);
    gotoxy(info.dwSize.X/2, info.dwSize.Y-2);
    printf("onda %d", onda);
    gotoxy(info.dwSize.X-8, info.dwSize.Y-2);
    printf("vidas");
    gotoxy(info.dwSize.X-10, info.dwSize.Y-1);
    for (int i=0; i<vidas; i++){
        printf("<3 ");
    }
    textcolor(PADRAO);
}

void dano(int alvo, int x[], int y[], int score, int onda, int vidas, char palavras[26][50]){
    int controle=0;
    for (int i=0; i<2;i++){
        system("color 44");
        Sleep(100);
        system("color CC");
        Sleep(100);
        system("color FF");
        Sleep(100);}
    system("color 07");
    for (controle; controle<26; controle++){
         if (gotoxy(x[controle], y[controle])== 0){
            if (alvo==controle){textcolor(AMARELO_CLARO);}
                printf("%s", palavras[controle]);
                textcolor(PADRAO);}
    }
    placar(1, score, onda, vidas);
}



int main() {
    srand(time(NULL));
    char input;
    int alvo=0; int letra=1; int score=0; int vidas=3;
    char palavras[26][50];
    unsigned onda= 1, timer=0;
    int coordX[26];
    int coordY[26];
    int controle=0;
    /*FILE *dicio;
    dicio= fopen("dicionario.txt", "r");
    if (dicio==NULL){
        printf("erro dicionario aberto incorretamente");
        return 1;
    }
    fclose(dicio);*/
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(h, &info);
        int x= (info.dwSize.X)/2; 
        int y =(info.dwSize.Y)/2;
    placar(1, score, onda, vidas);
        while (1){
            placar(0, score, onda, vidas);
            unsigned tempo= clock();
            tempo=tempo/CLOCKS_PER_SEC;
            setup(onda, coordX, coordY, palavras, x, y);
            //display
            if((tempo-timer)> 1){
                
            for (controle=0; controle<26; controle++){
                timer= tempo;
                if(coordY[controle]<info.dwSize.Y-3){
                    if (gotoxy(coordX[controle], coordY[controle])== 0){
                        if (alvo==controle){textcolor(AMARELO_CLARO);}
                        printf("%s", palavras[controle]);
                        textcolor(PADRAO);} 
                    coordY[controle]++;
                }else{
                    vidas--;
                    strcpy(palavras[controle], "");
                    dano(alvo, coordX,coordY, score, onda, vidas, palavras);
                }
                    
                }   
            }  
            //escrever palavras
            if(kbhit()){
                input=getch();
                if (alvo!=-1){
                    controle=0;
                    while (palavras[controle][0]!='#'){
                    if (input==palavras[controle][0]){
                        palavras[controle][0]= ' ';
                        alvo= controle;
                        break;
                    }
                    controle++;
                }
                }else {
                    if (input==palavras[alvo][letra]){
                        palavras[alvo][letra]=' ';
                        letra++;
                        if (letra<strlen(palavras[alvo])){
                            alvo=-1;
                            letra=1;
                            score += (10*strlen(palavras[alvo]));
                        }
                    }
                }
                
            }
    }
}
