#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

// Legendas de cores
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

// Dicionário
static const char *palavras_dicio[] = {
     "abelha", "amigo", "arvore", "brisa", "cachorro", "caneta",
    "carro", "chuva", "cidade", "coelho", "coragem", "cristal",
    "diamante", "espelho", "estrela", "familia", "fantasma", "floresta",
    "foguete", "girassol", "guitarra", "janela", "joaninha", "labirinto",
    "lanterna", "leitura", "liberdade", "montanha", "musica", "natureza",
    "neblina", "oceano", "pagina", "pantera", "parede", "passaro",
    "pintura", "planeta", "ponte", "portal", "quintal", "relogio",
    "riacho", "sabedoria", "sombra", "tempestade", "trovao", "universo",
    "vagalume", "viagem", "vitoria", "abraco", "aldeia", "alegria",
    "almoco", "aluno", "amizade", "aranha", "arauto", "areia",
    "armario", "aroma", "aventura", "balanco", "baleia", "banana",
    "bandeira", "barraca", "batalha", "beleza", "biblioteca", "bicicleta",
    "bolota", "bombom", "bondade", "bosque", "cachoeira", "calmaria",
    "camelo", "campeao", "canario", "caracol", "cardume", "carinho",
    "carruagem", "castelo", "caverna", "cavalaria", "cerejeira", "chamine",
    "charuto", "chocolate", "ciclone", "cinema", "circo", "clareira",
    "colcha", "colheita", "coluna", "cometa", "confianca", "coragem",
    "cortina", "costela", "coruja", "criatura", "crianca", "delicia",
    "desafio", "desenho", "destino", "dinheiro", "docura", "dragao",
    "duende", "elefante", "energia", "escola", "esconderijo", "esperanca",
    "espinho", "esqueleto", "esquilo", "estatua", "estufa", "faisca",
    "fazenda", "feiticeiro", "ferradura", "figueira", "fivela", "flauta",
    "flamingo", "fogueira", "folclore", "fonte", "formiga", "fortuna",
    "fragata", "fronteira", "fumaca", "garagem", "girafa", "gruta",
    "guardiao", "harmonia", "heroi", "horizonte", "hospital", "iceberg",
    "iguaria", "ilhota", "imagem", "impulso", "insetos", "jaqueta",
    "jardim", "jasmim", "joelho", "jornada", "labareda", "lagarto",
    "lamparina", "lavanda", "legenda", "lenda", "libelula", "limonada",
    "lousa", "luneta", "macaco", "madeira", "magia", "mandala",
    "manteiga", "maquina", "mariposa", "marfim", "melancia", "memoria",
    "mercado", "milagre", "minhoca", "misterio", "moedas", "moinho",
    "molecula", "monstro", "morango", "mosteiro", "muralha", "musgo",
    "nascente", "nevasca", "noivado", "nublado", "nuvem", "orbita",
    "orquestra", "ostra", "outono", "paisagem", "palacio", "palhaco",
    "pandeiro", "pantano", "papagaio", "paraiso", "parquinho", "passeio",
    "penhasco", "pergaminho", "pescador", "petala", "pipoca", "piquenique",
    "pirata", "poeira", "prateleira", "presente", "principe", "quintal",
    "raposa", "raiz", "raridade", "recanto", "refugio", "relampago",
    "resgate", "riacho", "riqueza", "robozinho", "rocha", "romance",
    "sacola", "saudade", "sepultura", "serpente", "silencio", "sirene",
    "soalho", "sotao", "surpresa", "tapecaria", "tartaruga", "tempero",
    "templo", "tesouro", "tigela", "torneira", "tornado", "torrada",
    "tradicao", "trenzinho", "trilha", "tulipa", "vagalume", "vampiro",
    "vantagem", "varanda", "veleiro", "verniz", "vidraca", "vinheta",
    "violino", "vulcao", "xicara", "zoologico","abobora", "acontecimento",
    "aeronave", "arquitetura", "astronauta", "borboleta","civilizacao",
    "computador", "conhecimento", "constelacao", "descoberta", "eletricidade",
    "engenharia", "experiencia", "felicidade", "gravidade", "imaginacao", "independencia",
    "labirintico", "matematica", "meteorito", "microscopio", "observatorio", "oportunidade",
    "paralelepipedo", "quantidade", "responsabilidade", "revolucao", "tecnologia", "telescopio",
    "transformacao", "tranquilidade", "universidade", "velocidade", "extraterrestre", "hipopotamo",
    "impossivel", "invisibilidade", "acompanhamento", "administracao", "agradecimento", "alfabetizacao",
    "aniversario", "aposentadoria", "aprendizagem", "arrependimento", "articulacao", "assombracao",
    "atmosfera", "automovel", "biblioteca", "brincadeira", "burocracia", "caracteristica",
    "cerimonia", "circunstancia", "coincidencia", "colaboracao", "comemoracao", "competicao",
    "comunidade", "concentracao", "confirmacao", "consciencia", "consequencia", "constituicao",
    "contabilidade", "contribuicao", "coordenacao", "criatividade", "curiosidade", "declaracao",
    "demonstracao", "desenvolvimento", "diversidade", "dificuldade", "eletromagnetico", "eliminacao",
    "emocionante", "espetaculo", "estabilidade", "estrategico", "exclamacao", "explicacao",
    "extraordinario", "fenomeno", "fortalecimento", "fotografia", "generosidade", "governanca",
    "identidade", "iluminacao", "imunologia", "inaugurar", "inesquecivel", "informacao",
    "inteligencia", "interpretacao", "investigacao", "linguistica", "maravilhoso", "mecanismo",
    "microorganismo", "multiplicacao", "necessidade", "negociacao", "observacao", "organizacao",
    "paleontologo", "participacao", "personagem", "planejamento", "populacao", "possibilidade",
    "preservacao", "probabilidade", "processamento", "profissional", "protagonista", "publicacao",
    "qualificacao", "reciclagem", "reconhecimento", "recuperacao", "representacao", "reproducao",
    "significado", "simplicidade", "sinceridade", "sofisticado", "sustentavel", "temperatura",
    "transparencia", "vulnerabilidade",
};
#define NUM_PALAVRAS (sizeof(palavras_dicio) / sizeof(palavras_dicio[0]))

