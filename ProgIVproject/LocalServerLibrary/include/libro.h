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
}Libro;
#endif