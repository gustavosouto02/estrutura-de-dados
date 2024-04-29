#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main(int argc, char* argv[]){

    //criar lista
    No* lista = NULL;

    //inserir nos
    lista = inserir_no(lista, 'A');
    lista = inserir_no(lista, 'B');
    lista = inserir_no(lista, 'C');

    //imprimir a lista
    printf("Lista circular: ");
    imprimir_lista(lista);
     printf("\n");

    //remover no
    printf("Remocao do no 'B'...\n");
    remover_no(lista, 'B');

    //imprimir a lista apos remover o no 
    printf("Lista circular apos remover o no: ");
    imprimir_lista(lista);
     printf("\n");

    //liberar memoria alocada
    liberar_lista(lista);

   return 0;
}