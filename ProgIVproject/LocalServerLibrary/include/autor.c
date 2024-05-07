#include <stdlib.h>
#include <string.h>
#include "autor.h"

Autor *crear_autor(const char *nombre, const char *fecha_nacimiento, const char *lugar_nacimiento) {
    Autor *autor = (Autor *)malloc(sizeof(Autor));
    if (autor == NULL) {
        return NULL;
    }

    autor->name = strdup(nombre);
    autor->date = strdup(fecha_nacimiento);
    autor->place = strdup(lugar_nacimiento);

    return autor;
}

void destruir_autor(Autor *autor) {
    free(autor->name);
    free(autor->date);
    free(autor->place);
    free(autor);
}

void imprimir_autor(Autor autor){
    printf("%s;%s;%s\n", autor.name, autor.date, autor.place);

}

void nombreAutor(Autor *autor, char *nombre){
    strdup(autor->name);
    strcpy(nombre, autor->name);
}

void fechaNacimiento(Autor *autor, char *fecha){
    strdup(autor->date);
    strcpy(fecha, autor->date);
}

void lugarNacimiento(Autor *autor, char *lugar){
    strdup(autor->place);
    strcpy(lugar, autor->place);
}