int gotoxy(int x, int y) {
    if(x >= 0 && y >= 0){
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

void esconder_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Só isso já tira o "piscar", o tamanho não importa
    SetConsoleCursorInfo(h, &cursorInfo);
}


int calcula_quantidade(int onda) {
    int quantidade = onda;
    if (quantidade > (int)NUM_PALAVRAS) quantidade = NUM_PALAVRAS;
    if (quantidade > 26) quantidade = 26;
    return quantidade;
}

void sorteio_palavras(int onda, char palavras[][50]) {
    int usado[NUM_PALAVRAS] = {0};
    int letra_usada[26] = {0}; 
    int quantidade = calcula_quantidade(onda);

    for (int i = 0; i < quantidade; i++) {
        int indice;
        int tentativas = 0;
        int limite_tentativas = NUM_PALAVRAS * 5;

        do {
            indice = rand() % NUM_PALAVRAS;
            tentativas++;
        } while ((usado[indice] || letra_usada[palavras_dicio[indice][0] - 'a']) && tentativas < limite_tentativas);

        if (usado[indice] || letra_usada[palavras_dicio[indice][0] - 'a']) {
            int achou = 0;
            for (int j = 0; j < (int)NUM_PALAVRAS; j++) {
                if (!usado[j] && !letra_usada[palavras_dicio[j][0] - 'a']) {
                    indice = j;
                    achou = 1;
                    break;
                }
            }
            if (!achou) break;
        }

        usado[indice] = 1;
        letra_usada[palavras_dicio[indice][0] - 'a'] = 1;
        strcpy(palavras[i], palavras_dicio[indice]);
    }
}

// Configura o início da onda
void setup(int onda, int x[], int y[], char matriz[26][50], int meiox, int meioy) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);

    // Limpa a tela para a nova onda
    system("cls");

    // Limpa a matriz inteira primeiro
    for(int i = 0; i < 26; i++){
        strcpy(matriz[i], "");
    }

    // Sorteia as palavras da onda
    sorteio_palavras(onda, matriz);

    int quantidade = calcula_quantidade(onda);

    // Define posições aleatórias
    for(int i = 0; i < quantidade; i++) {
        int colisao;
        do {
            colisao = 0;
            y[i] = -(rand() % 10); // Começam fora da tela, em cimaa
            x[i] = rand() % (info.dwSize.X - strlen(matriz[i]) - 1);

            for (int j = 0; j < i; j++) {
                if (y[i] == y[j] && x[i] < (x[j] + strlen(matriz[j]) + 3) && x[j] < (x[i] + strlen(matriz[i]) + 3)) {
                    colisao = 1;
                    break;
                }
            }
        } while (colisao);
    }

    // Animação de Nova Onda
    for (int i = 0; i < 3; i++) {
        gotoxy(meiox - 3, meioy);
        textcolor(VERMELHO_ESCURO);
        printf("ONDA %d", onda);
        Sleep(400);

        gotoxy(meiox - 3, meioy);
        textcolor(VERMELHO_CLARO);
        printf("onda %d", onda);
        Sleep(400);
    }
    textcolor(PADRAO);
    gotoxy(meiox - 3, meioy);
    printf("       "); // Apaga o texto da onda
}

