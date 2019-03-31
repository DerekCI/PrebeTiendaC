#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Empleado {
	char nombre_empleado[32];
	char usuario[32];
	char contrasena[32];
	char area[20];
	int sueldo[10];
	struct Empleado* siguiente;
}Empleado;
Empleado* empleados_inicio = NULL;
Empleado* empleados_final = NULL;
uint num_empleados = 0;

//Prototipos
Empleado* crearEmpleado(char nombre_empleado[],char usuario[], char contrasena[], char area[], int sueldo[] );
void agregarEmpleado(Empleado* empleado);
Empleado* removerEmpleado(char nombre_empleado[]);
bool EmpleadoRegistrado(char nombre_empleado[]);

Empleado* crearEmpleado(char nombre_empleado[],char usuario[], char contrasena[], char area[], int sueldo[]) {
	
	Empleado* nuevo = (Empleado*)malloc(sizeof(Empleado));
	strcpy(nuevo->nombre_empleado,nombre_empleado);
	strcpy(nuevo->contrasena,contrasena);
	strcpy(nuevo->area,area);
	nuevo->sueldo, sueldo;
	nuevo->siguiente = NULL;
	return nuevo;
}
void agregarEmpleado(Empleado* empleado) {
	if (empleados_inicio == NULL){
		empleados_inicio = empleado;
	}
	else {
		empleados_final->siguiente = empleado;
	}
	empleados_final = empleado;
	num_empleados++;
}
Empleado* removerEmpleado(char nombre_empleado[]) {
	
	Empleado* aux = empleados_inicio;
	if (empleados_inicio == empleados_final && strcmp(aux->nombre_empleado,nombre_empleado) == 0) {
		empleados_inicio = NULL;
		empleados_final = NULL;
		
		num_empleados--;
		return aux;
	}
	else if (strcmp(aux->nombre_empleado,nombre_empleado) == 0) {
		empleados_inicio = empleados_inicio->siguiente;
		aux->siguiente = NULL;
		
		num_empleados--;
		return aux;
	}
	else {
		Empleado* scout = empleados_inicio;
		while(strcmp(scout->nombre_empleado,nombre_empleado) != 0) {
			scout = scout->siguiente;
			if(scout == NULL) {
				return NULL;
			}
		}
		while(aux->siguiente != scout) {
			aux = aux->siguiente;
		}
		aux->siguiente = scout->siguiente;
		scout->siguiente = NULL;
		
		num_empleados--;
		return scout;
	}
}




void registrarEmpleado() {
	char nombre_empleado[32];
	char usuario[32];
	char contrasena[32];
	char area[20];
	int sueldo[10];
	//char buffer[32] = {'\0'};
	do {
		if(EmpleadoRegistrado(nombre_empleado)){
			printf("Ese dud ya esta registrado.\n");
		}
		printf("Ingrese nombre de empleado: \n");
		scanf("%c", nombre_empleado);
		printf("Ingrese usuario de empleado: \n");
		scanf("%c", usuario);
		printf("Ingrese contraseña de empleado: \n");
		scanf("%c", contrasena);
		printf("Ingrese area de empleado: \n");
		scanf("%c", area);
		printf("Ingrese sueldo de empleado: \n");
		scanf("%d", sueldo);

	} while (EmpleadoRegistrado(nombre_empleado));

	agregarEmpleado(crearEmpleado( nombre_empleado, usuario,  contrasena, area,  sueldo));
	printf("Empleado agregado con exito!.\n");
}

bool EmpleadoRegistrado(char nombre_empleado[]) {
	Empleado* aux = empleados_inicio;
	while(aux != NULL && strcmp(aux->nombre_empleado,nombre_empleado) != 0) {
		aux = aux->siguiente;
	}
	if (aux != NULL && strcmp(aux->nombre_empleado,nombre_empleado) == 0) {
		return true;
	}
	else {
		return false;
	}
}