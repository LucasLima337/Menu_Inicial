#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <stdbool.h>

using namespace std;

struct pessoa {
    char nome[40];
    int rg;
};

void printLista(pessoa *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "-------------------------------";
        cout << "\nPosicao: " << i + 1;
        cout << "\nNome: " << lista[i].nome << "\n";
        cout << "RG: " << lista[i].rg;
        cout << "\n-------------------------------\n";
    }
}

void line() {
    cout << "----------------------------------------------------\n";
}

void menu() {
    line();
    cout << "                *** Menu Inicial ***\n";

    cout << "[ 1 ] -- Insercao de um elemento no inicio da lista\n";
    cout << "[ 2 ] -- Insercao de um elemento no fim da lista\n";
    cout << "[ 3 ] -- Insercao de um elemento na posicao N\n\n";

    cout << "[ 4 ] -- Retirar um elemento do inicio da lista\n";
    cout << "[ 5 ] -- Retirar um elemento do fim da lista\n";
    cout << "[ 6 ] -- Retirar um elemento na posicao N\n\n";

    cout << "[ 7 ] -- Procurar um elemento com o campo RG\n";
    cout << "[ 8 ] -- Imprimir a lista\n\n";

    cout << "[ 9 ] -- Sair do sistema\n";
    line();
}

void askInfo(char *nome, int *rg) {
    cout << "Digite o seu nome: ";
    setbuf(stdin, NULL);
    fgets(nome, 40, stdin);
    nome[strlen(nome) - 1] = '\0';

    cout << "Digite o seu RG: ";
    cin >> *rg;
}

// *& significa definir um ponteiro como global
void addFirst(pessoa *&grupo, int *tamanho, char *nome, int rg) {
    // malloc por padrão retorna um ponteiro do tipo void*
    pessoa *newlist = (pessoa*) malloc((*tamanho + 1) * sizeof(pessoa));

    for (int i = 0; i < strlen(nome); i++) {
        newlist[0].nome[i] = nome[i];
    }
    newlist[0].rg = rg;

    for (int j = 0; j < *tamanho; j++) {
        for (int w = 0; w < strlen(grupo[j].nome); w++) {
            newlist[j + 1].nome[w] = grupo[j].nome[w];
        }
        newlist[j + 1].rg = grupo[j].rg;
    }

    cout << "Elemento inserido no inicio da lista com sucesso!\n\n";
    // o endereço é trocado
    grupo = newlist;
    *tamanho = *tamanho + 1;
}

void addLast(pessoa *&grupo, int *length, char *nome, int rg) {
    pessoa *newgrupo = (pessoa*) malloc((*length + 1) * sizeof(pessoa));

    for (int i = 0; i < *length; i++) {
        for (int j = 0; j < strlen(grupo[i].nome); j++) {
            newgrupo[i].nome[j] = grupo[i].nome[j];
        }
        newgrupo[i].rg = grupo[i].rg; 
    }

    for (int w = 0; w < strlen(nome); w++) {
        newgrupo[*length].nome[w] = nome[w];
    }
    newgrupo[*length].rg = rg;

    cout << "Elemento inserido no final da lista com sucesso!\n\n";
    grupo = newgrupo;
    *length = *length + 1;
}

void addX(pessoa *&grupo, int *length, char *nome, int rg, int pos) {
    cout << "\nElemento inserido na posicao " << pos + 1 << " da lista com sucesso!\n";
    pessoa *newgrupo = (pessoa*) malloc((*length + 1) * sizeof(pessoa));

    for (int w = 0; w < strlen(nome); w++) {
        newgrupo[pos].nome[w] = nome[w];
    }
    newgrupo[pos].rg = rg;

    for (int i = 0; i < *length; i++) {
        if (i < pos) {
            for (int j = 0; j < strlen(grupo[i].nome); j++) {
                newgrupo[i].nome[j] = grupo[i].nome[j];
            }
            newgrupo[i].rg = grupo[i].rg;
        }

        else {
            for (int x = 0; x < strlen(grupo[i].nome); x++) {
                newgrupo[i + 1].nome[x] = grupo[i].nome[x];
            }
            newgrupo[i + 1].rg = grupo[i].rg;
        }
    }

    grupo = newgrupo;
    *length = *length + 1;
}

void delFirst(pessoa *&grupo, int *length) {
    if (*length == 0) {
        cout << "Sua lista esta vazia!\n\n";
    }
    else{
        pessoa *newgrupo = (pessoa*) malloc((*length - 1) * sizeof(pessoa));
        for (int i = 0; i < *length - 1; i++) {
            for (int j = 0; j < strlen(grupo[i + 1].nome); j++) {
                newgrupo[i].nome[j] = grupo[i + 1].nome[j];
            }
            newgrupo[i].rg = grupo[i + 1].rg;
        }

        cout << "Primeiro elemento excluido com sucesso!\n\n";
        grupo = newgrupo;
        *length = *length - 1;
    }
}

void delLast(pessoa *&grupo, int *length) {
    if (*length == 0) {
        cout << "Sua lista esta vazia!\n\n";
    }
    else {
        pessoa *newgrupo = (pessoa*) malloc((*length - 1) * sizeof(pessoa));
        for (int i = 0; i < *length - 1; i++) {
            for (int j = 0; j < strlen(grupo[i].nome); j++) {
                newgrupo[i].nome[j] = grupo[i].nome[j]; 
            }
            newgrupo[i].rg = grupo[i].rg;
        }

        cout << "Ultimo elemento excluido com sucesso!\n\n";
        grupo = newgrupo;
        *length = *length - 1;
    }
}

