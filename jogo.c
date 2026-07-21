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
//legenda do vetor dificuldade
#define quantidade 0
#define intervalo 1

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
        //colocar função de escolher palavra não é um erro notebook lm
        y[i]=-(rand()%10);
        x[i]=rand()%info.dwSize.X;
        for (int j=0; j<i;j++){
            if(y[i] == y[j] && x[i] < (x[j] + strlen(matriz[j]) + 1) && x[j] < (x[i] + strlen(matriz[i]) + 1)){
                //há colizão e o programa tenta resolver
                while (y[i] == y[j] && x[i] < (x[j] + strlen(matriz[j]) + 1) && x[j] < (x[i] + strlen(matriz[i]) + 1) ){
                    if(x[i]<=0){
                        x[i]--;
                    }else{y[i]--;x[i]=info.dwSize.X-strlen(matriz[i]);j=-1;}
                }
                
            }
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
    unsigned tempo;
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
    while(vidas>0){
        setup(onda, coordX, coordY, palavras, x, y);
        placar(0, score, onda,vidas);
        tempo= clock();
        tempo=tempo/CLOCKS_PER_SEC;
        while (1){
            placar(0, score, onda, vidas);
            tempo= clock();
            tempo=tempo/CLOCKS_PER_SEC;
            setup(onda, coordX, coordY, palavras, x, y);
            //display
            if((tempo-timer)> 1){
            for (controle=0; controle<26; controle++){
                timer= tempo;
                if(coordY[controle]<info.dwSize.Y-3){
                    if (gotoxy(coordX[controle], coordY[controle]-1)== 0){
                        if (alvo==controle){textcolor(AMARELO_CLARO);}
                        for (int i=0; i<strlen(palavras[controle]); i++){printf(" ");}
                        gotoxy(coordX[controle], coordY[controle]);
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
                    if (input == 27) {
                        //tela de pause
                    }
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
                            for (int i=0; i<26; i++){
                                int cont=0;
                                if (palavras[i][0]== ' ' || palavras[i][0]=='#' ){
                                    cont++;
                                }if (cont==25){
                                alvo=-2;}
                            }
                        }
                    }
                }
                
            }
        if (alvo=-2){
            onda++;
            break;
            }
        }if (alvo=-3){
            break;
            }
    }
}
