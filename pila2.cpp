#include <stdlib.h>
#include <stdio.h>

#define N 20
#ifndef NODEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

typedef struct{
    int data[N];
    int cima;
}Pila;


void push(int dato, Pila *pushing){
    (pushing)->data[(pushing)->cima] = dato;
    (pushing)->cima++;
    DEBUG("-> %5i\n", dato);
}

int pop(Pila *poping){
    (poping)->cima--;
    DEBUG("<- %5i\n", (poping)->data[(poping)->cima]);
}

int main(){

    Pila pila;
    pila.cima = 0;

    push(9,&pila);
    push(4,&pila);
    push(0,&pila);

    pop(&pila);
    pop(&pila);

    push(14,&pila);

    return EXIT_SUCCESS;
}
