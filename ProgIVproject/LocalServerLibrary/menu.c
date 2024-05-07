#include "menu.h"
#include <stdio.h> 
#include <stdlib.h>
#include "include/autor.c"
#include "include/autor.h"
#include "include/categoria.c"
#include "include/categoria.h"
#include "include/editorial.c"
#include "include/editorial.h"


void imprimirMenuPrincipal(){ 		//Funcion para imprimir el menu principal
	

printf(
		"\n############################\n" 
		"#//////////////////////////#\n"
		"#     	  BIBLIOTECA        #\n" 
		"#//////////////////////////#\n" 
		"############################\n" 
		"#                          #\n" 
		"#  1. Descargar Libro      #\n" 
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
}

int seleccionarOpcionMenu() { //Funcion para seleccionar una opcion del menu
	int input;
	scanf("%d", &input);
	fflush(stdin);
	return input;

}



void gestionarSubmenus(int n) { //Funcion para gestionar los submenus

	switch (n) {
	    case 1:
	      MenuDescargar();
	      break;

	    case 2:
	      MenuSubir();
	      break;

	    case 3:
		  MenuModificar();
		  break;

		case 4:
		  MenuRegistrarAutor();
		  break;

	    case 5:
		    MenuRegistrarEditorial();
		  break;

		case 6:
		
		  MenuRegistrarCategoria();
		  break;

		case 7:
		printf("Saliendo...\n");
		  exit(0);
		  break;

	    default:
			
			printf(
				"############################\n" 
				"#   INSERTE VALOR VALIDO   #\n"  
				"############################\n"
			);
			sleep(1);
			

	
	
	}

}


void MenuDescargar() { //Funcion para descargar un libro
system("cls");
printf("Descargar Libro\n");
}


void MenuSubir(){ //Funcion para subir un libro
system("cls");
printf("Subir Libro\n");
}


void MenuModificar(){ 		//Funcion para modificar un libro
system("cls");
printf("Modificar Libro\n");
}


void MenuRegistrarAutor(){ //Funcion para registrar un autor
system("cls");

	char nombre[50];
	char fecha[50];
	char lugar[50];

	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#          Autor           #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	
	scanf("%s",nombre);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte anyo        #\n"
		"#      de nacimiento       #\n"
		"############################\n"
	);
	scanf("%s", fecha);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte nombre      #\n"
		"# del lugar de nacimiento  #\n"
		"############################\n"
	);
	scanf("%s", lugar);

	system("cls");
	Autor* objAutor;
	objAutor = crear_autor(nombre, fecha, lugar);
	imprimir_autor(*objAutor);

//abrirDB();
//	insertarAutor(objAutor);
	


}


void MenuRegistrarCategoria(){ //Funcion para registrar una categoria
system("cls");

	char nombre[50];
	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#         Categoria        #\n"
		"############################\n"
		"#      Inserte nombre      #\n"
		"#      de la categoria     #\n"
		"############################\n"
	);

	scanf("%s", nombre);
	system("cls");

	Categoria* objCategoria;
	objCategoria = crearCategoria(nombre);
	imprimirCategoria(objCategoria);
	//abrirDB();
	//insertarCategoria(objCategoria);

}


void MenuRegistrarEditorial(){ //Funcion para registrar una editorial
system("cls");
	char nombre[50];
	char fecha[50];

	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#         Editorial        #\n"
		"############################\n"
		"#       Inserte nombre     #\n"
		"#      de la editorial     #\n"
		"############################\n"
	);
	scanf("%s", nombre);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte fecha       #\n"
		"#       de fundacion       #\n"
		"############################\n"
	);

	scanf("%s",fecha);
	system("cls");

	Editorial* objEditorial;
	objEditorial = crear_editorial(nombre, fecha);
	imprimirEditorial(*objEditorial);
	// PUT THE NEW DATA IN DATABASE AND MANAGE THE ERRORS
	// CONNECT WITH THE REST OF THE APLICATION j

	//abrirDB();
	//insertarEditorial(objEditorial); 


}

void cargando(){ //Funcion para simular un cargando
	printf("Cargando.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".\n");
}

void empezarMenu(){ //Funcion para empezar el menu
	printf("Bienvenido al servidor local de la biblioteca\n");
	cargando();
	while (1){
	sleep(1);
	system("cls");
    imprimirMenuPrincipal();
	gestionarSubmenus(seleccionarOpcionMenu());
	}
}