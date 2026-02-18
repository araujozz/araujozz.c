#include <stdio.h>

float exponencial(int x, int y){
    if(y == 0){
        return 1;
    }

    else if (x == 0){
        return 0;
    }
    else{
        return x * exponencial(x,y-1);
    }
}

int main()
{

    int base;
    int expoente;

    printf("Me diga um numero (base):");
    scanf("%i", &base);

    printf("Me diga um numero (expoente):");
    scanf("%i", &expoente);

    float resultado = exponencial(base, expoente);
    printf("%i elevado a %i = %.2f\n", base, expoente, resultado);

    return 0;
}