#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

// Estrutura para armazenar uma data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para armazenar informações de uma pessoa
typedef struct {
    char nome[100];
    Data data;
} Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No; 


// Função para ler os dados de uma pessoa
Pessoa ler_pessoa() {
    Pessoa p;
    
    printf("Digite o nome da pessoa: ");
    scanf("%99s", p.nome);
    
    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &p.data.dia, &p.data.mes, &p.data.ano);
    
    return p;
}

// Função para imprimir os dados de uma pessoa
void imprimir_pessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n", p.data.dia, p.data.mes, p.data.ano);
}

// função para operação push (empilhar)
No *emplilhar (No *topo){
    //para empilhar, tem que criar um nono nó
    No *novo = malloc(sizeof(No));

    //novo topo da pilha
    if(novo){
        //atribui um valor a variavel p
        novo -> p = ler_pessoa();
        //pega esse valor e coloca no topo da pilha
        novo -> proximo = topo;
        //retorna o novo topo
        return novo;
    }
    else printf("\nErro ao alocar a memória...\n");
    return NULL;
}
//usar um ponteiro duplo para que o valor na main seja trocado,
//senão usar o ponteiro duplo vai apenas criar um copia
No *desempilhar(No **topo){
    if(*topo != NULL){
        //ponteiro apontando para o topo
        No *remover = *topo;
        //usando "*" na variavel topo, pq é ponteiro de ponteiro
        *topo = remover ->proximo;
        return remover;
    }
    else printf("\nPilha Vazia!\n");
    return NULL;
}
void imprimir_pilha(No *topo){
    while (topo){
        imprimir_pessoa(topo ->p);
        topo = topo ->proximo;
    }
    
}
//-------------------------------------------------------------------------------------------------------------
int main(){

    No *remover, *topo = NULL;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
        case 1:
            topo = emplilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("\nElemento a removido com sucesso!\n");
                imprimir_pessoa(remover ->p);
                free(remover);
            }
            else printf("\nSem no a remover.\n");
            break;

        case 3:
            imprimir_pilha(topo);
            break;            

        default:
            if (opcao != 0) printf("\nOpcao invalida!!!\n");
        }

    }while (opcao != 0);
    
    
    return 0;
}