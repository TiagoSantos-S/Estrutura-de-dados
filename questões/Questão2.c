#include <stdio.h>


 //Função para calcular o Máximo Divisor Comum (MDC)

 long long calcular_mdc(long long n1, long long n2) {
    while (n2 != 0) {
        long long resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    }
    return n1;
}

int main() {
    long long a, b, x, y;

    // Leitura dos quatro valores de entrada
    // %lld é o especificador de formato para long long
    if (scanf("%lld %lld %lld %lld", &a, &b, &x, &y) != 4) {
        return 0;
    }

    // PASSO 1: Simplificar a proporção x/y
    // Se x=10 e y=6, o MDC é 2. Dividindo ambos por 2, vira 5/3.
    long long g = calcular_mdc(x, y);
    x /= g;
    y /= g;

    // PASSO 2: Calcular o limite para largura e altura separadamente
    // Queremos saber quantas vezes 'x' cabe em 'a' e 'y' cabe em 'b'
    long long limite_w = a / x;
    long long limite_h = b / y;

    // PASSO 3: O resultado é o menor dos dois limites
    // Pois a proporção deve ser mantida e ambos os limites respeitados
    long long resultado;
    if (limite_w < limite_h) {
        resultado = limite_w;
    } else {
        resultado = limite_h;
    }

    // Imprime a quantidade total de variantes possíveis
    printf("%lld\n", resultado);

    return 0;
}