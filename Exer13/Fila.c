#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

FilaPrioridade* criaFila()
{
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    if(f != NULL)
    {
        f->inicio = NULL;
    }
    return f;
}

void enqueue(FilaPrioridade *f, int val, int prioridade)
{
    No *novo = (No*) malloc(sizeof(No));        //alocando memória para o novo nó da fila
    if(novo == NULL)       
    {
        printf("Erro: memória insuficiente\n");
        return;
    }

    novo->valor = val;      //inicializa os campos do novo nó
    novo->prioridade = prioridade;
    novo->prox = NULL;
    
    if(f->inicio == NULL)   //caso 1: Fila está vazia. O novo nó vira o primeiro da fila
    f->inicio = novo;

    else if(novo->prioridade > f->inicio->prioridade)   //caso 2: o novo tem prioridade maior que o atual início. Ele deve vir antes do atual, então
    {                                                   //Aponta o novo nó para o atual início e atualiza o início para esse novo nó
        novo->prox = f->inicio;
        f->inicio = novo;
    }
    else{                                               //caso 3: a fila já tem elementos, e o novo nó não tem maior prioridade que o primeiro, percorre a lista
        No *atual = f->inicio;                          //para encontrar onde se encaixa

        while(atual->prox != NULL && atual->prox->prioridade >= novo->prioridade)   //percorre os nós até enconrar onde a prioridade do próximo é menor que a do novo
        {
            atual = atual->prox;
        }
        novo->prox = atual->prox;   //Inserção onde o novo aponta para o próximo do atual e o atual passa a apontar para novo
        atual->prox = novo;
    }
}

int dequeue(FilaPrioridade *f, int *val)
{
    if(f->inicio == NULL)
        return 0;

    No *remover = f->inicio;

    *val = remover->valor;
    f->inicio = remover->prox;

    free(remover);

    return 1;
    
}