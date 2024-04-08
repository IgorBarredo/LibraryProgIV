#include <stdlib.h>
#include "libro.h"

Libro *crear_libro(const char *titulo, Autor **autores, int cantidad_autores, int cantidad_paginas, Editorial *editorial, int ano) {
    Libro *libro = (Libro *)malloc(sizeof(Libro));
    if (libro == NULL) {
        return NULL;
    }

    libro->title = strdup(titulo);
    libro->autores = autores;
    libro->cantAut = cantidad_autores;
    libro->cantPag = cantidad_paginas;
    libro->editorial = editorial;
    libro->date = ano;

    return libro;
}

void destruir_libro(Libro *libro) {
    free(libro->title);
    free(libro);
}