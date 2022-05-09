//Dario Llodra Barron 1ºINSO A

#include "objetos.h"
#include "misil.h"
#include "personaje.h"
#include "enemigo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Añadir la función para crear un objeto de un tipo dado. Inicializa sus valores "tipo",
//"sprite" y "posición" dependiendo del tipo indicado. La posición por defecto es "X=0" "Y=0"
// Por defecto, los objetos creados están activos (la variable "activo"=1) 
objeto_t CrearObjeto(tipoObjeto_e tipo) {
    objeto_t objeto;
    objeto.x = 0;
    objeto.y = 0;
    objeto.active = 1;
    objeto.tipo = tipo;
    switch (tipo) {
        case enemigo:
            objeto.enemigo = CrearEnemigo();
            objeto.sprite = 'V';
            break;
        case misil:
            objeto.misil = CrearMisil();
            objeto.sprite = '|';
            break;
        case personaje:
            objeto.personaje = CrearPersonajePrincipal();
            objeto.sprite = 'A';
            break;
    }
    return objeto;
}

direccion_e dameDireccion(char *strDir) {
    direccion_e direccionE;
    if (strcmp(strDir, "ascendente") == 0) {
        direccionE = asc;
    } else if (strcmp(strDir, "descendente") == 0) {
        direccionE = desc;
    } else {
        return 2;
    }
    return direccionE;
}

tipoObjeto_e dameTipo(char *strTipo) {
    tipoObjeto_e tipoObjetoE;
    if (strcmp(strTipo, "misil") == 0) {
        tipoObjetoE = misil;
    } else if (strcmp(strTipo, "enemigo") == 0) {
        tipoObjetoE = enemigo;
    } else if (strcmp(strTipo, "personaje") == 0) {
        tipoObjetoE = personaje;
    }
    return tipoObjetoE;
}

objeto_t CrearObjetoConDatos(char *cadena) {
    int posX = 0, posY = 0, hp = 0, score = 0, dmg = 0, x = 0, y = 0;
    char sprite = '\0';
    direccion_e direccionE = desc;
    tipoObjeto_e tipoObjetoE;

    char *cadena2 = (char *) calloc(strlen(cadena)+1, sizeof(char));
    strcpy(cadena2, cadena);
    if (strcmp(strtok(cadena2, "["), "objeto")==0){

    } else{
        printf("Error");
    }

}