#include <stdio.h>
#include <stdlib.h>
#include "regressao_linear.h"

void lerDados(const char *nomeArquivo, Ponto **pontos, int *n) {
    FILE *file = fopen(nomeArquivo, "r");//abrir arquivo, somente leitura
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char buffer[1024];//contar linhas do arquivo
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        count++;
    }

    *pontos = malloc(count * sizeof(Ponto));//alocar na memoria
    if (!*pontos) {
        perror("Erro na alocação de memória");
        fclose(file);
        exit(2);
    }

    rewind(file);//reler o arquivo
    int i = 0;
    while (fscanf(file, "%d,%f", &(*pontos)[i].x, &(*pontos)[i].y) == 2) {
        i++;                     //coordenada x,  coordenada y
    }
    fclose(file);//fechar
    *n = count;//contar quantos pontos de dados
}
//calcular linha reta
void calcularRegressao(Ponto *pontos, int n, double *interceptacao, double *inclinacao) {
    double somaX = 0, somaY = 0, num = 0, den = 0;
    for (int i = 0; i < n; i++) {//somando coordenadas
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }
    double mediaX = somaX / n;
    double mediaY = somaY / n; //calcular médias x,y

    for (int i = 0; i < n; i++) {
        num += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        den += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }
    *inclinacao = num / den;
    *interceptacao = mediaY - *inclinacao * mediaX;
}