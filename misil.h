//Dario Llodra Barron 1ºINSO A

#ifndef __MISIL_H__
#define __MISIL_H__

#include "tipos.h"

misil_t CrearMisil();
void mueveMisil(objeto_t* objeto, int numFilas, int numColumnas);
misil_t CrearMisilConDatos(int dmg,direccion_e dir);
#endif
