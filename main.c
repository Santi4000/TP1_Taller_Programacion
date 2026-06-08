// PROTOTIPOS

int tomarNum(void);

void elegirCelda(int **arr, int dato, int tam);

void imprimirTablero(int **arr, int tam);

int estadoJuego(int **arr, int tam);

int direccion(int **arr, int tam);

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

int main(){
	
	return 0;
}

// DEFINICIONES

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

void imprimirTablero (int **arr, int tam){
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


int direccion(int **arr, int tam){
	char info;

	while(1){
		printf("\nIngrese la dirección del movimiento (w / a / s / d): ");
		scanf(" %c", &info);

		switch(info){
			case 'a':
				return movIzquierda(arr, tam);

			case 'd':
				return movDerecha(arr, tam);

			case 'w':
				return movArriba(arr, tam);

			case 's':
				return movAbajo(arr, tam);

			default:
				printf("Caracter inválido.\n");
		}
	}
}

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
