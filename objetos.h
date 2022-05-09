//Dario Llodra Barron 1ºINSO A

#ifndef __OBJETOS_H__
#define __OBJETOS_H__
#include "tipos.h"

objeto_t CrearObjeto(tipoObjeto_e tipo);
tipoObjeto_e dameTipo(char* strTipo);
direccion_e dameDireccion(char* strDir);
objeto_t CrearObjetoConDatos(char* cadena);
#endif
