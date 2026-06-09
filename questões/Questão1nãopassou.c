#include <stdio.h>

int main(){

    int tam;

    printf("qual tamanho do vetor ?");
    scanf("%d", &tam);

    int vetor[tam];
    int vetor_ordenado[tam];
    int duplo = 0;
    int contador = 0;
    int aux = 0;

    printf("preencha o vetor\n");

    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    if(tam == 1){
        printf("YES");
        return 0;
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(vetor[j] > vetor[i]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
                contador++;
            }
        }
    }

    for(int i = 0; i < tam - 1; i++){
        if(vetor[i] == vetor[i+1]){
            printf("YES\n");
            return 0;
        } 
    }

        if(contador % 2 == 0){
            printf("YES");
        }else{
            printf("NO");
            return 0;
        }

    return 0;

}