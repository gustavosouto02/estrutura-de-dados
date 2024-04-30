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
    double beta0, beta1;

    lerDados(argv[1], &pontos, &n);
    calcularRegressao(pontos, n, &beta0, &beta1);

    int beta0_arredondado = (int)round(beta0);
    printf("y = %.1fx + %d\n", beta1, beta0_arredondado);

    free(pontos);
    return 0;
}