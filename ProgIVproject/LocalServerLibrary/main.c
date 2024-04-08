// Local Server in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#define MAX_PATH_LENGTH 4096 // Un tamaño suficientemente grande para almacenar la ruta
//#include "sqlManager.c"

#include "db/sqlite3.h"
#include "include/autor.h"
#include "include/categoria.h"
#include "include/editorial.h"
#include "include/libro.h"

// fflush(stdout); -- hace que en este punto muestre todo lo que hay en el buffer por pantalla


void autor() {

	printf(
		"#          Autor           #\n"
	);

}


void fecha() {

	printf(
		"#          Fecha           #\n"
	);

}


void contenido() {

	printf(
		"#        Contenido         #\n"
	);

}


void libro() {

	printf(
		"#          Libro           #\n"
	);

}


void editorial() {

	printf(
		"#        Editorial         #\n"
	);

}


void titulo() {

	printf(
		"#          Titulo          #\n"
	);

}


void categoria() {

	printf(
		"#        Categoria         #\n"
	);

}


void endMenu() {

	printf(
		"#--------------------------#\n"
	);

}


void endMenuShorter() {

	printf(
		"############################\n"
	);

}


void registrar() {

	printf(
		"############################\n"
		"#--------------------------#\n"
		"#         Registrar        #\n"
	);

}


void subir() {

	printf(
		"############################\n"
		"#--------------------------#\n"
		"#           Subir          #\n"
	);

}


void modificar() {

	printf(
		"############################\n"
		"#--------------------------#\n"
		"#         Modificar        #\n"
	);

}


void leer() {

	printf(
		"############################\n"
		"#--------------------------#\n"
		"#           Leer           #\n"
	);

}


void buscarPor() {

	printf(
		"############################\n"
		"#        Buscar Por        #\n"
	);

}


void introducir() {

	printf(
		"############################\n"
		"#        Introducir        #\n"
	);

}



void insertarNombre() {

	printf(
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);

}


void insertarTexto() {

	printf(
		"############################\n"
		"#       Inserte texto      #\n"
		"############################\n"
	);

}


void insertarFechaNacimiento() {

	printf(
		"############################\n"
		"#      Inserte fecha       #\n"
		"#      de nacimiento       #\n"
		"############################\n"
	);

}


void insertarLugarNacimiento() {

	printf(
		"############################\n"
		"# Inserte nombre completo  #\n"
		"# del lugar de nacimiento  #\n"
		"############################\n"
	);

}


void registrarAutorMenu() {

	/*char *name[50];
	char *date[50];
	char *place[50];*/

	Autor objAutor;

	registrar();
	autor();
	endMenu();

	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", objAutor.name);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", objAutor.date);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarLugarNacimiento();
	//FFLUSH(stdout);
	scanf("%s", objAutor.place);
	system("cls");

	printf("Nombre: %s\n", objAutor.name);

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	int result;
	sqlite3 *db;
	result = sqlite3_open("biblioteca.db", &db);

	if (result != SQLITE_OK) {
		printf("Error opening database: %s\n", sqlite3_errmsg(db));
		return;
	}

	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO autor (nombre_a, fecha_ncto, lugar_ncto) VALUES (?, ?, ?)";

	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	sqlite3_bind_text(stmt, 1, objAutor.name, strlen(objAutor.name), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, objAutor.date, strlen(objAutor.date), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, objAutor.place, strlen(objAutor.place), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting data: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}


