#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
    int qtd_n = argc -1;
    int soma_n = 0;
    float media_n = 0;
    int menor_n = atoi(argv[1]);
    int maior_n = atoi(argv[1]);

    for(int i = 1; i <= qtd_n; i++){
        int n = atoi(argv[i]);
        soma_n += *argv[i];

        if (menor_n > n ){
            menor_n = n;
        }

        if (n > maior_n){
            maior_n = n;
        }
    }

    for (int i = 0; i < qtd_n-1; i++){
        for(int j = i; j < qtd_n; j++){
            if(vetor_ord_n[i] > vetor_ord_n[j]){
                int aux = vetor_ord_n[j];
                vetor_ord_n[j] =  vetor_ord_n[i];
                vetor_ord_n[i] = aux;
            }
           
        }
    }
    

    media_n = (float) soma_n / qtd_n;

    printf("Quantidade de numeros recebidos: %d\n", qtd_n);
    printf("Valor medio dos numeros: %.2f\n", media_n);
    printf("Menor numero: %d\n", menor_n);
    printf("Maior numero: %d\n", maior_n);

    exit(0);
}