#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *criar_lista()
{
    return NULL;
}

void lista_inserir(No** H, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo_no = *H;
    *H = novo_no; 
}

void lista_imprimir(No *H)
{
    while (H != NULL)
    {
        printf("%c ", H->valor);
        H = H->proximo_no;
    }
    printf("\n");
}

void lista_destruir(No **H)
{
    No *atual = *H;
    while (atual != NULL)
    {
        No *proximo_no = atual->proximo_no;
        free(atual);
        atual = proximo_no;
    }
    *H = NULL;
}

int lista_verificar_existencia(No *H, char valor_busca)
{
    while (H != NULL)
    {
        if (H->valor == valor_busca)
        {
            return 1;
        }
        H = H->proximo_no;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* H, char valor_busca)
{
    int ocorrencias = 0;
    No* atual = H;
    while (atual != NULL)
    {
        if (atual->valor == valor_busca)
        {
            ocorrencias++;
        }
        atual = atual->proximo_no; 
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No *H)
{
    if (H == NULL)
    {
        return;
    }else{
        lista_imprimir_inversa(H->proximo_no);
        printf("%c ", H->valor);
}
    }
    
void lista_inserir_no_i(No *H, int i, char valor)
{
    int posicao = 0;
    No *anterior = NULL;
    while (H != NULL && posicao < i)
    {
        anterior = H;
        H = H->proximo_no;
        posicao++;
    }
    if (posicao != i)
    {
        printf("Posição de inserção inválida. \n");
        return;
    }
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memória para novo nó. \n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo_no = H;
    if (anterior != NULL)
    {
        anterior->proximo_no = novo_no;
    }
}

void lista_remover_no_i(No** H, int i){
    int posicao = 0;
    No *anterior = NULL;
    No *atual = *H;

    while (atual != NULL && posicao != i){
        anterior = atual;
        atual = atual->proximo_no;
        posicao++;
    } if (posicao != i){
        printf("Posição de remoção inválida. \n");
        return;
    }  if (anterior != NULL){
        anterior->proximo_no = atual->proximo_no;
        free(atual);
    }else{
        *H = atual->proximo_no;
        free(atual);
    }
}


void lista_remover_no(No**H, char valor_busca)
{
    No *anterior = NULL;
    No *atual = *H;
    while (atual != NULL)
    {
        if (atual->valor == valor_busca)
        {
            if (anterior != NULL)
            {
                anterior->proximo_no = atual->proximo_no;
                free(atual);
                atual = anterior->proximo_no;
            }
            else
            {
                *H = atual->proximo_no;
                free(atual);
                atual = *H;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->proximo_no;
        }
    }
}