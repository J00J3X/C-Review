#include <stdio.h>
#include "fila.h"

int main()
{
    Fila* f = criaFila(5);

    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);
    enqueue(f, 50);

     if (enqueue(f, 60) == -1)
        printf("Fila cheia! Não foi possível inserir 60.\n");

    imprimeFila(f);

    
    // Remove dois elementos
    int valor;
    dequeue(f, &valor);
    printf("Removido: %d\n", valor);
    dequeue(f, &valor);
    printf("Removido: %d\n", valor);

    // Imprime novamente após remoções
    imprimeFila(f);

    // Insere mais dois elementos pra testar circularidade
    enqueue(f, 60);
    enqueue(f, 70);

    // Imprime novamente
    imprimeFila(f);

    return 0;
}