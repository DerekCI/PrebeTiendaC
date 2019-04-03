#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * obtieneCadena3(int linea); 
int num_lineas_archivo(void); 

void sueldos()
{
	
	int linea;
	int num_empleados;
	int lineas; 
	int a;
	char * cadena; 
	float sueldo
	float final;
	num_empleados=1;
	final=0;
	lineas= num_lineas_archivo ();
	
	
	for(linea=5; num_empleados <=(lineas/6); linea) {
		
		num_empleados++;
		cadena=obtieneCadena3(linea+1);
		sueldo=(float)atof(cadena); 
		
		printf("Sueldo de empleado %d :%s\n ",num_empleados-1,cadena);
		linea=linea+7;
		final = final + sueldo;
		
	}
	printf("Total : %f\n ",final);
	return 0;
}

int num_lineas_archivo(void) 
{
   FILE *archivo;
   int ch;
   int num_lineas;
   
   if ((archivo = fopen(empleados, "r")) == NULL){
     
    }
   
   num_lineas = 0;
   while ((ch = fgetc(archivo)) != EOF){
      if (ch == '\n')
        num_lineas++;
   }
  
   fclose(archivo); 
   return num_lineas;
}


char * obtieneCadena3(int linea) 
{
	
	static char cadena[30]; 
	int lineass=0;
	FILE *file; 

	if( ( file = fopen(empleados,"r") ) == NULL )
	printf("No se puede abrir el archivo.");

	else{
	while (!feof(file))
	{
		
		fgets(cadena, 100, file) != NULL;
		lineass++; 
		if(lineass==linea) 
		{
			fclose(file);
			return cadena;	 
		}
	}
}
	 
	return cadena;
}