typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

//Declarando funções
Node* createNode(int data);
Node* insert(Node* root, int data);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);
Node* search(Node* root, int data);
Node* deleteNode(Node* root, int data);

