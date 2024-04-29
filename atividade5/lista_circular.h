typedef struct No{
    char valor;
    struct No* proximo_no;
    
} No;

No* inserir_no(No* H, char valor);
void imprimir_lista(No* H);
void remover_no(No* H, char valor);
void liberar_lista(No* H);
