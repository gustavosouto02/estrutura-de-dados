#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabela_hash.h"

int hash(char* chave){
    return (toupper(chave[0])-65)*TAM_ALFABETO + toupper(chave[1])-65;
    //toupper = letra maiuscula
    //chave[0] = primeira letra chave[1] = segunda letra
}

char** tabela_hash(){ //caixa vazia
    char** tabela = malloc(sizeof(char*)*TAM_TABELA); // tamanho da caixa

    for(int i = 0; i < TAM_TABELA; i++){
        tabela[i] = malloc(sizeof(char)*TAM_VALOR); //tamanho do brinquedo
        strcpy(tabela[i], "");
    }

    return tabela;
}

void put(char* chave, char* valor, char** tabela){
    strcpy(tabela[hash(chave)], valor); //adicionar
}

char* get(char* chave, char** tabela){
    return tabela[hash(chave)]; //pegar
}

int contains(char* chave, char** tabela){
    int tam = strlen(tabela[hash(chave)]);

    int contains = 0;//nao esta na caixa
    if(tam > 0){
        contains = 1;//esta na caixa
    }

    return contains;
}
void remover(char* chave, char** tabela){
    strcpy(tabela[hash(chave)], "");
}