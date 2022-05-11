//Dario Llodra Barron 1ºINSO A

#ifndef __TIPOS_H__
#define __TIPOS_H__

// Tipos enumerados.
// Crear un tipo enumerado direccion_e, que se usará para indicar la dirección de los misiles
typedef enum direccion_e{
    asc,
    desc
}direccion_e;
// Crear un tipo enumerado tipoObjeto_e, que se usará para indicar el tipo de objeto que 
// se usará en el juego. Hay tres tipos:
// enemigo, misil, personaje
typedef enum tipoObjeto_e{
    enemigo,
    misil,
    personaje
}tipoObjeto_e;


// Estructuras
// Estructura "movimiento_t" usada por los enemigos, indica la dirección del siguiente movimiento
typedef struct movimiento_t{
    int x;
    int y;
}movimiento_t;

// Estructura "enemigo_t" con los datos de los enemigos
typedef struct enemigo_t{
    int hp;
    int score;
    movimiento_t *mov;
    int tam;
    int pos;
}enemigo_t;

// Estructura misil_t con los datos de los misiles, y la dirección (tipo enumerado) a 
// la que se desplaza en cada turno
typedef struct misil_t{
    int dmg;
    direccion_e direccion;
}misil_t;

// Estructura personaje_t con los datos del personaje principal
typedef struct personaje_t{
    int hp_main;
    int score_main;
}personaje_t;


// Estructura de objeto genérico, puede ser cualquiera de los 3 anteriores. 
// Para ello se usará una variable enumerada "tipo", y tendrá las tres estructuras
// anteriores anidadas. Sólo habrá datos es la estructura indicada por la variable "tipo"
typedef struct objeto_t{
    int x;
    int y;
    int active;
    tipoObjeto_e tipo;
    char sprite;
    union {
        enemigo_t enemigo;
        misil_t misil;
        personaje_t personaje;
    };

}objeto_t;

#endif
