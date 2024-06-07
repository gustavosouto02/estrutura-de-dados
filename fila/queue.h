typedef struct QueueNode{
    char data;
    struct QueueNode* next;
} QueueNode;

void enqueue(QueueNode** root, char data); //adicionar elemento
char dequeue(QueueNode** root); // remover elemento
char peek(QueueNode* root); // "espia" o primeiro elemento da fila
int isEmpty(QueueNode* root); // ver se a fila esta vazia 
void display(QueueNode* root); // exibe todos elementos 