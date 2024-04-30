#ifndef REGRESSAO_LINEAR_H
#define REGRESSAO_LINEAR_H

typedef struct {
    int x;
    float y;
} Ponto;

void lerDados(const char *nomeArquivo, Ponto **pontos, int *n);
void calcularRegressao(Ponto *pontos, int n, double *beta0, double *beta1);

#endif