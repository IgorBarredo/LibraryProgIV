#include "menu.h"
#include <stdio.h> 

void imprimirMenuPrincipal(){

printf(
		"\n############################\n" 
		"#//////////////////////////#\n"
		"#     	  BIBLIOTECA       #\n" 
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



void imprimirSubmenus(int n) {

	switch (n) {
	    case 1:
	      imprimirMenuDescargar();
	      break;

	    case 2:
	      imprimirMenuSubir();
	      break;

	    case 3:
		  imprimirMenuModificar();
		  break;

		case 4:
		  imprimirMenuRegistrarAutor();
		  break;

	    case 5:
		  imprimirMenuRegistrarCategoria();
		  break;

		case 6:
		  imprimirMenuRegistrarEditorial();
		  break;

		case 7:
		  exit(0);
		  break;

	    default:
			
			printf(
				"############################\n" 
				"#   INSERTE VALOR VALIDO   #\n"  
				"############################\n"
			);

	
	
	}

}


void imprimirMenuDescargar() {
system("cls");
printf("Descargar Libro\n");
}
void imprimirMenuSubir(){
system("cls");
printf("Subir Libro\n");
}
void imprimirMenuModificar(){
system("cls");
printf("Modificar Libro\n");
}
void imprimirMenuRegistrarAutor(){
system("cls");
printf("Registrar Autor\n");
}
void imprimirMenuRegistrarCategoria(){
system("cls");
printf("Registrar Categoria\n");
}
void imprimirMenuRegistrarEditorial(){
system("cls");
printf("Registrar Editorial\n");
}
