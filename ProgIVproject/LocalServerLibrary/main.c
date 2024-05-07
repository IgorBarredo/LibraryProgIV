// Local Server in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#define MAX_PATH_LENGTH 4096 // Un tamaño suficientemente grande para almacenar la ruta
#include "db/sqlite3.h"
#include "db/sqlManager.h"
#include "include/autor.h"
#include "include/categoria.h"
#include "include/editorial.h"
#include "include/libro.h"
#include <time.h>
#include "gestorDeArchivos/gestorDeArchivos.h"
#include "menu.c"




/*
void registrarCategoriaMenu() {
	
	Categoria objCategoria;	
	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#         Categoria        #\n"
		"############################\n"
		"#         Inserte nombre   #\n"
		"#        de la categoria   #\n"
		"############################\n"
	);

	scanf("%s", objCategoria.name);
	system("cls");

	// Conexion con la base de datos y manejo de errores
	abrirDB();
	insertarCategoria(objCategoria);


}

void registrarEditorialMenu() {

	Editorial objEditorial;

	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#         Editorial        #\n"
		"############################\n"
		"#         Inserte nombre   #\n"
		"#        de la categoria   #\n"
		"############################\n"
	);
	scanf("%s", objEditorial.nombre);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte fecha      #\n"
		"#      de  de nacimiento  #\n"
		"############################\n"
	);

	scanf("%s", objEditorial.fecha);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION j

	insertarEditorial(objEditorial); 

}

void leerMenu() {


	int opcion;

	printf("############################\n");
	printf("#--------------------------#\n");
    printf("Buscar por:\n");
    printf("1) Autor\n");
    printf("2) Titulo\n");
    printf("3) Categoria\n");
    printf("4) Editorial\n");
	printf("#--------------------------#\n");
	printf("############################\n");
    printf("Ingrese el numero correspondiente a la opcion deseada: ");
	fflush(stdout);
    scanf("%d", &opcion);
	
	switch (opcion) {
        case 1:
			buscarPorAutor();
            break;
        case 2:
            buscarPorTitulo();
            break;
        case 3:
            buscarPorCategoria();
            break;
        case 4:
            buscarPorEditorial();
            break;
        default:
            printf("Opción no válida\n");
    }


}

void buscarPorAutor() {
	// Conexion a la base de datos
	printf("Autores disponibles:\n");

	mostrarAutores();

	int selectedAuthor;
	printf("Escriba el codigo del autor que desea seleccionar: ");
	scanf("%d", &selectedAuthor);
	fflush(stdout);

	seleccionarAutor(selectedAuthor);

	
}


void buscarPorTitulo() {
	char titulo[100];
	printf("Ingrese el título que desea buscar: ");
	scanf("%s", titulo);
	buscarLibroPorTitulo(titulo);
}

void buscarPorCategoria() {
	// Connect to the database
	sqlite3 *db;
	int result = sqlite3_open("biblioteca.db", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error opening database");
		return;
	}

	// Prepare the SQL statement to retrieve the categories
	sqlite3_stmt *stmt;
	const char *sql = "SELECT id_cat, nombre_c FROM categoria";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	// Execute the statement and retrieve the categories
	printf("Categorías disponibles:\n");
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		int codigo = sqlite3_column_int(stmt, 0);
		const unsigned char *nombre = sqlite3_column_text(stmt, 1);
		printf("Código: %d, Nombre: %s\n", codigo, nombre);
	}

	// Clean up
	sqlite3_finalize(stmt);

	// Prompt the user to enter a category code
	int selectedCodigo;
	printf("Ingrese el código de la categoría que desea ver: ");
	scanf("%d", &selectedCodigo);

	// Preparar el statement SQL para recuperar los libros de la categoría seleccionada
	sqlite3_stmt *stmt2;
	const char *sql2 = "SELECT * FROM libro WHERE id_cat = ?";
	result = sqlite3_prepare_v2(db, sql2, strlen(sql2) + 1, &stmt2, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}


	result = sqlite3_bind_int(stmt2, 1, selectedCodigo);
	if (result != SQLITE_OK) {
		printf("Error binding parameter: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error binding parameter");
		sqlite3_finalize(stmt2);
		sqlite3_close(db);
		return;
	}

	// Execute the statement and retrieve the books
	printf("Libros de la categoría con código %d:\n", selectedCodigo);
	while (sqlite3_step(stmt2) == SQLITE_ROW) {
		int bookId = sqlite3_column_int(stmt2, 0);
		const unsigned char *bookTitle = sqlite3_column_text(stmt2, 1);
		printf("Código: %d, Título: %s\n", bookId, bookTitle);
	}

	// Clean up
	sqlite3_finalize(stmt2);
	sqlite3_close(db);
}

void buscarPorEditorial() {
	// Connect to the database
	sqlite3 *db;
	int result = sqlite3_open("biblioteca.db", &db);

	// Prepare the SQL statement to retrieve the editorials
	sqlite3_stmt *stmt;
	const char *sql = "SELECT id_edi, nombre_e FROM editorial";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	// Execute the statement and retrieve the editorials
	printf("Editoriales disponibles:\n");
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		int codigo = sqlite3_column_int(stmt, 0);
		const unsigned char *nombre = sqlite3_column_text(stmt, 1);
		printf("Código: %d, Nombre: %s\n", codigo, nombre);
	}

	// Clean up
	sqlite3_finalize(stmt);

	// Prompt the user to enter an editorial code
	int selectedCodigo;
	printf("Ingrese el código de la editorial que desea ver: ");
	scanf("%d", &selectedCodigo);

	// Prepare the SQL statement to retrieve the books from the selected editorial
	sqlite3_stmt *stmt2;
	const char *sql2 = "SELECT * FROM libro WHERE id_edi = ?";
	result = sqlite3_prepare_v2(db, sql2, strlen(sql2) + 1, &stmt2, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error preparing statement");
		sqlite3_close(db);
		return;
	}

	result = sqlite3_bind_int(stmt2, 1, selectedCodigo);
	if (result != SQLITE_OK) {
		printf("Error binding parameter: %s\n", sqlite3_errmsg(db));
		guardarErrorEnLog("Error binding parameter");
		sqlite3_finalize(stmt2);
		sqlite3_close(db);
		return;
	}

	// Execute the statement and retrieve the books
	printf("Libros de la editorial con código %d:\n", selectedCodigo);
	while (sqlite3_step(stmt2) == SQLITE_ROW) {
		int bookId = sqlite3_column_int(stmt2, 0);
		const unsigned char *bookTitle = sqlite3_column_text(stmt2, 1);
		printf("Código: %d, Título: %s\n", bookId, bookTitle);
	}

	// Clean up
	sqlite3_finalize(stmt2);
	sqlite3_close(db);
}

void subirMenu() {

	Libro objLibro;
	printf(
		"############################\n"
		"#--------------------------#\n"
		"#           Subir          #\n"
		"#          Libro           #\n"
		"############################\n"
	);
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Titulo          #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	scanf("%s", objLibro.title);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#        cantidad de       #\n"
		"#         autores          #\n"
		"############################\n"
		"# Inserte numero		    #\n"
		"############################\n"
	);
	int cant;
	scanf("%d", cant);
	cant = objLibro.cantAut;
	system("cls");

	for (int i = 0; i < cant; i++) {
		printf(
			"############################\n"
			"#        Introducir        #\n"
			"#          Autor           #\n"
			"############################\n"
			"# Inserte nombre completo  #\n"
			"############################\n"
		);
		scanf("%s", objLibro.autores[i]);
		system("cls");
	};

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Fecha           #\n"
		"############################\n"
		"#      Inserte fecha       #\n"
		"#      de publicacion      #\n"
		"############################\n"
	);
	scanf("%s", objLibro.date);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Editorial       #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	
	scanf("%s", objLibro.editorial);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#        Categoria         #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	scanf("%s", objLibro.categoria);

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#        Contenido         #\n"
		"############################\n"
		"# Inserte texto            #\n"
		"############################\n"
	);

	scanf("%s", objLibro.content);
	system("cls");
	int size = sizeof(objLibro.content);									// Sacamos la cantidad de caracteres
	if (size > 200) {											// que hemos tecleado en el input
        char *newContent = malloc(size * sizeof(char));			// y las metemos en una nueva variable
		strcpy(newContent, objLibro.content);
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

	printf(
		"############################\n"
		"#--------------------------#\n"
		"#         Modificar        #\n"
		"#          Libro           #\n"
		"############################\n"
	);
	
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
*/

int main() {
	printf("Bienvenido al servidor local de la biblioteca\n");
	int opcion = 0;
	while (opcion != 7){
	sleep(2);
    imprimirMenuPrincipal();
	int opcion = seleccionarOpcionMenu();
	gestionarSubmenus(opcion);
	}
Autor *autor = crear_autor("Juan", "01/01/2000", "Mexico");
	imprimir_autor(*autor);
	
    return 0;
}