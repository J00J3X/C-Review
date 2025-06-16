#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


Fila* criaFila(int capacidade)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f != NULL)
    {
        f->capacidade = capacidade;
        f->dados = (int*) malloc(capacidade * sizeof(int));
        f->front = 0;
        f->qtd = 0;
        f->rear = 0;
    }

    return f;
}

int enqueue(Fila *f, int val)
{
    if(f->qtd == f->capacidade) //verifica se está cheia
    {
        return -1;
    }

    f->dados[f->rear] = val;        //insere o valor no vetor na posição rear
    f->rear = (f->rear + 1) % f->capacidade;    //atualiza o rear com (rear+1)%capacidade
    f->qtd++;   

    return 1;
}

int dequeue(Fila *f, int *val)
{
    if(f->qtd == 0) //verifica se está vazia
    {
        return -1;
    }

    *val = f->dados[f->front];
    f->front = (f->front + 1) % f->capacidade;
    f->qtd--;

    return 1;
}

int filaVazia(Fila *f)
{
   return (f->qtd == 0);
}

int filaCheia(Fila *f)
{
    return (f->qtd == f->capacidade);
}

void imprimeFila(Fila *f)
{
    int cont = 0;       //contador pra saber quantos elementos foram percorridos
    int indice = f->front;  //começa o indice do primeiro elemento(front)

    if (filaVazia(f))
    {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila:\n");
    while(cont < f->qtd)    //percorre a qtd de elemtnos existentes na fila
    {
        printf("| %d |\n", f->dados[indice]);
        indice = (indice + 1) % f->capacidade;
        cont++;
    }
    printf("--------\n");
}