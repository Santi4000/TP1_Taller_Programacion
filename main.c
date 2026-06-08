int tomarNum(){
    double chance = (double)rand() % 4;
    if (chance > 3)
        return 2;
    else
        return 4;
}

void elejirCelda(int **arr, int dato, int tamaño){ // toma el arreglo, el entero a ingresar y la cantidad de filas/columnas
    int contador = 0;
    int coords [tamaño * tamaño * 2];
    for (int i=0; i<tamaño; i++){
        for (int j=0; j<tamaño; j++){
            if (arr[i][j] == 0){ //Comprobar si la celda està vacìa. Si es verdadero, guardar las coordenadas y aumentar 2 al contador.
                coords[contador] = i;
                coords[contador+1] = j;
                contador += 2;
            }
        }
    }
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
}

int estadoJuego(int **arr, int tam){ // 0 -> sigue juegando; 1 -> perdió; 2 -> ganó
	int bandera = 0;
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (arr[i][j] == 2048)
				return 2; //resultado para ganar
			if (arr[i][j] == 0)
				bandera = 1; //todavía hay espacios vacíos
		}
	}

	if (bandera)
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

