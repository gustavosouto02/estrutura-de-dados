#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "regressao_linear.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_arquivo.csv>\n", argv[0]);
        return 1;
    }

    Ponto *pontos = NULL;
    int n = 0;
    double interceptacao, inclinacao;

    lerDados(argv[1], &pontos, &n);
    calcularRegressao(pontos, n, &interceptacao, &inclinacao);

    int interceptacao_arredondada = (int)round(interceptacao);
    printf("y = %.1fx + %d\n", inclinacao, interceptacao_arredondada);

    free(pontos);
    return 0;
}