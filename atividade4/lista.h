typedef struct No{
    char valor;
    struct No* proximo_no;
} No;

No* criar_lista();
void lista_inserir(No** H, char valor);
void lista_imprimir(No* H);
void lista_destruir(No** H);
int lista_verificar_existencia(No* H, char valor_busca);
int lista_verificar_ocorrencias(No* H, char valor_busca);
void lista_imprimir_inversa(No* H);
void lista_inserir_no_i(No* H, int i, char valor);
void lista_remover_no_i(No** H, int i);
void lista_remover_no(No** H, char valor_busca);