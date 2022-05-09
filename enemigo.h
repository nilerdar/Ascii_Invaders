//Dario Llodra Barron 1ºINSO A

#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__

#include "tipos.h"

enemigo_t CrearEnemigo();
void mueveEnemigo(objeto_t* objeto, int numFilas, int numColumnas);
enemigo_t CrearEnemigoConDatos(int hp, int score,movimiento_t* movs);

#endif
