# include <stdio.h>
# include <stdlib.h>
# include <string.h>	
#include <unistd.h>
#include <time.h>


/* ------------------------------------------------------------------ 1. REGISTRAR NIÑO ------------------------------------------------------------------ */

/* --------------------------- STRUCT DEL NIÑO --------------------------- */

typedef struct Kid
{
	char nombre [50];
	char nombre_usuario [50];
	char correo [50];
	char lugar_residencia [50];	
	int cedula;
	int edad;
	char fecha_nacimiento [50];
	char necesidades_especiales [50];	
	int contador_comportamiento_bueno;
	int contador_comportamiento_malo;
	struct Kid * next;	
}Kid;

typedef struct Imprimir
{
	Kid *front;
	Kid *rear;
	int size;
}Imprimir;

/* ----------------------- CREAR NUEVA COLA NIÑO ----------------------- */

Imprimir * CrearColaKids(Imprimir * ColaKids)
{
	ColaKids = NULL;
	ColaKids = (Imprimir *) malloc(sizeof(Imprimir));	
	ColaKids -> front = NULL;
	ColaKids -> rear = NULL;
	return ColaKids;
}

/* ----------------------- CREAR NODO NIÑO ----------------------- */

Kid * CrearKid(int cedula, char nombre[200], char nombre_usuario[200],char correo [200], char lugar_residencia [50], int edad, char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
{
	struct Kid *nuevo;
	nuevo = (Kid *) malloc(sizeof(Kid));
	nuevo -> next = NULL;
	
	nuevo->cedula=cedula;
	strcpy(nuevo->nombre,nombre);	
	strcpy(nuevo->nombre_usuario,nombre_usuario);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->lugar_residencia,lugar_residencia);
	nuevo->edad=edad;
	strcpy(nuevo->fecha_nacimiento,fecha_nacimiento);
	strcpy(nuevo->necesidades_especiales,necesidades_especiales);
	nuevo->contador_comportamiento_bueno = contador_comportamiento_bueno;
	nuevo->contador_comportamiento_malo = contador_comportamiento_malo;
	return nuevo;
}

/* ----------------------- REGISTRAR NIÑO ----------------------- */

