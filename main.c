#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define TAM 8

struct Poltrona{
    char nome[50];
    char cpf[20];
    int status;
};
//Status=0 poltrona desocupada| Status=1 poltrona reservada| Status=2 poltrona comprada
struct Sala{
    char filme[20];
    struct Poltrona poltronas[TAM][TAM];
};




int menuPrincipal();
int escolhaPrincipal();

int menuSalas(struct Sala sala[],int quantSalas);
int escolhaSalas(struct Sala sala[], int quantSalas);

int menuPoltrona();

int menuReserva();
int escolhaReserva(struct Poltrona poltronas[TAM][TAM]);

int reservarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j);
int comprarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j);
int cancelarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j);

void resetPoltronas(struct Poltrona poltronas[TAM][TAM]);
void printarPoltronas(struct Poltrona poltronas[TAM][TAM]);
void printCineMix();

void atribuirFilmes(char filmes[]);

int menuAdmin();
void admin(struct Sala sala[], int quantSalas);

int main()
{

    int quantSalas=5;
    struct Sala sala[quantSalas];

    for(int i=0; i<quantSalas; i++){
    resetPoltronas(sala[i].poltronas);
    }

    int escolha=0;

    do{
    escolha = escolhaPrincipal();
    if(escolha == 0){
        return 0;
    }
    if(escolha == 10){
        admin(sala, quantSalas);
    } else{
    escolhaSalas(sala, quantSalas);
    }
    }while(1);
    return 0;
}

