#include <stdio.h>
#include <stdlib.h>
#include "regressao_linear.h"

void lerDados(const char *nomeArquivo, Ponto **pontos, int *n) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char buffer[1024];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        count++;
    }

    *pontos = malloc(count * sizeof(Ponto));
    if (!*pontos) {
        perror("Erro na alocação de memória");
        fclose(file);
        exit(2);
    }

    rewind(file);
    int i = 0;
    while (fscanf(file, "%d,%f", &(*pontos)[i].x, &(*pontos)[i].y) == 2) {
        i++;
    }
    fclose(file);
    *n = count;
}

void calcularRegressao(Ponto *pontos, int n, double *beta0, double *beta1) {
    double sumX = 0, sumY = 0, num = 0, den = 0;
    for (int i = 0; i < n; i++) {
        sumX += pontos[i].x;
        sumY += pontos[i].y;
    }
    double meanX = sumX / n;
    double meanY = sumY / n;

    for (int i = 0; i < n; i++) {
        num += (pontos[i].x - meanX) * (pontos[i].y - meanY);
        den += (pontos[i].x - meanX) * (pontos[i].x - meanX);
    }
    *beta1 = num / den;
    *beta0 = meanY - *beta1 * meanX;
}