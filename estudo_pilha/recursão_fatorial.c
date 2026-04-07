#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
//forma função recursiva de fazer
int fatorial(int n){
    if (n == 0){
        return 1;
    } else return n * fatorial(n - 1);
}

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;
// para inicializar a pilha
void criar_pilha(Pilha *p){
    p -> topo = NULL;
    p -> tam = 0;
}

// função para operação push (empilhar)
void emplilhar (Pilha *p, int num){
    //para empilhar, tem que criar um nono nó
    No *novo = malloc(sizeof(No));

    //novo topo da pilha
    if(novo){
        //atribui um valor a variavel p (pessoa)
        novo -> valor = num;
        //coloca um novo proximo para pilha
        novo -> proximo = p->topo;
        //add um novo topo
        p->topo = novo;
        //incrementa no tamanho
        p-> tam++;
    }
    else printf("\nErro ao alocar a memória...\n");
}
No *desempilhar(Pilha *p){
   

    if(p-> topo){
       No *remover = p -> topo;
       p -> topo = remover -> proximo;
       p -> tam --;
       return remover;
    }else printf("\nPilha Vazia!\n");
    return NULL;
}

void imprimir(Pilha *p){
    No * aux = p->topo;
    while (aux){
        printf("%d\n", aux -> valor );
        aux = aux ->proximo;
    }
}

int fatorial_iterativo (Pilha *p, int num){
    criar_pilha(p);
    int res = 1;
    while (num > 1){
        emplilhar(p, num);
        num--;
    }
    
    imprimir(p);
    
    while (p->topo){
        No *aux = desempilhar(p);
        res *= aux->valor;
        free(aux);
    }
    return res;
}
int main(){
    Pilha p;
    int num = 5;
    int res = fatorial_iterativo(&p, num);
    printf("Fatorial de %d é %d\n", num, res);
    return 0;
}


