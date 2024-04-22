#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    //criar lista
    No* lista = criar_lista();
    
    //inserir valores
    lista_inserir(&lista, 'A');
    lista_inserir(&lista, 'B');
    lista_inserir(&lista, 'C');
    
    //imprimir lista
    printf("Lista original: \n");
    lista_imprimir(lista);

    //verificar a existência
    char valor_busca = 'D';
    if(lista_verificar_existencia(lista, valor_busca)){
        printf("O valor %c existe na lista.\n", valor_busca);
    }else{
        printf("O valor %c nao existe na lista.\n", valor_busca);
    }

    //verificar ocorrencias
    valor_busca = 'A';
    int ocorrencias = lista_verificar_ocorrencias(lista, valor_busca);
    printf("O valor %c ocorre %d vez(es) na lista.\n", valor_busca, ocorrencias);

    //imprimir lista inversa
    printf("Lista inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    //novo no em uma posiçao específica
    lista_inserir_no_i(lista, 2, 'X');
    printf("Lista apos insercao: ");
    lista_imprimir(lista);

    //remover no em uma posição específica
    lista_remover_no_i(&lista, 2);
    printf("Lista apos remocao: ");
    lista_imprimir(lista);

    //remover no com um valor específico
    lista_remover_no(&lista, 'C');
    printf("Lista apos remocao do valor: ");
    lista_imprimir(lista);

    //destruir a lista
    lista_destruir(&lista);
    printf("Lista destruida: ");
    lista_imprimir(lista);


    exit(0);
}
