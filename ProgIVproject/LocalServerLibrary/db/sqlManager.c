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

	

	
	

	

	

	