Imprimir * InsertarKid(Imprimir * ColaKids, int cedula, char nombre[200], char nombre_usuario[200], char correo [200], char lugar_residencia [50], int edad, char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
{
	ColaKids->size = ColaKids-> size + 1;
	if(ColaKids->front == NULL) 
	{
		ColaKids->front = CrearKid(cedula,nombre, nombre_usuario, correo,lugar_residencia,edad,fecha_nacimiento,necesidades_especiales,contador_comportamiento_bueno, contador_comportamiento_malo);
		ColaKids->rear = ColaKids->front;
		return ColaKids;
	}
	ColaKids ->rear->next = CrearKid(cedula,nombre, nombre_usuario, correo,lugar_residencia,edad,fecha_nacimiento,necesidades_especiales,contador_comportamiento_bueno,contador_comportamiento_malo);
	ColaKids ->rear = ColaKids->rear->next;
}

/* ----------------------- CONSULTAR NIÑO----------------------- */

int ConsultarKids(Imprimir *ColaKids)
{
	Kid *i;
	int cedula_verificar;
	int contador; 
	
	if (ColaKids -> front == NULL)
	{
		printf ("\nERROR: No hay niños registrados.");
		return;
	}
	else
	{
		printf ("\nIngrese la cedula del niño que desea consultar: ")	;
		scanf("%d", &cedula_verificar);
		
		for(i = ColaKids->front; i!= NULL; i = i->next)
		{
			if(i->cedula==cedula_verificar)
			{
				contador = 1;
				
				printf("\n\nNombre: %s", i->nombre);
				printf("\nNombre de usuario: %s", i->nombre_usuario);
				printf("\nCorreo: %s", i->correo);
				printf("\nLugar de residencia: %s", i->lugar_residencia);
				printf("\nCedula: %d", i->cedula);
				printf("\nEdad: %d", i->edad);
				printf("\nFecha de nacimiento: %s", i->fecha_nacimiento);
				printf("\nNecesidades especiales: %s", i->necesidades_especiales);
				printf("\n____________________________________________________________________________\n");
			}
		}			
					
		if (contador == 0)
		{
			printf ("\nERROR: la cedula ingresada no existe, la accion no se puede realizar.");
			return;
		}
	}

	return 0;
}


/* ----------------------- REGISTRAR NIÑO EN EL MAIN ----------------------- */

void RegistrarKidMain(Imprimir *ColaKids)
{
	char nombre_kid[100];
	char nombre_usuario_kid[100];
	char correo_kid[100];
	char residencia_kid[100];
	int cedula_kid;
	int edad_kid;
	char nacimiento_kid[100];
	char necesidades_especiales_kid[100];
	
	
	printf ("\nIngrese el nombre del niño que desea registrar: ");
	fflush (stdin);
	gets (nombre_kid);

	printf ("Ingrese la cedula del niño que desea registrar: ");
	scanf("%d", &cedula_kid);
	
	Kid *i;
	
	for(i = ColaKids->front; i!= NULL; i = i->next)
	{
		if (cedula_kid == i->cedula)
		{
			printf("ERROR: La cedula ya existe, la accion no se pudo completar. Intentelo mas tarde.\n");
			return;
		}	
	}
		
	printf ("Ingrese el nombre de usuario del niño que desea registrar: ");
	fflush (stdin);
	gets (nombre_usuario_kid);
	
	printf ("Ingrese el correo del niño que desea registrar: ");
	fflush (stdin);
	gets (correo_kid);
	
	printf ("Ingrese el lugar de residencia del niño que desea registrar: ");
	fflush (stdin);
	gets (residencia_kid);
	
	printf ("Ingrese la edad del niño que desea registrar: ");
	scanf("%d", &edad_kid);
	
	printf ("Ingrese la fecha de nacimiento del niño que desea registrar [dd/mm/yy]: ");
	fflush (stdin);
	gets (nacimiento_kid);
	
	printf ("Ingrese las necesidades especiales del niño que desea registrar: ");
	fflush (stdin);
	gets (necesidades_especiales_kid);
	
	
	InsertarKid(ColaKids, cedula_kid, nombre_kid, nombre_usuario_kid, correo_kid, residencia_kid, edad_kid, nacimiento_kid, necesidades_especiales_kid, 0, 0);		
}





/* ----------------------------------------------------------- 2. MODIFICAR INFORMACION DE UN NIÑO -------------------------------------------------------- */

int ModificarInfoKid (Imprimir *ColaKids)
{
	int cedula_verificar;
	int contador = 0;
	
	Kid *i = ColaKids->front;
	
	printf ("\n\nIngrese la cedula del niño que desea modificar: ")	;
	scanf("%d", &cedula_verificar);
	Kid *aux = ColaKids->front;
	for(i = ColaKids->front; i!= NULL; i = i->next)
	{
		if (cedula_verificar == i->cedula)
		{
			contador = 1;
			
			printf ("\n\n-------------------- DATOS A MODIFICAR --------------------");
			printf ("\n1. Modificar nombre.");
			printf ("\n2. Modificar nombre de usuario.");
			printf ("\n3. Modificar correo.");
			printf ("\n4. Modificar lugar de residencia.");
			printf ("\n5. Modificar edad.");
			printf ("\n6. Modificar necesidades especiales.");
			
			int dato;
			printf ("\n\nIngrese el numero del dato que desea modificar: ");
			scanf("%d", &dato);
			
			if (dato == 1)
			{
				printf ("Ingrese el nuevo nombre del niño: ");
				scanf("%s",i->nombre);
			}
			
			else if (dato == 2)
			{
				printf ("Ingrese el nuevo nombre de usuario del niño: ");
				scanf("%s",i->nombre_usuario);
			}
			
			else if (dato == 3)
			{
				printf ("Ingrese el nuevo correo del niño: ");
				scanf("%s",i->correo);	
			}
			
			else if (dato == 4)
			{
				char modificar_lugar_residencia[100];
				
				printf ("Ingrese el nuevo lugar de residencia del niño: ");
				scanf("%s",i->lugar_residencia);				
			}
			
			else if (dato == 5)
			{
				printf ("Ingrese la nueva edad del niño: ");
				scanf("%d",i->edad);
			}
			
			else if (dato == 6)
			{
				printf ("Ingrese las nuevas necesidades especiales del niño: ");
				scanf("%s",i->necesidades_especiales);		
			}
			
			else
			{
				printf ("ERROR: el dato solicitado no existe, la accion no se pudo completar con exito.");
				return;
			}
			
			printf ("\nLa informacion fue modificada con exito.");
			printf ("\n\n-------------------- DATOS MODIFICADOS --------------------");
			printf("\n\nNombre: %s", i->nombre);
			printf("\nNombre de usuario: %s", i->nombre_usuario);
			printf("\nCorreo: %s", i->correo);
			printf("\nLugar de residencia: %s", i->lugar_residencia);
			printf("\nCedula: %d", i->cedula);
			printf("\nEdad: %d", i->edad);
			printf("\nFecha de nacimiento: %s", i->fecha_nacimiento);
			printf("\nNecesidades especiales: %s", i->necesidades_especiales);
			printf("\n____________________________________________________________________________\n");
			return;
		}

	}
		
	if (contador == 0)
	{
		printf ("\nERROR: la cedula ingresada no existe, la informacion no se pudo modificar.");
		return;
	}
	
	return;
}






/* ------------------------------------------------------------- 3. REGISTRAR AYUDANTE DE SANTA ------------------------------------------------------------ */

/* --------------------------- STRUCT DEL AYUDANTE --------------------------- */

typedef struct Ayudante
{
	char nombre [50];
	char puesto [50];
	char correo [50];
	char funcion [50];	
	int cedula;
	char fecha_entrada [50];	
	int contador_cartas;
	struct Ayudante * next;	
}Ayudante;

typedef struct ImprimirAyudante
{
	Ayudante *front;
	Ayudante *rear;
	int size;
}ImprimirAyudante;

/* ----------------------- CREAR NUEVA COLA AYUDANTE ----------------------- */

ImprimirAyudante * CrearColaAyudantes(ImprimirAyudante * ColaAyudantes)
{
	ColaAyudantes = NULL;
	ColaAyudantes = (ImprimirAyudante *) malloc(sizeof(ImprimirAyudante));	
	ColaAyudantes -> front = NULL;
	ColaAyudantes -> rear = NULL;
	return ColaAyudantes;
}

/* ----------------------- CREAR NODO AYUDANTE ----------------------- */

Ayudante * CrearAyudante(int cedula, char nombre[200], char puesto[200],char correo [200], char funcion [200], char fecha_entrada [50], int contador_cartas)
{
	struct Ayudante *nuevo;
	nuevo = (Ayudante *) malloc(sizeof(Ayudante));
	nuevo -> next = NULL;
	
	nuevo->cedula=cedula;
	strcpy(nuevo->nombre,nombre);	
	strcpy(nuevo->puesto,puesto);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->funcion,funcion);
	strcpy(nuevo->fecha_entrada,fecha_entrada);
	nuevo->contador_cartas = contador_cartas;
	return nuevo;
}

