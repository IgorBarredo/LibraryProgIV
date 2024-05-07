#include "menu.h"
#include <stdio.h> 
#include <stdlib.h>
#include "include/autor.c"


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
		  exit(0);
		  printf("Saliendo...\n");
		  break;

	    default:
			
			printf(
				"############################\n" 
				"#   INSERTE VALOR VALIDO   #\n"  
				"############################\n"
			);

	
	
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


	Autor objAutor;

	printf(
		"############################\n"
		"#         Registrar        #\n"
		"#          Autor           #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	
	scanf("%s", objAutor.name);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte any         #\n"
		"#      de nacimiento       #\n"
		"############################\n"
	);
	scanf("%s", objAutor.date);
	system("cls");

	printf(
		"############################\n"
		"#      Inserte nombre      #\n"
		"# del lugar de nacimiento  #\n"
		"############################\n"
	);
	scanf("%s", objAutor.place);
	system("cls");

	imprimir_autor(objAutor);

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
