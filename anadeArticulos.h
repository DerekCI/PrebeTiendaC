#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
char * obtieneCadenaArt(int linea,char* depto);
int anadeArticulo();
int obtieneLineaArt(char* nombreEmp,char* depto);
char* itoa(int i, char b[]);

char * obtieneCadenaArt(int linea,char depto[30]){
	
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(depto,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp))
	{
		

		fscanf(fp, "%s\n", nombre);
		lines++;
		if(lines%6==5){
			linea--;
		}
		if(lines==linea)
		{
			fclose(fp);
			return nombre;	
		}
		
	}
	}
	fclose(fp); //cierra el archivo 
	return nombre;
}
int anadeArticulo() 
  {

        FILE *arch1, *arch2;
        int li, cuentaL = 0;
        char str[MAX],fname[MAX];     
        char art[MAX];
        char nombreDep[MAX];   
        char nueva[MAX], temp[] = "temp.txt";
        printf("-------------------------------------------------------------\n"); 
        //fgets(fname, MAX, stdin);
        //fname[strlen(fname) - 1] = '\0';
        printf("Nombre del departamento: "); //se tiene que poner el nombre del depa con .d -> nuevoDepa.d
		scanf("%s",nombreDep);
		strcat(nombreDep,".d"); 
		arch1 = fopen ( nombreDep, "r" );
		printf("Escribe id de articulo a surtir ");
		scanf("%s",&art);
        //arch1 = fopen("empleados", "r");
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
        int r= obtieneLineaArt(art,nombreDep);//linea donde esta el nombre del articulo
        printf("linea obtenida%d\n",r );
        if(r==-1){
        	printf("No existe ese articulo\n");
        }
        printf("loquehay----%s\n", obtieneCadenaArt(r+2,nombreDep));
		int hay = atoi( obtieneCadenaArt(r+2,nombreDep));
        printf(" Ingresa el numero de articulos a añadir: ");
        scanf("%s",&nueva);
        hay = hay + atoi( nueva);
        itoa(hay, nueva);
        //fgets(nueva, MAX, stdin);
        li=r+2;
        printf("%d\n",li );
        scanf("%d",&li);
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
                        fprintf(arch2, "%s\n", nueva);
                    }
                }
        }
        fclose(arch1);
        fclose(arch2);
        remove(nombreDep);
        rename(temp, nombreDep);
        printf(" Se realizo correctamente el cambio \n");
        return -1;
      
}

int obtieneLineaArt(char* nombreEmp,char* depto){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(depto,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp))
	{
		

		fscanf(fp, "%s\n", nombre);
		lines++;
		if(lines%5==0){
            lines++;
        }
		//printf("%d\n",lines );
		if(strcmp(nombre,nombreEmp) == 0)
		{
			printf("si jala-%d\n",lines );
			if((lines)%6==1){
				fclose(fp);
				return lines;	
			}
			
		}
	}
}
	fclose(fp); //cierra el archivo 
	printf("Articulo no encontrado.\n");
	return -1;
}

char* itoa(int i, char b[]){
    char const digito[] = "0123456789";
    char* ptr = b;
    if(i < 0){
        *ptr++ = '-';
        i *= -1;
    }
    int aux = i;
    do{ 
        ++ptr;
        aux = aux/10;
    }while(aux);
    *ptr = '\0';
    do{ 
        *--p = digito[i%10];
        i = i/10;
    }while(i);

    return b;
}