/* ----------------------- REGISTRAR AYUDANTE ----------------------- */

ImprimirAyudante * InsertarAyudante(ImprimirAyudante * ColaAyudantes, int cedula, char nombre[200], char puesto[200], char correo [200], char funcion [200], char fecha_entrada [50], int contador_cartas)
{
	ColaAyudantes->size = ColaAyudantes-> size + 1;
	if(ColaAyudantes->front == NULL) 
	{
		ColaAyudantes->front = CrearAyudante(cedula,nombre, puesto, correo,funcion,fecha_entrada,contador_cartas);
		ColaAyudantes->rear = ColaAyudantes->front;
		return ColaAyudantes;
	}
	ColaAyudantes ->rear->next = CrearAyudante(cedula,nombre, puesto, correo,funcion,fecha_entrada,contador_cartas);
	ColaAyudantes ->rear = ColaAyudantes->rear->next;
}


/* ----------------------- CONSULTAR AYUDANTE ----------------------- */

int ConsultarAyudantes(ImprimirAyudante *ColaAyudantes)
{
	Ayudante *i;
	int cedula_verificar;
	int contador; 
	
	if (ColaAyudantes -> front == NULL)
	{
		printf ("\nERROR: No hay ayudantes registrados");
	}
	
	else
	{
		printf ("\nIngrese la cedula del ayudante que desea consultar: ")	;
		scanf("%d", &cedula_verificar);
		
		for(i = ColaAyudantes->front; i!= NULL; i = i->next)
		{
			if(i->cedula == cedula_verificar)
			{
				contador = 1;
				
				printf("\n\nNombre: %s", i->nombre);
				printf("\nPuesto: %s", i->puesto);
				printf("\nCorreo: %s", i->correo);
				printf("\nFuncion: %s", i->funcion);
				printf("\nCedula: %d", i->cedula);
				printf("\nFecha en que comienza a trabajar: %s", i->fecha_entrada);
				printf("\n____________________________________________________________________________\n");
			}
		}			
					
		if (contador == 0)
		{
			printf ("\nERROR: la cedula ingresada no existe, la accion no se puede realizar.");
			return;
		}
	}

	return;
}



