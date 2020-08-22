#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct pessoa {
    char nome[40];
    int rg;
    pessoa *next;
};

void line() {
    cout << "----------------------------------------------------\n";
}

void menu() {
    line();
    cout << "                 *** Menu Inicial ***\n";

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

void printVetor(pessoa *grupo) {
    while (grupo != NULL) {
        line();
        cout << "Nome: " << grupo->nome << "\n";
        cout << "RG: " << grupo->rg << "\n";
        grupo = grupo->next;
    }
}

void askinfo(char *nome, int *rg) {
    cout << "Digite o nome: ";
    setbuf(stdin, NULL);
    fgets(nome, 40, stdin);
    nome[strlen(nome) - 1] = '\0';

    cout << "Digite o rg: ";
    cin >> *rg;
}

int tamanho(pessoa *grupo) {
    int tam = 0;

    while (grupo != NULL) {
        grupo = grupo->next;
        tam++;
    }
    
    return tam;
}

void addFirst(pessoa *&grupo, char *nome, int rg, char *nomeBlank) {
    pessoa *um = (pessoa*) malloc(sizeof(pessoa));
    for (int i = 0; i < strlen(nome); i++) {
        um->nome[i] = nome[i];
    }
    um->rg = rg;

    if (*grupo->nome == nomeBlank[0]) {
        um->next = NULL;
    }
    else {
        um->next = grupo;
    }
    
    grupo = um;
}

void addLast(pessoa *&grupo, char *nome, int rg) {
    pessoa *last = (pessoa*) malloc(sizeof(pessoa));
    for (int i = 0; i < strlen(nome); i++) {
        last->nome[i] = nome[i];
    }
    last->rg = rg;
    last->next = NULL;

    pessoa *first = grupo; 
    while (grupo != NULL) {
        if (grupo->next == NULL) {
            grupo->next = last;
            break;
        }
        grupo = grupo->next;
    }

    grupo = first;
}

void addX(pessoa *&grupo, char *nome, int rg, int pos) {
    pessoa *Xelement = new pessoa;
    for (int i = 0; i < strlen(nome); i++) {
        Xelement->nome[i] = nome[i];
    }
    Xelement->rg = rg;

    pessoa *value = new pessoa;
    pessoa *first = grupo;
    int contador = 0;

    while (grupo != NULL) {
        if (contador == pos - 1) {
            value = grupo->next;
            grupo->next = Xelement;
        }
        else if (contador == pos) {
            grupo = Xelement;
            grupo->next = value;
            break;
        }
        contador++;
        grupo = grupo->next;
    }

    grupo = first;
}

void delFirst(pessoa *&grupo, char *nomeBlank) {
    if (grupo->next == NULL) {
        pessoa *newBlank = new pessoa;
        *newBlank->nome = nomeBlank[0];
        newBlank->rg = 0;
        newBlank->next = NULL;

        grupo = newBlank;
    }
    else {
        grupo = grupo->next; 
    }
}

void delLast(pessoa *&grupo, int length, char *nomeBlank) {
    if (grupo->next == NULL) {
        pessoa *newBlank = new pessoa;
        *newBlank->nome = nomeBlank[0];
        newBlank->rg = 0;
        newBlank->next = NULL;

        grupo = newBlank;
    }
    else {
        int contador = 1;
        pessoa *first = grupo;
        while (grupo != NULL) {
            if (contador == length - 1) {
                grupo->next = NULL;
                break;
            }
            contador++;
            grupo = grupo->next;
        }

        grupo = first;
    }
}

void delX(pessoa *&grupo, int pos, char *nomeBlank) {
    if (grupo->next == NULL) {
        pessoa *newBlank = new pessoa;
        *newBlank->nome = nomeBlank[0];
        newBlank-> rg;
        newBlank->next = NULL;

        grupo = newBlank;
    }
    else {
        int contador = 0;
        pessoa *first = grupo; 
        while (grupo != NULL) {
            if (contador == pos - 1) {
                grupo->next = grupo->next->next;
                break;
            }
            contador++;
            grupo = grupo->next;
        }

        grupo = first;
    }
}

void searchRG(pessoa *grupo, int rg) {
    pessoa *first = grupo;
    pessoa *nome = new pessoa;

    int aux = 0;
    while (grupo != NULL) {
        if (rg == grupo->rg) {
            cout << "RG encontrado!";
            cout << "\nNome: " << grupo->nome << "\n\n";
            aux++;
            break;
        }
        grupo = grupo->next;
    }

    if (aux == 0) {
        cout << "RG nao encontrado!\n\n";
    }

    grupo = first;
}

int main() {
    bool logic = true;
    int opcao;
    char nomeBlank[1] = {""};

    pessoa *grupo = (pessoa*) malloc(sizeof(pessoa));
    *grupo->nome = nomeBlank[0];
    grupo->rg = 0;
    grupo->next = NULL;
    int length = 0;

    char nome[40];
    int rg;

    while (logic) {
        menu();
        cout << "\nEscolha a opcao desejada: ";
        cin >> opcao;
        
        bool logic2 = true;
        bool logic3 = true;
        
        system("cls");
        switch(opcao) {
            case 1:
                cout << "Opcao escolhida: [ 1 ] -- Insercao de um elemento no inicio da lista\n\n";

                askinfo(nome, &rg);
                addFirst(grupo, nome, rg, nomeBlank);

                system("cls");
                cout << "Pessoa adicionada no inicio da lista com sucesso!\n";
                break;
            case 2:
                cout << "Opcao escolhida: [ 2 ] -- Insercao de um elemento no fim da lista\n\n";

                askinfo(nome, &rg);

                if (*grupo->nome == nomeBlank[0]) { addFirst(grupo, nome, rg, nomeBlank); }
                else { addLast(grupo, nome, rg); }

                system("cls");
                cout << "Pessoa adicionada no fim da lista com sucesso!\n";
                break;
            case 3:
                cout << "Opcao escolhida: [ 3 ] -- Insercao de um elemento na posicao N\n\n";

                cout << "Opcoes disponiveis\n";
                if (*grupo->nome == nomeBlank[0]) { cout << "| 1 |\n\n"; }
                else if (tamanho(grupo) == 1) { cout << "| 1 | | 2 |\n\n"; }
                else {
                    for (int i = 0; i < tamanho(grupo) + 1; i++) { 
                        cout << "| " << i + 1 << " | "; 
                    }
                    cout << "\n\n";
                }

                while (logic2) {
                    int choice;
                    cout << "Em que posicao deseja inserir o elemento? ";
                    cin >> choice;
                    cout << "\n";

                    if (choice < 1 || choice > tamanho(grupo) + 1 || *grupo->nome == nomeBlank[0] && choice != 1) {
                        cout << "Numero digitado nao esta disponivel!\n\n";
                    }
                    else {
                        if (choice == 1) {
                            askinfo(nome, &rg);
                            addFirst(grupo, nome, rg, nomeBlank);
                            system("cls");
                            cout << "Pessoa adicionada no inicio da lista com sucesso!\n";
                            logic2 = false;
                        }
                        else if (choice == tamanho(grupo) + 1) {
                            askinfo(nome, &rg);
                            addLast(grupo, nome, rg);
                            system("cls");
                            cout << "Pessoa adicionada no fim da lista com sucesso!\n";
                            logic2 = false;
                        }
                        else {
                            askinfo(nome, &rg);
                            addX(grupo, nome, rg, choice - 1);
                            system("cls");
                            cout << "Pessoa adicionada na posicao " << choice << " da lista!\n";
                            logic2 = false;
                        }
                    }
                }
                break;
            case 4:
                cout << "Opcao escolhida: [ 4 ] -- Retirar um elemento do inicio da lista";

                if (*grupo->nome == nomeBlank[0]) { cout << "\n\nA lista esta vazia!\n\n"; }
                else { 
                    delFirst(grupo, nomeBlank); 
                    cout << "\n\nPrimeiro elemento removido com sucesso!\n\n";
                }
                break;
            case 5:
                cout << "Opcao escolhida: [ 5 ] -- Retirar um elemento do fim da lista";

                if (*grupo->nome == nomeBlank[0]) { cout << "\n\nA lista esta vazia!\n\n"; }
                else {
                    if (tamanho(grupo) == 1) { delFirst(grupo, nomeBlank); }
                    else { delLast(grupo, tamanho(grupo), nomeBlank); }
                    
                    cout << "\n\nUltimo elemento removido com sucesso!\n\n";
                }
                break;
            case 6:
                cout << "Opcao escolhida: [ 6 ] -- Retirar um elemento na posicao N\n\n";

                if (*grupo->nome == nomeBlank[0]) { cout << "Lista Vazia\n\n"; }
                else {
                    cout << "Opcoes disponiveis\n";
                    for (int i = 0; i < tamanho(grupo); i++) { 
                        cout << "| " << i + 1 << " | "; 
                    }
                    cout << "\n\n";

                    while (logic3) {
                        int choice;
                        cout << "Qual elemento voce deseja remover? ";
                        cin >> choice;
                        cout << "\n";
        
                        if (choice < 1 || choice > tamanho(grupo) || *grupo->nome == nomeBlank[0] && choice != 1) {
                            cout << "Numero digitado nao esta disponivel!\n\n";
                        }
                        else {
                            if (choice == 1) {
                            delFirst(grupo, nomeBlank); 
                            system("cls");
                            cout << "Primeiro elemento removido com sucesso!\n\n";
                            logic3 = false;
                            }
                            else if (choice == tamanho(grupo)) {
                                delLast(grupo, tamanho(grupo), nomeBlank);
                                system("cls");
                                cout << "Ultimo elemento removido com sucesso!\n\n";
                                logic3 = false;
                            }
                            else {
                                delX(grupo, choice - 1, nomeBlank);
                                system("cls");
                                cout << "Elemento removido da posicao " << choice << " da lista!\n\n";
                                logic3 = false;
                            }
                        }
                    }
                }
                break;
            case 7:
                cout << "Opcao escolhida: [ 7 ] -- Procurar um elemento com o campo RG\n\n";

                if (*grupo->nome == nomeBlank[0]) {
                    cout << "A lista esta vazia!\n\n";
                }
                else {
                    int findRG;
                    cout << "Digite um RG valido: ";
                    cin >> findRG;

                    system("cls");
                    searchRG(grupo, findRG);
                }
                break;
            case 8:
                cout << "Lista de Pessoas\n\n";
                printVetor(grupo);
                break;
            case 9:
                cout << "\nPrograma encerrado com sucesso!\n\n";
                logic = false;
                break;
            default:
                cout << "\nOpcao invalida, tente novamente!\n";
        }
    }
    return 0;
}
