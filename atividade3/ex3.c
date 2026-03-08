#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct
{
    char nomeCliente[60];
    float saldo;
} Conta;

Conta inicializar (Conta c){
    c.saldo = 0;
    return c;
}

Conta depositar(Conta c, float valor){
    c.saldo += valor;
    return c;
}

Conta sacar(Conta c, float valor){
    if(valor > c.saldo){
        printf("Saldo indisponivel!");
        return c;
    }
    else{
        c.saldo -= valor;
        return c;
    }
}

void imprimir(Conta c){
    printf("%s \nSaldo: R$%.2f\n",c.nomeCliente, c.saldo);
}


int main(){
    Conta  cliente1;
    
    printf("Digite seu nome: ");
    scanf("%s", cliente1.nomeCliente);

    cliente1 = inicializar(cliente1);

    cliente1 = depositar(cliente1, 150.00);
    cliente1 = sacar(cliente1, 55.50);

    imprimir(cliente1);

    return 0;
}


