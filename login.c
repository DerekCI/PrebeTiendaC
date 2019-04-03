/*
Verificar usuario
ENtrada: usuario, contraseña
Salida: tpo de usuario

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>

#include <stdbool.h>
#include "Administrador.h"
#include "anadeArticulos.h"
#include "ventaArticulos.h"
//#include "sueldos.h"


int checaTipoEmpleado(char* usuario,char* contrasena);
int obtieneLinea2(char* nombreEmp);
char * obtieneCadena(int linea);
void menuCompras();
void replaceArticulo(int line); 



int main(int argc, char const *argv[])
{	

	
	int tipo;
	do{
	char usuario[30];
	char contrasena[30];
	printf("Ingrese el usuario:\n");
	scanf(" %s",usuario);
	printf("Ingrese la contraseña:\n");
	scanf(" %s",contrasena);
	tipo=checaTipoEmpleado(usuario,contrasena);
	printf("%d\n",tipo );
	if(tipo==1){
		printf("Aqui se hace venta\n");//FALTA
		//es de ventas
		int v;
		do{
			v = vendeArticulo();
		}while(v !=-1 );
	}else if(tipo==2){
		printf("Aqui se surte articulos\n");//FALTA
		//es de compras
		int c;
		do{
			c = anadeArticulo();
		}while(c !=-1 );
	}else if(tipo==3){
		printf("eres admin\n");
		int a;
		do{
			a = menuAdmin();
		}while(a !=-1 );
		//es de administracion
	}else if(tipo==4){
		printf("Usuario y/o contrasena incorrecta intente de nuevo.\n");
	}
	}while(tipo==4);
	


	return 0;
}

void menuCompras(){
	printf("[1] Dar de alta o baja departamentos\n");
	printf("[2] Agregar articulos nuevos a un departamento\n");
	printf("[3] Eliminar articulos\n");//FALTA
	printf("[4] Modificar informacion de empleados\n");
}

int checaTipoEmpleado(char* usuario,char* contrasena){
	
	int tipo;
	int lineaEmpieza=obtieneLinea2(usuario);
	//printf("%d\n",lineaEmpieza );
	if(lineaEmpieza==-1){
		//si no existe el usuario
		
		return 4;
	}
	char* prueba;
	prueba=obtieneCadena(lineaEmpieza+2);
	
	prueba=obtieneCadena(lineaEmpieza+3);
	if(strcmp(prueba,contrasena) ==0){
		prueba=obtieneCadena(lineaEmpieza+4);
		tipo = prueba[0] - '0'; 
		
		return tipo;
	}else{
		//si no es la contraseña
		printf("Contraseña incorrecta.\n");
		return 4;
	}
	
}


int obtieneLinea2(char* nombreEmp){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("empleados","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp))
	{
		

		fscanf(fp, "%s\n", nombre);
		lines++;
		//printf("%d\n",lines );
		if(strcmp(nombre,nombreEmp) == 0)
		{
			fclose(fp);
			return lines-1;	
		}
	}
}
	fclose(fp); //cierra el archivo 
	printf("Usuario no encontrado.\n");
	return -1;
}

char * obtieneCadena(int linea){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("empleados","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp))
	{
		

		fscanf(fp, "%s\n", nombre);
		lines++;
		if(lines==linea-1)
		{
			fclose(fp);
			return nombre;	
		}
		
	}
	}
	fclose(fp); //cierra el archivo 
	return nombre;
}

