// Local Server in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.c"


/*
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
*/


/*
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

int main(void) {
empezarMenu(); // Llamamos a la función que inicia el menú
    return 0;
}