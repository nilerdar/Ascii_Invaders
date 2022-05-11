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
    objeto_t objeto;

    char *cadena2 = (char *) calloc(strlen(cadena) + 1, sizeof(char));
    char *aux = NULL, *aux2 = NULL, *aux3 = NULL;
    strcpy(cadena2, cadena);
    if (strcmp(strtok(cadena2, "["), "objeto") == 0) {
        while ((aux2 = strtok(NULL, ","))) {
            aux = strtok(NULL, "=");
            if (!strcmp(aux, "movimientos")) {
                aux = aux2;
                aux = strtok(aux, "=");
                aux2 = strtok(NULL, "=");
            }
            if (strstr(aux2, "]"))aux2 = strtok(aux2, "]");
            if (!strcmp(aux, "posX",4)) {
                posX = strtol(aux2, NULL, 10);
            }
            if (!strncmp(aux, "posY",4)) {
                posY = strtol(aux2, NULL, 10);
            }
            if (!strncmp(aux, "vida",4)) {
                hp = strtol(aux2, NULL, 10);
            }
            if (!strcmp(aux, "puntuacion")) {
                score = strtol(aux2, NULL, 10);
            }
            if (!strcmp(aux, "danio")) {
                dmg = strtol(aux2, NULL, 10);
            }
            if (!strcmp(aux, "x")) {
                x = strtol(aux2, NULL, 10);
            }
            if (!strcmp(aux, "y")) {
                y = strtol(aux2, NULL, 10);
            }
            if (!strcmp(aux, "sprite")) {
                sprite = aux2[0];
            }
            if (!strcmp(aux, "direccion")) {
                direccionE = dameDireccion(aux2);
            }
            if (!strcmp(aux, "tipo")) {
                tipoObjetoE = dameTipo(aux2);
            }
            printf("%d %d %c\n", posX, posY, sprite);
            printf("%d %d \n", x, y);
        }
    } else {
        printf("Error");
    }
    objeto.x = posX;
    objeto.y = posY;
    objeto.sprite = sprite;
    objeto.tipo = tipoObjetoE;
    switch (objeto.tipo) {
        case misil:
            objeto.misil = CrearMisilConDatos(dmg, direccionE);
            break;
        case enemigo:
            objeto.enemigo = CrearEnemigoConDatos(hp, score, movs);
            break;
        case personaje:
            objeto.personaje = CrearPersonajePrincipalConDatos(hp, score);
            break;
    }
    return objeto;
}