/* ----------------------- REGISTRAR AYUDANTE EN EL MAIN ----------------------- */

void RegistrarAyudanteMain(ImprimirAyudante *ColaAyudantes)
{
	char nombre_ayudante[100];
	char correo_ayudante[100];
	char puesto_ayudante[100];
	int cedula_ayudante;	
	char funcion_ayudante[100];
	char fecha_entrada_ayudante[100];
	
	
	printf ("\nIngrese el nombre del ayudante que desea registrar: ");
	fflush (stdin);
	gets (nombre_ayudante);

	printf ("Ingrese la cedula del ayudante que desea registrar: ");
	scanf("%d", &cedula_ayudante);
	
	Ayudante *i;
	
	for(i = ColaAyudantes->front; i!= NULL; i = i->next)
	{
		if (cedula_ayudante == i->cedula)
		{
			printf("ERROR: La cedula ya existe, la accion no se pudo completar. Intentelo mas tarde.\n");
			return;
		}	
	}
	
	printf ("Ingrese el correo del ayudante que desea registrar: ");
	fflush (stdin);
	gets (correo_ayudante);
	
	printf ("Ingrese el puesto del ayudante que desea registrar: ");
	fflush (stdin);
	gets (puesto_ayudante);
	
	printf ("Ingrese la fecha en que el ayudante comienza a trabajar [dd/mm/yy]: ");
	fflush (stdin);
	gets (fecha_entrada_ayudante);
	
	printf ("Ingrese la funcion del ayudante que desea registrar: ");
	fflush (stdin);
	gets (funcion_ayudante);
	
	
	InsertarAyudante(ColaAyudantes, cedula_ayudante, nombre_ayudante, puesto_ayudante, correo_ayudante, funcion_ayudante, fecha_entrada_ayudante, 0);

}




/* ------------------------------------------------------- 4. MODIFICAR INFORMACION DE UN AYUDANTE DE SANTA ------------------------------------------------- */


