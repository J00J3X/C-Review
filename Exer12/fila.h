#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int *dados;     //vetor que guarda os números
    int capacidade; //quantidade máxima que a fila suporta
    int front;      //aponta para o índice do elemento mais antigo(que será removido primeiro)
    int rear;       //aponta para a posição onde será colocado o próximo elemento(inserir)
    int qtd;        // indica quantos elementos tem dentro da fila no momento
} Fila;

Fila* criaFila(int capacidade);
int enqueue(Fila *f, int val);
int dequeue(Fila *f, int *val);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void imprimeFila(Fila *f);