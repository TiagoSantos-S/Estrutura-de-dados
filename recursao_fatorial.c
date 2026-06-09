#include <stdio.h>
#include <stdlib.h>


int fibonacci(int enesimo){
    if(enesimo == 1)return 0;
    if(enesimo == 2)return 1;
    return fibonacci(enesimo-1) + fibonacci(enesimo-2);
}

int fibonacci_loop(int enesimo, int primeiro, int segundo){

    int aux;

    if(enesimo == 1) return 0;
    if(enesimo == 2) return 1;

    for(int i = 2; i < enesimo; i++){

        aux = segundo;
        segundo = segundo + primeiro;
        primeiro = aux;
    }

    return segundo;
}

int main(){
    int primeiro = 0;
    int segundo = 1;
    int enesimo = 9;

    int resultado = fibonacci_loop(enesimo, primeiro, segundo);

   printf("%d\n", resultado);

    return 0;
}