int ModificarInfoAyudante (ImprimirAyudante *ColaAyudantes)
{
	int cedula_verificar;
	int contador = 0;	

	if (ColaAyudantes -> front == NULL)
	{
		printf ("\nERROR: No hay ayudantes registrados");
	}
	
	else
	{
		Ayudante *i = ColaAyudantes->front;
		
		printf ("\n\nIngrese la cedula del ayudante que desea modificar: ")	;
		scanf("%d", &cedula_verificar);
		
		for(i = ColaAyudantes->front; i!= NULL; i = i->next)
		{
			if (cedula_verificar == i->cedula)
			{
				contador = 1;
				
				printf ("\n\n-------------------- DATOS A MODIFICAR --------------------");
				printf ("\n1. Modificar nombre.");
				printf ("\n2. Modificar puesto.");
				printf ("\n3. Modificar correo.");
				printf ("\n4. Modificar funcion.");
				
				int dato;
				printf ("\n\nIngrese el numero del dato que desea modificar: ");
				scanf("%d", &dato);
				
				if (dato == 1)
				{
					printf ("Ingrese el nuevo nombre del ayudante: ");
					scanf("%s",i->nombre);
				}
				
				else if (dato == 2)
				{
					printf ("Ingrese el nuevo puesto del ayudante: ");
					scanf("%s",i->puesto);
				}
				
				else if (dato == 3)
				{
					printf ("Ingrese el nuevo correo del ayudante: ");
					scanf("%s",i->correo);	
				}
				
				else if (dato == 4)
				{
					printf ("Ingrese la nueva funcion del ayudante: ");
					scanf("%s",i->funcion);				
				}
				
				else
				{
					printf ("ERROR: el dato solicitado no existe, la accion no se pudo completar con exito.");
					return;
				}
				
				printf ("\nLa informacion fue modificada con exito.");
				printf ("\n\n-------------------- DATOS MODIFICADOS --------------------");
				printf("\n\nNombre: %s", i->nombre);
				printf("\n\nPuesto: %s", i->puesto);
				printf("\nCorreo: %s", i->correo);
				printf("\nFuncion: %s", i->funcion);
				printf("\nCedula: %d", i->cedula);
				printf("\nFecha en que comienza a trabajar: %s", i->fecha_entrada);
				printf("\n____________________________________________________________________________\n");	
				return;		
			}
		}
			
		if (contador == 0)
		{
			printf ("\nERROR: la cedula ingresada no existe, la informacion no se pudo modificar.");
			return;
		}
	}
		
	return;
}







/* ------------------------------------------------------------------ 5. REGISTRAR JUGUETE ------------------------------------------------------------------ */






/* ----------------------------------------------------------- 6. MODIFICAR INFORMACION DE UN JUGUETE -------------------------------------------------------- */






/* -------------------------------------------------------------- 7. REGISTRAR LUGAR DE DOMICILIO ------------------------------------------------------------ */






/* -------------------------------------------------------------- 8. MODIFICAR LUGAR DE DOMICILIO ------------------------------------------------------------ */






/* ----------------------------------------------------------- 9. REGISTRAR COMPORTAMIENTO DE UN NIÑO -------------------------------------------------------- */






/* --------------------------------------------------------------- 10. REGISTRAR CARTA PARA SANTA ------------------------------------------------------------- */






/* --------------------------------------------------------------- 11. MODIFICAR CARTA PARA SANTA ------------------------------------------------------------- */






/* --------------------------------------------------------------- 12. CONSULTAR CARTA PARA SANTA ------------------------------------------------------------- */






/* ---------------------------------------------------------------- 13. PROCESAR CARTA PARA SANTA ------------------------------------------------------------- */






/* ------------------------------------------------------------------ 14. ENTREGA DE JUGUETES ----------------------------------------------------------------- */






/* ------------------------------------------------------------------ 15. ANALISIS DE DATOS ------------------------------------------------------------------- */














/* ------------------------------------------------------------------ FUNCION PRINCIPAL ------------------------------------------------------------------ */

