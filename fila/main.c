#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[]){

    QueueNode* root = NULL;

    enqueue(&root, 'A');
    enqueue(&root, 'B');
    enqueue(&root, 'C'); 

    printf("%c\n", peek(root)); // primeiro elemento
    printf("%c\n", dequeue(&root)); // tirar primeiro elemento
    display(root);

    exit(0);
}