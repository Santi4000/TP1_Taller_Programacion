int tomarNum(){
    double chance = (double)rand() % 4;
    if (chance > 3)
        return 2;
    else
        return 4;
}

void chooseCell(int **arr, int dato, int tamaño){ // toma el arreglo, el entero a ingresar y la cantidad de filas/columnas
    int contador = 0;
    int coords [tamaño*2];
    for (int i=0; i<tamaño; i++){
        for (int j=0; j<tamaño; j++){
            if (arr[i][j] == 0) //Comprobar si la celda està vacìa. Si es verdadero, guardar las coordenadas y aumentar 2 al contador.
                contador = contador + 2;
                coords[contador-1] = i;
                coords[contador] = j;
        }
    }
    int num = rand() % (contador / 2 + 1) * 2; //nùmero aleatorio con respecto a la cantidad de celdas vacìa
    arr [coords[num-1]] [coords[num]] = data; //se le asigna el valor, paràmetro de la funciòn
}
