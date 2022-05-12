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
    int posX = 0, posY = 0, hp = 0, score = 0, dmg = 0, x = 0, y = 0, offsetX = 0, offsetY = 0;
    char sprite;
    direccion_e direccionE = desc;
    tipoObjeto_e tipoObjetoE;
    objeto_t objeto;
    movimiento_t *mov;
    int *Xs = calloc(1, sizeof(int));
    int *Ys = calloc(1, sizeof(int));
    int i = 0;
    char *cadena2 = (char *) calloc(strlen(cadena) + 1, sizeof(char));
    char *cadena3 = (char *) calloc(strlen(cadena) + 1, sizeof(char));
    char *aux = NULL, *aux2 = NULL, *aux3 = NULL, *aux4 = NULL;
    strcpy(cadena2, cadena);
    strcpy(cadena3, cadena);
    if (strcmp(strtok(cadena2, "["), "objeto") == 0) {
        while ((aux = strtok(NULL, "="))) {
            aux2 = strtok(NULL, ",");
            if (strstr(aux2, "]"))aux2 = strtok(aux2, "]");
            if (strcmp(aux, "posX") == 0) {
                posX = strtol(aux2, NULL, 10);
            }
            if (strcmp(aux, "posY") == 0) {
                posY = strtol(aux2, NULL, 10);
            }
            if (strcmp(aux, "vida") == 0) {
                hp = strtol(aux2, NULL, 10);
            }
            if (strcmp(aux, "puntuacion") == 0) {
                score = strtol(aux2, NULL, 10);
            }
            if (strcmp(aux, "danio") == 0) {
                dmg = strtol(aux2, NULL, 10);
            }
            if (strcmp(aux, "sprite") == 0) {
                sprite = aux2[0];
            }
            if (strcmp(aux, "direccion") == 0) {
                direccionE = dameDireccion(aux2);
            }
            if (strcmp(aux, "tipo") == 0) {
                tipoObjetoE = dameTipo(aux2);
            }
        }
    } else {
        printf("Error\n");
    }
    aux3 = strtok(cadena3, "]");
    aux3 = strtok(aux3, "[");
    aux3 = strtok(NULL, "[");
    aux3 = strtok(aux3, ",");
    int j = 0;
    char *tipo, *valor;
    while (aux3 != NULL) {
        aux3 = strtok(NULL, ",");
        if (j == 1 && aux3 != NULL) {
            valor = aux3;
            if (strcmp(tipo, "x") == 0) {
                x = strtol(valor, NULL, 10);
                Xs = realloc(Xs, sizeof(int) * offsetX + 1);
                Xs[offsetX] = x;
                offsetX++;
            }
            if (strcmp(tipo, "y") == 0) {
                y = strtol(valor, NULL, 10);
                Ys = realloc(Ys, sizeof(int) * offsetY + 1);
                Ys[offsetY] = y;
                offsetY++;
            }
        }
        aux3 = strtok(NULL, "=");
        if (j == 1 && aux3 != NULL) {
            tipo = aux3;
        }
        if (aux3 != NULL && strcmp(aux3, "movimientos") == 0) {
            j = 1;
            aux3 = strtok(NULL, "=");
            tipo = aux3;
        }
    }

    mov = calloc(offsetX, sizeof(movimiento_t) * offsetX);
    for (int j = 0; j < offsetX; j++) {
        mov[j].x = Xs[j];
        mov[j].y = Ys[j];
    }

    objeto.x = posX;
    objeto.y = posY;
    objeto.sprite = sprite;
    objeto.tipo = tipoObjetoE;
    objeto.active=1;
    switch (objeto.tipo) {
        case misil:
            objeto.misil = CrearMisilConDatos(dmg, direccionE);
            break;
        case enemigo:
            objeto.enemigo = CrearEnemigoConDatos(hp, score, mov);
            break;
        case personaje:
            objeto.personaje = CrearPersonajePrincipalConDatos(hp, score);
            break;
    }
    free(cadena2);
    free(cadena3);
    free(Xs);
    free(Ys);
    return objeto;
}