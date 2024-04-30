#ifndef sqlManager_h
#define sqlManager_h

#include "sqlite3.h"
#include "Autor.h"
#include "Categoria.h"
#include "Editorial.h"


sqlite3* abrirDB();
void cerrarDB(sqlite3 *db);
void insertarAutor(Autor objAutor);
void insertarCategoria(Categoria objCategoria);
void insertarEditorial(Editorial objEditorial);

void mostrarAutores();
void seleccionarAutor();
void buscarLibroPorTitulo(char *titulo);



#endif
