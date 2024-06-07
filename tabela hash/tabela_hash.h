#define TAM_ALFABETO 26
#define TAM_TABELA TAM_ALFABETO*TAM_ALFABETO
#define TAM_VALOR 255

int hash(char* chave);
char** tabela_hash(); //criar caixa
void put(char* chave, char* valor, char** tabela); //adicionar na caixa
char* get(char* chave, char** tabela); //pegar da caixa
int contains(char* chave, char** tabela); //checar se esta ou nao na caixa
void remover(char* chave, char** tabela); //remover da caixa