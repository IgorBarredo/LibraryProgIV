#ifdef libro_H
#define libro_H
#include "autor.h"
#include "editorial.h"
#include "categoria.h"
typedef struct{
	char *title;
	char *date;
    Autor *autor;
    Editorial *editorial;
    Categoria *categoria;
}Libro;

#endif