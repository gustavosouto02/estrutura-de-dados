#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

//vai mudar o elemento do topo
void push(StackNode** root, char data){
    StackNode* stackNode = malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = *root;//novo topo
    *root = stackNode;
}

char pop(StackNode** root){
    if(isEmpty(*root)){
        return CHAR_MIN;
    }
    StackNode* tmp = *root;//tmp = novo topo temporiariamente
    *root = tmp->next;//topo é o prox elemento
    char tmpData = tmp->data;
    free(tmp);
    return tmpData;
}

char peek(StackNode* root){
    if(isEmpty(root)){
        return CHAR_MIN;
    }
    return root->data; 
}

int isEmpty(StackNode* root){
    return root == NULL;
}

int display(StackNode* root){
    StackNode* tmp = root;//aponta pro topo
    while(tmp != NULL){//pecorre a lista enquanto não for nula
        printf("%c -> ", tmp->data);
        tmp =  tmp->next;
    }
    printf("NULL\n");
}