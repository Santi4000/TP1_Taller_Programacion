#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "tablero.h"

Pila *crearPila(){
    Pila *pila = malloc(sizeof(Pila));
    pila->top = NULL; //se inicializa vacia
    return pila;
}

void destruirPila(Pila *pila){
    NodoPila *actual = pila->top;

    while(actual){
         NodoPila *actual = pila->top;
        while (actual) {
            NodoPila *sig = actual->sig;
            free(actual);
            actual = sig;
        }
    free(pila);
    }
}

void apilarPila(Pila *pila, int **tablero){
    NodoPila *nuevoNodo = malloc(sizeof(NodoPila));

    nuevoNodo->tablero = tablero;
    nuevoNodo->sig = pila->top;

    pila->top = nuevoNodo;
}
int **desapilarPila(Pila *pila){

    if(pilaVacia(pila))
        return NULL;

    NodoPila *aux = pila->top;
    int **tablero = aux->tablero;
    pila->top = aux->sig;

    free(aux);

    return tablero;
}
int pilaVacia(Pila *pila){
    return (!pila || pila->top == NULL);
}

