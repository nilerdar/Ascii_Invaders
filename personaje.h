//Dario Llodra Barron 1ºINSO A

#ifndef __PERSONAJE_H__
#define __PERSONAJE_H__
#include "tipos.h"

personaje_t CrearPersonajePrincipal();
void muevePersonaje(objeto_t* objeto, int numFilas, int numColumnas);
personaje_t CrearPersonajePrincipalConDatos(int hp, int score);
#endif
