#ifndef TABLERO_H
#define TABLERO_H

void imprimirTablero(int **arr, int tam);

void destruirTablero(int **tablero, int tam);

int tomarNum();

void elegirCelda(int **arr, int dato, int tam);

int estadoJuego(int **arr, int tam);

int **copiarTablero(int **tablero, int tam);

#endif