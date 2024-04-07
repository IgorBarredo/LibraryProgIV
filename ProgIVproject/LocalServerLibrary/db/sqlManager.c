#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"

sqlite3* abrirDB() {
    sqlite3 *db;
    int result = sqlite3_open("biblioteca.db", &db);
    if (result != SQLITE_OK) {
		printf("Error opening database\n");
	}
    return db;
}

/*int anadirAutor(){
    sqlite3 *db = abrirDB();
    int resultado;
    sqlite3_stmt *stmt;
    char sql1[]= "insert into Autor (id_aut, nombre_a, fecha_ncto, lugar_ncto) values (null, ?, ?, ?)";
    sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, campeon);
}

char sql[100];
sprintf(sql,"insert into Autor (id_aut, nombre_a, fecha_ncto, lugar_ncto) values (null, '%s', '%s', '%s')", name, date, place); 

	int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al insertar autor: %s\n", sqlite3_errmsg(db));
        return;
    }
*/