#ifndef JUEGO_H
#define JUEGO_H

int movIzquierda(int **arr, int tam);
int desplazarIz(int **arr, int tam);
int fusionIz(int **arr, int tam);

int movDerecha(int **arr, int tam);
int desplazarDe(int **arr, int tam);
int fusionDe(int **arr, int tam);

int movArriba(int **arr, int tam);
int desplazarAr(int **arr, int tam);
int fusionAr(int **arr, int tam);

int movAbajo(int **arr, int tam);
int desplazarAb(int **arr, int tam);
int fusionAb(int **arr, int tam);

#endif