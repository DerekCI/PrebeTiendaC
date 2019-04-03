#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX 256

struct articuloV {

    char codigo[MAX];
    char nombre[MAX];
    char cantidad[MAX];
    char costo[MAX];
    char precio[MAX];
    char total[MAX];
};

typedef struct articulos Articulos;

char * obtieneCadenaV(int linea,char* depto);
int vendeArticulo();
int obtieneLineaV(char* nombreEmp,char* depto);
char* itoaV(int i, char b[]);

char * obtieneCadenaV(int linea,char depto[30]){
    
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
int vendeArticulo() 
  {
       int total=0;
    int i=0;
        FILE *arch1, *arch2;
        int li, cuentaL = 0;
        char str[MAX],fname[MAX];     
        char art[MAX];
        char nombreDep[MAX];   
        char nueva[MAX], temp[] = "temp.txt";

        struct articuloV Articulo[MAX];
        printf("-------------------------------------------------------------\n"); 
       
        int z;
       do{
        i++;
        printf("Nombre del departamento donde desea comprar: "); //se tiene que poner el nombre del depa con .d -> nuevoDepa.d
        scanf("%s",nombreDep);
        strcat(nombreDep,".d"); 
        arch1 = fopen ( nombreDep, "r" );
        printf("Escribe id de articulo a comprar ");
        scanf("%s",&art);
      
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
        int r= obtieneLineaV(art,nombreDep);//linea donde esta el nombre del articulo
        printf("linea obtenida%d\n",r );
        if(r==-1){
            printf("No existe ese articulo\n");
        }
        printf("loquehay----%s\n", obtieneCadenaV(r+2,nombreDep));
        int hay = atoi( obtieneCadenaV(r+2,nombreDep));
        
        printf(" Ingresa el numero de articulos que desea comprar: ");
        scanf("%s",&nueva);
        strcpy(Articulo[i].cantidad,nueva);
        //Articulo[i].cantidad=nueva;
        strcpy(Articulo[i].nombre,obtieneCadenaV(r+1,nombreDep));
        //Articulo[i].nombre=obtieneCadenaArt(r,nombreDep);
        strcpy(Articulo[i].precio,obtieneCadenaV(r+4,nombreDep));

        itoaV(atoi(nueva)*atoi(Articulo[i].precio),Articulo[i].total);
        total+=atoi(Articulo[i].total);

        hay = hay - atoi( nueva);
        itoaV(hay, nueva);
      
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
        
        printf("Desea acabar compra? (1) si (2) no"); //se tiene que poner el nombre del depa con .d -> nuevoDepa.d
        
        scanf("%d",&z);
        

       }while(z==2);
        
       //ticket
       printf("----------------------------------------------------\n");
       for (int j = 1; j <=i; j++)
       {
        printf("%s\t%s\t%s\t%s\n",Articulo[j].cantidad,Articulo[j].nombre,Articulo[j].precio,Articulo[j].total );
       }
       printf("El total de la compra es --> %d\n",total );


        return -1;
      
}

int obtieneLineaV(char* nombreEmp,char* depto){
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

char* itoaV(int i, char b[]){//redefino el itoa porque habia problema con la funcion
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ 
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}