void placar(int display, int score, int onda, int vidas) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);

    gotoxy(0, info.dwSize.Y - 3);
    textcolor(VERMELHO_CLARO);

    if (display) {
        for (int i = 0; i < info.dwSize.X; i++) {
            printf("#");
        }
    }

    gotoxy(0, info.dwSize.Y - 2);
    printf("score: %d     ", score); // Espaços extras para limpar rastros antigos

    gotoxy(info.dwSize.X / 2 - 4, info.dwSize.Y - 2);
    printf("onda %d  ", onda);

    gotoxy(info.dwSize.X - 15, info.dwSize.Y - 2);
    printf("vidas");

    gotoxy(info.dwSize.X - 15, info.dwSize.Y - 1);
    for (int i = 0; i < 3; i++) {
        if(i < vidas) printf("<3 ");
        else printf("   "); // Apaga corações perdidos
    }
    textcolor(PADRAO);
}

void dano(int alvo, int x[], int y[], int score, int onda, int vidas, char palavras[26][50]) {
    // Pisca a tela em vermelho
    for (int i = 0; i < 2; i++) {
        system("color 44");
        Sleep(100);
        system("color 07"); // Volta ao normal
        Sleep(100);
    }
    system("color 07");

    system("cls"); // Força atualização da tela

    int quantidade = calcula_quantidade(onda);

    // Redesenha as palavras restantes
    for (int controle = 0; controle < quantidade; controle++) {
        if(strlen(palavras[controle]) > 0 && y[controle] >= 0){
            gotoxy(x[controle], y[controle]);
            if (alvo == controle) { textcolor(AMARELO_CLARO); }
            printf("%s", palavras[controle]);
            textcolor(PADRAO);
        }
    }
    placar(1, score, onda, vidas);
}

// Controla a velocidade das palavras. Quanto menor o retorno, mais rápido.
double intervalo(int onda) {
    double velocidade = 1.0 - (onda * 0.05); // Começa lento e acelera
    if (velocidade < 0.15) { return 0.15; }  // Limite máximo de velocidade
    return velocidade;
}

