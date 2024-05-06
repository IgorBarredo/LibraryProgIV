#ifndef LIBRO_H
#define LIBRO_H
#include "autor.h"
#include "editorial.h"
#include "categoria.h"
typedef struct{
	char *title;
	char *date;
    Autor **autores;
    int cantAut;
    int cantPag;
    Editorial *editorial;
    Categoria *categoria;
    char* content;
}Libro;

Libro *crear_libro(const char *titulo, Autor **autores, int cantidad_autores, int cantidad_paginas, Editorial *editorial, int ano);
void destruir_libro(Libro *libro);
#endif