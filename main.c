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
int resetPoltronas(struct Poltronas);

int main()
{
    menuPrincipal();
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
    scanf("%d",opcao);
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
    scanf("%d",opcao);
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
    }
}

/*int resetPoltronas(struct Poltrona){
    for(int i=0; i<TAM; i++){
        for(int j; j<TAM; j++){
            poltronas[i][j]=0;
        }
    }
    return 0;
};
*/
