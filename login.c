/*
Verificar usuario
ENtrada: usuario, contraseña
Salida: tpo de usuario

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checaTipoEmpleado(char* usuario,char* contrasena);
int obtieneLinea(char* nombreEmp);
char * obtieneCadena(int linea);



int main(int argc, char const *argv[])
{

	char usuario[30];
	char contrasena[30];
	printf("Ingrese el usuario:\n");
	scanf(" %s",usuario);
	printf("Ingrese la contraseña:\n");
	scanf(" %s",contrasena);
	int tipo=checaTipoEmpleado(usuario,contrasena);
	printf("%d\n",tipo );
	if(tipo==1){
		//es de ventas
	}else if(tipo==2){
		//es de compras
	}else if(tipo==3){
		//es de administracion
	}
	return 0;
}

int checaTipoEmpleado(char* usuario,char* contrasena){
	int tipo;
	int lineaEmpieza=obtieneLinea(usuario);
	char* prueba;
	prueba=obtieneCadena(lineaEmpieza+2);
	
	prueba=obtieneCadena(lineaEmpieza+3);
	if(strcmp(prueba,contrasena) ==0){
		prueba=obtieneCadena(lineaEmpieza+4);
		tipo = prueba[0] - '0'; 
		
		return tipo;
	}
	
}



int obtieneLinea(char* nombreEmp){
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
		if(strcmp(nombre,nombreEmp) == 0)
		{
			fclose(fp);
			return lines-1;	
		}
	}
}
	fclose(fp); //cierra el archivo 
	return lines;
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
	printf("%s\n",nombre );
	printf("sdsd\n");
	return nombre;
}
