#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>

#include <stdbool.h>
#include "Empleados.h"

struct articulo {
	int codigo;
	char nombre[MAX];
	char costo[MAX];
	char precio[MAX];
};

typedef struct articulos Articulos;

void almacenar(char* cadena); //Funcion para almacenar una cadena
void altaBajaDepto();
int menuAdmin();
void mostrarInvDepto();
void agregarArticulosNuevos();

int menuAdmin(){
	printf("[1] Dar de alta o baja departamentos\n");
	printf("[2] Agregar articulos nuevos a un departamento\n");
	printf("[3] Eliminar articulos\n");//FALTA
	printf("[4] Modificar informacion de empleados\n");
	printf("[5] Agregar empleados\n");
	printf("[6] Eliminar empleados\n");//al eliminar empleado de los de en medio se agrega un salto de linea de mas
	printf("[7] Ver gastos en sueldo\n");//FALTA
	printf("[8] Reporte de articulos\n");
	printf("[9] Dinero en inventario\n");//FALTA
	printf("[10] Salir\n");
	int op;
	scanf("%d",&op);
    switch (op){
        case 1:
            altaBajaDepto();//ya sirve
            break;
        case 2:
            //agregaArticulos
        	agregarArticulosNuevos();//ya sirve
            break;
        case 3:
            //eliminaArticulos
            break;
        case 4:
            menuCambiaEmpleado();//ya sirve
            break;
        case 5:
            agregaEmpleado();//ya sirve
            break;
        case 6:
            eliminaEmpleado();//al borrar un empleado de en medio deja un espacio de mas
            break;
        case 7:
            printf("Se ve gasto en sueldos\n");
            //funcion para ver gastos en sueldos
            break;
        case 8:
            //reporte articulos de un depto
        	mostrarInvDepto();//ya sirve, los deptos son "depto.d"
            break;
        case 9:
            //ver dinero en inventario
            break;
        case 10:
        	return -1;
            break;
        default:
        printf("Ingresa un numero correcto\n");
        
    }
	return 0;
}

void agregarArticulosNuevos(){
	int a=0;
	char repite = 1;
	char respuesta[2];
	//FILE *art = fopen("articulos.txt","a");

	char depap[30];
 	FILE *art;
 	printf("Escribe el departamento para agregarle articulos nuevos: ");
	scanf("%s",depap);
 	strcat(depap,".d");
 	art=fopen(depap,"a");

	struct articulo Articulo[a];
	do {
		if(art)
		{
			printf("Cantidad del nuevo articulo que deseas agregar: ");
			scanf("%d", &a);
			//fprintf(art,"\n%d\n ",a);

			printf( "Escribe el codigo del articulo: " );
			scanf( "%d", &Articulo[a].codigo);
			fprintf(art,"\n%d\n",Articulo[a].codigo);
			
			printf( "Escribe el nombre del articulo: " );
			scanf( "%s", &Articulo[a].nombre);
			fprintf(art,"%s\n",Articulo[a].nombre);
			fprintf(art,"%d\n ",a);
			
			printf( "Escribe el costo del articulo: " );
			scanf( "%s", &Articulo[a].costo );
			fprintf(art,"%s\n",Articulo[a].costo);
			
			printf( "Escribe el precio del articulo: " );
			scanf( "%s", &Articulo[a].precio );
			fprintf(art,"%s\n",Articulo[a].precio);
		}
			printf("\nDesea seguir ingresando productos? [S/N]: ");
			scanf("%s",&respuesta);
			if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
			}
	} while (repite);
	
	fclose(art);
}

void mostrarInvDepto(){
	 	char depap[30];
 	FILE *art;
 	printf("Escribe el departamento para mostrar su inventario: ");
	scanf("%s",depap);
 	strcat(depap,".d");
 	art=fopen(depap,"r");
 
	 if( art==NULL )
  	printf("Error al abrir el fichero\n");
  
 	else
 	{
  		while( !feof(art) )
   		printf("%c",getc(art));
 	}
 	printf("-------------------------------------------\n");
 	printf("El orden de lo mostrado es:\n");
 	printf("--idArticulo\n");
 	printf("--NombreArticulo\n");
 	printf("--CantidadArticulo\n");
 	printf("--PrecioVenta\n");
 	printf("--PrecioCompra\n");
 	printf("-------------------------------------------\n");
	
}

void altaBajaDepto() {
	int i,op2,numArti;
	
	char depap[20];
	char nombreDep[30]; //Aqui almacenamos el nombre que va a tener nuestro archivo 
	char cadena1[30];
 	char *cadena;
 	cadena=cadena1;

 /*	char nombreDep[20];
	char cadena1[100];
 	char *cadena;
 	cadena=&cadena1;*/
 	
 	printf("PRUEBA DEPARTAMENTOS...\n");
	printf("1. Dar de baja un departamento\n");
	printf("2. Dar de alta un departamento\n");
	printf("R: ");
	scanf("%d",&op2);
	
	if(op2==1) {
		printf("Que departamento quieres dar de baja? R: ");
		scanf("%s",depap); //Se tiene que escribir todo el nombre del archivo, ejem -> departamento1.txt
		if(remove(depap)==0) { // Eliminamos el archivo
        	printf("El archivo fue eliminado satisfactoriamente\n");
        }
    	else {
    		printf("No se pudo eliminar el archivo\n");
		}
	}
	
	else {
		FILE *nuevoDepa;
		printf("\nSe va a crear un departamento\n");
		printf("Nombre del departamento: "); //se tiene que poner el nombre del depa con txt -> nuevoDepa.txt
		scanf("%s",nombreDep); 
		nuevoDepa = fopen ( nombreDep, "w+" );
		printf("Cuandos articulos quieres agregar? ");
		scanf("%d",&numArti);
		for(i=0; i<numArti;i++) {
			printf("\nidArticulo #%d: ",i+1);
			almacenar(cadena); //mandamos a llamar a la funcion "almacenar" para alamacenar la cadena
			fputs( cadena, nuevoDepa );	//escribirmos en el archivo lo que almacenamos en "cadena"
			fputc('\n', nuevoDepa); //Da un salto de linea en el archivo
			printf("Nombre del articulo #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, nuevoDepa );
			fputc('\n', nuevoDepa); 
			printf("Cantidad de articulos disponibles #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, nuevoDepa );
			fputc('\n', nuevoDepa); 
			printf("Precio venta #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, nuevoDepa );
			fputc('\n', nuevoDepa); 
			printf("Precio compra #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, nuevoDepa );
			fputc('\n', nuevoDepa); //Damos dobre salto de linea para que empiece a escribir el siguiente artículo con una separación 
			fputc('\n', nuevoDepa); 		
		}
					
		fclose(nuevoDepa); //cerramos el archivo
		
	return 0;
	}
}

void almacenar(char* cadena) {
	setbuf(stdin, NULL);
	scanf("%[^\n]",cadena);
	getchar();
 	
}