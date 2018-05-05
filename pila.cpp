#include <stdio.h>
#include <stdlib.h>


#ifndef NODEGUB
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 20

    typedef struct {
        int data[N];
        int cima;
    }Pila;
void push(int dato, Pila *pushing){

    (pushing)->data[(pushing)->cima] = dato;
    (pushing)->cima++;
 DEBUG("-> %i\n",dato);

//    DEBUG("-> %i\n",(pushing)->data[(pushing)->cima]);
}

int pop(Pila *poping){
      (poping)->cima--;

    DEBUG("<- %i\n",(poping)->data[(poping)->cima]);
      return (poping)->data[(poping)->cima];
}

int cola(Pila *cola){
    int *dato;
    DEBUG("Que dato quieres, dime la posicion: \n");
    scanf(" %i", dato);
  (cola)->cima = *dato;
  DEBUG("Toma tu numero:  %i\n",(cola)->data[*dato]);
  return (cola)->data[*dato];
}
int main() {
  Pila pila;
  pila.cima = 0;

  push(14,&pila);
  push(22,&pila);
  push(6,&pila);
  push(11,&pila);
  push(19,&pila);

  pop(&pila);
  pop(&pila);
  pop(&pila);
  pop(&pila);
  cola(&pila);
  push(44,&pila);




    return EXIT_SUCCESS;

}
