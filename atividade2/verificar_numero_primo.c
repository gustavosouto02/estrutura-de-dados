#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int ehPrimo(int num){
        
        if (num <= 1) {
            return 0; // Falso
        }

        for (int i = 2; i * i <= num; i++){
            if (num % i == 0){
                return 0; // Falso
            }
        }

        return 1; // Verdadeiro
    }

    if (argc != 2){
        printf("Uso : %s <numero> \n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    
    if (ehPrimo(numero)){
        printf("True\n");
    } else{
        printf("False\n");
    }
    

    return 0;

}