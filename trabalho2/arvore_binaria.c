#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// criar nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inserir nó 
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// percorrer em ordem
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// percorrer em pré-ordem 
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// percorrer em pós-ordem
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// buscar nó 
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// encontrar o menor valor na árvore
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// remover nó 
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Caso 1: Nó com apenas um filho ou sem filho
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Caso 2: Nó com dois filhos
        Node* temp = findMin(root->right);  // Encontra o menor nó na subárvore direita
        root->data = temp->data;  // Copia o valor do menor nó encontrado para o nó atual
        root->right = deleteNode(root->right, temp->data);  // Remove o menor nó da subárvore direita
    }
    return root;
}
