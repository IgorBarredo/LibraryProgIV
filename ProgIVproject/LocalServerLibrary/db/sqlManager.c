#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autor.h"
#include "categoria.h"
#include "editorial.h"
#include "sqlite3.h"

sqlite3* abrirDB() {
    sqlite3 *db;
    int result = sqlite3_open("biblioteca.db", &db);
    if (result != SQLITE_OK) {
        printf("Error opening database\n");
        return NULL;
    }
    return db;
}
void cerrarDB(sqlite3 *db) {
    sqlite3_close(db);
}



void insertarAutor(Autor objAutor) {
    sqlite3 *db = abrirDB();
    int result;

    sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO autor (nombre_a, fecha_ncto, lugar_ncto) VALUES (?, ?, ?)";

	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	sqlite3_bind_text(stmt, 1, objAutor.name, strlen(objAutor.name), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, objAutor.date, strlen(objAutor.date), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, objAutor.place, strlen(objAutor.place), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting data: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error inserting data");
	}

	cerrarDB(db);
}

void insertarCategoria(Categoria objCategoria) {
    sqlite3 *db = abrirDB();
    int result;

    sqlite3_stmt *stmt;
    char sql[] = "INSERT INTO categoria (nombre_c) VALUES (?)";

    result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (result != SQLITE_OK) {
        printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
        guardarErrorEnLog("Error preparing statement");
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, objCategoria.name, strlen(objCategoria.name), SQLITE_STATIC);

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        guardarErrorEnLog("Error inserting data");
    }
    sqlite3_finalize(stmt);
    cerrarDB(db);
}

void insertarEditorial(Editorial objEditorial) {
    sqlite3 *db = abrirDB();
    int result;

    sqlite3_stmt *stmt;
    char sql[] = "INSERT INTO editorial (nombre_e, fecha_fundacion) VALUES (?, ?)";

    result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (result != SQLITE_OK) {
        printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
        guardarErrorEnLog("Error preparing statement");
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, objEditorial.nombre, strlen(objEditorial.nombre), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, objEditorial.fecha, strlen(objEditorial.fecha), SQLITE_STATIC);

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        guardarErrorEnLog("Error inserting data");
    }
    
    sqlite3_finalize(stmt);
    cerrarDB(db);
}

void mostrarAutores() {
	sqlite3 *db = abrirDB();
	int result;
   
	// Preparar el statement SQL para recuperar los nombres de los autores
	sqlite3_stmt *stmt4;
	char sql[] = "SELECT id_aut, nombre_a FROM autor";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt4, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	// Ejecutar la consulta y recuperar los nombres de los autores
	printf("Autores:\n");
	while (sqlite3_step(stmt4) == SQLITE_ROW) {
		const unsigned char *codAut = sqlite3_column_text(stmt4, 1);
		printf("%s\n", codAut);
	}
	// Finalizar la consulta anterior
	sqlite3_finalize(stmt4);
	cerrarDB(db);
}

void seleccionarAutor() {
	sqlite3 *db = abrirDB();
	int result;

	// Prompt el usuario para seleccionar un autor
	int selectedAuthor;
	printf("Escriba el codigo del autor que desea seleccionar: ");
	scanf("%d", &selectedAuthor);

	// Preparar el statement SQL para recuperar los títulos de los libros del autor seleccionado
	sqlite3_stmt *stmt5;
	const char *sql5 = "SELECT titulo FROM libro WHERE id_aut = ?";
	result = sqlite3_prepare_v2(db, sql5, strlen(sql5) + 1, &stmt5, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	// Vincular el valor del ID del autor al marcador de posición
	result = sqlite3_bind_int(stmt5, 1, selectedAuthor);
	if (result != SQLITE_OK) {
		printf("Error binding parameter: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error binding parameter");
		sqlite3_finalize(stmt5);
		sqlite3_close(db);
		return;
	}

	// Ejecutar la consulta y recuperar los títulos de los libros
	printf("Libros del autor %d:\n", selectedAuthor);
	while (sqlite3_step(stmt5) == SQLITE_ROW) {
		const unsigned char *bookTitle = sqlite3_column_text(stmt5, 0);
		printf("%s\n", bookTitle);
	}

	// Clean up
	sqlite3_finalize(stmt5);
	cerrarDB(db);
}



void buscarLibroPorTitulo(char *titulo) {
    // Abrir la base de datos
    sqlite3 *db = abrirDB();
    int result;
    // Preparar el statement SQL para buscar libros por título
	sqlite3_stmt *stmt;
	const char *sql = "SELECT id_libro, titulo FROM libro WHERE titulo LIKE ?";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}
    // Vincular el valor del título al marcador de posición
	result = sqlite3_bind_text(stmt, 1, titulo, strlen(titulo), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameter: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error binding parameter");
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return;
	}
    // Ejecutar la consulta y recuperar los títulos de los libros
	printf("Lista de libros con título similar a '%s':\n", titulo);
	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		int bookId = sqlite3_column_int(stmt, 0);
		const unsigned char *bookTitle = sqlite3_column_text(stmt, 1);
		printf("Código: %d, Título: %s\n", bookId, bookTitle);
	}

    // Clean up
	sqlite3_finalize(stmt);

    // Prompt el usuario para ingresar el código del libro seleccionado
	int selectedBookId;
	printf("Ingrese el código del libro que desea ver: ");
	scanf("%d", &selectedBookId);

    // Preparar el statement SQL para buscar el libro por código
	sqlite3_stmt *stmt2;
	const char *sql2 = "SELECT * FROM libro WHERE id_libro = ?";
	result = sqlite3_prepare_v2(db, sql2, strlen(sql2) + 1, &stmt2, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

    // Vincular el valor del código al marcador de posición
	result = sqlite3_bind_int(stmt2, 1, selectedBookId);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameter: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error binding parameter");
		sqlite3_finalize(stmt2);
		sqlite3_close(db);
		return;
	}

    // Ejecutar la consulta y recuperar los datos del libro
	if (sqlite3_step(stmt2) == SQLITE_ROW)
	{
		int bookId = sqlite3_column_int(stmt2, 0);
		const unsigned char *bookTitle = sqlite3_column_text(stmt2, 1);
		const unsigned char *bookAuthor = sqlite3_column_text(stmt2, 2);
		const unsigned char *bookCategory = sqlite3_column_text(stmt2, 3);
		const unsigned char *bookEditorial = sqlite3_column_text(stmt2, 4);
		const unsigned char *bookYear = sqlite3_column_text(stmt2, 5);

		// Obtener los demás datos del libro y mostrarlos
		printf("Código: %d\n", bookId);
		printf("Título: %s\n", bookTitle);
		printf("Autor: %s\n", bookAuthor);
		printf("Categoría: %s\n", bookCategory);
		printf("Editorial: %s\n", bookEditorial);
		printf("Año: %s\n", bookYear);
		
	}
	else
	{
		printf("No se encontró un libro con el código %d\n", selectedBookId);
	}
    // Clean up
	sqlite3_finalize(stmt2);
    cerrarDB(db);
	

}
	
	

	
	

	

	