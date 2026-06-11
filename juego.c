#include <stdlib.h>
#include "juego.h"

int moverLinea(int v[], int tam){
	int cambio = 0;
    int destino = 0;
	
    for(int i = 0; i < tam; i++){ // Desplazar
        if(v[i] != 0){
            if(i != destino){
                v[destino] = v[i];
                v[i] = 0;
                cambio = 1;
            }
            destino++;
        }
    }

    for(int i = 0; i < tam - 1; i++){ // Fusionar
        if(v[i] != 0 && v[i] == v[i + 1]){
            v[i] *= 2;
            v[i + 1] = 0;
            cambio = 1;
        }
    }

    // Desplazar de nuevo
    destino = 0;
    for(int i = 0; i < tam; i++){
        if(v[i] != 0){
            if(i != destino){
                v[destino] = v[i];
                v[i] = 0;
            }
            destino++;
        }
    }
    return cambio;
}
