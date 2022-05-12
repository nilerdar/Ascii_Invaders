//Dario Llodra Barron 1ºINSO A

#include "enemigo.h"

//Añadir función para crear un enemigo con valores por defecto (todo a 0).
enemigo_t CrearEnemigo() {
    enemigo_t enemigo1;
    enemigo1.hp = 0;
    enemigo1.score = 0;
    enemigo1.tam = 4;
    enemigo1.pos = 0;

    enemigo1.mov[0].x = 1;
    enemigo1.mov[0].y = 0;

    enemigo1.mov[1].x = 0;
    enemigo1.mov[1].y = 1;

    enemigo1.mov[2].x = -1;
    enemigo1.mov[2].y = 0;

    enemigo1.mov[3].x = 0;
    enemigo1.mov[3].y = -1;

    return enemigo1;
}

void mueveEnemigo(objeto_t *objeto, int numFilas, int numColumnas) {
    objeto->x = objeto->x + objeto->enemigo.mov[objeto->enemigo.pos].x;
    objeto->y = objeto->y + objeto->enemigo.mov[objeto->enemigo.pos].y;
    if (objeto->x >= numColumnas || objeto->x < 0) {
        objeto->x = objeto->x - objeto->enemigo.mov[objeto->enemigo.pos].x;
    }
    if (objeto->y >= numFilas || objeto->y < 0) {
        objeto->y = objeto->y - objeto->enemigo.mov[objeto->enemigo.pos].y;
    }
    objeto->enemigo.pos++;
    if (objeto->enemigo.pos >= objeto->enemigo.tam) {
        objeto->enemigo.pos = 0;
    }
}

enemigo_t CrearEnemigoConDatos(int hp, int score,movimiento_t* movs){
    enemigo_t enemigo_1;

    enemigo_1.hp=hp;
    enemigo_1.score=score;
    enemigo_1.mov=movs;
    enemigo_1.pos=0;
    enemigo_1.tam=4;
    return enemigo_1;
}