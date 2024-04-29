#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// inserir no
No* inserir_no(No* H, char valor)
{
    No* novo_no = (No *)malloc(sizeof(No));

    if (novo_no == NULL)
    {
        printf("Erro ao alocar memória para novo no.\n");
        return H;
    }
    novo_no->valor = valor;

    if (H == NULL)
    {
        novo_no->proximo_no = novo_no; // lista vazia

        return novo_no;
    }
    No* ultimo_no = H;
    while (ultimo_no->proximo_no != H)
    {
        ultimo_no = ultimo_no->proximo_no;
    }
    
    novo_no->proximo_no = H;
    ultimo_no->proximo_no = novo_no;

    return H; 
}

// imprimir
void imprimir_lista(No* H)
{
    if (H == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    No* atual = H;
    do
    {
        printf("%c ", atual->valor);
        atual = atual->proximo_no;
    } while (atual != H);
    printf("\n");
    
}

// remover
void remover_no(No* H, char valor)
{
    if (H == NULL)
    {
        printf("Lista vazia, nada a remover.\n");
        return;
    }
    No* atual = H;
    No* anterior = NULL;
    do
    {
        if (atual->valor == valor)
        {
            if (anterior == NULL)
            {
                No* ultimo_no = H->proximo_no;
                while (ultimo_no->proximo_no != H)
                {
                    ultimo_no = ultimo_no->proximo_no;
                }
                H = H->proximo_no;
                ultimo_no->proximo_no = H;
            }
            else
            {
                anterior->proximo_no = atual->proximo_no;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo_no;
    } while (atual != H);

    printf("Valor nao encontrado na lista.\n");
}

//liberar memoria
void liberar_lista(No* H){
    if (H == NULL)
    {
        return;
    }

    No* atual = H;
    do{
        No* proximo_no = atual ->proximo_no;
        free(atual);
        atual = proximo_no;
    }while(atual != H) ;
}