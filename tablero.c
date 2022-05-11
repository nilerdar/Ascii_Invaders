//Dario Llodra Barron 1ºINSO A
#include "tablero.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "objetos.h"
#include "misil.h"
#include "enemigo.h"
#include "personaje.h"

void iniciaTablero(objeto_t **tablero, int numFilas, int numColumnas) {
    int numEn = 0, numMis = 0;
    //iniciar el random
    srand(getpid());
    //inicializar el tablero con objetos "no activos"
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            tablero[i][j].active = 0;
        }
    }
    //numero de enemigos entre 1 y 3
    numEn = rand() % 3 + 1;
    //numero de misiles entre 2 y 5
    numMis = rand() % 4 + 2;
    //aniadir Enemigos
    //la posición está en la mitad superior del tablero (Y<=(numFilas/2))

    for (int i = 0; i < numEn; i++) {
        objeto_t enemig = CrearObjeto(enemigo);
        enemig.x = rand() % numColumnas;
        enemig.y = rand() % (numFilas / 2);
        tablero[enemig.y][enemig.x] = enemig;
    }

    //aniadir misiles
    //cualquier posición del tablero
    for (int i = 0; i < numMis; i++) {
        objeto_t mis = CrearObjeto(misil);
        mis.x = rand() % numColumnas;
        mis.y = rand() % numFilas;
        tablero[mis.y][mis.x] = mis;
    }

    //el  personaje principal está en la fila más inferior del tablero, en una columna aleatoria
    objeto_t pj = CrearObjeto(personaje);
    pj.x = rand() % numColumnas;
    pj.y = numFilas - 1;
    tablero[pj.y][pj.x] = pj;
}

objeto_t **reservaTablero(int numFilas, int numColumnas) {
    objeto_t **tablero = calloc(numFilas, sizeof(objeto_t));
    for (int i = 0; i < numFilas; i++) {
        tablero[i] = calloc(numColumnas, sizeof(objeto_t));
    }
    return tablero;
}

void actualizaTablero(objeto_t **tablero, int numFilas, int numColumnas) {
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            if (tablero[i][j].active) {
                switch (tablero[i][j].tipo) {
                    case enemigo:
                        mueveEnemigo(&tablero[i][j], numFilas, numColumnas);
                        break;
                    case misil:
                        mueveMisil(&tablero[i][j], numFilas, numColumnas);
                        break;
                    case personaje:
                        muevePersonaje(&tablero[i][j], numFilas, numColumnas);
                        break;
                }
            }
        }
    }
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            if (tablero[i][j].active) {
                if (i != tablero[i][j].y || j != tablero[i][j].x) {
                    int newX = tablero[i][j].x;
                    int newY = tablero[i][j].y;
                    if (tablero[newY][newX].active) {
                        switch (tablero[newY][newX].tipo) {
                            case enemigo:
                                if (tablero[i][j].tipo == misil) {
                                    tablero[i][j].active = 0;
                                    tablero[newY][newX].active = 0;
                                }
                                break;
                            case personaje:
                                if (tablero[i][j].tipo == misil) {
                                    tablero[i][j].active = 0;
                                    tablero[newY][newX].active = 0;
                                }
                                break;
                            case misil:
                                if (tablero[i][j].tipo == enemigo) {
                                    tablero[i][j].active = 0;
                                    tablero[newY][newX].active = 0;
                                }
                                break;
                        }
                    } else {
                        tablero[newY][newX] = tablero[i][j];
                        tablero[i][j].active = 0;
                    }
                }
            }
        }
    }
}

int buscaPersonaje(objeto_t **tablero, int numFilas, int numColumnas) {
    int ex = 0;
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            if (tablero[i][j].active && tablero[i][j].tipo == personaje) {
                ex = 1;
            }
        }
    }
    return ex;
}

void iniciaTableroConDatos(objeto_t **tablero, int numFilas, int numColumnas, int numObjetos, char **datos) {
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            tablero[i][j].active = 0;
        }
    }
    for (int i = 1; i < numObjetos; i++) {
        objeto_t objeto1 = CrearObjetoConDatos(datos[i]);
        if (objeto1.y < 0 || objeto1.y >= numFilas || objeto1.x < 0 || objeto1.x >= numColumnas){
            printf("objeto fuera de tablero");
        }else{
            tablero[objeto1.y][objeto1.x] = objeto1;
        }
    }
}

void dibujaTablero(objeto_t **tablero, int numFilas, int numColumnas) {
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            if (tablero[i][j].active == 1) {
                printf("%c", tablero[i][j].sprite);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


