#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"

sqlite3* abrirDB() {
    sqlite3 *db;
    sqlite3_open("biblioteca.db", &db);
    
}