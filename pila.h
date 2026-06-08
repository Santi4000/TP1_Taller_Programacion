#ifndef PILA_H
#define PILA_H

#include "tablero.h"

typedef struct NodoPila {
    Tablero *actual;
    struct NodoPila *sig;
} NodoPila;

typedef struct{ 
    NodoPila *top;
} Pila;

Pila *crearPila();
void destruirPila(Pila *pila);

void apilarPila(Pila *pila, Tablero *tablero); //se repite con cada movimiento
void desapilarPila(Pila *pila); // devuelve el tablero
int pilaVacia(Pila *pila); // si es vacia no puede hacer mas undos, no existen

#endif 