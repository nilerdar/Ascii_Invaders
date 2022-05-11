//Dario Llodra Barron 1ºINSO A
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "objetos.h"
#include "tablero.h"

// Programa principal

int main(int argc, char **argv) {
    /*int numFilas = 0;
    int numColumnas = 0;
    printf("Introduzca el tamaño del tablero, filas:\n");
    scanf("%d", &numFilas);
    printf("Columnas:\n");
    scanf("%d", &numColumnas);
    getchar();
    objeto_t **tablero = reservaTablero(numFilas, numColumnas);
    iniciaTableroConDatos(tablero,numFilas,numColumnas,argc, argv);
    do {
        dibujaTablero(tablero, numFilas, numColumnas);
        actualizaTablero(tablero, numFilas, numColumnas);
    } while (buscaPersonaje(tablero, numFilas, numColumnas));
    for (int i = 0; i < numFilas; ++i) {
        free(tablero[i]);
    }
    free(tablero);
    printf("Fin del juego\n");*/
    CrearObjetoConDatos(argv[1]);
    return 0;
}