void registrarCategoriaMenu() {
	//char *name[50];
	Categoria objCategoria;	
	
	registrar();
	categoria();
	endMenu();

	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", objCategoria.name);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	sqlite3 *db;
	int result = sqlite3_open("biblioteca.db", &db);

	if (result != SQLITE_OK) {
		printf("Error opening database: %s\n", sqlite3_errmsg(db));
		return;
	}

	sqlite3_stmt *stmt2;
	char sql[] = "INSERT INTO categoria (nombre_c) VALUES (?)";

	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt2, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	sqlite3_bind_text(stmt2, 1, objCategoria.name, strlen(objCategoria.name), SQLITE_STATIC);

	result = sqlite3_step(stmt2);
	if (result != SQLITE_DONE) {
		printf("Error inserting data: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt2);
	sqlite3_close(db);
}

void registrarEditorialMenu() {

	/*char *name[50];
	char *date[50];*/
	Editorial objEditorial;

	registrar();
	editorial();
	endMenu();

	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", objEditorial.nombre);
	system("cls");

	registrar();
	editorial();
	endMenu();

	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", objEditorial.fecha);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION j

	sqlite3 *db;
	int result = sqlite3_open("biblioteca.db", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database: %s\n", sqlite3_errmsg(db));
		return;
	}

	sqlite3_stmt *stmt3;
	char sql[] = "INSERT INTO editorial (nombre_e, fecha_fundacion) VALUES (?, ?)";
	
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt3, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	sqlite3_bind_text(stmt3, 1, objEditorial.nombre, strlen(objEditorial.nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt3, 2, objEditorial.fecha, strlen(objEditorial.fecha), SQLITE_STATIC);

	result = sqlite3_step(stmt3);
	if (result != SQLITE_DONE) {
		printf("Error inserting data: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt3);
	sqlite3_close(db);
}

void leerMenu() {

	char *name[50];
	char *title[50];
	char *date[50];
	char *place[50];
	char *category[50];
	char *edit[50];

	
	leer();
	libro();
	endMenu();

	buscarPor();
	autor();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	fecha();
	endMenuShorter();
	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	titulo();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	categoria();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	editorial();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION


	//free(name);
	//free(title);
	//free(date);
	//free(place);
	//free(category);
	//free(edit);

}


void subirMenu() {

	char *name[50];
	char *title[50];
	char *date[50];
	char *place[50];
	char *category[50];
	char *edit[50];
	char *content[200];

	subir();
	libro();
	endMenu();

	introducir();
	autor();
	endMenuShorter();
	insertarNombre();
	scanf("%s", name);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	fecha();
	endMenuShorter();
	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	titulo();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	categoria();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	editorial();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	contenido();
	endMenuShorter();
	insertarTexto();
	//FFLUSH(stdout);
	scanf("%s", content);
	int size = sizeof(content);									// Sacamos la cantidad de caracteres
	if (size > 200) {											// que hemos tecleado en el input
        char *newContent = malloc(size * sizeof(char));			// y las metemos en una nueva variable
		strcpy(newContent, content);
    }
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	//free(name);
	//free(title);
	//free(date);
	//free(place);
	//free(category);
	//free(edit);
	//free(content);

}


void modificarMenu() {

	char *name[50];
	char *title[50];
	char *date[50];
	char *place[50];
	char *category[50];
	char *edit[50];

	modificar();
	libro();
	endMenu();

	buscarPor();
	autor();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	fecha();
	endMenuShorter();
	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	titulo();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	categoria();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	editorial();
	endMenuShorter();
	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	//free(name);
	//free(title);
	//free(date);
	//free(place);
	//free(category);
	//free(edit);

}


int mainWindowMenu() {

	int input;

	printf(
		"\n############################\n" 
		"#//////////////////////////#\n"
		"#     	  BIBLIOTECA        #\n" 
		"#//////////////////////////#\n" 
		"############################\n" 
		"#                          #\n" 
		"#  1. Leer Libro           #\n" 
		"#  2. Subir Libro          #\n" 
		"#  3. Modificar Libro      #\n" 
		"#  4. Registrar Autor      #\n" 
		"#  5. Registrar Editorial  #\n" 
		"#  6. Registrar Categoria  #\n" 
		"#  7. Salir                #\n" 
		"#                          #\n" 
		"############################\n" 
		"#      Inserte numero      #\n" 
		"############################\n"
	);

	//FFLUSH(stdout);

	char cadena[100]; // Declarar una cadena de caracteres

	scanf("%d", &cadena);

    if (cadena[0] != '\0') { // Verificar si la cadena no está vacía

        input = cadena[0]; // Asignar el primer carácter a la variable primer_caracter

    }

	system("cls");
	return input;

}


void reiniciarPrograma(char *argv[]) {
    // Lógica para reiniciar el programa
    printf("Reiniciando el programa...\n");

    // Creamos un arreglo de argumentos para la función execv()
    const char *argumentos[] = {argv[0], NULL};

    // Ejecutamos el programa nuevamente
    if (execv(argv[0], argumentos) == -1) {
        perror("Error al reiniciar el programa");
    }
}


void windowSelector(int n, char *argv[]) {

	switch (n) {
	    case 1:
	      leerMenu();
	      break;

	    case 2:
	      subirMenu();
	      break;

	    case 3:
		  modificarMenu();
		  break;

		case 4:
		  registrarAutorMenu();
		  break;

	    case 5:
		  registrarEditorialMenu();
		  break;

		case 6:
		  registrarCategoriaMenu();
		  break;

		case 7:
		  exit(0);
		  break;

	    default:
			// default statements
			printf(
				"############################\n" 
				"#//////////////////////////#\n" 
				"#   INSERTE VALOR VALIDO   #\n" 
				"#//////////////////////////#\n" 
				"############################\n"
			);
			sleep(3);
			system("cls");
			reiniciarPrograma(argv);
	
	}

}


// main function
int main(int argc, char *argv[]) {
    while (1) {
        windowSelector(mainWindowMenu(), argv);
    }
    return 0;
}