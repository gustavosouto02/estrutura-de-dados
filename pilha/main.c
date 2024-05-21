#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char* argv[]){

    StackNode* top = NULL;

    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');
    
    display(top);

    printf("remover:%c \n", pop(&top));

    display(top);

    printf("topo: %c \n", peek(top));

    printf("remover:%c \n", pop(&top));
    printf("remover:%c \n", pop(&top));
    
    display(top);

    exit (0);
}