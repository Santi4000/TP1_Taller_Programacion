#include <stdlib.h>
#include "juego.h"

int moverLinea(int *arr, int tam){
	int cambio = 0;
    int destino = 0;
	
    for(int i = 0; i < tam; i++){ // Desplazar
        if(arr[i] != 0){
            if(i != destino){
                arr[destino] = arr[i];
                arr[i] = 0;
                cambio = 1;
            }
            destino++;
        }
    }

    for(int i = 0; i < tam - 1; i++){ // Fusionar
        if(arr[i] != 0 && arr[i] == arr[i + 1]){
            arr[i] *= 2;
            arr[i + 1] = 0;
            cambio = 1;
        }
    }

    // Desplazar de nuevo
    destino = 0;
    for(int i = 0; i < tam; i++){
        if(arr[i] != 0){
            if(i != destino){
                arr[destino] = arr[i];
                arr[i] = 0;
            }
            destino++;
        }
    }
    return cambio;
}
