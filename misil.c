//Dario Llodra Barron 1ºINSO A

#include "misil.h"

//Añadir la función para crear un misil con valores por defecto (todo a 0, dirección ascendente).
misil_t CrearMisil(){
    misil_t misil1;
    misil1.dmg=0;
    misil1.direccion=asc;
    return misil1;
}

void mueveMisil (objeto_t* objeto, int numFilas, int numColumnas) {
    if (objeto->misil.direccion==asc){
        objeto->y++;
    } else{
        objeto->y--;
    }
    if (objeto->y >= numFilas || objeto->y < 0) {
        objeto->active=0;
    }
}

misil_t CrearMisilConDatos(int dmg,direccion_e dir){
    misil_t misil_1;
    misil_1.dmg=dmg;
    misil_1.direccion=dir;
    return misil_1;
}