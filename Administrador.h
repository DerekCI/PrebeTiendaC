#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>

#include <stdbool.h>
#include "Empleados.h"


struct articulo {
	char id[10];
	char nombre[256];
	char numeroproductos[10];
	char compra[256];
	char venta[256];
};

typedef struct articulos Articulos;

void almacenar(char* cadena); //Funcion para almacenar una cadena
void altaBajaDepto();
int menuAdmin();
void mostrarInvDepto();
void agregarArticulosNuevos();
void eliminarArticulo();

int menuAdmin(){

	printf("----------------------------------------\n");
	printf("[1] Dar de alta o baja departamentos\n");
	printf("[2] Agregar articulos nuevos a un departamento\n");
	printf("[3] Eliminar articulos\n");
	printf("[4] Modificar informacion de empleados\n");
	printf("[5] Agregar empleados\n");
	printf("[6] Eliminar empleados\n");
	printf("[7] Ver gastos en sueldo\n");
	printf("[8] Reporte de articulos\n");
	printf("[9] Dinero en inventario\n");
	printf("[10] Salir\n");
	printf("----------------------------------------\n");
	int op;
	scanf("%d",&op);
    switch (op){
        case 1:
            altaBajaDepto();
            break;
        case 2:
            //agregaArticulos
        	agregarArticulosNuevos();
            break;
        case 3:
            //eliminaArticulos
            break;
        case 4:
            menuCambiaEmpleado();
            break;
        case 5:
            agregaEmpleado();
            break;
        case 6:
            eliminaEmpleado();
            break;
        case 7:
            printf("Se ve gasto en sueldos\n");
         
            break;
        case 8:
            /
        	mostrarInvDepto();
            break;
        case 9:
            
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
	char rpp = 1;
	char respuesta[2];
	

	char depBaja[30];
 	FILE *art;
 	printf("Departamento que se quiere ingresar:  ");
	scanf("%s",depBaja);
 	
 	art=fopen(depBaja,"a");

	struct articulo Articulo[a];
	do {
		if(art)
		{
			printf("--------------------------------\n");
			printf("Cuantos articulos se agregaran? ");
			scanf("%d", &a);
			
			printf("Articulo: ");
			scanf("%s", &Articulo[a].nombre);
			fprintf(art,"%s\n",Articulo[a].nombre);
			fprintf(art,"%d\n",a);
			
			printf("venta con el que se comprar el articulo");
			scanf( "%s", &Articulo[a].compra );
			fprintf(art,"%s\n",Articulo[a].compra);
			
			printf("venta para el publico: ");
			scanf( "%s", &Articulo[a].venta );
			fprintf(art,"%s\n",Articulo[a].venta);
		}
			printf("\nDesea seguir ingresando productos? [S/N]: ");
			scanf("%s",&respuesta);
			if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			rpp = 0;
			}
	} while (rpp);
	
	fclose(art);
}

void mostrarInvDepto(){
	 	char depBaja[30];
 	FILE *art;
 	printf("Departamento que se va a entrar: ");
	scanf("%s",depBaja);
 	strcat(depBaja,".d");
 	art=fopen(depBaja,"r");
 
	 if( art==NULL )
  	printf("Error al abrir\n");
  
 	else
 	{
  		while( !feof(art) )
   		printf("%c",getc(art));
 	}
 	printf("-------------------------------------------\n");
 	printf("El orden de lo mostrado es:\n");
 	printf("--idArticulo\n");
 	printf("--NombreArticulo\n");
 	printf("--numeroproductosArticulo\n");
 	printf("--ventaVenta\n");
 	printf("--ventaCompra\n");
 	printf("-------------------------------------------\n");
	
}

void altaBajaDepto() {
	int i,op2,numArti;
	
	char depBaja[20];
	char nombreDep[30]; 
	char auxiliar1[30];
 	char *cadena;
 	cadena=auxiliar1;

	printf("1. Dar de baja un departamento\n");
	printf("2. Dar de alta un departamento\n");
	printf("R: ");
	scanf("%d",&op2);
	
	if(op2==1) {
		printf("Que departamento quieres dar de baja? ");
		scanf("%s",depBaja); 
		strcat(depBaja,".txt");
		if(remove(depBaja)==0) { 
        	printf("El archivo fue eliminado satisfactoriamente\n");
        }
    	else {
    		printf("No se pudo eliminar el archivo\n");
		}
	}
	
	else {
		FILE *nuevoDepa;
		do {
			if(art)
			{
				printf("--------------------------------\n");
				printf("Cuantos articulos se agregaran? ");
				scanf("%d", &a);
			
				printf("Articulo: ");
				scanf("%s", &Articulo[a].nombre);
				fprintf(art,"%s\n",Articulo[a].nombre);
				fprintf(art,"%d\n",a);
			
				printf("venta con el que se comprar el articulo");
				scanf( "%s", &Articulo[a].compra );
				fprintf(art,"%s\n",Articulo[a].compra);
			
				printf("venta para el publico: ");
				scanf( "%s", &Articulo[a].venta );
				fprintf(art,"%s\n",Articulo[a].venta);
			}
				printf("\nDesea seguir ingresando productos? [S/N]: ");
				scanf("%s",&respuesta);
				if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
					rpp = 0;
				}
		} while (rpp);		
	}
					
		fclose(nuevoDepa); //cerramos el archivo
		
	
}

void almacenar(char* cadena) {
	setbuf(stdin, NULL);
	scanf("%[^\n]",cadena);
	getchar();
 	
}
void eliminarArticulo(){
	
	FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[100],fname[100];        
        char nombreart[100], temp[] = "temp.txt";
        char nombredep2[100];
        
        printf("\n\n Borra un articulo:\n");
        printf("-------------------------------------------------------------\n"); 
        printf("A que departamento quieres entrar?\n");
        scanf("%s",nombredep2);
        fptr1 = fopen(nombredep2, "r");
        if (!fptr1) 
        {
                printf("NO se pudo abrir!!\n");      
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2) 
        {
                printf("Error en archivo aux");
                fclose(fptr1);
               
        }
        printf("Articulo a eliminar: \n");
		
		scanf("%s",&nombreart);
		printf("----------------------");
		printf("%s",nombreart);
		//(----------------);
        lno = obtieneLinea(nombreart);
		lno--;
        printf("Linea %d\n",lno);

        for(int i=0;i<100;i++){
			nombreart[i]='\0';
		}

       
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, 100, fptr1);
            if(!feof(fptr1)) 
            {
                linectr++;
             
                if (linectr == lno ) 
                {
                	fprintf(fptr2, "%s", nombreart);
                }else if(linectr == lno+1){	
                	fprintf(fptr2, "%s",nombreart);
                }else if(linectr == lno+2){	
                	fprintf(fptr2, "%s",nombreart);
                }else if(linectr == lno+3){	
                	fprintf(fptr2, "%s",nombreart);
                }else if(linectr == lno+4){	
                	fprintf(fptr2, "%s",nombreart);
                }else{
                    fprintf(fptr2, "%s", str);
                }

           	}
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(nombredep2);
        rename(temp, strcat(nombredep2,".d"));
        printf(" Borrado.!! \n");

}