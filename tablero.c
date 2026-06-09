#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprimirTablero(int **arr, int tam){
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (!arr[i][j])
				printf("[    ]"); //celda vacía
			else
				printf("[%4d]", arr[i][j]); //celdas con un tamaño de 4 caracteres.
		}
		printf("\n");
	}
	printf("\n");
}

void destruirTablero(int **tablero, int tam){
    if(tablero == NULL)
        return;

    for(int i = 0; i < tam; i++){
        free(tablero[i]);
    }

    free(tablero);
}

int tomarNum(void){
	int chance = rand() % 4;
	if (chance == 0)
		return 4;
	else
		return 2;
}

void elegirCelda(int **arr, int dato, int tam){ // toma el arreglo, el entero a ingresar y la cantidad de filas/columnas
	int contador = 0;
	int coords [tam * tam * 2];
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (arr[i][j] == 0){ //Comprobar si la celda està vacìa. Si es verdadero, guardar las coordenadas y aumentar 2 al contador.
				coords[contador] = i;
				coords[contador+1] = j;
				contador += 2;
			}
		}
	}
	if(contador == 0)
		return;
	int num = (rand() % (contador / 2)) * 2; //nùmero aleatorio con respecto a la cantidad de celdas vacìa
	arr [coords[num]] [coords[num+1]] = dato; //se le asigna el valor, paràmetro de la funciòn
}

int estadoJuego(int **arr, int tam){ // 0 -> sigue juegando; 1 -> perdió; 2 -> ganó
	int hayHuecos = 0;
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (arr[i][j] == 2048)
				return 2; //resultado para ganar
			if (arr[i][j] == 0)
				hayHuecos = 1;
		}
	}

	if (hayHuecos)
		return 0; //resultado para seguir jugando

	//verificar si hay números iguales contiguos horizontalmente
	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam - 1; j++){ // (j < tam - 1) para que no se acceda a memoria no permitida
		if(arr[i][j] == arr[i][j+1]) 
			return 0;
		}
	}

	//verificar si hay números iguales contiguos verticalmente
	for (int i = 0; i < tam - 1; i++){ // (i < tam - 1) para que no se acceda a memoria no permitida
		for (int j = 0; j < tam; j++){ 
		if(arr[i][j] == arr[i+1][j]) 
			return 0;
		}
	}

	return 1; //perdió 
}

int **copiarTablero(int **tablero, int tam){     // se guarda una copia pq sino todos los 
    int **copia = malloc(tam * sizeof(int *));   // nodos estarian apuntando al mismo tablero

    for(int i = 0; i < tam; i++){
        copia[i] = malloc(tam * sizeof(int));

        for(int j = 0; j < tam; j++)
            copia[i][j] = tablero[i][j];
    }

    return copia;
}