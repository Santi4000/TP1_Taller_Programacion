#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "tablero.c"

Pila *crearPila(){
    Pila *pila = malloc(sizeof(Pila));
    pila->top = NULL; //se inicializa vacia
    pila->tamaño = 0;
    return pila;
}

void destruirPila(Pila *pila){
    NodoPila *actual = pila->top;
    while (actual){
        NodoPila *sig = actual->sig;
        destruirTablero(actual->tablero); //tengo que definirla tdv
        free(actual);
        actual = sig;
    }
    free(pila);
}

void apilarPila(Pila *pila, Tablero *tablero){
    NodoPila nuevoNodo* = malloc(sizeof(NodoPila));

    nuevoNodo->actual = tablero;
    nuevoNodo->sig = pila->top;

    pila->top = nuevoNodo;
}

Tablero desapilarPila(Pila *pila){
    NodoPila *nuevoNodo = pila->top;
    Tablero *tablero = nuevoNodo->tablero;
    pila->top = nuevoNodo->sig;
    free(nuevoNodo);
    return tablero;
}

int pilaVacia(Pila *pila){
    return (!pila || pila->top == NULL);
}

