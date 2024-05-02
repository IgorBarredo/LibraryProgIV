#ifndef sqlManager_h
#define sqlManager_h

#include "sqlite3.h"
#include "../include/autor.h"
#include "../include/categoria.h"
#include "../include/editorial.h"


sqlite3* abrirDB();
void cerrarDB(sqlite3 *db);
void insertarAutor(Autor objAutor);
void insertarCategoria(Categoria objCategoria);
void insertarEditorial(Editorial objEditorial);

void mostrarAutores();
void seleccionarAutor(int seleccion);
void buscarLibroPorTitulo(char *titulo);



#endif
