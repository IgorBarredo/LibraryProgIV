// Local Server in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "strings/strings.h"


// FFLUSH(STDOUT) -- hace que en este punto muestre todo lo que hay en el buffer por pantalla


void autor() {

	printf(
			"#          Autor           #"
	);

}


void fecha() {

	printf(
			"#          Fecha           #"
	);

}


void contenido() {

	printf(
			"#        Contenido         #"
	);

}


void libro() {

	printf(
			"#          Libro           #"
	);

}


void editorial() {

	printf(
			"#        Editorial         #"
	);

}


void titulo() {

	printf(
			"#          T�tulo          #"
	);

}


void categoria() {

	printf(
			"#        Categor�a         #"
	);

}


void endMenu() {

	printf(
			"#//////////////////////////#"
	);

}


void endMenuShorter() {

	printf(
			"############################"
	);

}


void registrar() {

	printf(
			"############################" +
			"#\\\\\\\\\\\\\\\\\\\\\\\\\\#" +
			"#         Registrar        #"
	);

}


void subir() {

	printf(
			"############################" +
			"#\\\\\\\\\\\\\\\\\\\\\\\\\\#" +
			"#           Subir          #"
	);

}


void modificar() {

	printf(
			"############################" +
			"#\\\\\\\\\\\\\\\\\\\\\\\\\\#" +
			"#         Modificar        #"
	);

}


void leer() {

	printf(
			"############################" +
			"#\\\\\\\\\\\\\\\\\\\\\\\\\\#" +
			"#           Leer           #"
	);

}


void buscarPor() {

	printf(
			"############################" +
			"#        Buscar Por        #"
	);

}


void introducir() {

	printf(
			"############################" +
			"#        Introducir        #"
	);

}



void insertarNombre() {

	printf(
			"############################" +
			"# Inserte nombre completo  #" +
			"############################"
	);

}


void insertarTexto() {

	printf(
			"############################" +
			"#       Inserte texto      #" +
			"############################"
	);

}


void insertarFechaNacimiento() {

	printf(
			"############################" +
			"#      Inserte fecha       #" +
			"#      de nacimiento       #" +
			"############################"
	);

}


void insertarLugarNacimiento() {

	printf(
			"############################" +
			"# Inserte nombre completo  #" +
			"# del lugar de nacimiento  #" +
			"############################"
	);

}


void registrarAutorMenu() {

	char *name[50];
	char *date[50];
	char *place[50];

	registrar();
	autor();
	endMenu();

	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarFechaNacimiento();
	FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarLugarNacimiento();
	FFLUSH(stdout);
	scanf("%s", place);
	system("cls");

	mainWindowMenu();

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

}


void registrarCategoriaMenu() {

	char *name[50];

	registrar();
	categoria();
	endMenu();

	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	mainWindowMenu();

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

}

void registrarEditorialMenu() {

	char *name[50];
	char *date[50];

	registrar();
	editorial();
	endMenu();

	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	registrar();
	editorial();
	endMenu();

	insertarFechaNacimiento();
	FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	mainWindowMenu();

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

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
	FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	fecha();
	endMenuShorter();
	insertarFechaNacimiento();
	FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	titulo();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	categoria();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	leer();
	libro();
	endMenu();

	buscarPor();
	editorial();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	mainWindowMenu();

	free(name);
	free(title);
	free(date);
	free(place);
	free(category);
	free(edit);

}


void subirMenu() {

	char *name[50];
	char *title[50];
	char *date[50];
	char *place[50];
	char *category[50];
	char *edit[50];
	char *content[];

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
	FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	titulo();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	categoria();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	editorial();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	subir();
	libro();
	endMenu();

	introducir();
	contenido();
	endMenuShorter();
	insertarTexto();
	FFLUSH(stdout);
	scanf("%s", content);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	mainWindowMenu();

	free(name);
	free(title);
	free(date);
	free(place);
	free(category);
	free(edit);
	free(content);

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
	FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	fecha();
	endMenuShorter();
	insertarFechaNacimiento();
	FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	titulo();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", title);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	categoria();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", category);
	system("cls");

	modificar();
	libro();
	endMenu();

	buscarPor();
	editorial();
	endMenuShorter();
	insertarNombre();
	FFLUSH(stdout);
	scanf("%s", edit);
	system("cls");

	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION

	mainWindowMenu();

	free(name);
	free(title);
	free(date);
	free(place);
	free(category);
	free(edit);

}


void windowSelector(int n) {

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
	      //sleep(int 3);
	      mainWindow();
	}

}


void mainWindowMenu() {

	int input;

	printf(
			"############################\n" 
			"#//////////////////////////#\n" 
			"#     	   MAIN MENU        #\n" 
			"#//////////////////////////#\n" 
			"############################\n" 
			"#                          #\n" 
			"#  1. Leer                 #\n" 
			"#  2. Subir                #\n" 
			"#  3. Modificar            #\n" 
			"#  4. Registrar Autor      #\n" 
			"#  5. Registrar Editorial  #\n" 
			"#  6. Registrar Categoria  #\n" 
			"#  7. Salir                #\n" 
			"#                          #\n" 
			"############################\n" 
			"#      Inserte numero      #\n" 
			"############################\n"
	);
	FFLUSH(STDOUT);
	scanf("%d", &input);
	windowSelector(input);

}


void main(void) {

	mainWindowMenu();

}

