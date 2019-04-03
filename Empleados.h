#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 256

typedef struct Empleado {
	char nombre_empleado[32];
	char apellido[32];
	char usuario[32];
	char contrasena[32];
	char tipo_empleado[20];
	char  sueldo[20];
	struct Empleado* siguiente;
}Empleado;
Empleado* empleados_inicio = NULL;

void replace(int line);
int obtieneLinea(char* nombreEmp);
int menuCambiaEmpleado();
void agregaEmpleado();
void eliminaEmpleado();

int menuCambiaEmpleado(){
    char usuario[40];
    char bufferNombre[40];
    int op;
    int d;
    do{
    printf("Ingrese el usuario a modificar: "); 
    scanf(" %[^\n]",usuario);
    d = obtieneLinea(usuario);
    printf("Numero de linea----%d\n",d );
    }while(d == -1);
    
    do{
    printf("Ingrese el numero para cambiar atributo del empleado:\n "); 
    printf("[1] Nombre\n"); 
    printf("[2] Apellido\n"); 
    printf("[3] Usuario"); 
    printf("\n[4] Contraseña"); 
    printf("\n[5] Tipo de empleado, escribe en siguiente opcion: (1) Ventas, (2) Compras, (3) Administracion"); 
    printf("\n[6] Sueldo\n");
    printf("\n[7] Salir de menu\n");
    scanf("%d",&op);
    switch (op){
        case 1:
            replace(d-2);
            break;
        case 2:
            replace(d-1);
            break;
        case 3:
            printf("Switch\n");
            replace(d);
            break;
        case 4:
            replace(d+1);
            break;
        case 5:
            replace(d+2);
            break;
        case 6:
            replace(d+3);
            break;
        case 7:
            break;
        default:
        printf("Ingresa un numero correcto\n");
        
    }

    }while(op!=7);

    return 0;

  }

int obtieneLinea(char* nombreEmp){
    int i;
    static char nombre[30];
    int lines=0;
    FILE *fp; //creamos apuntador a archivo

    if( ( fp = fopen("empleados","r") ) == NULL )//comprueba que haya un archivo con nombre empleados que se pueda leer
    printf("Error al leer el archivo.");

    else{
    while (!feof(fp))
    {
        

        fscanf(fp, "%s\n", nombre);
        lines++;
        if(lines%6==0){
            lines++;
        }
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

 void replace(int line) 
  {

        FILE *arch1, *arch2;
        int li, cuentaL = 0;
        char str[MAX],fname[MAX];        
        char nueva[MAX], temp[] = "temp.txt";
        printf("-------------------------------------------------------------\n"); 
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';
        arch1 = fopen("empleados", "r");
        if (!arch1) 
        {
                printf("No se pudo abrir el archivo de empleados\n");
               
        }
        arch2 = fopen(temp, "w");
        if (!arch2) 
        {
                printf("No  se pudo abrir archivo temporal\n");
                fclose(arch1);
                
        }
        printf(" Ingresa el nuevo valor: ");
        fgets(nueva, MAX, stdin);
        li=line;
        li++;
        while (!feof(arch1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, arch1);
            if (!feof(arch1)) 
            {
                cuentaL++;
                if (cuentaL != li) 
                    {
                        fprintf(arch2, "%s", str);
                    } 
                    else 
                    {
                        fprintf(arch2, "%s", nueva);
                    }
                }
        }
        fclose(arch1);
        fclose(arch2);
        remove("empleados");
        rename(temp, "empleados");
        printf(" Se realizo correctamente el cambio \n");
      
}

void agregaEmpleado(){
	int finalarchivo;
	int opcion = 2;
	char nombre[10];
	do{
		Empleado empleado;
		FILE* archivo=fopen("empleados","a+");

		printf("Nombre del empleado: ");
		scanf("%s",empleado.nombre_empleado);
		fprintf(archivo,"\n%s \n",empleado.nombre_empleado);
		//fputs(empleado.nombre_empleado,archivo);

		printf("Apellido del empleado: \n");
		scanf("%s",empleado.apellido);
		fprintf(archivo,"%s \n",empleado.apellido);
		//fputs(empleado.apellido,archivo);

		printf("Usuario del empleado: \n");
		scanf(" %s",empleado.usuario);
		fprintf(archivo,"%s \n",empleado.usuario);
		//fputs(empleado.usuario,archivo);

		printf("Contraseña del empleado: \n");
		scanf(" %s",empleado.contrasena);
		fprintf(archivo,"%s \n",empleado.contrasena);
		//fputs(empleado.contrasena,archivo);

		printf("Tipo de empleado: \n");
		scanf(" %s",empleado.tipo_empleado);
		fprintf(archivo,"%s \n",empleado.tipo_empleado);
		//fputs(empleado.tipo_empleado,archivo);

		printf("Sueldo del empleado: \n");
		scanf("%s",empleado.sueldo);
		fprintf(archivo,"%s ",empleado.sueldo);	
		//fputs(*empleado.sueldo,archivo);

		fseek(archivo,0,SEEK_END);
		finalarchivo = ftell(archivo);
		fclose(archivo);
		printf("Desea continuar(1)?\n");
		scanf("%d", &opcion);
		printf("\n");

	}while(opcion == 1 || opcion == 1);	
}

void eliminaEmpleado()
{
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[100],fname[100];        
        char nombreel[100], temp[] = "temp.txt";
        
        printf("\n\n Borra un empleado:\n");
        printf("-------------------------------------------------------------\n"); 
        
        fptr1 = fopen("empleados", "r");
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
        printf("Nombre a eliminar: \n");
		
		scanf("%s",nombreel);
       
        lno = obtieneLinea(nombreel);
		lno++;
        printf("Linea %d\n",lno);

        for(int i=0;i<100;i++){
			nombreel[i]='\0';
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
                	fprintf(fptr2, "%s", nombreel);
                }else if(linectr == lno+1){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+2){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+3){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+4){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+5){	
                	fprintf(fptr2, "%s",nombreel);
                }
                else{
                    fprintf(fptr2, "%s", str);
                }

           	}
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("empleados");
        rename(temp, "empleados");
        printf(" Borrado.!! \n");
 
}
