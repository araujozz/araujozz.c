//exemplo 2 de como usar pilha
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
// estrutura para pilha, para nn depender de no encadeado
typedef struct{
    No *topo;
    int tam;
}Pilha;
// para inicializar a pilha
void criar_pilha(Pilha *p){
    p -> topo = NULL;
    p -> tam = 0;
}


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
void emplilhar (Pilha *p){
    //para empilhar, tem que criar um nono nó
    No *novo = malloc(sizeof(No));

    //novo topo da pilha
    if(novo){
        //atribui um valor a variavel p (pessoa)
        novo -> p = ler_pessoa();
        //coloca um novo proximo para pilha
        novo -> proximo = p->topo;
        //add um novo topo
        p->topo = novo;
        //incrementa no tamanho
        p-> tam++;
    }
    else printf("\nErro ao alocar a memória...\n");
    
}
//for de desempilhar sem usar ponteiro de ponteiro
No *desempilhar(Pilha *p){
    if(p->topo){
        //remove o topo
        No *remover = p->topo;
        //remove o proximo
        p ->topo = remover -> proximo;
        //decrementa o valor da pilha
        p->tam --;
        //retorna o remover
        return remover;
    }
    else printf("\nPilha Vazia!\n");
    return NULL;
}
void imprimir_pilha(Pilha *p){
    // usa um axiliar para nn embaralhar a pilha 
    No * aux = p->topo;
    while (aux){
        imprimir_pessoa(aux ->p);
        aux = aux ->proximo;
    }
    
}
//-------------------------------------------------------------------------------------------------------------
int main(){

    No *remover;
    Pilha p;
    int opcao;
    criar_pilha(&p);

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
        case 1:
            emplilhar(&p);
            break;
        case 2:
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento a removido com sucesso!\n");
                imprimir_pessoa(remover ->p);
                free(remover);
            }
            else printf("\nSem no a remover.\n");
            break;

        case 3:
            imprimir_pilha(&p);
            break;            

        default:
            if (opcao != 0) printf("\nOpcao invalida!!!\n");
        }

    } while (opcao != 0);
    
    
    return 0;
}