int main() {
SetConsoleOutputCP(65001);
esconder_cursor(); // Remove o piscar do cursor durante o jogo, sem afetar gotoxy
char opcao;
while(1){
system("cls");

printf(
    "███████╗ ███████╗  ██████╗██████╗ ███████╗██╗   ██╗  █████╗      ██████╗██╗\n"
    "██╔════╝ ██╔════╝ ██╔════╝██╔══██╗██╔════╝██║   ██║ ██╔══██╗    ██╔════╝██║\n"
    "█████╗   ███████╗ ██║     ██████╔╝█████╗  ██║   ██║ ███████║    ██║     ██║\n"
    "██╔══╝   ╚════██║ ██║     ██╔══██╗██╔══╝  ╚██╗ ██╔╝ ██╔══██║    ██║     ██║\n"
    "███████╗ ███████║ ╚██████╗██║  ██║███████╗ ╚████╔╝  ██║  ██║    ╚██████╗██║\n"
    "╚══════╝ ╚══════╝  ╚═════╝╚═╝  ╚═╝╚══════╝  ╚═══╝   ╚═╝  ╚═╝     ╚═════╝╚═╝\n"
    );
    printf("JOGAR - 1\n"
           "SAIR  - 2\n"
           );
    opcao=getch();
switch (opcao){

   case '1':
    //codigo do jogo
    system("cls");
    srand(time(NULL));
    char input;
    int alvo = -1; // -1 significa "Nenhum alvo selecionado"
    int letra = 0; // Começa da letra 0
    int score = 0;
    int vidas = 3;
    char palavras[26][50];
    unsigned onda = 1;
    double tempo;
    double timer = 0;
    int coordX[26];
    int coordY[26];
    int controle = 0;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);
    int x = (info.dwSize.X) / 2;
    int y = (info.dwSize.Y) / 2;

    int voltarmenu = 0;

    system("cls");


    while(vidas > 0) {
        setup(onda, coordX, coordY, palavras, x, y);
        placar(1, score, onda, vidas);

        tempo = (double)clock() / CLOCKS_PER_SEC;
        timer = tempo;

        int quantidade = calcula_quantidade(onda);

        while (1) {
            placar(0, score, onda, vidas);
            tempo = (double)clock() / CLOCKS_PER_SEC;

            // LÓGICA DE QUEDA DAS PALAVRAS
            if ((tempo - timer) > intervalo(onda)) {
                timer = tempo;

for (controle = 0; controle < quantidade; controle++) {

    // Se a palavra já foi destruída, ignora
    if (strlen(palavras[controle]) == 0) {
        continue;
    }

    // Verifica se ainda pode cair
    if (coordY[controle] < info.dwSize.Y - 3) {

        // Apaga a palavra na posição antiga
        if (coordY[controle] >= 0) {
            gotoxy(coordX[controle], coordY[controle]);

            for (int i = 0; i < strlen(palavras[controle]); i++) {
                printf(" ");
            }
        }

        // Move a palavra para baixo
        coordY[controle]++;

        // Desenha na nova posição
        if (coordY[controle] >= 0 && coordY[controle] < info.dwSize.Y - 3) {

            gotoxy(coordX[controle], coordY[controle]);

            if (alvo == controle) {
                textcolor(AMARELO_CLARO);
            }

            printf("%s", palavras[controle]);
            textcolor(PADRAO);
        }

    } else {

    // A palavra chegou ao final da tela
    vidas--;

    // Remove a palavra
    strcpy(palavras[controle], "");

    // Se era o alvo atual, cancela o alvo
    if (alvo == controle) {
        alvo = -1;
        letra = 0;
    }

    // Atualiza a tela mostrando o dano
    dano(alvo, coordX, coordY, score, onda, vidas, palavras);

    // Se acabou as vidas, encerra
    if (vidas <= 0) {
        break;
    }

    // VERIFICA SE TODAS AS PALAVRAS ACABARAM
    int palavras_restantes = 0;

    for (int i = 0; i < quantidade; i++) {
        if (strlen(palavras[i]) > 0) {
            palavras_restantes++;
        }
    }

    // Se nenhuma palavra restou, passa de onda
    if (palavras_restantes == 0) {
        alvo = -2;
        break;
    }
}
}
}
            if(vidas <= 0) break; // Sai do while(1) se morreu

            // LÓGICA DE DIGITAÇÃO (TIROS)
            if (kbhit()) {
                input = getch();

                if (input == 27) {
                    // Aqui você pode colocar uma tela de pause depois
                    system("cls");
                    int pause = 1;
                     while(pause==1){
                             char opcao;

                      printf(   "██████╗  █████╗ ██╗   ██╗███████╗███████╗\n"
                                "██╔══██╗██╔══██╗██║   ██║██╔════╝██╔════╝\n"
                                "██████╔ ███████║██║   ██║███████╗█████╗\n"
                                "██╔═══╝ ██╔══██║██║   ██║╚════██║██╔══╝\n"
                                "██║     ██║  ██║╚██████╔╝███████║███████╗\n"
                                "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝\n"
                                );

                                 printf("CONTINUAR - 1\n"
                                        "SAIR   - 0\n");
                                 opcao=getch();
                                   switch (opcao){
                                     case '1':
                                      pause = 0;
                                      system("cls");
                                      placar(1, score, onda, vidas);
                                      for (int i = 0; i < quantidade; i++) {
                                        if (strlen(palavras[i]) > 0 && coordY[i] >= 0 && coordY[i] < info.dwSize.Y - 3) {
                                        gotoxy(coordX[i], coordY[i]);
                                        if (alvo == i) { textcolor(AMARELO_CLARO); }
                                        printf("%s", palavras[i]);
                                        textcolor(PADRAO);
     }
 }

                                      break;
                                     case '0':
                                      alvo = -3;
                                      pause = 0;
                                      break;
  }
}
                }

                if (alvo == -1) {
                    // PROCURANDO ALVO (Checa a primeira letra)
                    for (controle = 0; controle < quantidade; controle++) {
                        if (strlen(palavras[controle]) > 0 && coordY[controle] >= 0) {
                            if (input == palavras[controle][0]) {
                                // Apaga a primeiraa letra visualmente
                                // Apaga a primeira letra visualmente
                                gotoxy(coordX[controle], coordY[controle]);
                                printf(" ");
                                palavras[controle][0] = ' ';
                                alvo = controle;
                                letra = 1;
                                break;
                            }
                        }
                    }
                } else {
                    // ATIRANDO NO ALVO ATUAL (Checa as próximas letras)
                    if (input == palavras[alvo][letra]) {
                        // Apaga a letra que acabou de acertar
                        gotoxy(coordX[alvo] + letra, coordY[alvo]);
                        printf(" ");
                        palavras[alvo][letra] = ' ';
                        letra++;

                        // Se completou a palavra
                        if (letra == strlen(palavras[alvo])) {
                            // Apaga o rastro dela na tela
                            gotoxy(coordX[alvo], coordY[alvo]);
                            for(int i = 0; i < letra; i++) { printf(" "); }

                            strcpy(palavras[alvo], ""); // Destrói a palavra
                            alvo = -1;
                            letra = 0;
                            score += (10 * strlen(palavras_dicio[0])); // Ganha pontos

                            // Checa se passou de onda
                            int palavras_restantes = 0;
                            for (int i = 0; i < quantidade; i++) {
                                if (strlen(palavras[i]) > 0) {
                                    palavras_restantes++;
                                }
                            }
                            if (palavras_restantes == 0) {
                                alvo = -2; // Sinal de passar de onda
                            }
                        }
                    }
                }
            }

            // Se o sinal de passar de onda foi ativado
            if (alvo == -2) {
                onda++;
                alvo = -1;
                letra = 0;
                break; // Sai do while(1) e recomeça a próxima onda no setup
            }
            if (alvo == -3) {
                voltarmenu = 1;
                break;
            }
        }
        if (voltarmenu)
            break;
    }
   if(!voltarmenu){
    // TELA DE GAME OVER
    system("cls");
    gotoxy(info.dwSize.X / 2 - 5, info.dwSize.Y / 2);
    textcolor(VERMELHO_CLARO);
    printf("GAME OVER");
    textcolor(PADRAO);

    gotoxy(info.dwSize.X / 2 - 10, info.dwSize.Y / 2 + 1);
    printf("SCORE FINAL: %d", score);

    gotoxy(info.dwSize.X / 2 - 15, info.dwSize.Y / 2 + 3);
    printf("Pressione qualquer tecla para sair...");

    getch();
    }
      break;
   case '2':
      return 0;
      break;
   default:

       printf("opção invalida");
       break;

}
}
    return 0;
}
