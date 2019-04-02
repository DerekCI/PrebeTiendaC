#include <stdio.h>
#include <string.h>
#define MAX 256

int obtieneLinea(char* nombreEmp);
void replace(int line);
int menuCambiaEmpleado();

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
                return 0;
        }
        arch2 = fopen(temp, "w");
        if (!arch2) 
        {
                printf("No  se pudo abrir archivo temporal\n");
                fclose(arch1);
                return 0;
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
        return 0;
  }