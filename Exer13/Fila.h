#include <stdio.h>
#include <stdlib.h>


//Representa ym nó da fila(um elemento com valor, prioridade e ponteiro para o próximo)
typedef struct No
{
    int valor;          //O valor armazenado no nó, po exemplo, um número genérico
    int prioridade;     //A prioridade do elemento
    struct No *prox;    // Ponteiro para o próximo nó na fila
} No;

typedef struct FilaPrioridade
{
    No *inicio;         //Ponteiro para o primeiro nó da fila (maior prioridade)
} FilaPrioridade;

FilaPrioridade* criaFila();
void enqueue(FilaPrioridade *f, int val, int prioridade);
int dequeue(FilaPrioridade *f, int *val);
void imprimeFila(FilaPrioridade *f);