int menuSalas(struct Sala sala[],int quantSalas){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printCineMix();
    int i=0;
    for(i=0; i<quantSalas; i++){
    printf(" %d - Sala %d - %s\n", i+1, i+1, sala[i].filme);
    }
    printf(" %d - Sair                                                                            ", i+1);
    printf("\n--------------------------------------------------------------------------------------");
    printf("\nDigite a sala desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int escolhaSalas(struct Sala sala[], int quantSalas){
    char cont[5];
    do{
    int opcao = menuSalas(sala,quantSalas);
    if(opcao == quantSalas+1){
        return 0;
    }else if(opcao < quantSalas+1 && opcao >= 0){
        do{
        int sair=0;
        printCineMix();
        printarPoltronas(sala[opcao-1].poltronas);
        sair = menuPoltrona();
        if(sair==1){
            fflush(stdin);
            escolhaReserva(sala[opcao-1].poltronas);
        } else if(sair==2){
            printf("Enter to continue");
            break;
        } else {
            fflush(stdin);
            printf("Opção invalida!\nEnter to continue");
            gets(cont);
        }
        }while(1);
    } else
        printf("\nOpção invalida!\nEnter to continue");
        fflush(stdin);
        gets(cont);
    }while(1);
}

int menuPoltrona(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printf("| 1 - Escolher poltrona                                                              |");
    printf("\n| 2 - Sair                                                                           |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int menuPrincipal(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printCineMix();
    printf("| Bem vindo ao CineMix!                                                              |");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n| 1 - Listar Salas                                                                   |");
    printf("\n| 2 - Encerar                                                                        |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int escolhaPrincipal(){
    char cont[5];
    do{
    int opcao = menuPrincipal();
    switch(opcao){
    case 1:
        return 1;
    case 2:
        return 0;
    case 159753:
        return 10;
    default:
        printf("\nOpção invalida!\nEnter to continue");
        fflush(stdin);
        gets(cont);
    }
    }while(1);
}

int menuReserva(){
    setlocale(LC_ALL, "Portuguese");
    printCineMix();
    int opcao;
    printf("| 1 - Reservar                                                                       |");
    printf("\n| 2 - Comprar                                                                        |");
    printf("\n| 3 - Cancelar                                                                       |");
    printf("\n| 4 - Sair                                                                           |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

int escolhaReserva(struct Poltrona poltronas[TAM][TAM]){
    int i=0, j=0;
    char cont[5];
    printf("Digite a poltrona desejada: ");
    scanf("%c%d",&i,&j);
    i -= 'A';
    j -= 1;
    int opcao = menuReserva();

    switch (opcao){
    case 1:
        reservarPoltrona(poltronas, i, j);
        break;
    case 2:
        comprarPoltrona(poltronas, i, j);
        break;
    case 3:
        cancelarPoltrona(poltronas, i, j);
        break;
    case 4:
        break;
    case 1987:
        break;
    default:
        printf("\nOpção invalida!\nEnter to continue");
        fflush(stdin);
        gets(cont);
        break;
    }
}


int reservarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j){
    char cont[5];
    if(poltronas[i][j].status==0){
        fflush(stdin);
        printf("Digite seu nome: ");
        gets(poltronas[i][j].nome);
        for(int k=0; strlen(poltronas[i][j].cpf)!=11; k++){
        if(k!=0)
        printf("CPF invalido! |digite somente numeros|\n");
        printf("Digite seu CPF: ");
        gets(poltronas[i][j].cpf);
        }
        poltronas[i][j].status=1;
        printf("Poltrona %c%d reservada com sucesso!\nEnter to continue",i+'A', j+1);
        gets(cont);
        return 1;
    }
    else{
        fflush(stdin);
        printf("Poltrona %c%d ocupada!\nEnter to continue", i+'A', j+1);
        gets(cont);
        return 0;
    }

}

int comprarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j){
    char cont[5];
    if(poltronas[i][j].status==0){
        fflush(stdin);
        printf("Digite seu nome: ");
        gets(poltronas[i][j].nome);
        for(int k=0;strlen(poltronas[i][j].cpf)!=11 || k==0 ;k++){
        if(k!=0)
        printf("CPF invalido! |digite somente numeros|\n");
        printf("Digite seu CPF: ");
        gets(poltronas[i][j].cpf);
        }
        poltronas[i][j].status=2;
        printf("Poltrona %c%d comprada com sucesso!\nEnter to continue",i+'A', j+1);
        gets(cont);
        return 1;
    }else if(poltronas[i][j].status==1){
        fflush(stdin);
        char cpf[20];
        printf("Digite o CPF vinculado a reserva: ");
        gets(cpf);
        if(strcmp(cpf, poltronas[i][j].cpf)==0){
            poltronas[i][j].status=2;
            printf("Poltrona %c%d comprada com sucesso!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 1;
        } else{
            printf("CPF digitado diferente do vinculado a reserva da poltrona %c%d!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 0;
        }
    }else {
        fflush(stdin);
        printf("Poltrona %c%d ocupada!\nEnter to continue",i+'A', j+1);
        gets(cont);
        return 0;
    }
}

int cancelarPoltrona(struct Poltrona poltronas[TAM][TAM],int i, int j){

    char cont[5];
    if(poltronas[i][j].status==0){
        fflush(stdin);
        printf("Poltrona %c%d desoculpada!\nEnter to continue",i+'A', j+1);
        gets(cont);
        return 0;
    }else if(poltronas[i][j].status==1){
        fflush(stdin);
        char cpf[20];
        printf("Digite o CPF vinculado a reserva: ");
        gets(cpf);
        if(strcmp(cpf, poltronas[i][j].cpf)==0){
            poltronas[i][j].status=0;
            printf("Reserva da poltrona %c%d cancelada com sucesso!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 1;
        } else{
            printf("CPF digitado diferente do vinculado a reserva da poltrona %c%d!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 0;
        }
    }else if(poltronas[i][j].status==2){
        fflush(stdin);
        char cpf[20];
        printf("Digite o CPF vinculado a compra: ");
        gets(cpf);
        if(strcmp(cpf, poltronas[i][j].cpf)==0){
            poltronas[i][j].status=0;
            printf("Compra da poltrona %c%d cancelada com sucesso!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 1;
        } else{
            printf("CPF digitado diferente do vinculado a compra da poltrona %c%d!\nEnter to continue",i+'A', j+1);
            gets(cont);
            return 0;
        }
    }
}


void printCineMix(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    system("cls");
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf(R"EOF(--------------------------------------------------------------------------------------
|     ,ad8888ba,                                88b           d88                    |
|    d8"'    `"8b                               888b         d888                    |
)EOF");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf(R"EOF(|   d8'                                         88`8b       d8'88                    |
|   88             88  8b,dPPYba,    ,adPPYba,  88 `8b     d8' 88  88  8b,     ,d8   |
)EOF");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf(R"EOF(|   88                 88P'   `"8a  a8P_____88  88  `8b   d8'  88       `Y8, ,8P'    |
|   Y8,            88  88       88  8PP"""""""  88   `8b d8'   88  88     )888(      |
)EOF");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf(R"EOF(|    Y8a.    .a8P  88  88       88  "8b,   ,aa  88    `888'    88  88   ,d8" "8b,    |
|     `"Y8888Y"'   88  88       88   `"Ybbd8"'  88     `8'     88  88  8P'     `Y8   |
)EOF");
    printf("--------------------------------------------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

void printarPoltronas(struct Poltrona poltronas[TAM][TAM]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    for(int i=0; i<TAM; i++){
            printf("|          ");
        for(int j=0; j<TAM; j++){
            if(poltronas[i][j].status == 0){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            fflush(stdin);
            printf("[%c][%d]  ",i+'A',j+1);
            }
            if(poltronas[i][j].status == 1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            fflush(stdin);
            printf("[%c][%d]  ",i+'A',j+1);
            }
            if(poltronas[i][j].status == 2){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            fflush(stdin);
            printf("[%c][%d]  ",i+'A',j+1);
            }
        }
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("          |");
        printf("\n");

    }
    printf("--------------------------------------------------------------------------------------\n");
}

void resetPoltronas(struct Poltrona poltronas[TAM][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            poltronas[i][j].status=0;
        }
    }
}

void atribuirFilmes(char filme[]){
    fflush(stdin);
    printf("Filme atribuido atualmente na sala: %s\n",filme);
    printf("Digite o nome do novo Filme: ");
    gets(filme);
}

int menuAdmin(){
    int opcao;
    printf("| Bem vindo admin do CineMix!                                                        |");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n| 1 - Atribuir nome de filme a uma sala                                              |");
    printf("\n| 2 - Atribuir nome de filme a todas as salas                                        |");
    printf("\n| 3 - Resetar poltronas de uma sala                                                  |");
    printf("\n| 4 - Resetar poltronas de todas as salas                                            |");
    printf("\n| 5 - Sair                                                                           |");
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opcao);
    return opcao;
}

void admin(struct Sala sala[], int quantSalas){
    int qSala;
    int opcao;
    char cont[5];
    do{
    printCineMix();
    opcao = menuAdmin();
    switch(opcao){
    case 1:
        qSala = menuSalas(sala,quantSalas);
        if(qSala==quantSalas+1){
            break;
        }else if(qSala<quantSalas+1 && qSala>0){
        atribuirFilmes(sala[qSala-1].filme);
        }else {
            fflush(stdin);
            printf("Opção invalida!\nEnter to continue");
            gets(cont);
        }
        break;
    case 2:
        for(int i=0; i<quantSalas; i++){
        int qSala = menuSalas(sala,quantSalas);
        if(qSala==quantSalas+1){
            break;
        }else if(qSala<quantSalas+1 && qSala>0){
        atribuirFilmes(sala[qSala-1].filme);
        }else {
            fflush(stdin);
            printf("Opção invalida!\nEnter to continue");
            gets(cont);
        }
        }
        break;
    case 3:
        do{
        int qSala = menuSalas(sala,quantSalas);
        if(qSala==quantSalas+1){
            break;
        }else if(qSala<quantSalas+1 && qSala>0){
        resetPoltronas(sala[qSala-1].poltronas);
        printf("Poltronas da sala %d resetada!\nEnter to continue", qSala);
            fflush(stdin);
            gets(cont);
        }else {
            fflush(stdin);
            printf("Opção invalida!\nEnter to continue");
            gets(cont);
        }
        }while(1);
        break;
    case 4:
        for(int i=0; i<quantSalas; i++){
        resetPoltronas(sala[i].poltronas);
        }
        fflush(stdin);
        printf("Todas as poltronas das salas resetadas!\nEnter to continue");
        gets(cont);
        break;
    case 5:
        return;
    default:
        printf("\nOpção invalida!\nEnter to continue");
        fflush(stdin);
        gets(cont);
    }
    }while(1);
}




/*
void printCineMix(){
    system("cls");
    fflush(stdin);
    printf(R"EOF(--------------------------------------------------------------------------------------
|     ,ad8888ba,                                88b           d88                    |
|    d8"'    `"8b                               888b         d888                    |
|   d8'                                         88`8b       d8'88                    |
|   88             88  8b,dPPYba,    ,adPPYba,  88 `8b     d8' 88  88  8b,     ,d8   |
|   88                 88P'   `"8a  a8P_____88  88  `8b   d8'  88       `Y8, ,8P'    |
|   Y8,            88  88       88  8PP"""""""  88   `8b d8'   88  88     )888(      |
|    Y8a.    .a8P  88  88       88  "8b,   ,aa  88    `888'    88  88   ,d8" "8b,    |
|     `"Y8888Y"'   88  88       88   `"Ybbd8"'  88     `8'     88  88  8P'     `Y8   |)EOF");
    printf("\n--------------------------------------------------------------------------------------\n");
}
*/
