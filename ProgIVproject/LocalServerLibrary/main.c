// Local Server in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#define MAX_PATH_LENGTH 4096 // Un tamaño suficientemente grande para almacenar la ruta


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
		"#          Título          #\n"
	);

}


void categoria() {

	printf(
		"#        Categoría         #\n"
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

	char *name[50];
	char *date[50];
	char *place[50];

	registrar();
	autor();
	endMenu();

	insertarNombre();
	//FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarFechaNacimiento();
	//FFLUSH(stdout);
	scanf("%s", date);
	system("cls");

	registrar();
	autor();
	endMenu();

	insertarLugarNacimiento();
	//FFLUSH(stdout);
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
	//FFLUSH(stdout);
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
	//FFLUSH(stdout);
	scanf("%s", name);
	system("cls");

	registrar();
	editorial();
	endMenu();

	insertarFechaNacimiento();
	//FFLUSH(stdout);
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

	mainWindowMenu();

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

	mainWindowMenu();

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

	mainWindowMenu();

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
		"#     	  MAIN MENU        #\n" 
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