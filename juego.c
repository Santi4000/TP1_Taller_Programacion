#include <stdlib.h>
#include "juego.h"

int movIzquierda (int **arr, int tam){ //0 -> no cambió; 1 -> cambió
	int cambio = 0;
	cambio += desplazarIz (arr, tam);
	cambio += fusionIz (arr, tam);
	cambio += desplazarIz (arr, tam);
	return cambio != 0;
}


int desplazarIz (int **arr, int tam){ // 0 -> no cambió; 1 -> cambió
    int cambio = 0;
    for(int i = 0; i < tam; i++){
        int destino = 0;
        for(int j = 0; j < tam; j++){
            if(arr[i][j] != 0){
                if(j != destino){
                    arr[i][destino] = arr[i][j];
                    arr[i][j] = 0;
                    cambio = 1;
                }
                destino++;
            }
        }
    }

    return cambio;
}

int fusionIz (int **arr, int tam){ // 0 -> no cambió; 1 -> cambió
	int cambio=0;
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam-1; j++){
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j+1]){
				arr[i][j] = arr[i][j] * 2;
				arr[i][j+1] = 0; 
				cambio = 1;
			}
		}
	}
	return cambio;
}

int movDerecha (int **arr, int tam){ 
	int cambio = 0;
	cambio += desplazarDe (arr, tam);
	cambio += fusionDe (arr, tam);
	cambio += desplazarDe (arr, tam);
	return cambio != 0;
}


int desplazarDe (int **arr, int tam){ 
    int cambio = 0;
    for(int i = 0; i < tam; i++){
        int destino = tam-1;
        for(int j = tam-1; j >= 0; j--){
            if(arr[i][j] != 0){
                if(j != destino){
                    arr[i][destino] = arr[i][j];
                    arr[i][j] = 0;
                    cambio = 1;
                }
                destino--;
            }
        }
    }

    return cambio;
}

int fusionDe (int **arr, int tam){
	int cambio=0;
	for (int i=0; i<tam; i++){
		for (int j=tam-1; j>0; j--){
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j-1]){
				arr[i][j] = arr[i][j] * 2;
				arr[i][j-1] = 0; 
				cambio = 1;
			}
		}
	}
	return cambio;
}

int movArriba (int **arr, int tam){ 
	int cambio = 0;
	cambio += desplazarAr (arr, tam);
	cambio += fusionAr (arr, tam);
	cambio += desplazarAr (arr, tam);
	return cambio != 0;
}


int desplazarAr (int **arr, int tam){
    int cambio = 0;
    for(int j = 0; j < tam; j++){
        int destino = 0;
        for(int i = 0; i < tam; i++){
            if(arr[i][j] != 0){
                if(i != destino){
                    arr[destino][j] = arr[i][j];
                    arr[i][j] = 0;
                    cambio = 1;
                }
                destino++;
            }
        }
    }

    return cambio;
}

int fusionAr (int **arr, int tam){
	int cambio=0;
	for (int j=0; j<tam; j++){
		for (int i=0; i<tam-1; i++){
			if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j]){
				arr[i][j] = arr[i][j] * 2;
				arr[i+1][j] = 0; 
				cambio = 1;
			}
		}
	}
	return cambio;
}

int movAbajo (int **arr, int tam){ 
	int cambio = 0;
	cambio += desplazarAb (arr, tam);
	cambio += fusionAb (arr, tam);
	cambio += desplazarAb (arr, tam);
	return cambio != 0;
}


int desplazarAb (int **arr, int tam){ 
    int cambio = 0;
    for(int j = 0; j < tam; j++){
        int destino = tam-1;
        for(int i = tam-1; i >= 0; i--){
            if(arr[i][j] != 0){
                if(i != destino){
                    arr[destino][j] = arr[i][j];
                    arr[i][j] = 0;
                    cambio = 1;
                }
                destino--;
            }
        }
    }

    return cambio;
}

int fusionAb (int **arr, int tam){
	int cambio=0;
	for (int j=0; j<tam; j++){
		for (int i=tam-1; i>0; i--){
			if (arr[i][j] != 0 && arr[i][j] == arr[i-1][j]){
				arr[i][j] = arr[i][j] * 2;
				arr[i-1][j] = 0; 
				cambio = 1;
			}
		}
	}
	return cambio;
}