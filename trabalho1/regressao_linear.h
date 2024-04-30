typedef struct {
    int x;
    float y;
} Ponto;

void lerDados(const char *nomeArquivo, Ponto **pontos, int *n);
void calcularRegressao(Ponto *pontos, int n, double *interceptacao, double *inclinacao);
