#include<stdio.h>
#include<stdlib.h>
#include<strings.h>


typedef struct
{
    char nomeCliente[60];
    float saldo;
} Conta;

Conta* criarConta(){
    Conta *c = malloc(sizeof(Conta));
    c->saldo = 0;
    return c;
}

int main(){

    Conta *cliente1;

    cliente1 = criarConta();

    printf("Digite o nome do cliente: ");
    scanf("%s", cliente1->nomeCliente);

    cliente1->saldo = 200;

    printf("Cliente: %s\n", cliente1->nomeCliente);
    printf("Saldo: R$%.2f\n", cliente1->saldo);

    free(cliente1);

    return 0;
}