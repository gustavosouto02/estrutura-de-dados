#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(int argc, char *argv[]){
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 100);

    printf("Arvore em ordem: ");
    inOrder(root);
    printf("\n");

    printf("Arvore pre-ordem : ");
    preOrder(root);
    printf("\n");

    printf("Arvore pos-ordem: ");
    postOrder(root);
    printf("\n");

    printf("Procurando no com valor = 40...\n");
    Node* searchResult = search(root, 40);
    if (searchResult != NULL)
    {
        printf("No encontrado. Valor = %d\n", searchResult->data);
    }else{
        printf("No nao encontrado.\n");
    }
    
    printf("Removendo no com valor = 20...\n");
    root = deleteNode(root, 20);
    printf("Arvore em ordem depois da remocao:  ");
    inOrder(root);
    printf("\n");

    return 0;
}