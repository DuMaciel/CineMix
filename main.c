#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define TAM 8

struct Poltrona{
    char nome[50];
    char cpf[12];
    int status;
};

struct Sala{
    char filme[20];
    struct Poltrona poltronas[TAM][TAM];
};

int menuPrincipal();
int menuReserva();
int escolha(int opcao);
int resetPoltronas(struct Poltrona poltronas[TAM][TAM]);
void printarPoltronas(struct Poltrona poltronas[TAM][TAM]);

int main()
{

    struct Sala sala1;
    resetPoltronas(sala1.poltronas);
    escolha(menuReserva());
    printarPoltronas(sala1.poltronas);
    return 0;
}


int menuPrincipal(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printf(R"EOF(--------------------------------------------------------------------------------------
|     ,ad8888ba,                                88b           d88                    |
|    d8"'    `"8b                               888b         d888                    |
|   d8'                                         88`8b       d8'88                    |
|   88             88  8b,dPPYba,    ,adPPYba,  88 `8b     d8' 88  88  8b,     ,d8   |
|   88                 88P'   `"8a  a8P_____88  88  `8b   d8'  88       `Y8, ,8P'    |
|   Y8,            88  88       88  8PP"""""""  88   `8b d8'   88  88     )888(      |
|    Y8a.    .a8P  88  88       88  "8b,   ,aa  88    `888'    88  88   ,d8" "8b,    |
|     `"Y8888Y"'   88  88       88   `"Ybbd8"'  88     `8'     88  88  8P'     `Y8   |)EOF");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n| 1 - Listar Salas                                                                   |");
    printf("\n| 2 - ?                                                                              |");
    printf("\n| 3 - ?                                                                              |");
    printf("\n| 4 - Sair                                                                           |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("\nDigite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int menuReserva(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printf(R"EOF(--------------------------------------------------------------------------------------
|     ,ad8888ba,                                88b           d88                    |
|    d8"'    `"8b                               888b         d888                    |
|   d8'                                         88`8b       d8'88                    |
|   88             88  8b,dPPYba,    ,adPPYba,  88 `8b     d8' 88  88  8b,     ,d8   |
|   88                 88P'   `"8a  a8P_____88  88  `8b   d8'  88       `Y8, ,8P'    |
|   Y8,            88  88       88  8PP"""""""  88   `8b d8'   88  88     )888(      |
|    Y8a.    .a8P  88  88       88  "8b,   ,aa  88    `888'    88  88   ,d8" "8b,    |
|     `"Y8888Y"'   88  88       88   `"Ybbd8"'  88     `8'     88  88  8P'     `Y8   |)EOF");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n| 1 - Reservar                                                                       |");
    printf("\n| 2 - Comprar                                                                        |");
    printf("\n| 3 - Cancelar                                                                       |");
    printf("\n| 4 - Sair                                                                           |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("\nDigite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int escolha(int opcao){
    switch (opcao){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 1987:
        break;
    default:
        printf("\nOpção invalida!");
    }
}

int resetPoltronas(struct Poltrona poltronas[TAM][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            poltronas[i][j].status=0;
        }
    }
    return 0;
};

void printarPoltronas(struct Poltrona poltronas[TAM][TAM]){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(poltronas[i][j].status == 0){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            fflush(stdin);
            printf("[%d][%d]  ",i+1,j+1);
            }
            if(poltronas[i][j].status == 1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            fflush(stdin);
            printf("[%d][%d]  ",i+1,j+1);
            }
            if(poltronas[i][j].status == 2){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            fflush(stdin);
            printf("[%d][%d]  ",i+1,j+1);
            }
        }
        printf("\n");
    }SetConsoleTextAttribute(hConsole, saved_attributes);
}


