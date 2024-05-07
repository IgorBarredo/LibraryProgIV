#include "menu.h"
#include <stdio.h> 
#include <stdlib.h>
#include "include/autor.c"
#include "include/autor.h"


void imprimirMenuPrincipal(){

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

int seleccionarOpcionMenu() {
	int input;
	scanf("%d", &input);
	fflush(stdin);
	return input;

}



void gestionarSubmenus(int n) {

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
		  MenuRegistrarCategoria();
		  break;

		case 6:
		  MenuRegistrarEditorial();
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


void MenuDescargar() {
system("cls");
printf("Descargar Libro\n");
}


void MenuSubir(){
system("cls");
printf("Subir Libro\n");
}


void MenuModificar(){
system("cls");
printf("Modificar Libro\n");
}


void MenuRegistrarAutor(){
system("cls");

	char name[50];
	char date[50];
	char place[50];

	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#          Autor           #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	
	scanf("%s",name);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte any         #\n"
		"#      de nacimiento       #\n"
		"############################\n"
	);
	scanf("%s", date);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte nombre      #\n"
		"# del lugar de nacimiento  #\n"
		"############################\n"
	);
	scanf("%s", place);

	system("cls");
	Autor* objAutor;
	objAutor = crear_autor(name, date, place);
	imprimir_autor(*objAutor);
	//Conexion con la base de datos

	//abrirDB();
//	insertarAutor(objAutor);
	


}


void MenuRegistrarCategoria(){
system("cls");
printf("Registrar Categoria\n");
}


void MenuRegistrarEditorial(){
system("cls");
printf("Registrar Editorial\n");
}

void cargando(){
	printf("Cargando.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".\n");
}