int main()
{
	//DECLARACION DE ESTRUCTURAS DE DATOS
	Imprimir * ColaKids = CrearColaKids(ColaKids);
	ImprimirAyudante * ColaAyudantes = CrearColaAyudantes(ColaAyudantes);
	
	
	//MENU PRINCIPAL DE LA FUNCION
	printf ("\n --------------------- BIENVENIDO AL SISTEMA DE REGISTRO Y PROCESAMIENTO DE CARTAS DE SANTA --------------------- \n");

	printf ("\n\n -------------------------- MENU PRINCIPAL -------------------------- \n");
	printf ("\n 1.  Registrar niño.");
	printf ("\n 2.  Modificar informacion de un niño.");
	printf ("\n 3.  Registrar ayudante de Santa.");
	printf ("\n 4.  Modificar informacion de un ayudante de Santa.");
	printf ("\n 5.  Registrar juguete.");
	printf ("\n 6.  Modificar informacion de un juguete.");
	printf ("\n 7.  Registrar lugar de domicilio en el catalogo.");
	printf ("\n 8.  Modificar lugar de domicilio en el catalogo.");
	printf ("\n 9.  Registrar comportamiento de un niño.");
	printf ("\n 10. Registrar carta para Santa.");
	printf ("\n 11. Modificar carta para Santa.");
	printf ("\n 12. Consultar carta para Santa.");
	printf ("\n 13. Procesar carta para Santa.");
	printf ("\n 14. Realizar entrega de juguetes.");
	printf ("\n 15. Analizar datos.");
	printf ("\n 16. Finalizar programa.");
	
	int opcion;
	printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
	scanf_s ("%d", &opcion);
	
	while (opcion != 16)
	{
		if (opcion == 1)
		{
			RegistrarKidMain(ColaKids);
			//ConsultarKids(ColaKids);   //Funcion para probar otras, no la piden
		}
		
		
		else if (opcion == 2)
		{
			ModificarInfoKid (ColaKids);
		}
		
		
		else if (opcion == 3)
		{
			RegistrarAyudanteMain(ColaAyudantes);
			//ConsultarAyudantes(ColaAyudantes);   //Funcion para probar otras, no la piden		
		}
		
		
		else if (opcion == 4)
		{
			ModificarInfoAyudante (ColaAyudantes);
		}
		
		
		else if (opcion == 5)
		{
			return 0;
		}
		
	
		else if (opcion == 6)
		{
			return 0;
		}
		
		
		else if (opcion == 7)
		{
			return 0;
		}
		
		
		else if (opcion == 8)
		{
			return 0;;
		}
		
		
		else if (opcion == 9)
		{
			return 0;
		}
		
		
		else if (opcion == 10)
		{
			return 0;
		}
		
		
		else if (opcion == 11)
		{
			return 0;
		}
		
		
		else if (opcion == 12)
		{
			return 0;
		}
		
		
		else if (opcion == 13)
		{
			return 0;
		}
		
		
		else if (opcion == 14)
		{
			return 0;
		}
		
		
		else if (opcion == 15)
		{
			return 0;
		}
		
		
		else
		{
			printf("\nERROR: La opcion solicitada no se encuentra disponible");
		}	
		
		int opcion_p;

		printf ("\n\nDijite 1 si desea continuar con el programa: ");
		scanf_s ("%d", &opcion_p);
		
		if (opcion_p ==1)
		{
			printf ("\n\n -------------------------- MENU PRINCIPAL -------------------------- \n");
			printf ("\n 1.  Registrar niño.");
			printf ("\n 2.  Modificar informacion de un niño.");
			printf ("\n 3.  Registrar ayudante de Santa.");
			printf ("\n 4.  Modificar informacion de un ayudante de Santa.");
			printf ("\n 5.  Registrar juguete.");
			printf ("\n 6.  Modificar informacion de un juguete.");
			printf ("\n 7.  Registrar lugar de domicilio en el catalogo.");
			printf ("\n 8.  Modificar lugar de domicilio en el catalogo.");
			printf ("\n 9.  Registrar comportamiento de un niño.");
			printf ("\n 10. Registrar carta para Santa.");
			printf ("\n 11. Modificar carta para Santa.");
			printf ("\n 12. Consultar carta para Santa.");
			printf ("\n 13. Procesar carta para Santa.");
			printf ("\n 14. Realizar entrega de juguetes.");
			printf ("\n 15. Analizar datos.");
			printf ("\n 16. Finalizar programa.");
			
			printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
			scanf_s ("%d", &opcion);
		}
		else
		{
			printf ("\n\nPrograma Finalizado.");
			return 0;
		}	
	}
	
	printf ("\n\nPrograma Finalizado.");
	return 0;
}
	