void delX(pessoa *&grupo, int *length, int pos) {
    pessoa *newgrupo = (pessoa*) malloc((*length - 1) * sizeof(pessoa));
    for (int i = 0; i < *length; i++) {
        if (i < pos) {
            for (int j = 0; j < strlen(grupo[i].nome); j++) {
                newgrupo[i].nome[j] = grupo[i].nome[j];
            }
            newgrupo[i].rg = grupo[i].rg;
        }
        else if (i > pos) {
            for (int w = 0; w < strlen(grupo[i].nome); w++) {
                newgrupo[i - 1].nome[w] = grupo[i].nome[w];
            }
            newgrupo[i - 1].rg = grupo[i].rg;
        }
    }

    cout << "\nElemento removido da posicao " << pos + 1 << " da lista com sucesso!\n";
    grupo = newgrupo;
    *length = *length - 1;
}

void findRG(pessoa *grupo, int length, int myrg) {
    int cont = 0;

    for (int i = 0; i < length; i++) {
        if (grupo[i].rg == myrg) {
            cout << "------------------------\n";
            cout << "Nome: " << grupo[i].nome << "\n";
            cout << "RG: " << grupo[i].rg << "\n";
            cout << "------------------------\n";
            cont++;
            break;
        }
    }

    if (cont == 0) {
        cout << "RG nao encontrado na lista!\n\n";
    }
}

int main() {
    int choice;
    bool logic = true;

    int length = 0;
    pessoa *grupo;

    char nome[40];
    int rg;
    int pos;

    int myrg;

    while (logic) {
        menu();
        cout << "\nEscolha uma opcao desejada: ";
        cin >> choice;

        system("clear");
        bool test = true;
        bool test2 = true;

        switch(choice) {
            case 1:
                cout << "Opcao escolhida: [ 1 ] -- Insercao de um elemento no inicio da lista\n\n";

                askInfo(nome, &rg);
                system("clear");
                addFirst(grupo, &length, nome, rg);
                break;

            case 2:
                cout << "Opcao escolhida: [ 2 ] -- Insercao de um elemento no fim da lista\n\n";

                askInfo(nome, &rg);
                system("clear");
                addLast(grupo, &length, nome, rg);
                break;

            case 3:
                cout << "Opcao escolhida: [ 3 ] -- Insercao de um elemento na posicao N\n\n";

                cout << "Posicoes Disponiveis:\n";
                if (length > 0) {
                    cout << "| ";
                    for (int i = 1; i <= length + 1; i++) {
                        cout << i << " | ";
                    }
                    cout << "\n\n";
                }
                else {
                    cout << "| 1 |\n\n";
                }

                askInfo(nome, &rg);

                while (test) {
                    cout << "Digite a posicao que deseja inserir as informacoes: ";
                    cin >> pos;

                    if ((pos - 1) >= 0 && (pos - 1) <= length && length == 0) {
                        test = false;
                        system("clear");
                        addFirst(grupo, &length, nome, rg);
                    }

                    else if ((pos - 1) < 0 || (pos - 1) > length) {
                        cout << "\nPosicao inválida ou maior que o tamanho da lista, tente novamente.\n\n";
                    }

                    else {
                        if ((pos - 1) == 0) {
                            system("clear");
                            addFirst(grupo, &length, nome, rg);
                        }
                        else if (pos == length + 1) {
                            system("clear");
                            addLast(grupo, &length, nome, rg);
                        }
                        else {
                            system("clear");
                            addX(grupo, &length, nome, rg, pos - 1);
                        }

                        test = false;
                    }
                }
                break;

            case 4:
                cout << "Opcao escolhida: [ 4 ] -- Retirar um elemento do inicio da lista\n\n";

                delFirst(grupo, &length);
                break;

            case 5:
                cout << "Opcao escolhida: [ 5 ] -- Retirar um elemento do fim da lista\n\n";

                delLast(grupo, &length);
                break;

            case 6:
                cout << "Opcao escolhida: [ 6 ] -- Retirar um elemento na posicao N\n\n";
                
                if (length == 0) {
                    cout << "A lista esta vazia!\n\n";
                    test2 = false;
                }
                else if (length == 1) {
                    cout << "Posicoes Disponiveis:\n";
                    cout << "| 1 | -- " << grupo[0].nome << "\n\n";
                }
                else {
                    cout << "Posicoes Disponiveis:\n";

                    for (int i = 1; i <= length; i++) {
                        cout << "| " << i << " | -- " << grupo[i - 1].nome << "\n";
                    }
                    cout << "\n";
                }

                while (test2) {
                    cout << "Digite a posicao que deseja remover: ";
                    cin >> pos;

                    if (pos <= 0 || pos > length) {
                        cout << "\nPosicao invalida ou maior que o tamanho da lista, tente novamente!\n\n";
                    }
                    else {
                        if (pos == 1) {
                            system("clear");
                            delFirst(grupo, &length);
                            test2 = false;
                        }
                        else if (pos == length) {
                            system("clear");
                            delLast(grupo, &length);
                            test2 = false;
                        }
                        else {
                            system("clear");
                            delX(grupo, &length, pos - 1);
                            test2 = false;
                        }
                    }
                }
                break;

            case 7:
                cout << "Opcao escolhida: [ 7 ] -- Procurar um elemento com o campo RG\n\n";

                if (length == 0) {
                    cout << "A lista esta vazia!\n\n";
                }
                else {
                    cout << "Digite um RG valido: ";
                    cin >> myrg;

                    system("clear");
                    findRG(grupo, length, myrg);
                }
                break;
            
            case 8:
                cout << "** Lista de Pessoas **\n\n";
                printLista(grupo, length);
                break;
        
            case 9:
                logic = false;
                cout << "Programa encerrado com sucesso!\n\n";
                break;

            default:
                cout << "\nNumero invalido digitado, tente novamente.\n\n";
        }
    }
    return 0;
}
