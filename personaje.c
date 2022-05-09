//Dario Llodra Barron 1ºINSO A

#include "personaje.h"
#include <stdio.h>

//Añadir función para crear un personaje con valores por defecto (todo a 0).
personaje_t CrearPersonajePrincipal() {
    personaje_t personaje1;
    personaje1.hp_main = 0;
    personaje1.score_main = 0;
    return personaje1;
}

void muevePersonaje(objeto_t *objeto, int numFilas, int numColumnas) {
    char opc = 0;
    printf("A”: Mover izquierda una unidad\n“D”: Mover derecha una unidad\n“S”: Acabar el juego\n");
    scanf("%c", &opc);
    switch (opc) {
        case 'A':
            objeto->x--;
            break;
        case 'D':
            objeto->x++;
            break;
        case 'S':
            objeto->active = 0;
            break;
    }
    if (objeto->x >= numColumnas) {
        objeto->x--;
    }
    if (objeto->x < 0) {
        objeto->x++;
    }
}

personaje_t CrearPersonajePrincipalConDatos(int hp, int score){
    personaje_t personaje_1;
    personaje_1.hp_main=hp;
    personaje_1.score_main=score;
    return personaje_1;
}
