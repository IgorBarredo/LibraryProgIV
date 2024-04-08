
#include "autor.h"
#include "editorial.h"
#include "categoria.h"
typedef struct{
	char *title;
	char *date;
    Autor *autor;
    int cantiAurores;
    Editorial *editorial;
    Categoria *categoria;
}Libro;
