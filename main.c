#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juego.h"
#include "pila.h"
#include "tablero.h"

int main(int argc, char *argv[]) {
    // Verificar argumento
    if (argc != 2) {
        printf("Uso: %s <tamano>\n", argv[0]);
        printf("Ejemplo: %s 4\n", argv[0]);
        return 1;
    }
    
    int TAM = atoi(argv[1]);
    
    
    srand(time(NULL));
    
    // Inicializar tablero
    int **tablero = malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++) {
        tablero[i] = calloc(TAM, sizeof(int));
    }
    
    // Agregar dos fichas iniciales
    elegirCelda(tablero, tomarNum(), TAM);
    elegirCelda(tablero, tomarNum(), TAM);
    
    // Crear pila para deshacer
    Pila *pila = crearPila();
    
    int estado = 0;
char opcion;

printf("\n=== 2048 - Tablero %dx%d ===\n", TAM, TAM);
printf("Comandos: w(arriba) s(abajo) a(izquierda) d(derecha) u(deshacer) q(salir)\n\n");

while(estado == 0){

    imprimirTablero(tablero, TAM);

    printf("Movimiento: ");
    scanf(" %c", &opcion);

    int **copia = copiarTablero(tablero, TAM);

    int movio = 0;
    int direccion = -1;

    switch(opcion){

        case 'a':
            direccion = 0;
            break;

        case 'd':
            direccion = 1;
            break;

        case 'w':
            direccion = 2;
            break;

        case 's':
            direccion = 3;
            break;

        case 'u':{
            int **anterior = desapilarPila(pila);

            if(anterior){
                destruirTablero(tablero, TAM);
                tablero = anterior;
                printf("Movimiento deshecho!\n");
            }
            else{
                printf("No hay movimientos para deshacer!\n");
            }

            destruirTablero(copia, TAM);
            continue;
        }

        case 'q':
            printf("¡Gracias por jugar!\n");
            destruirTablero(copia, TAM);
            destruirTablero(tablero, TAM);
            destruirPila(pila);
            return 0;

        default:
            printf("Comando no válido. Use w/a/s/d/u/q\n");
            destruirTablero(copia, TAM);
            continue;
    }

    movio = mover(tablero, TAM, direccion);

    if(movio){

        apilarPila(pila, copia);

        elegirCelda(tablero, tomarNum(), TAM);

        estado = estadoJuego(tablero, TAM);

        if(estado == 2){
            imprimirTablero(tablero, TAM);
            printf("¡FELICIDADES! ¡Llegaste a 2048!\n");
        }
        else if(estado == 1){
            imprimirTablero(tablero, TAM);
            printf("GAME OVER - No hay movimientos posibles\n");
        }

    }
    else{

        destruirTablero(copia, TAM);
        printf("Movimiento no válido - intenta otra dirección\n");

    }
}
    
    // Liberar memoria
    destruirTablero(tablero, TAM);
    destruirPila(pila);
    
    return 0;
}
