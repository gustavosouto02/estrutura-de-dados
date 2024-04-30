#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main(int argc, char* argv[]){
    
    printf("Inserindo nos... \n");
    No* H = no('A', NULL);//no cabeça
    inserir_no(H, 'B');
    inserir_no(H, 'C');

    printf("Lista circular: ");
    imprimir_lista(H);
    printf("\n");

    printf("Remocao do no 'B'...\n");
    remover_no(H, 'B');

    printf("Lista circular apos remover o no: ");
    imprimir_lista(H);

    printf("\nRemocao do no 'C'...\n");
    remover_no(H, 'C');

    printf("Lista circular apos remover o no: ");
    imprimir_lista(H);
    printf("\n");

    exit(0);

}