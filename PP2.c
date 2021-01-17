# include <stdio.h>
# include <stdlib.h>
# include <string.h>	
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define Domicilio struct domicilio
#define Ruta struct ruta
#define Lista struct pila




/* ------------------------------------------------------------- 3. REGISTRAR AYUDANTE DE SANTA ------------------------------------------------------------ */

/* --------------------------- STRUCT DEL AYUDANTE --------------------------- */

typedef struct Ayudante
{
	char nombre [50];
	char puesto [50];
	char correo [50];
	char funcion [50];	
	char cedula[50];
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

Ayudante * CrearAyudante(char cedula[50], char nombre[200], char puesto[200],char correo [200], char funcion [200], char fecha_entrada [50], int contador_cartas)
{
	struct Ayudante *nuevo;
	nuevo = (Ayudante *) malloc(sizeof(Ayudante));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->nombre,nombre);	
	strcpy(nuevo->puesto,puesto);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->funcion,funcion);
	strcpy(nuevo->fecha_entrada,fecha_entrada);
	nuevo->contador_cartas = contador_cartas;
	return nuevo;
}

/* ----------------------- REGISTRAR AYUDANTE ----------------------- */

ImprimirAyudante * InsertarAyudante(ImprimirAyudante * ColaAyudantes, char cedula[50], char nombre[200], char puesto[200], char correo [200], char funcion [200], char fecha_entrada [50], int contador_cartas)
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
	char cedula_verificar[20];
	int contador; 
	
	if (ColaAyudantes -> front == NULL)
	{
		printf ("\nERROR: No hay ayudantes registrados");
	}
	
	else
	{
		printf ("\nIngrese la cedula del ayudante que desea consultar: ")	;
		fflush (stdin);
		gets (cedula_verificar);
		
		for(i = ColaAyudantes->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,cedula_verificar)==0)
			{
				contador = 1;
				
				printf("\n\nNombre: %s", i->nombre);
				printf("\nPuesto: %s", i->puesto);
				printf("\nCorreo: %s", i->correo);
				printf("\nFuncion: %s", i->funcion);
				printf("\nCedula: %s", i->cedula);
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
	char num_puesto[100];
	char puesto_ayudante[100];
	char cedula_ayudante[50];
	char num_funcion[100];	
	char funcion_ayudante[100];
	char fecha_entrada_ayudante[100];
	
	
	printf ("\nIngrese el nombre del ayudante que desea registrar: ");
	fflush (stdin);
	gets (nombre_ayudante);

	printf ("Ingrese la cedula del ayudante que desea registrar: ");
	fflush (stdin);
	gets (cedula_ayudante);
	
	Ayudante *i;
	
	for(i = ColaAyudantes->front; i!= NULL; i = i->next)
	{
		if (strcmp(i->cedula,cedula_ayudante)==0)
		{
			printf("ERROR: La cedula ya existe, la accion no se pudo completar. Intentelo mas tarde.\n");
			return;
		}	
	}
	
	printf ("Ingrese el correo del ayudante que desea registrar: ");
	fflush (stdin);
	gets (correo_ayudante);
	
	
	printf ("\n\n---------------- PUESTOS DISPONIBLES ----------------");
	printf ("\n1. Gestion de cartas");
	printf ("\n2. Produccion de juguetes");
	printf ("\n3. Envoltorio de juguetes");
	printf ("\n4. Distribucion de regalos");
	printf ("\n\nIngrese numero del puesto que el ayudante realiza: ");
	fflush (stdin);
	gets (num_puesto);
	
	if (strcmp(num_puesto,"1")==0)
	{
		strcpy(puesto_ayudante,"Gestion de cartas");
		
		printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
		printf ("\n1. Seleccion de cartas.");
		printf ("\n2. Clasificacion de niños segun su comportamiento.");	
		printf ("\n\nIngrese la funcion que realiza el ayudante: ");
		fflush (stdin);
		gets (num_funcion);
		
		if (strcmp(num_funcion,"1")==0)
		{
			strcpy(funcion_ayudante,"Seleccion de cartas");
		}
		else if (strcmp(num_funcion,"2")==0)
		{
			strcpy(funcion_ayudante,"Clasificacion de niños segun su comportamiento");
		}
		else
		{
			printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
			return;
		}				
	}
	
	else if (strcmp(num_puesto,"2")==0)
	{
		strcpy(puesto_ayudante,"Produccion de juguetes");

		printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
		printf ("\n1. Ensamblaje de juguetes.");
		printf ("\n2. Inventario de juguetes producidos.");
		printf ("\n3. Manipulacion de materia prima.");	
		printf ("\n\nIngrese la funcion que realiza el ayudante: ");
		fflush (stdin);
		gets (num_funcion);
		
		if (strcmp(num_funcion,"1")==0)
		{
			strcpy(funcion_ayudante,"Ensamblaje de juguetes");
		}
		else if (strcmp(num_funcion,"2")==0)
		{
			strcpy(funcion_ayudante,"Inventario de juguetes producidos");
		}
		else if (strcmp(num_funcion,"3")==0)
		{
			strcpy(funcion_ayudante,"Manipulacion de materia prima");
		}
		else
		{
			printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
			return;
		}
	}
	
	else if (strcmp(num_puesto,"3")==0)
	{
		strcpy(puesto_ayudante,"Envoltorio de juguetes");
		
		printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
		printf ("\n1. Inventario de envoltorios de navidad.");
		printf ("\n2. Envoltorio de regalos.");
		printf ("\n3. Inventario de juguetes envueltos.");	
		printf ("\n\nIngrese la funcion que realiza el ayudante: ");
		fflush (stdin);
		gets (num_funcion);
		
		if (strcmp(num_funcion,"1")==0)
		{
			strcpy(funcion_ayudante,"Inventario de envoltorios de navidad");
		}
		else if (strcmp(num_funcion,"2")==0)
		{
			strcpy(funcion_ayudante,"Envoltorio de regalos");
		}
		else if (strcmp(num_funcion,"3")==0)
		{
			strcpy(funcion_ayudante,"Inventario de juguetes envueltos");
		}
		else
		{
			printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
			return;
		}
	}
	
	else if (strcmp(num_puesto,"4")==0)
	{
		strcpy(puesto_ayudante,"Distribucion de regalos");

		printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
		printf ("\n1. Inventario de regalos a entregar.");
		printf ("\n2. Distribucion de regalos segun la region.");	
		printf ("\n\nIngrese la funcion que realiza el ayudante: ");
		fflush (stdin);
		gets (num_funcion);
		
		if (strcmp(num_funcion,"1")==0)
		{
			strcpy(funcion_ayudante,"Inventario de regalos a entregar");
		}
		else if (strcmp(num_funcion,"2")==0)
		{
			strcpy(funcion_ayudante,"Distribucion de regalos segun la region");
		}
		else
		{
			printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
			return;
		}
	}
	
	else
	{
		printf("\nERROR: el puesto no existe, la accion no se pudo realizar con exito.");
		return;
	}
	
				
	printf ("Ingrese la fecha en que el ayudante comienza a trabajar [dd/mm/yy]: ");
	fflush (stdin);
	gets (fecha_entrada_ayudante);
	
	InsertarAyudante(ColaAyudantes, cedula_ayudante, nombre_ayudante, puesto_ayudante, correo_ayudante, funcion_ayudante, fecha_entrada_ayudante, 0);

	return;
}




/* ------------------------------------------------------- 4. MODIFICAR INFORMACION DE UN AYUDANTE DE SANTA ------------------------------------------------- */

int ModificarInfoAyudante (ImprimirAyudante *ColaAyudantes)
{
	char cedula_verificar[20];
	int contador = 0;	

	if (ColaAyudantes -> front == NULL)
	{
		printf ("\nERROR: No hay ayudantes registrados");
	}
	
	else
	{
		Ayudante *i = ColaAyudantes->front;
		
		printf ("\n\nIngrese la cedula del ayudante que desea modificar: ")	;
		fflush (stdin);
		gets (cedula_verificar);
		
		for(i = ColaAyudantes->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,cedula_verificar)==0)
			{
				contador = 1;
				
				printf ("\n\n-------------------- DATOS A MODIFICAR --------------------");
				printf ("\n1. Modificar nombre.");
				printf ("\n2. Modificar correo.");
				printf ("\n3. Modificar puesto y funcion.");
				
				int dato;
				printf ("\n\nIngrese el numero del dato que desea modificar: ");
				scanf("%d", &dato);
				
				if (dato == 1)
				{
					printf ("Ingrese el nuevo nombre del ayudante: ");
					fflush (stdin);
					gets (i->nombre);
				}
				
				else if (dato == 2)
				{
					printf ("Ingrese el nuevo correo del ayudante: ");
					fflush (stdin);
					gets (i->correo);
				}
				
				else if (dato == 3)
				{
					char num_puesto[20];
					char num_funcion[20];
					
					printf ("\n\n---------------- PUESTOS DISPONIBLES ----------------");
					printf ("\n1. Gestion de cartas");
					printf ("\n2. Produccion de juguetes");
					printf ("\n3. Envoltorio de juguetes");
					printf ("\n4. Distribucion de regalos");
				
					printf ("\nIngrese el numero del nuevo puesto del ayudante: ");
					fflush (stdin);
					gets (num_puesto);
					
					if (strcmp(num_puesto,"1")==0)
					{
						strcpy(i->puesto,"Gestion de cartas");
						
						printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
						printf ("\n1. Seleccion de cartas.");
						printf ("\n2. Clasificacion de niños segun su comportamiento.");	
						printf ("\n\nIngrese la funcion que realiza el ayudante: ");
						fflush (stdin);
						gets (num_funcion);
						
						if (strcmp(num_funcion,"1")==0)
						{
							strcpy(i->funcion,"Seleccion de cartas");
						}
						else if (strcmp(num_funcion,"2")==0)
						{
							strcpy(i->funcion,"Clasificacion de niños segun su comportamiento");
						}
						else
						{
							printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
							return;
						}
					}
					
					else if (strcmp(num_puesto,"2")==0)
					{
						strcpy(i->puesto,"Produccion de juguetes");

						printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
						printf ("\n1. Ensamblaje de juguetes.");
						printf ("\n2. Inventario de juguetes producidos.");
						printf ("\n3. Manipulacion de materia prima.");	
						printf ("\n\nIngrese la funcion que realiza el ayudante: ");
						fflush (stdin);
						gets (num_funcion);
						
						if (strcmp(num_funcion,"1")==0)
						{
							strcpy(i->funcion,"Ensamblaje de juguetes");
						}
						else if (strcmp(num_funcion,"2")==0)
						{
							strcpy(i->funcion,"Inventario de juguetes producidos");
						}
						else if (strcmp(num_funcion,"3")==0)
						{
							strcpy(i->funcion,"Manipulacion de materia prima");
						}
						else
						{
							printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
							return;
						}
					}
					
					else if (strcmp(num_puesto,"3")==0)
					{
						strcpy(i->puesto,"Envoltorio de juguetes");
						
						printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
						printf ("\n1. Inventario de envoltorios de navidad.");
						printf ("\n2. Envoltorio de regalos.");
						printf ("\n3. Inventario de juguetes envueltos.");	
						printf ("\n\nIngrese la funcion que realiza el ayudante: ");
						fflush (stdin);
						gets (num_funcion);
						
						if (strcmp(num_funcion,"1")==0)
						{
							strcpy(i->funcion,"Inventario de envoltorios de navidad");
						}
						else if (strcmp(num_funcion,"2")==0)
						{
							strcpy(i->funcion,"Envoltorio de regalos");
						}
						else if (strcmp(num_funcion,"3")==0)
						{
							strcpy(i->funcion,"Inventario de juguetes envueltos");
						}
						else
						{
							printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
							return;
						}
					}
					
					else if (strcmp(num_puesto,"4")==0)
					{
						strcpy(i->puesto,"Distribucion de regalos");
						
						printf ("\n\n---------------- FUNCIONES DISPONIBLES ----------------");
						printf ("\n1. Inventario de regalos a entregar.");
						printf ("\n2. Distribucion de regalos segun la region.");	
						printf ("\n\nIngrese la funcion que realiza el ayudante: ");
						fflush (stdin);
						gets (num_funcion);
						
						if (strcmp(num_funcion,"1")==0)
						{
							strcpy(i->funcion,"Inventario de regalos a entregar");
						}
						else if (strcmp(num_funcion,"2")==0)
						{
							strcpy(i->funcion,"Distribucion de regalos segun la region");
						}
						else
						{
							printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
							return;
						}
					}	
					
					else
					{
						printf("\nERROR: el puesto no existe, la accion no se pudo realizar con exito.");
						return;
					}	
				}
				
				else
				{
					printf ("ERROR: el dato solicitado no existe, la accion no se pudo completar con exito.");
					return;
				}
				
				printf ("\nLa informacion fue modificada con exito.");
				printf ("\n\n-------------------- DATOS MODIFICADOS --------------------");
				printf("\n\nNombre: %s", i->nombre);
				printf("\nPuesto: %s", i->puesto);
				printf("\nCorreo: %s", i->correo);
				printf("\nFuncion: %s", i->funcion);
				printf("\nCedula: %s", i->cedula);
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


typedef struct _nodo {
	
	//DATOS DEL JUGUETE
	int dato;
	char nombre [15];
	char descripcion [30];
	char categoria [15];
	int edad_minima;
	int edad_maxima;
	int costo;
	int contador;
	struct _nodo *derecho;
	struct _nodo *izquierdo;\
	
} tipoNodo;


typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;
Arbol ArbolInt=NULL;


//FUNCIONES AUXILIARES ARBOL BINARIO
int Vacio(Arbol r)
{
   return r==NULL;
}


int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}


int BuscarCodigo(Arbol a, int dat)
{
	pNodo actual = a;

	while(!Vacio(actual)) 
	{
		if(dat == actual->dato) 
		{ 
			return 0;
		}
		else if(dat < actual->dato) actual = actual->izquierdo; 
		else if(dat > actual->dato) actual = actual->derecho;
	}
	return 1; 
}

//INSERTAR ARBOL DE JUGUETES
void InsertarArbol(Arbol *a, int dat,char nombre[15], char descripcion [30],char categoria [15], int edad_minima, int edad_maxima, int costo, int contador)
{
	pNodo padre = NULL;
	pNodo actual = *a;

	while(!Vacio(actual) && dat != actual->dato) 
	{
		padre = actual;
		if(dat < actual->dato) actual = actual->izquierdo;
		else if(dat > actual->dato) actual = actual->derecho;
	}

   /* Si se ha encontrado el elemento, regresar sin insertar */
	if(!Vacio(actual)) 
	{
		printf("Error: juguete ya registrado");
		return;	
	}
   
   //PADRE
	if(Vacio(padre)) 
	{
		*a = (Arbol)malloc(sizeof(tipoNodo));
		(*a)->dato = dat;
    	(*a)-> edad_minima = edad_minima;
    	(*a)->costo= costo;
    	(*a)->contador= contador;
    	(*a)->edad_maxima= edad_maxima;
    	strcpy((*a)->categoria,categoria);
    	strcpy((*a)->descripcion,descripcion);
		strcpy((*a)->nombre,nombre);
    	(*a)->izquierdo = (*a)->derecho = NULL;
	}
	
   //IZQUIERDA
	else if(dat < padre->dato) 
	{
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->izquierdo = actual;
		actual->dato = dat;
		actual-> edad_minima = edad_minima;
		actual->costo= costo;
		actual->contador= contador;
		actual->edad_maxima = edad_maxima;
		strcpy(actual->categoria,categoria);
		strcpy(actual->descripcion,descripcion);
		strcpy(actual->nombre,nombre);
		
		actual->izquierdo = actual->derecho = NULL;
	}
	
	//DERECHA
	else if(dat > padre->dato) 
	{
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->derecho = actual;
		actual->dato = dat;
		actual->edad_minima = edad_minima;
		actual->costo= costo;
		actual->contador = contador;
		actual->edad_maxima = edad_maxima;
		strcpy(actual->categoria,categoria);
		strcpy(actual->descripcion,descripcion);
		strcpy(actual->nombre,nombre);
		actual->izquierdo = actual->derecho = NULL;
	}
	printf("---------REGISTRADO!!----------");
}

/* ----------------------- REGISTRAR JUGUETES EN EL MAIN ----------------------- */

void RegistrarJuguetesMain( )
{
	int dato;
	char nombre[50];
    char descripcion[100];
    int edad_minima;
	int edad_maxima;
    int costo;
    char categoria[15];
    char eleccion_categ[10];
    
	printf("\n--------------REGISTRO DE JUGUETES---------------\n\n");
	printf("Ingrese el codigo del juguete: ");
	scanf("%d", &dato);
	
	printf("Ingrese el nombre del juguete: ");
	fflush (stdin);
	gets (nombre);
	
	printf("Ingrese la descripcion del juguete: ");
	fflush (stdin);
	gets (descripcion);
	
	printf("\n\n--------------CATEGORIAS DISPONIBLES---------------\n\n");
	printf("\n 1. Peluches");
	printf("\n 2. Muñecas");
	printf("\n 3. Vehiculos");
	printf("\n 4. Juguestes de contruccion");
	printf("\n 5. Juguetes educativos");
	printf("\n 6. Juguetes para bebes");
 	
	printf("\nIngrese el numero al que pertenece la categoria del juguete: ");
	fflush (stdin);
	gets (eleccion_categ);
	
	if (strcmp(eleccion_categ,"1")==0)
	{
		strcpy(categoria,"Peluches");
	}
	else if (strcmp(eleccion_categ,"2")==0)
	{
		strcpy(categoria,"Munecas");
	}
	else if (strcmp(eleccion_categ,"3")==0)
	{
		strcpy(categoria,"Vehiculos");
	}
	else if (strcmp(eleccion_categ,"4")==0)
	{
		strcpy(categoria,"Juguetes de construccion");
	}
	else if (strcmp(eleccion_categ,"5")==0)
	{
		strcpy(categoria,"Juguetes educativos");
	}
	else if (strcmp(eleccion_categ,"6")==0)
	{
		strcpy(categoria,"Juguetes para bebes");
	}
	else
	{
		printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
		return;
	}			
	
	printf("Ingrese el rango de edad para la que recomienda el juguete: ");
	printf("\nEdad minima:");
	scanf("%d",&edad_minima);
	printf("Edad máxima: ");
	scanf("%d",&edad_maxima);
	printf("Ingrese el costo total de fabricacion del juguete: ");
	scanf("%d", &costo);

	InsertarArbol( &ArbolInt, dato, nombre, descripcion, categoria, edad_minima, edad_maxima, costo,0);
	
	return;	
}

//BUSCAR JUGUETE
void Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
	while(!Vacio(actual)) 
	{
    	if(dat == actual->dato)
		{
			printf("\n-------------- INFORMACIÓN DEL JUGUETE --------------");
			printf("\nID: %d", actual -> dato);
			printf("\nNombre: %s", actual -> nombre);
			printf("\nCategoria: %s", actual -> categoria);
			printf("\nRango de edad: %d a %d", actual -> edad_minima, actual -> edad_maxima);
			//printf("\nCosto: %d", actual -> costo);	
			printf("\nDescripcion: %s", actual -> descripcion);	
			return;
		}
    	else if(dat < actual->dato) actual = actual->izquierdo; 
    	else if(dat > actual->dato) actual = actual->derecho;
   }
   printf("ERROR: No encontrado");
   return; 
}

//VALIDACION CODIGOS
void ValidarCodigoJuguetes(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
	while(!Vacio(actual)) 
	{
    	if(dat == actual->dato)
		{
			a -> contador = a -> contador + 1;
			return;
		}
    	else if(dat < actual->dato) actual = actual->izquierdo; 
    	else if(dat > actual->dato) actual = actual->derecho;
   }

}


//MOSTRAR ARBOL
void PreOrden(Arbol a)
{
	if(!Vacio(a)) 
	{
     
		printf("\nID: %d", a-> dato);
		printf("\nNombre: %s", a -> nombre);
		printf("\nCategoria: %s", a -> categoria);
		printf("\nRango de edad: %d a %d", a -> edad_minima, a -> edad_maxima);
		//printf("\nCosto: %d", a -> costo);	
		printf("\nDescripcion: %s", a -> descripcion);	
		printf("\n_______________________________\n\n");
	
		if(a->izquierdo) PreOrden(a->izquierdo);
		if(a->derecho) PreOrden(a->derecho);
	}
	
	else
	{
		printf("\n\n---------- Catalogo vacio!! ----------");
		return;	
	}	
}


//----------------------------------------------6.MODIFICAR JUGUETE----------------------------------------------------------------//
//ELIMINAR JUGUETE
void BorrarJuguete(Arbol *a, int dat)
{
	pNodo padre = NULL;
	pNodo actual;
	pNodo nodo;
	int aux;
	
	actual = *a;
  
	while(!Vacio(actual)) 
	{
		if(dat == actual->dato) 
		{ 
        	if(EsHoja(actual)) 
			{ 
            	if(padre) 
               /* Anulamos el puntero que le hace referencia */
            	if(padre->derecho == actual) padre->derecho = NULL;
            	else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            	free(actual); /* Borrar el nodo */
            	actual = NULL;
            	return;
        	}
         	
        	else 
			{ /* Si el valor está en el nodo actual, pero no es hoja */
            	padre = actual;
            
		        if(actual->derecho) 
				{
		        	nodo = actual->derecho;
		        	while(nodo->izquierdo) 
					{
		            	padre = nodo;
		            	nodo = nodo->izquierdo;
		        	}
		        }
		        
		        else 
				{
		        	nodo = actual->izquierdo;
		        	while(nodo->derecho) 
					{
		            	padre = nodo;
		            	nodo = nodo->derecho;
		        	}
		        }
		        
		        /* Intercambiar valores*/ 
		        aux = actual->dato;
		        actual->dato = nodo->dato;
		        nodo->dato = aux;
		        actual = nodo;
        	}
    	}
    	
    	else 
		{ 
        	padre = actual;
        	if(dat > actual->dato) actual = actual->derecho;
        	else if(dat < actual->dato) actual = actual->izquierdo;
    	}
   }  
}

//MODIFICAR DATOS JUGUETE
modificarJuguete(Arbol a )
{
	pNodo actual = a;
	char nombre [15];
	char descripcion [30];
	char categoria [15];
	char eleccion_categ [10];
	int edad_minima;
	int edad_maxima;
	int costo;
	int contador;
	
	
	int dat;
	int x = 0;
	char dato_mod [10];
	printf("\n---------MOFICAR JUGUETE--------");
	printf("\nID del juguete: ");
	scanf("%d", &dat);
	
	
	
	while(!Vacio(actual)) 
	{
    	if(dat == actual->dato)
		{
			Buscar(ArbolInt, dat);
			printf("\n__________________________________________\n\n\n\n");
			printf("\n---------DATOS A MODIFICAR--------------");
			printf("\n1.Nombre");
			printf("\n2.Descripcion");
			printf("\n3.Categoria ");
			printf("\n4.Rango de edad recomendado");
			printf("\n5.Costo de fabricacion");
			printf("-----------------------------------------------");    
			
			printf("\nIngrese el numero del dato que desea modificar: ");
			fflush (stdin);
			gets (dato_mod);
			
			if (strcmp(dato_mod,"1")==0)
			{
				printf("\nNuevo nombre:");
				fflush (stdin);
				gets (nombre);
				strcpy(actual->nombre,nombre);
				x=1;
				break;	
			}
			
			else if (strcmp(dato_mod,"2")==0)
			{
				printf("\nNueva descripcion:");
				fflush (stdin);
				gets (descripcion);
				strcpy(actual->descripcion,descripcion);
				x=1;
				break;
			}
			
			else if (strcmp(dato_mod,"3")==0)
			{
				printf("\n\n--------------CATEGORIAS DISPONIBLES---------------\n\n");
				printf("\n 1. Peluches");
				printf("\n 2. Muñecas");
				printf("\n 3. Vehiculos");
				printf("\n 4. Juguestes de contruccion");
				printf("\n 5. Juguetes educativos");
				printf("\n 6. Juguetes para bebes");
				
				printf("\nIngrese nueva categoria: ");
				fflush (stdin);
				gets (eleccion_categ);
				
				if (strcmp(eleccion_categ,"1")==0)
				{
					strcpy(actual->categoria,"Peluches");
				}
				else if (strcmp(eleccion_categ,"2")==0)
				{
					strcpy(actual->categoria,"Munecas");
				}
				else if (strcmp(eleccion_categ,"3")==0)
				{
					strcpy(actual->categoria,"Vehiculos");
				}
				else if (strcmp(eleccion_categ,"4")==0)
				{
					strcpy(actual->categoria,"Juguetes de construccion");
				}
				else if (strcmp(eleccion_categ,"5")==0)
				{
					strcpy(actual->categoria,"Juguetes educativos");
				}
				else if (strcmp(eleccion_categ,"6")==0)
				{
					strcpy(actual->categoria,"Juguetes para bebes");
				}
				else
				{
					printf("Error: fuera de rango.");
				}
				x=1;
				break;		
			}
			
			else if (strcmp(dato_mod,"4")==0)
			{
				printf("\nRango de edad:");
				printf("\nEdad minima:");
				scanf("%d", &edad_minima);
				printf("\nEdad maxima");
				scanf("%d", &edad_maxima);
				actual -> edad_minima = edad_minima;
				actual -> edad_maxima = edad_maxima;
				x=1;
				break;
			}
			
			else if (strcmp(dato_mod,"5")==0)
			{
				printf("\nNuevo costo de fabricación:");
				scanf("%d", &costo);
				actual -> costo = costo;
				x=1;
				break;
			}
			
			else
			{
				printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
				x=0;
			}	
		}
	   
    	else if(dat < actual->dato) actual = actual->izquierdo; 
    	else if(dat > actual->dato) actual = actual->derecho;
	}
   
	if(x==0)
	{
		printf("Error: juguete no registrado");
	} 
	
	else
	{
		printf("\n------------- MODIFICADO!! -------------\n\n");
		Buscar(ArbolInt, dat);	
	}
}
	
		
	
	




/* -------------------------------------------------------------- 7. REGISTRAR LUGAR DE DOMICILIO ------------------------------------------------------------ */

//GRAFO CON LISTA DE ADYACENCIA

Domicilio 
{
	char nombre [15];
	int codigo;
	int postal;
	
	Domicilio*siguiente;
	Ruta*adyacencia;
	
	//ANALISIS
	int contador;
	//Algoritmos DJISK
	int visitado,terminado;
	int monto;
	char anterior [15];		
};

Ruta
{
	char origen [15];
	char destino [15];
	float tiempo;
	int distancia;
	char tipo_ruta [15];
	Domicilio*vrt;
	Ruta*siguiente;
};

Lista
{
	Domicilio* dato;
	Lista*siguiente;
};

Domicilio*inicio = NULL;
Lista*ini=NULL;
Lista*final=NULL; 


//FUNCIÓN DE CREAR EL NODO DOMOCILIO

void insertarLugar ()
{
	char nombre [15];
	int codigo, postal;
	Domicilio*aux, *aux2, *aux3;
	Domicilio* nuevo = (Domicilio*)malloc(sizeof(Domicilio));
	aux2 = inicio;
	aux = inicio;
	aux3 = inicio;
	
	//DATOS DEL LUGAR PARA CATALOGO
	printf("Codigo Catalogo: ");
	scanf("%d",&codigo);
	
	while(aux2 != NULL)
	{
		if (aux2 -> codigo == codigo)
		{	
			printf("Error: codigo registrado");
			return;
		}
		aux2 = aux2 -> siguiente;
	}
	
	
	printf("Nombre del lugar: ");
	fflush (stdin);
	gets (nombre);
	while(aux3 != NULL)
	{
		if (strcmp(aux3-> nombre, nombre)==0)
		{	
			printf("Error: lugar registrado.");
			return;
		}
		aux3 = aux3 -> siguiente;
	}
		
	printf("Código postal: ");
	scanf("%d",&postal);
	
	while(aux != NULL)
	{
		if (aux -> postal == postal)
		{
			
			printf("Error: codigo anteriormente registrado");
			return;
		}
		aux = aux -> siguiente;
	}
	nuevo -> codigo = codigo;
	nuevo -> postal = postal;
	strcpy(nuevo-> nombre, nombre);
	nuevo -> siguiente = NULL;
	nuevo -> adyacencia = NULL;
	nuevo -> contador = 0;
	
	//ALGORITMO RECORRIDOS
	nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
	
	if (inicio==NULL)
	{
		inicio = nuevo;
	}
	
	else
	{
		aux = inicio;
		while (aux -> siguiente != NULL)
		{
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
	}
}

//INSERTAR POLO NORTE
void insertarLugarPolo (char nombre [15],int codigo,int postal)
{

	Domicilio*aux;
	Domicilio* nuevo = (Domicilio*)malloc(sizeof(Domicilio));
	aux = inicio;
	while(aux != NULL)
	{
		aux = aux -> siguiente;
	}
	nuevo -> codigo = codigo;
	nuevo -> postal = postal;
	strcpy(nuevo-> nombre, nombre);
	nuevo -> siguiente = NULL;
	nuevo -> adyacencia = NULL;
	nuevo -> contador = 0;
	
	//ALGORITMO RECORRIDOS
	nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
	
	if (inicio==NULL)
	{
		inicio = nuevo;
	}
	
	else
	{
		aux = inicio;
		while (aux -> siguiente != NULL)
		{
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
	}
}





//FUNCIÓN DE CREAR LAS CONEXION DE RUTAS CON DOMOCILIOS

void agregarRuta(Domicilio*aux, Domicilio*aux2, Ruta*nuevo,char ini [15],char fin [15],float distancia, float tiempo, char tipo_ruta [15])
{
	Ruta*a;

	
	if(aux-> adyacencia == NULL)
	{
	
		aux-> adyacencia = nuevo;
		nuevo -> vrt = aux2;
		nuevo -> tiempo = tiempo;
		nuevo -> distancia = distancia;
		strcpy(nuevo->tipo_ruta,tipo_ruta);
		strcpy(nuevo->origen,ini);
		strcpy(nuevo->destino,fin);
	}
	
	else
	{
		a = aux -> adyacencia;
		
		while(a -> siguiente != NULL)
		{
		
			if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
			{
				printf("Error: ruta ya registrada.");
				return;
			}
			
			a = a -> siguiente;
		}
		
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			printf("\n\nError: ruta ya registrada.\n");
			return;
		}
		
		nuevo -> vrt = aux2;
		nuevo -> tiempo = tiempo;
		nuevo -> distancia = distancia;
		strcpy(nuevo->tipo_ruta,tipo_ruta);
		strcpy(nuevo->origen,ini);
		strcpy(nuevo->destino,fin);
		a -> siguiente =  nuevo;		
	}
				
}


//FUNCION AUX DE RUTAS

void insertarRuta()
{
	char ini[15], fin[15], tipo_ruta [15];
	float tiempo; 
	int distancia;
	Ruta*nuevo = (Ruta*)malloc(sizeof(Ruta));
	nuevo -> siguiente = NULL;
	Domicilio *aux2, *aux, *aux3; 
	Ruta * a;
	
	if (inicio==NULL)
	{
		printf("\n\nERROR: el grafo esta vacio\n");
		return;
	}
	
	printf("Ingregar lugar de origen:");
	fflush (stdin);
	gets (ini);
	
	printf("Ingresar lugar de destino:");
	fflush (stdin);
	gets (fin);
	
	aux = inicio;
	aux2 = inicio;

	while(aux2 != NULL)
	{
		if ( strcmp(fin,aux2 ->nombre) == 0)
		{
			break;
		}
		aux2 = aux2 -> siguiente;
	}
				
	if (aux2 == NULL)
	{
		printf("\n\nERROR: Domicilio no encontrado\n");
		return;
	}
	
	while(aux != NULL)
	{
		if(strcmp(ini,aux ->nombre)== 0)
		{
			printf("Ingresar distancia [km]:");
			scanf("%d", &distancia);
			printf("Ingresar tiempo estimado [min]:");
			scanf("%f", &tiempo);
			printf("\n-------RUTAS--------");
			printf("\n1.Terrestre.");
			printf("\n2.Aerea.");
			printf("\n3.Maritima.");
			printf("\nIngresar tipo de ruta:");
			scanf("%s", tipo_ruta);
			if(strcmp(tipo_ruta,"1")==0)
			{
				strcpy(tipo_ruta, "Terrestre");
			}
			
			else if(strcmp(tipo_ruta,"2")==0)
			{
				strcpy(tipo_ruta, "Aerea");
			}
			
			else if(strcmp(tipo_ruta,"3")==0)
			{
				strcpy(tipo_ruta, "Maritima");
			}
			
			else
			{
				printf("\nERROR: opción incorrecta.");
				return;
			}
			
			agregarRuta(aux, aux2, nuevo,ini,fin,distancia,tiempo, tipo_ruta);
			printf("\n\n--------------- NUEVA RUTA INSERTADA! ---------------");
			return;
		}
		
		aux = aux -> siguiente;
	}
	
	if(aux == NULL)
	{
		printf("\n\nERROR: Domicilio no encontrado\n");
	}

}

void RutaModificar(char ini[15],char fin [15], float distancia, float tiempo, char tipo_ruta[15])
{
	int x=0;
	Ruta*nuevo = (Ruta*)malloc(sizeof(Ruta));
	Domicilio *aux2, *aux;
	
	if (inicio==NULL)
	{
		printf("\n\nERROR: el grafo esta vacio\n");
		return;
	}
	
	aux = inicio;
	aux2 = inicio;
	
	while(aux2 != NULL)
	{
		if ( strcmp(fin,aux2 ->nombre) == 0)
		{
			break;
		}
		aux2 = aux2 -> siguiente;
	}
				
	if (aux2 == NULL)
	{
		printf("\n\nERROR: Domicilio no encontrado\n");
		return;
	}
	
	while(aux != NULL)
	{
		if(strcmp(ini,aux ->nombre)== 0)
		{
			agregarRuta(aux, aux2, nuevo,ini,fin,distancia,tiempo, tipo_ruta);
			printf("\n\n---------- RUTA MODIFICADA ----------");
			printf("\nRuta %s -> %s", aux-> nombre, aux2 -> nombre);
			x =1;
			return;   
		}
		aux = aux -> siguiente;
	}
	
	if(x == 0)
	{
		printf("\n\nERROR: Domicilio no encontrado\n");
	}

}
/* -------------------------------------------------------------- 8. MODIFICAR LUGAR DE DOMICILIO ------------------------------------------------------------ */

//MODIFICAR DOMICILIO
void modificarDomicilio()
{
	char domicilio [15];
	char nombre [15];
	int i, codigo, postal;
	Domicilio* aux = inicio;

	if (inicio==NULL)
	{
		printf("\n\nERROR: el grafo esta vacio\n");
		return;
	}
	
	printf("Nombre del domicilio: ");
	fflush (stdin);
	gets (domicilio);
	
	while(aux != NULL)
	{
		if(strcmp(domicilio,aux ->nombre)== 0)
		{
			printf("\n1. Modificar nombre");
			printf("\n2. Modificar codigo catalago");
			printf("\n3. Modificar codigo postal");
			printf("\nOpcion: ");
			scanf("%d", &i);
			
			while (i>3 || i<1)
			{
				printf("\nERROR: opcion no valida. \nOpcion: ");
				scanf("%d", &i);	
			}
			
			if(i == 1)
			{
				Domicilio* aux2 = inicio;
				printf("\nNuevo nombre: ");
				fflush (stdin);
				gets (nombre);
				
				while(aux2 != NULL)
				{
					if (strcmp(aux2 -> nombre, nombre)==0)
					{
						printf("\nERROR: nombre anteriormente registrado");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				strcpy(aux->nombre,nombre);
				printf("\n MODIFICADO !! ");
				printf("\n___________________________________");
				printf("\n\nDOMICILIO: %s", aux -> nombre);
				printf("\nCODIGO #%d", aux -> codigo);
				printf("\nCODIGO POSTAL: %d", aux -> postal);
				return;			
			}
			
			if(i==2)
			{
				Domicilio* aux2 = inicio;
				printf("\nNuevo codigo: ");
				scanf("%d", &codigo);
				
				while(aux2 != NULL)
				{
					if (aux2 -> codigo == codigo)
					{
						printf("\nERROR: codigo anteriormente registrado");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				aux -> codigo = codigo;
				printf("\n MOFICADO!!!");
				printf("\n___________________________________");
				printf("\n\nDOMICILIO: %s", aux -> nombre);
				printf("\nCODIGO #%d", aux -> codigo);
				printf("\nCODIGO POSTAL: %d", aux -> postal);
				return;			
			}
			
			if(i==3)
			{
				Domicilio* aux2  = inicio;
				printf("\nNuevo codigo postal: ");
				scanf("%d", &postal);
				
				while(aux2 != NULL)
				{
					if (aux2 -> postal == postal)
					{
						printf("\nERROR: codigo anteriormente registrado");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				aux -> postal = postal;
				printf("\n MOFICADO !!!");
				printf("\n___________________________________");
				printf("\n\nDOMICILIO: %s", aux -> nombre);
				printf("\nCODIGO # %d", aux -> codigo);
				printf("\nCODIGO POSTAL: %d", aux -> postal);
				
				return;		
			}		
		}
		
		aux = aux -> siguiente;			
	}	
	
	if (aux == NULL)
	{
		printf("\n\nERROR: Domicilio no encontrado\n");
		return;
	}
}


//ELIMINAR ARISTA AUX
void eliminarAristaAux(char ini [15], char fin[15]){
	Domicilio * aux, *aux2, *aux3;
	Ruta * q, *r ,*a;
	aux = inicio;
	aux2 = inicio;
	aux3 = inicio;
	int y =0;
	a = aux3 -> adyacencia;
		
	while(a != NULL)
	{
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			y=1;		
		}
		
		a = a -> siguiente;
	}
		
	if(y ==1)
	{	
		while(aux2 != NULL)
		{
			if(strcmp(aux2 -> nombre,fin)==0)
			{
				break;
			}
			else
			{
				aux2 = aux -> siguiente;
			}	
		}
		
		while(aux != NULL)
		{
			if(strcmp(aux -> nombre,ini)==0)
			{
				q = aux -> adyacencia;
				
				while(q!=NULL)
				{
					if(q -> vrt ==aux2)
					{
						if(q== aux -> adyacencia)
						{
							aux -> adyacencia = aux -> adyacencia -> siguiente;
						}
						else
						{
							r -> siguiente = q -> siguiente;
						}
						
						free(q);
						printf("\nRuta %s -> %s eliminada!!", aux-> nombre, aux2 -> nombre);
						return;	
					}
				}
				
				r = q;
				q = q = q-> siguiente;		
			}
			
			aux = aux -> siguiente;
		}
	} 
	
	else
	{
		printf("\nERROR: ruta no registrada");
	}
}


//ELIMINAR NODO

void vaciar_aristas(Domicilio*aux)
{
	Ruta * q, *r;
	q = aux -> adyacencia;
	while(q -> siguiente != NULL)
	{
		r=q;
		q = q->siguiente;
		free(r);
	}
}

void contadorDomicilio (char dom [15],int cant)
{
	Domicilio* aux = inicio;
	while(aux != NULL){
		if (strcmp(dom, aux -> nombre)==0){
			aux -> contador = aux -> contador + cant;
	   }
		aux = aux -> siguiente;
   } 
}
		
		
	
void borrarDomicilio()
{
	char domicilio [15];
	Domicilio* aux = inicio;
	Domicilio * ant;
	
	if (inicio==NULL)
	{
		printf("\nERROR: no hay domicilios registrados.\n");
		return;
	}
	
	printf("Ingrese el nombre del domicilio que desea eliminar: ");
	fflush (stdin);
	gets (domicilio);
	
	while(aux != NULL)
	{
		if(strcmp(domicilio,aux->nombre)==0)
		{
			if(aux -> adyacencia != NULL)
			{
				vaciar_aristas(aux);
			}
			
			if(aux == inicio)
			{
				inicio = inicio -> siguiente;
				free(aux);
				printf("\nDomicilio eliminado");
				return;	
			}
			
			else
			{
				ant -> siguiente = aux -> siguiente;
				free(aux);
				printf("\nDomicilio eliminado");
				return;	
			}
		}
		
		else
		{
			ant = aux;
			aux = aux -> siguiente;
		}
	}
	
	if(aux == NULL)
	{
		printf("\nERROR: Domicilio no encontrado");
	}
}

	

//ELIMINAR ARISTA 
void eliminarArista()
{
	int x = 0;
	int y = 0;
	char ini [15];
	char fin [15];
	Domicilio * aux, *aux2, *aux3;
	Ruta * q, *r, *a;
	printf("\nIngrese el origen:");
	fflush (stdin);
	gets (ini);
	printf("\nIngrese el final:");
	fflush (stdin);
	gets (fin);
	
	aux = inicio;
	aux2 = inicio;
	aux3 = inicio;
	a = aux3 -> adyacencia;
		
	while(a != NULL)
	{
	
	
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			y=1;	
		}
		
		a = a -> siguiente;
	}
	
	if(y==1)
	{
		while(aux2 != NULL)
		{
			if(strcmp(aux2 -> nombre,fin)==0)
			{
				break;
			}
			else
			{
				aux2 = aux2 -> siguiente;
			}	
		}
		
		while(aux != NULL)
		{
			if(strcmp(aux -> nombre,ini) == 0 && aux2 != NULL)
			{
				q = aux -> adyacencia;
				while(q!=NULL)
				{
					if(q -> vrt ==aux2)
					{
						if(q== aux -> adyacencia)
						{
							aux -> adyacencia = aux -> adyacencia -> siguiente;
						}
						else
						{
							r -> siguiente = q -> siguiente;
						}
						
						free(q);
						x = 1;
						printf("\nRuta %s -> %s eliminada!!", aux-> nombre, aux2 -> nombre);
						return;	
					}
				}
				
				r = q;
				q = q = q-> siguiente;		
			}
			
			aux = aux -> siguiente;
		}
	}
		
	if(x==0)
	{
		printf("ERROR: Ruta no encontrada.");
	}
	
	else
	{
		printf("ERROR: Ruta no encontrada.");	
	}	
}


//MODIFICAR ARISTA

modificar_ruta_aux(char ini[15], char fin[15], int distancia, float tiempo, char tipo_ruta [15])
{
	int op;
	printf("\n----MODIFICAR RUTA-----\n\n");
	printf("\n1. Modificar punto de origen");
	printf("\n2. Modificar punto de llegada");
	printf("\n3. Modificar tiempo de la ruta");
	printf("\n4. Modificar distancia de la ruta");
	printf("\n5. Modificar tipo de ruta");
	printf("\nopcion: ");
	scanf("%d",&op);
	
	switch(op)
	{
		case 1:
			printf("Escriba el nuevo punto de origen: ");
			fflush (stdin);
			gets (ini);
			break;
		case 2:
			printf("Escriba el nuevo punto de llegada: ");
			fflush (stdin);
			gets (fin);
			break;
		case 3:
			printf("Escriba el nuevo tiempo de la ruta:");
			scanf("%f",&tiempo);
			break;
		case 4:
			printf("Escriba la nueva distancia:");
			scanf("%d",&distancia);
			break;
		case 5:
			printf("Escriba el nuevo tipo de ruta:");
			fflush (stdin);
			gets (tipo_ruta);
			break;		
	}
	
	RutaModificar(ini,fin,distancia, tiempo,tipo_ruta);	
}


modificarArista()
{
	char ini [15];
	char fin [15];

	float tiempo;
	int distancia;
	char tipo_ruta [15];
	Domicilio * aux, *aux2;
	Ruta * q, *r;
	int x=0;

	printf("\n--------------- DATOS ---------------");
	printf("\n\nIngrese el origen: ");
	fflush (stdin);
	gets (ini);
	printf("\nIngrese el final: ");
	fflush (stdin);
	gets (fin);

	aux = inicio;
	aux2 = inicio;

	while(aux2 != NULL)
	{
		if(strcmp(aux2 -> nombre,fin)==0)
		{
			break;
		}
		
		else
		{
			aux2 = aux2 -> siguiente;
		}	
	}

	while(aux != NULL)
	{
	
		if(strcmp(aux -> nombre,ini )==0 && aux2 !=NULL)
		{
			q = aux -> adyacencia;
			while(q!=NULL)
			{
				if(q -> vrt ==aux2)
				{
					if(q== aux -> adyacencia)
					{
						aux -> adyacencia = aux -> adyacencia -> siguiente;
					}
					
					else
					{
						r -> siguiente = q -> siguiente;
					}
					
					x=1;
					tiempo = q -> tiempo;
					distancia = q -> distancia;
					strcpy(q-> tipo_ruta,tipo_ruta);
					free(q);
					
					modificar_ruta_aux(ini, fin, distancia, tiempo, tipo_ruta);		
				}
			}
			
			r = q;
			q = q = q-> siguiente;		
		}
		
		aux = aux -> siguiente;
	}
	
	if(x==0)
	{
		printf("ERROR: ruta no encontrada");
	}
}



void visualizarGrafo()
{
    Domicilio*aux=inicio;
    Ruta* ar;
    printf("\nGRAFO DE RUTAS\n");
    while(aux!=NULL)
	{   
	    printf("%s:    ",aux->nombre);
        if(aux->adyacencia!=NULL)
		{
            ar=aux->adyacencia;
            while(ar!=NULL)
			{ 
			    printf(" -> %s",ar->vrt->nombre);
                ar=ar->siguiente;
            }
        }
        
        printf("\n");
        aux=aux->siguiente;
    }
    
    printf("\n");
}


//----------------------------------------------------ALGORITMO DIJKSTRA--------------------------------------------------------------//

//PILA PARA RECORRIDO

void insertarPila(Domicilio* aux)
{
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL)
	{
		ini=nuevo;
		final=nuevo;
	}
	
	else
	{
	   nuevo->siguiente=ini;
	   ini=nuevo;    	
	}
}


void insertarCola(Domicilio*aux)
{
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL)
	{
		ini=nuevo;
		final=nuevo;
	}
	
	else
	{
		final->siguiente=nuevo;
		final=nuevo;
	}
}


Domicilio * desencolar()
{
	Lista*aux;
	if(ini==NULL)
	{
		return NULL;
	}
	
	else
	{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		{
			final=NULL;
		}	
	}
	
	Domicilio*resultado=aux->dato;
	free(aux);
	return resultado;
}


void reiniciar()
{
	if(inicio!=NULL)
	{
		Domicilio*aux=inicio;
		while(aux!=NULL)
		{
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}


void dijkstra(char a [15], char b [15])
{
	Domicilio*aux=inicio;

	char temp [15];
	
	
	while(aux!=NULL)
	{
		if(strcmp(aux->nombre,a)==0)
		{
			aux->terminado=1;
			aux->monto=0;
	
			break;
		}
		
		aux=aux->siguiente;
	}
	
	if(aux==NULL)
	{
		printf("ERROR: ruta no encontrada.");
		return;
	}
	
	while(aux!=NULL)
	{
		Ruta*a=aux->adyacencia;
	    while(a!=NULL)
		{
		    if(a->vrt->monto==-1 || (aux->monto+a->distancia)<a->vrt->monto)
			{
		    	a->vrt->monto=aux->monto+a->distancia;
		        strcpy(a->vrt->anterior, aux->nombre);
			}
			
		    a=a->siguiente;
	    }
	    
	    aux=inicio;
	    Domicilio*min= inicio;
	    
	    while(min->anterior==0 || min->terminado ==1)
		{
	    	min=min->siguiente;
		}
		
	    while(aux!=NULL)
		{
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
			{
	    		min=aux;
	    	}
	    	
	    	aux=aux->siguiente;
		}
		
		aux=min;
		aux->terminado=1;
		
		if(strcmp(aux->nombre,b)==0)
		{
			break;
		}
	}
	
	while(strcmp(aux->anterior,"0")==1)
	{
		insertarPila(aux);
		strcpy(temp,aux->anterior);
		aux=inicio;
		while(strcmp(aux->nombre,temp)==1)
		{
		   aux=aux->siguiente;	
		}
	}
	
	insertarPila(aux);
	
	while(ini!=NULL)
	{
		printf("%s ",desencolar()->nombre);
	}
	
	printf("\n");
	reiniciar();
}



/* ------------------------------------------------------------------ 1. REGISTRAR NIÑO ------------------------------------------------------------------ */

/* --------------------------- STRUCT DEL NIÑO --------------------------- */

typedef struct Kid
{
	char nombre [50];
	char nombre_usuario [50];
	char correo [50];
	char lugar_residencia [50];	
	char cedula [50];
	char edad[50];
	char fecha_nacimiento [50];
	char necesidades_especiales [50];	
	int contador_comportamiento_bueno;
	int contador_comportamiento_malo;
	char estado_carta [15];
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

Kid * CrearKid( char estado_carta [15], char cedula[15], char nombre[200], char nombre_usuario[200],char correo [200], char lugar_residencia [50], char edad [50], char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
{
	struct Kid *nuevo;
	nuevo = (Kid *) malloc(sizeof(Kid));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->nombre,nombre);	
	strcpy(nuevo->nombre_usuario,nombre_usuario);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->estado_carta,"Sin asignar");
	strcpy(nuevo->lugar_residencia,lugar_residencia);
	strcpy(nuevo->edad,edad);
	strcpy(nuevo->fecha_nacimiento,fecha_nacimiento);
	strcpy(nuevo->necesidades_especiales,necesidades_especiales);
	nuevo->contador_comportamiento_bueno = contador_comportamiento_bueno;
	nuevo->contador_comportamiento_malo = contador_comportamiento_malo;
	return nuevo;
}

/* ----------------------- REGISTRAR NIÑO ----------------------- */

Imprimir * InsertarKid(Imprimir * ColaKids,char estado_carta [15], char cedula[15], char nombre[200], char nombre_usuario[200], char correo [200], char lugar_residencia [50], char edad [50], char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
{
	ColaKids->size = ColaKids-> size + 1;
	if(ColaKids->front == NULL) 
	{
		ColaKids->front = CrearKid( estado_carta, cedula,nombre, nombre_usuario, correo,lugar_residencia,edad,fecha_nacimiento,necesidades_especiales,contador_comportamiento_bueno, contador_comportamiento_malo);
		ColaKids->rear = ColaKids->front;
		return ColaKids;
	}
	ColaKids ->rear->next = CrearKid( estado_carta, cedula,nombre, nombre_usuario, correo,lugar_residencia,edad,fecha_nacimiento,necesidades_especiales,contador_comportamiento_bueno,contador_comportamiento_malo);
	ColaKids ->rear = ColaKids->rear->next;
}

/* ----------------------- CONSULTAR NIÑO----------------------- */

int ConsultarKids(Imprimir *ColaKids)
{
	Kid *i;
	char cedula_verificar[15];
	int contador; 
	
	if (ColaKids -> front == NULL)
	{
		printf ("\nERROR: No hay niños registrados.");
		return;
	}
	else
	{
		printf ("\nIngrese la cedula del niño que desea consultar: ")	;
		fflush (stdin);
		gets (cedula_verificar);
		
		for(i = ColaKids->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,cedula_verificar)==0)
			{
				contador = 1;
				
				printf("\n\nNombre: %s", i->nombre);
				printf("\nNombre de usuario: %s", i->nombre_usuario);
				printf("\nCorreo: %s", i->correo);
				printf("\nLugar de residencia: %s", i->lugar_residencia);
				printf("\nCedula: %s", i->cedula);
				printf("\nEdad: %s", i->edad);
				printf("\nFecha de nacimiento: %s", i->fecha_nacimiento);
				printf("\nNecesidades especiales: %s", i->necesidades_especiales);
				printf("\nComportamientos buenos: %d", i->contador_comportamiento_bueno);
				printf("\nComportamientos malos: %d", i->contador_comportamiento_malo);
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
	char cedula_kid[15];
	char edad_kid [10];
	char nacimiento_kid[100];
	char necesidades_especiales_kid[100];
	
	
	printf ("\nIngrese el nombre del niño que desea registrar: ");
	fflush (stdin);
	gets (nombre_kid);

	printf ("Ingrese la cedula del niño que desea registrar: ");
	fflush (stdin);
	gets (cedula_kid);
	
	Kid *i;
	
	for(i = ColaKids->front; i!= NULL; i = i->next)
	{
		if (strcmp(i->cedula,cedula_kid)==0)
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
	Domicilio * a;
	a =  inicio;
	int x = 0;
	if(inicio ==NULL){
		printf("\nError: No hay domicilios en el catalogo.");
		return;
	}		
	while (a != NULL)
	{
		if(strcmp(a ->nombre,residencia_kid)==0){
			x = 1;
			
		}
		a = a -> siguiente;
	}
	if( x == 0){
		printf("E\nrror: Domicilio no registrado.");
		return;
	}


	
	printf ("Ingrese la edad del niño que desea registrar: ");
	fflush (stdin);
	gets (edad_kid);
	
	printf ("Ingrese la fecha de nacimiento del niño que desea registrar [dd/mm/yy]: ");
	fflush (stdin);
	gets (nacimiento_kid);
	
	printf ("Ingrese las necesidades especiales del niño que desea registrar: ");
	fflush (stdin);
	gets (necesidades_especiales_kid);
	
	
	InsertarKid(ColaKids, "sin asignar", cedula_kid, nombre_kid, nombre_usuario_kid, correo_kid, residencia_kid, edad_kid, nacimiento_kid, necesidades_especiales_kid, 0, 0);		
}





/* ----------------------------------------------------------- 2. MODIFICAR INFORMACION DE UN NIÑO -------------------------------------------------------- */

int ModificarInfoKid (Imprimir *ColaKids)
{
	char residencia_kid [15];
	char cedula_verificar[15];
	int contador = 0;
	
	Kid *i = ColaKids->front;
	
	printf ("\n\nIngrese la cedula del niño que desea modificar: ")	;
	fflush (stdin);
	gets (cedula_verificar);
	
	Kid *aux = ColaKids->front;
	for(i = ColaKids->front; i!= NULL; i = i->next)
	{
		if (strcmp(i->cedula,cedula_verificar)==0)
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
				fflush (stdin);
				gets (i->nombre);
			}
			
			else if (dato == 2)
			{
				printf ("Ingrese el nuevo nombre de usuario del niño: ");
				fflush (stdin);
				gets (i->nombre_usuario);
			}
			
			else if (dato == 3)
			{
				printf ("Ingrese el nuevo correo del niño: ");
				fflush (stdin);
				gets (i->correo);	
			}
			
			else if (dato == 4)
			{
				printf ("Ingrese el nuevo lugar de residencia del niño: ");
				fflush (stdin);
				gets (residencia_kid);
					Domicilio * a;
					a =  inicio;
					int x = 0;
					if(inicio== NULL){
						printf("\n----No existen domicilos registrados!!! ----");
						return;
					}
					
					while (a != NULL)
					{
						if(strcmp(a ->nombre,residencia_kid)==0){
							strcpy(i->lugar_residencia,residencia_kid );
							x = 1;
						
						}
						a = a -> siguiente;
					}
					if( x == 0){
						printf("E\nrror: Domicilio no registrado.");
						return;
				}
			}
									
			
			else if (dato == 5)
			{
				printf ("Ingrese la nueva edad del niño: ");
				scanf("%s",i->edad);
			}
			
			else if (dato == 6)
			{
				printf ("Ingrese las nuevas necesidades especiales del niño: ");
				fflush (stdin);
				gets (i->necesidades_especiales);			
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
			printf("\nCedula: %s", i->cedula);
			printf("\nEdad: %s", i->edad);
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








/* ----------------------------------------------------------- 9. REGISTRAR COMPORTAMIENTO DE UN NIÑO -------------------------------------------------------- */

/* --------------------------- STRUCT DEL COMPORTAMIENTO --------------------------- */

typedef struct Comportamiento
{
	char nombre_padre [50];
	char cedula_kid [50];
	char fecha_registro [50];
	char descripcion_comportamiento [50];
	char comportamiento [50];	
	struct Comportamiento * next;	
}Comportamiento;

typedef struct ImprimirComportamiento
{
	Comportamiento *front;
	Comportamiento *rear;
	int size;
}ImprimirComportamiento;

/* ----------------------- CREAR NUEVA COLA COMPORTAMIENTO ----------------------- */

ImprimirComportamiento * CrearColaComportamientos(ImprimirComportamiento * ColaComportamientos)
{
	ColaComportamientos = NULL;
	ColaComportamientos = (ImprimirComportamiento *) malloc(sizeof(ImprimirComportamiento));	
	ColaComportamientos -> front = NULL;
	ColaComportamientos -> rear = NULL;
	return ColaComportamientos;
}

/* ----------------------- CREAR NODO COMPORTAMIENTO ----------------------- */

Comportamiento * CrearComportamiento(char cedula_kid[15], char nombre_padre[200], char comportamiento[50], char fecha_registro [50], char descripcion_comportamiento [200])
{
	struct Comportamiento *nuevo;
	nuevo = (Comportamiento *) malloc(sizeof(Comportamiento));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula_kid,cedula_kid);	
	strcpy(nuevo->nombre_padre,nombre_padre);
	strcpy(nuevo->comportamiento,comportamiento);
	strcpy(nuevo->fecha_registro,fecha_registro);
	strcpy(nuevo->descripcion_comportamiento,descripcion_comportamiento);
	return nuevo;
}

/* ----------------------- REGISTRAR COMPORTAMIENTO ----------------------- */

ImprimirComportamiento * InsertarComportamiento(ImprimirComportamiento * ColaComportamientos, char cedula_kid[15], char nombre_padre[200], char comportamiento[50], char fecha_registro [50], char descripcion_comportamiento [200])
{
	ColaComportamientos->size = ColaComportamientos-> size + 1;
	if(ColaComportamientos->front == NULL) 
	{
		ColaComportamientos->front = CrearComportamiento(cedula_kid,nombre_padre,comportamiento,fecha_registro,descripcion_comportamiento);
		ColaComportamientos->rear = ColaComportamientos->front;
		return ColaComportamientos;
	}
	ColaComportamientos ->rear->next = CrearComportamiento(cedula_kid,nombre_padre,comportamiento,fecha_registro,descripcion_comportamiento);
	ColaComportamientos ->rear = ColaComportamientos->rear->next;
}


/* ----------------------- CONSULTAR COMPORTAMIENTO ----------------------- */

int ConsultarComportamientos(ImprimirComportamiento *ColaComportamientos)
{
	Comportamiento *i; 
	
	if (ColaComportamientos -> front == NULL)
	{
		printf ("\nERROR: No hay comportamientos registrados.");
		return;
	}
	
	else
	{
		for(i = ColaComportamientos->front; i!= NULL; i = i->next)
		{		
				printf("\n\nCedula: %s", i->cedula_kid);
				printf("\nNombre del padre: %s", i->nombre_padre);
				printf("\nFecha del registro: %s", i->fecha_registro);
				printf("\nTipo de comportamiento: %s", i->comportamiento);
				printf("\nDescripcion del comportamiento: %s", i->descripcion_comportamiento);
				printf("\n____________________________________________________________________________\n");
		}			
	}
	
	return 0;
}

/* ----------------------- REGISTRAR COMPORTAMIENTO EN EL MAIN ----------------------- */

void RegistrarComportamientoMain(ImprimirComportamiento *ColaComportamientos, Imprimir *ColaKids)
{
	char nombre_padre [50];
	char cedula_kid [50];
	char fecha_registro [50];
	char descripcion_comportamiento [50];
	char num_comportamiento [50];
	char comportamiento [50];
	int contador=0;

	printf ("\nIngrese la cedula del niño que desea registrar: ");
	fflush (stdin);
	gets (cedula_kid);
	
	Kid *i;
	
	for(i = ColaKids->front; i!= NULL; i = i->next)
	{
		if (strcmp(i->cedula,cedula_kid)==0)
		{
			contador = 1;
			
			printf ("Ingrese el nombre del padre que registra el comportamiento: ");
			fflush (stdin);
			gets (nombre_padre);
			
			printf ("Ingrese la fecha del registro [dd/mm/yy]: ");
			fflush (stdin);
			gets (fecha_registro);
			
			printf ("Ingrese una breve descripcion del comportamiento: ");
			fflush (stdin);
			gets (descripcion_comportamiento);
			
			
			printf ("\n1. Comportamiento bueno.");	
			printf ("\n2. Comportamiento malo.");
			printf ("\n\nIngrese el numero del tipo de comportamiento que se registra: ");	
			fflush (stdin);
			gets (num_comportamiento);	
			
			if (strcmp(num_comportamiento,"1")==0)
			{
				strcpy(comportamiento,"Bueno");
				i->contador_comportamiento_bueno = i->contador_comportamiento_bueno + 1;
			}	
			else if (strcmp(num_comportamiento,"2")==0)
			{
				strcpy(comportamiento,"Malo");
				i->contador_comportamiento_malo = i->contador_comportamiento_malo + 1;
			}	
			else
			{
				printf ("\nERROR: el tipo de comportamiento solicitado no existe, la accion no se pudo completar.");
				return;
			}
			
			
			InsertarComportamiento(ColaComportamientos,cedula_kid,nombre_padre,comportamiento,fecha_registro,descripcion_comportamiento);
		}
	}	
	
	if (contador ==0)
	{
		printf("ERROR: la cedula no existe, la accion no se pudo completar.");
		return;
	}	
}





/* --------------------------------------------------------------- 10. REGISTRAR CARTA PARA SANTA ------------------------------------------------------------- */




/* ----------------------------------------------------- LISTA DE DESEOS --------------------------------------------------------------- */

/* --------------------------- STRUCT DE LA lISTA DE DESEOS--------------------------- */

typedef struct ListaDeseos  
{
	char cedula[15];
	char jugueteLD1[50];
	char jugueteLD2[50];
	char jugueteLD3[50];
	char jugueteLD4[50];
	char jugueteLD5[50];
	char jugueteLD6[50];
	char jugueteLD7[50];
	char jugueteLD8[50];
	char jugueteLD9[50];
	char jugueteLD10[50];
	char jugueteLD11[50];
	char jugueteLD12[50];
	char jugueteLD13[50];
	char jugueteLD14[50];
	char jugueteLD15[50];
	char jugueteLD16[50];
	char jugueteLD17[50];
	char jugueteLD18[50];
	char jugueteLD19[50];
	char jugueteLD20[50];
	int codLD1;
	int codLD2;
	int codLD3;
	int codLD4;
	int codLD5;
	int codLD6;
	int codLD7;
	int codLD8;
	int codLD9;
	int codLD10;
	int codLD11;
	int codLD12;
	int codLD13;
	int codLD14;
	int codLD15;
	int codLD16;
	int codLD17;
	int codLD18;
	int codLD19;
	int codLD20;

	struct ListaDeseos * next;	
}ListaDeseos;

typedef struct ImprimirLD
{
	ListaDeseos *front;
	ListaDeseos *rear;
	int size;
}ImprimirLD;

/* ----------------------- CREAR NUEVA COLA LISTA DE DESEOS ----------------------- */

ImprimirLD * CrearColaListaDeseos(ImprimirLD* ColaListaDeseos)
{
	ColaListaDeseos = NULL;
	ColaListaDeseos = (ImprimirLD *) malloc(sizeof(ImprimirLD));	
	ColaListaDeseos -> front = NULL;
	ColaListaDeseos -> rear = NULL;
	return ColaListaDeseos;
}

/* ----------------------- CREAR NODO LISTA DE DESEOS ----------------------- */

ListaDeseos * CrearListaDeseos(char cedula[15], char jugueteLD1[50],char jugueteLD2[50],char jugueteLD3[50],char jugueteLD4[50],char jugueteLD5[50],char jugueteLD6[50],char jugueteLD7[50],char jugueteLD8[50],char jugueteLD9[50],char jugueteLD10[50], char jugueteLD11[50],char jugueteLD12[50],char jugueteLD13[50],char jugueteLD14[50],char jugueteLD15[50],char jugueteLD16[50],char jugueteLD17[50],char jugueteLD18[50],char jugueteLD19[50],char jugueteLD20[50],int codLD1, int codLD2, int codLD3,int codLD4, int codLD5, int codLD6,int codLD7, int codLD8, int codLD9,int codLD10, int codLD11, int codLD12,int codLD13, int codLD14, int codLD15, int codLD16, int codLD17, int codLD18,int codLD19, int codLD20)
{
	struct ListaDeseos *nuevo;
	nuevo = (ListaDeseos *) malloc(sizeof(ListaDeseos));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->jugueteLD1,jugueteLD1);
	strcpy(nuevo->jugueteLD2,jugueteLD2);
	strcpy(nuevo->jugueteLD3,jugueteLD3);
	strcpy(nuevo->jugueteLD4,jugueteLD4);
	strcpy(nuevo->jugueteLD5,jugueteLD5);
	strcpy(nuevo->jugueteLD6,jugueteLD6);
	strcpy(nuevo->jugueteLD7,jugueteLD7);
	strcpy(nuevo->jugueteLD8,jugueteLD8);
	strcpy(nuevo->jugueteLD9,jugueteLD9);
	strcpy(nuevo->jugueteLD10,jugueteLD10);	
	strcpy(nuevo->jugueteLD11,jugueteLD11);
	strcpy(nuevo->jugueteLD12,jugueteLD12);
	strcpy(nuevo->jugueteLD13,jugueteLD13);
	strcpy(nuevo->jugueteLD14,jugueteLD14);
	strcpy(nuevo->jugueteLD15,jugueteLD15);
	strcpy(nuevo->jugueteLD16,jugueteLD16);
	strcpy(nuevo->jugueteLD17,jugueteLD17);
	strcpy(nuevo->jugueteLD18,jugueteLD18);
	strcpy(nuevo->jugueteLD19,jugueteLD19);
	strcpy(nuevo->jugueteLD20,jugueteLD20);	
	nuevo->codLD1=codLD1;
	nuevo->codLD2=codLD2;
	nuevo->codLD3=codLD3;
	nuevo->codLD4=codLD4;
	nuevo->codLD5=codLD5;
	nuevo->codLD6=codLD6;
	nuevo->codLD7=codLD7;
	nuevo->codLD8=codLD8;
	nuevo->codLD9=codLD9;
	nuevo->codLD10=codLD10;
	nuevo->codLD11=codLD11;
	nuevo->codLD12=codLD12;
	nuevo->codLD13=codLD13;
	nuevo->codLD14=codLD14;
	nuevo->codLD15=codLD15;
	nuevo->codLD16=codLD16;
	nuevo->codLD17=codLD17;
	nuevo->codLD18=codLD18;
	nuevo->codLD19=codLD19;
	nuevo->codLD20=codLD20;

	return nuevo;
}

/* ----------------------- REGISTRAR LISTA DE DESEOS ----------------------- */

ImprimirLD * InsertarListaDeseos(ImprimirLD* ColaListaDeseos,char cedula[15], char jugueteLD1[50],char jugueteLD2[50],char jugueteLD3[50],char jugueteLD4[50],char jugueteLD5[50],char jugueteLD6[50],char jugueteLD7[50],char jugueteLD8[50],char jugueteLD9[50],char jugueteLD10[50], char jugueteLD11[50],char jugueteLD12[50],char jugueteLD13[50],char jugueteLD14[50],char jugueteLD15[50],char jugueteLD16[50],char jugueteLD17[50],char jugueteLD18[50],char jugueteLD19[50],char jugueteLD20[50], int codLD1, int codLD2, int codLD3,int codLD4, int codLD5, int codLD6,int codLD7, int codLD8, int codLD9,int codLD10, int codLD11, int codLD12,int codLD13, int codLD14, int codLD15, int codLD16, int codLD17, int codLD18,int codLD19, int codLD20)
{
	ColaListaDeseos->size = ColaListaDeseos-> size + 1;
	if(ColaListaDeseos->front == NULL) 
	{
		ColaListaDeseos->front = CrearListaDeseos(cedula, jugueteLD1, jugueteLD2, jugueteLD3, jugueteLD4, jugueteLD5, jugueteLD6, jugueteLD7, jugueteLD8, jugueteLD9, jugueteLD10, jugueteLD11, jugueteLD12, jugueteLD13, jugueteLD14, jugueteLD15, jugueteLD16, jugueteLD17, jugueteLD18, jugueteLD19, jugueteLD20, codLD1, codLD2, codLD3, codLD4, codLD5, codLD6, codLD7, codLD8, codLD9, codLD10, codLD11, codLD12, codLD13, codLD14, codLD15, codLD16, codLD17, codLD18, codLD19, codLD20);
		ColaListaDeseos->rear = ColaListaDeseos->front;
		return ColaListaDeseos;
	}
	ColaListaDeseos ->rear->next = CrearListaDeseos(cedula, jugueteLD1, jugueteLD2, jugueteLD3, jugueteLD4, jugueteLD5, jugueteLD6, jugueteLD7, jugueteLD8, jugueteLD9, jugueteLD10, jugueteLD11, jugueteLD12, jugueteLD13, jugueteLD14, jugueteLD15, jugueteLD16, jugueteLD17, jugueteLD18, jugueteLD19, jugueteLD20, codLD1, codLD2, codLD3, codLD4, codLD5, codLD6, codLD7, codLD8, codLD9, codLD10, codLD11, codLD12, codLD13, codLD14, codLD15, codLD16, codLD17, codLD18, codLD19, codLD20);
	ColaListaDeseos ->rear = ColaListaDeseos->rear->next;
}







/* --------------------------------- CARTA ---------------------------------- */

/* --------------------------- STRUCT DE LA CARTA --------------------------- */

typedef struct Carta
{
	char year[10];
	char cedula [50];
	char juguete1[50];
	char juguete2[50];
	char juguete3[50];
	char juguete4[50];
	char juguete5[50];
	char juguete6[50];
	char juguete7[50];
	char juguete8[50];
	char juguete9[50];
	char juguete10[50];
	int cod1;
	int cod2;
	int cod3;
	int cod4;
	int cod5;
	int cod6;
	int cod7;
	int cod8;
	int cod9;
	int cod10;
	char estado_jug[30];
	
	int contador_2017;
	int contador_2018;
	int contador_2019;
	int contador_2020;
	int contador_2021;
	
	struct Carta * next;	
}Carta;

typedef struct ImprimirCarta
{
	Carta *front;
	Carta *rear;
	int size;
}ImprimirCarta;

/* ----------------------- CREAR NUEVA COLA CARTA ----------------------- */

ImprimirCarta * CrearColaCartas(ImprimirCarta * ColaCartas)
{
	ColaCartas = NULL;
	ColaCartas = (ImprimirCarta *) malloc(sizeof(ImprimirCarta));	
	ColaCartas -> front = NULL;
	ColaCartas -> rear = NULL;
	return ColaCartas;
}

/* ----------------------- CREAR NODO CARTA ----------------------- */

Carta * CrearCarta(char cedula[15], char year[10], char juguete1[50], int cod1, char juguete2[50], int cod2,char juguete3[50], int cod3,char juguete4[50], int cod4,char juguete5[50], int cod5,char juguete6[50], int cod6,char juguete7[50], int cod7,char juguete8[50], int cod8,char juguete9[50], int cod9,char juguete10[50], int cod10, char estado_jug[30], int contador_2017, int contador_2018, int contador_2019, int contador_2020, int contador_2021)
{
	struct Carta *nuevo;
	nuevo = (Carta *) malloc(sizeof(Carta));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->year,year);
	strcpy(nuevo->juguete1,juguete1);
	nuevo->cod1=cod1;
	strcpy(nuevo->juguete2,juguete2);
	nuevo->cod2=cod2;
	strcpy(nuevo->juguete3,juguete3);
	nuevo->cod3=cod3;
	strcpy(nuevo->juguete4,juguete4);
	nuevo->cod4=cod4;
	strcpy(nuevo->juguete5,juguete5);
	nuevo->cod5=cod5;
	strcpy(nuevo->juguete6,juguete6);
	nuevo->cod6=cod6;
	strcpy(nuevo->juguete7,juguete7);
	nuevo->cod7=cod7;
	strcpy(nuevo->juguete8,juguete8);
	nuevo->cod8=cod8;
	strcpy(nuevo->juguete9,juguete9);
	nuevo->cod9=cod9;
	strcpy(nuevo->juguete10,juguete10);	
	nuevo->cod10=cod10;	
	strcpy(nuevo->estado_jug,estado_jug);
	nuevo->contador_2017=contador_2017;	
	nuevo->contador_2018=contador_2018;	
	nuevo->contador_2019=contador_2019;	
	nuevo->contador_2020=contador_2020;	
	nuevo->contador_2021=contador_2021;		

	return nuevo;
}

/* ----------------------- REGISTRAR CARTA ----------------------- */

ImprimirCarta * InsertarCarta(ImprimirCarta * ColaCartas,char cedula[15], char year[10],  char juguete1[50], int cod1, char juguete2[50], int cod2,char juguete3[50], int cod3,char juguete4[50], int cod4,char juguete5[50], int cod5,char juguete6[50], int cod6,char juguete7[50], int cod7,char juguete8[50], int cod8,char juguete9[50], int cod9,char juguete10[50], int cod10, char estado_jug[30], int contador_2017, int contador_2018, int contador_2019, int contador_2020, int contador_2021)
{
	ColaCartas->size = ColaCartas-> size + 1;
	if(ColaCartas->front == NULL) 
	{
		ColaCartas->front = CrearCarta(cedula, year, juguete1, cod1, juguete2, cod2, juguete3, cod3, juguete4, cod4, juguete5, cod5, juguete6,cod6, juguete7,cod7,juguete8,cod8, juguete9, cod9, juguete10,cod10, estado_jug, contador_2017, contador_2018, contador_2019, contador_2020, contador_2021);
		ColaCartas->rear = ColaCartas->front;
		return ColaCartas;
	}
	ColaCartas ->rear->next = CrearCarta(cedula, year, juguete1, cod1, juguete2, cod2, juguete3, cod3, juguete4, cod4, juguete5, cod5, juguete6,cod6, juguete7,cod7,juguete8,cod8, juguete9, cod9, juguete10,cod10, estado_jug,contador_2017, contador_2018, contador_2019, contador_2020, contador_2021);
	ColaCartas ->rear = ColaCartas ->rear->next;
}



/* ----------------------- REGISTRAR CARTA EN EL MAIN ----------------------- */

void RegistrarCartaMain(ImprimirCarta *ColaCartas, ImprimirLD *ColaListaDeseos, Imprimir *ColaKids)
{
	
	Arbol a;
	
	char year[10];
	char cedula_kid [50];
	char juguete1[50]="0";
	char juguete2[50]="0";
	char juguete3[50]="0";
	char juguete4[50]="0";
	char juguete5[50]="0";
	char juguete6[50]="0";
	char juguete7[50]="0";
	char juguete8[50]="0";
	char juguete9[50]="0";
	char juguete10[50]="0";
	int cod1;
	int cod2;
	int cod3;
	int cod4;
	int cod5;
	int cod6;
	int cod7;
	int cod8;
	int cod9;
	int cod10;
	
	char estado_jug[30];
	int contador_2017=0;
	int contador_2018=0;
	int contador_2019=0;
	int contador_2020=0;
	int contador_2021=0;
	

	char jugueteLD1[50]="0";
	char jugueteLD2[50]="0";
	char jugueteLD3[50]="0";
	char jugueteLD4[50]="0";
	char jugueteLD5[50]="0";
	char jugueteLD6[50]="0";
	char jugueteLD7[50]="0";
	char jugueteLD8[50]="0";
	char jugueteLD9[50]="0";
	char jugueteLD10[50]="0";
	char jugueteLD11[50]="0";
	char jugueteLD12[50]="0";
	char jugueteLD13[50]="0";
	char jugueteLD14[50]="0";
	char jugueteLD15[50]="0";
	char jugueteLD16[50]="0";
	char jugueteLD17[50]="0";
	char jugueteLD18[50]="0";
	char jugueteLD19[50]="0";
	char jugueteLD20[50]="0";
	int codLD1;
	int codLD2;
	int codLD3;
	int codLD4;
	int codLD5;
	int codLD6;
	int codLD7;
	int codLD8;
	int codLD9;
	int codLD10;
	int codLD11;
	int codLD12;
	int codLD13;
	int codLD14;
	int codLD15;
	int codLD16;
	int codLD17;
	int codLD18;
	int codLD19;
	int codLD20;

	char opc_carta[10];
	int cantidad_jug;
	int contador=0;
	
	printf ("--------------------- BIENVENIDO AL REGISTRO DE CARTAS ---------------------\n\n");
	
	printf ("Ingrese la cedula del niño que desea registrar la carta: ");
	fflush (stdin);
	gets (cedula_kid);
	
	Kid *i;
	
	for(i = ColaKids->front; i != NULL; i = i->next)
	{
		if(strcmp(i->cedula,cedula_kid)==0)
		{
			contador = 1;
	
			printf ("Ingrese el año para el que corresponde la carta [yyyy]: ");
			fflush (stdin);
			gets (year);
			
			if ((strcmp(year,"2017")==1) && (strcmp(year,"2018")==1) && (strcmp(year,"2019")==1) && (strcmp(year,"2020")==1) && (strcmp(year,"2021")==1)) 
			{
         		printf("ERROR: solo se aceptan cartas de los años 2017, 2018, 2019, 2020, 2021. La carta no se pudo registrar");
         		return;
			}
			
			else
			{

				printf("\n----------- JUGUETES DISPONIBLES -----------\n\n");
				PreOrden(ArbolInt);
				
				printf ("\n  OPCIONES DISPONIBLES \n");
				printf ("1. Añadir juguete a la carta\n");
				printf ("2. Añadir juguete a la lista de deseos\n");
				
				printf("\nIngrese el numero de la opcion que desea realizar: ");
				fflush (stdin);
				gets (opc_carta);
				
		
				if (strcmp(opc_carta,"1")==0)
				{
					printf("Ingrese la catidad de juguetes que desea seleccionar: ");
					scanf("%d",&cantidad_jug);
					
					contadorDomicilio (i->lugar_residencia,cantidad_jug);
					
					
			
					
					
					
					
					
					if (cantidad_jug == 1)
					{
						printf ("Ingrese el nombre del juguete que desea seleccionar: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete que desea seleccionar: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
	
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 1;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 1;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 1;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 1;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 1;
						}
					}
					
					else if (cantidad_jug==2)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						//-------------------------------------- VALIDACION ARBOL --------------------------------------------------- 
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						
						//-------------------------------------- VALIDACION ARBOL --------------------------------------------------- 
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
	
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 2;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 2;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 2;
						}
					    if(strcmp(year,"2020")==0)
						{
							contador_2020 = 2;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 2;
						}
					}
					else if (cantidad_jug==3)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						
						//-------------------------------------- VALIDACION ARBOL --------------------------------------------------- 
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 3;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 3;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 3;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 3;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 3;
						}
					}
					
					else if (cantidad_jug==4)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						//-------------------------------------- VALIDACION ARBOL ---------------------------------------------------
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 4;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 4;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 4;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 4;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 4;
						}
					}						
	
					else if (cantidad_jug==5)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 5;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 5;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 5;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 5;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 5;
						}
					}
					
					else if (cantidad_jug==6)
					{
						printf ("\nIngrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("\nLos datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (juguete6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&cod6);
						ValidarCodigoJuguetes(ArbolInt, cod6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod6);	
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 6;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 6;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 6;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 6;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 6;
						}
					}
					
					else if (cantidad_jug==7)
					{
						printf ("\nIngrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (juguete6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&cod6);
						ValidarCodigoJuguetes(ArbolInt, cod6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod6);	
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (juguete7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&cod7);
						ValidarCodigoJuguetes(ArbolInt, cod7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod7);	
	
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 7;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 7;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 7;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 7;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 7;
						}
					}
					
					else if (cantidad_jug==8)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (juguete6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&cod6);
						ValidarCodigoJuguetes(ArbolInt, cod6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod6);	
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (juguete7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&cod7);
						ValidarCodigoJuguetes(ArbolInt, cod7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod7);	
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (juguete8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&cod8);
						ValidarCodigoJuguetes(ArbolInt, cod8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod8);	
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 8;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 8;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 8;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 8;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 8;
						}
					}
					
					else if (cantidad_jug==9)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (juguete6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&cod6);
						ValidarCodigoJuguetes(ArbolInt, cod6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod6);	
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (juguete7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&cod7);
						ValidarCodigoJuguetes(ArbolInt, cod7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod7);	
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (juguete8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&cod8);
						ValidarCodigoJuguetes(ArbolInt, cod8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod8);	
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (juguete9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&cod9);
						ValidarCodigoJuguetes(ArbolInt, cod9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod9);	
	
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 9;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 9;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 9;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 9;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 9;
						}
					}
						
					else if (cantidad_jug==10)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (juguete1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&cod1);
						ValidarCodigoJuguetes(ArbolInt, cod1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod1);	
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (juguete2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&cod2);
						ValidarCodigoJuguetes(ArbolInt, cod2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod2);	
						
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (juguete3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&cod3);
						ValidarCodigoJuguetes(ArbolInt, cod3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod3);	
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (juguete4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&cod4);
						ValidarCodigoJuguetes(ArbolInt, cod4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod4);	
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (juguete5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&cod5);
						ValidarCodigoJuguetes(ArbolInt, cod5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod5);	
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (juguete6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&cod6);
						ValidarCodigoJuguetes(ArbolInt, cod6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod6);	
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (juguete7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&cod7);
						ValidarCodigoJuguetes(ArbolInt, cod7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod7);	
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (juguete8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&cod8);
						ValidarCodigoJuguetes(ArbolInt, cod8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod8);	
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (juguete9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&cod9);
						ValidarCodigoJuguetes(ArbolInt, cod9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod9);	
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (juguete10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&cod10);
						ValidarCodigoJuguetes(ArbolInt, cod10);
						
						//-------------------------------------- ULTIMA VALIDACION ARBOL --------------------------------------------------- 
						
						
						
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, cod10);
						
						if(strcmp(year,"2017")==0)
						{
							contador_2017 = 10;
						}
						if(strcmp(year,"2018")==0)
						{
							contador_2018 = 10;
						}
						if(strcmp(year,"2019")==0)
						{
							contador_2019 = 10;
						}
						if(strcmp(year,"2020")==0)
						{
							contador_2020 = 10;
						}
						if(strcmp(year,"2021")==0)
						{
							contador_2021 = 10;
						}	
					}
					else
					{
						printf("ERROR: Solo se permite un maximo de 10 juguetes en la carta");
					}
					
					strcpy(estado_jug,"Solicitado");
					InsertarCarta(ColaCartas, cedula_kid, year, juguete1, cod1, juguete2, cod2, juguete3, cod3, juguete4, cod4, juguete5, cod5, juguete6, cod6, juguete7, cod7, juguete8, cod8, juguete9, cod9, juguete10, cod10, estado_jug, contador_2017, contador_2018,contador_2019,contador_2020, contador_2021);
					
					//Cambiar el estado del juguete
				}
				else if (strcmp(opc_carta,"2")==0)
				{
					printf("Ingrese la catidad de juguetes que desea seleccionar: "); 
					int cantidad_jug;
					
					if (cantidad_jug==1)
					{
						printf ("Ingrese el nombre del juguete que desea seleccionar: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete que desea seleccionar: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);	
					}
					else if (cantidad_jug==2)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
					}
					else if (cantidad_jug==3)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
					}
					else if (cantidad_jug==4)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
					}						
	
					else if (cantidad_jug==5)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
					}
					
					else if (cantidad_jug==6)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
					}
					else if (cantidad_jug==7)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
					}
					else if (cantidad_jug==8)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
					}
					else if (cantidad_jug==9)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
					}	
					else if (cantidad_jug==10)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
					}	
					else if (cantidad_jug==11)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
					}
					
					else if (cantidad_jug==12)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
					}
					else if (cantidad_jug==13)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
					}
					else if (cantidad_jug==14)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
					}			
					else if (cantidad_jug==15)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
					}	
					else if (cantidad_jug==16)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
	
						printf ("\nIngrese el nombre del juguete 16: ");
						fflush (stdin);
						gets (jugueteLD16);
						printf ("Ingrese el codigo del juguete 16: ");
						scanf("%d",&codLD16);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD16);
					}	
	
					else if (cantidad_jug==17)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
	
						printf ("\nIngrese el nombre del juguete 16: ");
						fflush (stdin);
						gets (jugueteLD16);
						printf ("Ingrese el codigo del juguete 16: ");
						scanf("%d",&codLD16);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD16);
						
						printf ("\nIngrese el nombre del juguete 17: ");
						fflush (stdin);
						gets (jugueteLD17);
						printf ("Ingrese el codigo del juguete 17: ");
						scanf("%d",&codLD17);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD17);
					}
	
					else if (cantidad_jug==18)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
	
						printf ("\nIngrese el nombre del juguete 16: ");
						fflush (stdin);
						gets (jugueteLD16);
						printf ("Ingrese el codigo del juguete 16: ");
						scanf("%d",&codLD16);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD16);
						
						printf ("\nIngrese el nombre del juguete 17: ");
						fflush (stdin);
						gets (jugueteLD17);
						printf ("Ingrese el codigo del juguete 17: ");
						scanf("%d",&codLD17);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD17);
						
						printf ("\nIngrese el nombre del juguete 18: ");
						fflush (stdin);
						gets (jugueteLD18);
						printf ("Ingrese el codigo del juguete 18: ");
						scanf("%d",&codLD18);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD18);
					}	
					
					else if (cantidad_jug==19)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
	
						printf ("\nIngrese el nombre del juguete 16: ");
						fflush (stdin);
						gets (jugueteLD16);
						printf ("Ingrese el codigo del juguete 16: ");
						scanf("%d",&codLD16);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD16);
						
						printf ("\nIngrese el nombre del juguete 17: ");
						fflush (stdin);
						gets (jugueteLD17);
						printf ("Ingrese el codigo del juguete 17: ");
						scanf("%d",&codLD17);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD17);
						
						printf ("\nIngrese el nombre del juguete 18: ");
						fflush (stdin);
						gets (jugueteLD18);
						printf ("Ingrese el codigo del juguete 18: ");
						scanf("%d",&codLD18);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD18);
						
						printf ("\nIngrese el nombre del juguete 19: ");
						fflush (stdin);
						gets (jugueteLD19);
						printf ("Ingrese el codigo del juguete 19: ");
						scanf("%d",&codLD19);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD19);
					}	
					
					else if (cantidad_jug==20)
					{
						printf ("Ingrese el nombre del juguete 1: ");
						fflush (stdin);
						gets (jugueteLD1);
						printf ("Ingrese el codigo del juguete 1: ");
						scanf("%d",&codLD1);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD1);
						
						printf ("\nIngrese el nombre del juguete 2: ");
						fflush (stdin);
						gets (jugueteLD2);
						printf ("Ingrese el codigo del juguete 2: ");
						scanf("%d",&codLD2);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD2);
						
						printf ("\nIngrese el nombre del juguete 3: ");
						fflush (stdin);
						gets (jugueteLD3);
						printf ("Ingrese el codigo del juguete 3: ");
						scanf("%d",&codLD3);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD3);
	
						printf ("\nIngrese el nombre del juguete 4: ");
						fflush (stdin);
						gets (jugueteLD4);
						printf ("Ingrese el codigo del juguete 4: ");
						scanf("%d",&codLD4);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD4);
						
						printf ("\nIngrese el nombre del juguete 5: ");
						fflush (stdin);
						gets (jugueteLD5);
						printf ("Ingrese el codigo del juguete 5: ");
						scanf("%d",&codLD5);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD5);
						
						printf ("\nIngrese el nombre del juguete 6: ");
						fflush (stdin);
						gets (jugueteLD6);
						printf ("Ingrese el codigo del juguete 6: ");
						scanf("%d",&codLD6);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD6);
	
						printf ("\nIngrese el nombre del juguete 7: ");
						fflush (stdin);
						gets (jugueteLD7);
						printf ("Ingrese el codigo del juguete 7: ");
						scanf("%d",&codLD7);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD7);
						
						printf ("\nIngrese el nombre del juguete 8: ");
						fflush (stdin);
						gets (jugueteLD8);
						printf ("Ingrese el codigo del juguete 8: ");
						scanf("%d",&codLD8);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD8);
						
						printf ("\nIngrese el nombre del juguete 9: ");
						fflush (stdin);
						gets (jugueteLD9);
						printf ("Ingrese el codigo del juguete 9: ");
						scanf("%d",&codLD9);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD9);
						
						printf ("\nIngrese el nombre del juguete 10: ");
						fflush (stdin);
						gets (jugueteLD10);
						printf ("Ingrese el codigo del juguete 10: ");
						scanf("%d",&codLD10);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD10);
	
						printf ("\nIngrese el nombre del juguete 11: ");
						fflush (stdin);
						gets (jugueteLD11);
						printf ("Ingrese el codigo del juguete 11: ");
						scanf("%d",&codLD11);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD11);
						
						printf ("\nIngrese el nombre del juguete 12: ");
						fflush (stdin);
						gets (jugueteLD12);
						printf ("Ingrese el codigo del juguete 12: ");
						scanf("%d",&codLD12);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD12);
						
						printf ("\nIngrese el nombre del juguete 13: ");
						fflush (stdin);
						gets (jugueteLD13);
						printf ("Ingrese el codigo del juguete 13: ");
						scanf("%d",&codLD13);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD13);
						
						printf ("\nIngrese el nombre del juguete 14: ");
						fflush (stdin);
						gets (jugueteLD14);
						printf ("Ingrese el codigo del juguete 14: ");
						scanf("%d",&codLD14);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD14);
						
						printf ("\nIngrese el nombre del juguete 15: ");
						fflush (stdin);
						gets (jugueteLD15);
						printf ("Ingrese el codigo del juguete 15: ");
						scanf("%d",&codLD15);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD15);
	
						printf ("\nIngrese el nombre del juguete 16: ");
						fflush (stdin);
						gets (jugueteLD16);
						printf ("Ingrese el codigo del juguete 16: ");
						scanf("%d",&codLD16);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD16);
						
						printf ("\nIngrese el nombre del juguete 17: ");
						fflush (stdin);
						gets (jugueteLD17);
						printf ("Ingrese el codigo del juguete 17: ");
						scanf("%d",&codLD17);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD17);
						
						printf ("\nIngrese el nombre del juguete 18: ");
						fflush (stdin);
						gets (jugueteLD18);
						printf ("Ingrese el codigo del juguete 18: ");
						scanf("%d",&codLD18);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD18);
						
						printf ("\nIngrese el nombre del juguete 19: ");
						fflush (stdin);
						gets (jugueteLD19);
						printf ("Ingrese el codigo del juguete 19: ");
						scanf("%d",&codLD19);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD19);
						
						printf ("\nIngrese el nombre del juguete 20: ");
						fflush (stdin);
						gets (jugueteLD20);
						printf ("Ingrese el codigo del juguete 20: ");
						scanf("%d",&codLD20);
						printf ("Los datos del juguete son:\n ");
						Buscar(ArbolInt, codLD20);
					}	
										
					InsertarListaDeseos(ColaListaDeseos,cedula_kid, jugueteLD1,jugueteLD2, jugueteLD3, jugueteLD4, jugueteLD5, jugueteLD6, jugueteLD7,jugueteLD8, jugueteLD9, jugueteLD10, jugueteLD11, jugueteLD12, jugueteLD13, jugueteLD14, jugueteLD15, jugueteLD16, jugueteLD17, jugueteLD18, jugueteLD19, jugueteLD20, codLD1, codLD2, codLD3, codLD4, codLD5, codLD6, codLD7, codLD8, codLD9, codLD10, codLD11, codLD12, codLD13, codLD14, codLD15, codLD16, codLD17, codLD18, codLD19, codLD20);
					ConsultarListaDeseos(ColaListaDeseos,cedula_kid);
				}
			}
		}
	}
	if (contador == 0)
	{
		printf("ERROR: la cedula no existe, la accion no se pudo completar.");
		return;
	}

}


/* --------------------------------------------------------------- 11. MODIFICAR CARTA PARA SANTA ------------------------------------------------------------- */


void modificar_carta(ImprimirCarta *ColaCartas, ImprimirLD *ColaListaDeseos, Imprimir *ColaKids)
{
	Carta *i;
	ListaDeseos *j;
	
	char verificar_cedula[15];
	char verificar_year[15];
	int contador; 
	char op_modif[10];
	char num_jug[10];
	char num_jugLD[10];
	if (ColaCartas -> front == NULL)
	{
		printf ("\nERROR: No hay cartas registradas.");
		return;
	}
	
	else
	{
		printf("\n------------------------ MODIFICAR CARTAS ------------------------\n");
		printf ("\nIngrese la cedula del niño al que pertenece la carta: ")	;
		fflush (stdin);
		gets (verificar_cedula);
		printf ("Ingrese el año para el que se solicito la carta: ")	;
		fflush (stdin);
		gets (verificar_year);
			
		for(i = ColaCartas->front; i!= NULL; i = i->next)
		{
			for(j = ColaListaDeseos->front; j!= NULL; j = j->next)
			
			if (strcmp(i->cedula,verificar_cedula)==0 && strcmp(i->year,verificar_year)==0)
			{
				contador = 1;
				
				
				printf("\nOpciones disponibles:");
				printf("\n1. Agregar juguete.");
				printf("\n2. Eliminar juguete.");
				printf("\n3. Pasa juguete de la lista de deseos a la carta.");
				
				printf("\nIngrese el numero de la opcion que desea realizar: ");
				fflush (stdin);
				gets (op_modif);
				
				if (strcmp(op_modif,"1")==0)
				{
					if (strcmp(i->juguete1,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete1);	
					}
					else if(strcmp(i->juguete2,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete2);
					}
					else if (strcmp(i->juguete3,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete3);
					}
					else if (strcmp(i->juguete4,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete4);
					}
					else if (strcmp(i->juguete5,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete5);
					}	
					else if (strcmp(i->juguete6,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete6);
					}
					else if (strcmp(i->juguete7,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete7);
					}
					else if (strcmp(i->juguete8,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete8);
					}
					else if (strcmp(i->juguete9,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete9);
					}	
					else if (strcmp(i->juguete10,"0")==0)
					{
						printf ("Ingrese el nombre del juguete: ");
						fflush (stdin);
						gets (i->juguete10);
					}
					else
					{
						printf("ERROR: no hay espacios disponibles par agregar juguetes a la carta");
					}
				}
				else if (strcmp(op_modif,"2")==0)
				{
					ConsultarCartas(ColaCartas, verificar_cedula, verificar_year);
					
					printf("Ingrese el numero de juguete que desea eliminar de la carta: ");
					fflush (stdin);
					gets (num_jug);
					
					if (strcmp(num_jug,"1")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete1,"0");
						}
					}					
					else if (strcmp(num_jug,"2")==0)
					{
						if (strcmp(i->juguete2,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete2,"0");
						}
					}
					else if (strcmp(num_jug,"3")==0)
					{
						if (strcmp(i->juguete3,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete3,"0");
						}
					}
					else if (strcmp(num_jug,"4")==0)
					{
						if (strcmp(i->juguete4,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete4,"0");
						}
					}
					else if (strcmp(num_jug,"5")==0)
					{
						if (strcmp(i->juguete5,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete5,"0");
						}
					}
					else if (strcmp(num_jug,"6")==0)
					{
						if (strcmp(i->juguete6,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete6,"0");
						}
					}					
					else if (strcmp(num_jug,"7")==0)
					{
						if (strcmp(i->juguete7,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete7,"0");
						}
					}
					else if (strcmp(num_jug,"8")==0)
					{
						if (strcmp(i->juguete8,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete8,"0");
						}
					}
					else if (strcmp(num_jug,"9")==0)
					{
						if (strcmp(i->juguete9,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete9,"0");
						}
					}
					else if (strcmp(num_jug,"10")==0)
					{
						if (strcmp(i->juguete10,"0")==0 )
						{
							printf("Error: no hay juguetes registrados");
							return;
						}
						else
						{
							strcpy(i->juguete10,"0");
						}
					}
				}
				else if (strcmp(op_modif,"3")==0)
				{
					ConsultarListaDeseos(ColaListaDeseos,verificar_cedula, verificar_year);
					
					printf("\nIngrese el numero de juguete que desea pasar a la carta: ");
					fflush (stdin);
					gets (num_jugLD);
					
					if (strcmp(num_jugLD,"1")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD1);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD1);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD1);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD1);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD1);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD1);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD1);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD1);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD1);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD1);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD1,"0");
					}
					else if (strcmp(num_jugLD,"2")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD2);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD2);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD2);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD2);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD2);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD2);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD2);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD2);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD2);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD2);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD2,"0");
					}
					else if (strcmp(num_jugLD,"3")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD3);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD3);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD3);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD3);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD3);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD3);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD3);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD3);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD3);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD3);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD3,"0");
					}
					else if (strcmp(num_jugLD,"4")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD4);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD4);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD4);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD4);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD4);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD4);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD4);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD4);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD4);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD4);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD4,"0");
					}						
					else if (strcmp(num_jugLD,"5")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD5);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD5);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD5);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD5);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD5);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD5);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD5);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD5);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD5);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD5);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD5,"0");			
					}
					else if (strcmp(num_jugLD,"6")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD6);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD6);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD6);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD6);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD6);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD6);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD6);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD6);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD6);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD6);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD6,"0");			
					}					
					else if (strcmp(num_jugLD,"7")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD7);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD7);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD7);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD7);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD7);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD7);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD7);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD7);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD7);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD7);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD7,"0");			
					}		
					else if (strcmp(num_jugLD,"8")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD8);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD8);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD8);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD8);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD8);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD8);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD8);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD8);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD8);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD8);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD8,"0");			
					}
					else if (strcmp(num_jugLD,"9")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD9);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD9);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD9);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD9);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD9);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD9);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD9);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD9);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD9);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD9);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD9,"0");			
					}	
					else if (strcmp(num_jugLD,"10")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD10);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD10);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD10);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD10);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD10);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD10);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD10);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD10);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD10);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD10);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD10,"0");			
					}

					else if (strcmp(num_jugLD,"11")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD11);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD11);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD11);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD11);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD11);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD11);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD11);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD11);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD11);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD11);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD11,"0");
					}
					else if (strcmp(num_jugLD,"12")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD12);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD12);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD12);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD12);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD12);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD12);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD12);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD12);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD12);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD12);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD12,"0");
					}
					else if (strcmp(num_jugLD,"13")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD13);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD13);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD13);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD13);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD13);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD13);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD13);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD13);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD13);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD13);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD13,"0");
					}
					else if (strcmp(num_jugLD,"14")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD14);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD14);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD14);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD14);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD14);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD14);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD14);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD14);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD14);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD14);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD14,"0");
					}						
					else if (strcmp(num_jugLD,"15")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD15);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD15);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD15);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD15);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD15);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD15);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD15);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD15);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD15);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD15);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD15,"0");			
					}
					else if (strcmp(num_jugLD,"16")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD16);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD16);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD16);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD16);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD16);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD16);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD16);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD16);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD16);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD16);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD16,"0");			
					}					
					else if (strcmp(num_jugLD,"17")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD17);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD17);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD17);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD17);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD17);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD17);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD17);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD17);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD17);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD17);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD7,"0");			
					}		
					else if (strcmp(num_jugLD,"18")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD18);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD18);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD18);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD18);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD18);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD18);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD18);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD18);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD18);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD18);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD18,"0");			
					}
					else if (strcmp(num_jugLD,"19")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD19);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD19);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD19);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD19);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD19);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD19);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD19);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD19);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD19);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD19);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD19,"0");			
					}	
					else if (strcmp(num_jugLD,"20")==0)
					{
						if (strcmp(i->juguete1,"0")==0 )
						{
							strcpy(i->juguete1,j->jugueteLD20);
						}
						else if (strcmp(i->juguete2,"0")==0 )
						{
							strcpy(i->juguete2,j->jugueteLD20);
						}
						else if (strcmp(i->juguete3,"0")==0 )
						{
							strcpy(i->juguete3,j->jugueteLD20);
						}
						else if (strcmp(i->juguete4,"0")==0 )
						{
							strcpy(i->juguete4,j->jugueteLD20);
						}
						else if (strcmp(i->juguete5,"0")==0 )
						{
							strcpy(i->juguete5,j->jugueteLD20);
						}
						else if (strcmp(i->juguete6,"0")==0 )
						{
							strcpy(i->juguete6,j->jugueteLD20);
						}
						else if (strcmp(i->juguete7,"0")==0 )
						{
							strcpy(i->juguete7,j->jugueteLD20);
						}
						else if (strcmp(i->juguete8,"0")==0 )
						{
							strcpy(i->juguete8,j->jugueteLD20);
						}
						else if (strcmp(i->juguete9,"0")==0 )
						{
							strcpy(i->juguete9,j->jugueteLD20);
						}
						else if (strcmp(i->juguete10,"0")==0 )
						{
							strcpy(i->juguete10,j->jugueteLD20);
						}
						else
						{
							printf("ERROR: No hay espacios disponibles en la carta.");
							return;
						}
						strcpy(j->jugueteLD20,"0");			
					}							
				}
				else
				{
					printf("ERROR: la opcion no esta disponible");
					return;
				}	
			}
		}			
					
		if (contador == 0)
		{
			printf ("\nERROR: la cedula o año ingresado no contiene cartas, la accion no se puede realizar.");
			return;
		}
	}

	return;
}






/* --------------------------------------------------------------- 12. CONSULTAR CARTA PARA SANTA ------------------------------------------------------------- */

int ConsultarCartas(ImprimirCarta *ColaCartas, char verificar_cedula[15], char verificar_year[15])
{

	Carta *i;
	int contador; 
	
	if (ColaCartas -> front == NULL)
	{
		printf ("\nERROR: No hay cartas registradas.");
		return;
	}
	
	else
	{
		printf("Los juguetes de la carta son:\n");
		for(i = ColaCartas->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,verificar_cedula)==0 && strcmp(i->year,verificar_year)==0)
			{
				contador = 1;
				
				if (strcmp(i->juguete1,"0")==0)
				{
					printf("ERROR: no hay juguetes en la carta");	
				}	
				
				else if(strcmp(i->juguete2,"0")==0)
				{
					printf("1. %s\n",i->juguete1);	
				}	
				else if (strcmp(i->juguete3,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);	
				}
				else if (strcmp(i->juguete4,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
				}
				else if (strcmp(i->juguete5,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
				}	
				else if (strcmp(i->juguete6,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
				}
				else if (strcmp(i->juguete7,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
					printf("6. %s\n",i->juguete6);
				}
				else if (strcmp(i->juguete8,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
					printf("6. %s\n",i->juguete6);
					printf("7. %s\n",i->juguete7);
				}
				else if (strcmp(i->juguete9,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
					printf("6. %s\n",i->juguete6);
					printf("7. %s\n",i->juguete7);
					printf("8. %s\n",i->juguete8);
				}	
				else if (strcmp(i->juguete10,"0")==0)
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
					printf("6. %s\n",i->juguete6);
					printf("7. %s\n",i->juguete7);
					printf("8. %s\n",i->juguete8);
					printf("9. %s\n",i->juguete9);
				}
				else 
				{
					printf("1. %s\n",i->juguete1);
					printf("2. %s\n",i->juguete2);
					printf("3. %s\n",i->juguete3);
					printf("4. %s\n",i->juguete4);
					printf("5. %s\n",i->juguete5);
					printf("6. %s\n",i->juguete6);
					printf("7. %s\n",i->juguete7);
					printf("8. %s\n",i->juguete8);
					printf("9. %s\n",i->juguete9);
					printf("10. %s\n",i->juguete10);
				}				
			}
		}			
					
		if (contador == 0)
		{
			printf ("\nERROR: la cedula o año ingresado no contiene cartas, la accion no se puede realizar.");
			return;
		}
	}

	return 0;
}


/* ----------------------- CONSULTAR LISTA DE DESEOS----------------------- */

int ConsultarListaDeseos(ImprimirLD *ColaListaDeseos,char verificar_cedula[15])
{
	ListaDeseos *i;
	int contador; 
	
	if (ColaListaDeseos -> front == NULL)
	{
		printf ("\nERROR: No hay listas de deseos registradas.");
		return;
	}
	else
	{
		printf("\nLista de juguetes almacenados en la lista de deseos: \n");
		for(i = ColaListaDeseos->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,verificar_cedula)==0)
			{
				contador = 1;
				
				if (strcmp(i->jugueteLD1,"0")==0)
				{
					printf("\n ERROR: no hay juguetes en la lista de deseos\n");	
				}
				else if (strcmp(i->jugueteLD2,"0")==0) 
				{
					printf("1. %s\n",i->jugueteLD1);	
				}	
				else if (strcmp(i->jugueteLD3,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);	
				}
				else if (strcmp(i->jugueteLD4,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
				}
				else if (strcmp(i->jugueteLD5,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
				}	
				else if (strcmp(i->jugueteLD6,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
				}
				else if (strcmp(i->jugueteLD7,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
				}
				else if (strcmp(i->jugueteLD8,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
				}
				else if (strcmp(i->jugueteLD9,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
				}
				else if (strcmp(i->jugueteLD10,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
				}
				else if (strcmp(i->jugueteLD11,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
				}	
				else if (strcmp(i->jugueteLD12,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
				}
				else if (strcmp(i->jugueteLD13,"0")==0) 
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);
				}	
				else if (strcmp(i->jugueteLD14,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);	
				}
				else if (strcmp(i->jugueteLD15,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);	
				}
				else if (strcmp(i->jugueteLD16,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
				}	
				else if (strcmp(i->jugueteLD17,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
					printf("16. %s\n",i->jugueteLD16);
				}
				else if (strcmp(i->jugueteLD18,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
					printf("16. %s\n",i->jugueteLD16);
					printf("17. %s\n",i->jugueteLD17);
				}
				else if (strcmp(i->jugueteLD19,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
					printf("16. %s\n",i->jugueteLD16);
					printf("17. %s\n",i->jugueteLD17);
					printf("18. %s\n",i->jugueteLD18);
				}
				else if (strcmp(i->jugueteLD20,"0")==0)
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
					printf("16. %s\n",i->jugueteLD16);
					printf("17. %s\n",i->jugueteLD17);
					printf("18. %s\n",i->jugueteLD18);
					printf("19. %s\n",i->jugueteLD19);
				}

				else 
				{
					printf("1. %s\n",i->jugueteLD1);
					printf("2. %s\n",i->jugueteLD2);
					printf("3. %s\n",i->jugueteLD3);
					printf("4. %s\n",i->jugueteLD4);
					printf("5. %s\n",i->jugueteLD5);
					printf("6. %s\n",i->jugueteLD6);
					printf("7. %s\n",i->jugueteLD7);
					printf("8. %s\n",i->jugueteLD8);
					printf("9. %s\n",i->jugueteLD9);
					printf("10. %s\n",i->jugueteLD10);
					printf("11. %s\n",i->jugueteLD11);	
					printf("12. %s\n",i->jugueteLD12);	
					printf("13. %s\n",i->jugueteLD13);
					printf("14. %s\n",i->jugueteLD14);
					printf("15. %s\n",i->jugueteLD15);
					printf("16. %s\n",i->jugueteLD16);
					printf("17. %s\n",i->jugueteLD17);
					printf("18. %s\n",i->jugueteLD18);
					printf("19. %s\n",i->jugueteLD19);
					printf("20. %s\n",i->jugueteLD20);
				}		
			}
		}			
			
		if (contador == 0)
		{
			printf ("\nERROR: la cedula ingresada no contiene lista de deseos, la accion no se puede realizar.");
			return;
		}
	}

	return 0;
}




/* ---------------------------------------------------------------- 13. PROCESAR CARTA PARA SANTA ------------------------------------------------------------- */

typedef struct ProcesarCarta
{
	char Ide_Ayudante[50];
	char Year [10];	
	char Ide_Kid[50];
	
	struct ProcesarCarta * next;	
}ProcesarCarta;

typedef struct ImprimirCProcesada
{
	ProcesarCarta *front;
	ProcesarCarta *rear;
	int size;
}ImprimirCProcesada;


/* ----------------------- CREAR NUEVA COLA CARTAS PROCESADAS----------------------- */

ImprimirCProcesada * CrearColaCartasProcesadas(ImprimirCProcesada * ColaCartasProcesadas)
{
	ColaCartasProcesadas = NULL;
	ColaCartasProcesadas = (ImprimirCProcesada *) malloc(sizeof(ImprimirCProcesada));	
	ColaCartasProcesadas -> front = NULL;
	ColaCartasProcesadas -> rear = NULL;
	return ColaCartasProcesadas;
}


/* ----------------------- CREAR NODO CARTA PROCESADA ----------------------- */

ProcesarCarta * CrearCartaProcesada(char Ide_Ayudante[50], char Year[10], char Ide_Kid[50])
{
	struct ProcesarCarta *nuevo;
	nuevo = (ProcesarCarta *) malloc(sizeof(ProcesarCarta));
	nuevo -> next = NULL;
	
	strcpy(nuevo->Ide_Ayudante,Ide_Ayudante);
	strcpy(nuevo->Year,Year);	
	strcpy(nuevo->Ide_Kid,Ide_Kid);

	return nuevo;
}

/* ----------------------- REGISTRAR CARTA PROCESADA ----------------------- */

ImprimirCProcesada  * InsertarCartaProcesada (ImprimirCProcesada  * ColaCartasProcesadas, char Ide_Ayudante[50], char Year[10], char Ide_Kid[50])
{
	ColaCartasProcesadas->size = ColaCartasProcesadas->size + 1;
	if(ColaCartasProcesadas->front == NULL) 
	{
		ColaCartasProcesadas->front = CrearCartaProcesada(Ide_Ayudante,Year, Ide_Kid);
		ColaCartasProcesadas->rear = ColaCartasProcesadas->front;
		return ColaCartasProcesadas;
	}
	ColaCartasProcesadas ->rear->next = CrearCartaProcesada(Ide_Ayudante,Year, Ide_Kid);
	ColaCartasProcesadas ->rear = ColaCartasProcesadas->rear->next;
}


int ValidarComportamiento(Imprimir * ColaKids, char cedula_ver[10])
{
	Kid *j;
	
	for(j = ColaKids->front; j!= NULL; j = j->next)
	{
		if (strcmp(j->cedula,cedula_ver)==0)
		{
			if (j->contador_comportamiento_malo > 6)
			{
				return 1;
			}
		}
	}
	return 0;
	
}

int ValidarCedula(ImprimirCarta *ColaCartas, char cedula_proc[10])
{
	Carta *i;
	
	for(i = ColaCartas->front; i!= NULL; i = i->next)
	{
		if (strcmp(i->cedula,cedula_proc)==0)
		{
			return 1;
		}
	}
	return 0;
	
}		


void procesar_carta(ImprimirCProcesada  * ColaCartasProcesadas, Imprimir * ColaKids, ImprimirAyudante *ColaAyudantes, ImprimirCarta *ColaCartas)
{
	char Ide_Ayudante[50];
	char Year [10];	
	char Ide_Kid[50];
	
	char yearConsultar[10];
	char ced_Procesar[10];
	char opcion[10];
	char ver_Ayu[10];
	
	printf("Ingrese la cedula del ayudante que procesará la carta: ");
	fflush (stdin);
	gets (ver_Ayu);
	
	Ayudante *h;	
	for(h = ColaAyudantes->front; h!= NULL; h = h->next)
	{
		if (strcmp(h->cedula,ver_Ayu)==0)
		{
			printf("Indique el año al que corresponden las cartas a procesar: ");
			fflush (stdin);
			gets (yearConsultar);
			
			Carta *i;
			Kid *j;
			
			if (ColaCartas -> front == NULL)
			{
				printf ("\nERROR: No hay cartas registradas");
				return;
			}
			else
			{			
				printf("Los niños que registraron cartas para el año %s son: \n", yearConsultar);
				for(i = ColaCartas->front; i!= NULL; i = i->next)
				{
					if (strcmp(i->year,yearConsultar)==0)
					{
						for(j = ColaKids->front; j!= NULL; j = j->next)
						{
							if (strcmp(i->cedula,j->cedula)==0)
							{
								printf("Nombre: %s\nCedula: %s\n",j->nombre, j->cedula);
								printf("--------------------------------------\n");
							}
						}
						
					}
				}
				
				printf("\nIngrese la cedula del niño al que se le precesará la carta: \n");
				fflush (stdin);
				gets (ced_Procesar);
				
				if(ValidarCedula(ColaCartas, ced_Procesar)==0)
				{
					printf("ERROR: EL niño no tiene cartas registradas.");
					return;
				}
				else
				{							
					if (ValidarComportamiento(ColaKids, ced_Procesar)==0)
					{					
						printf("------INFORMACIÓN DE LA CARTA-------\n");
						
						for(i = ColaCartas->front; i!= NULL; i = i->next)
						{
							if (strcmp(i->cedula,ced_Procesar)==0)
							{
								for(j = ColaKids->front; j!= NULL; j = j->next)
								{
									if (strcmp(ced_Procesar,j->cedula)==0)
									{
										printf("Nombre del niño: %s\nCedula: %s\n",j->nombre,j->cedula),
										ConsultarCartas(ColaCartas, ced_Procesar, yearConsultar);
										
										printf("\nESTADO DE LA CARTA\n");
										printf("1. Todos los juguetes estan listos para entragar\n");
										printf("2. Los juguetes NO estan listos para entragar\n");
										printf("Ingrese la opcion que corresponda: ");
										fflush (stdin);
										gets (opcion);
										
										if (strcmp(opcion,"1")==0)
										{
											strcpy(i->estado_jug,"Entregar");
											strcpy(j->estado_carta,"Entregar");
										}
										else if (strcmp(opcion,"2")==0)
										{
											strcpy(i->estado_jug,"Rechazado");		
										}
										else
										{
											printf("ERROR: opcion no disponible");
											return;
										}			
									}
								}	
							}
						}
					}
				
					else
					{
						printf("\n\nEstimado padre o madre del niño. \n Se le comunica que su hijo cuenta con un registro de más de 6 omportamientos malos,\n por lo cual este año no recibirá regalos por parte de Santa y la carta será rechazada.");
						for(i = ColaCartas->front; i!= NULL; i = i->next)
						{
							if (strcmp(i->cedula,ced_Procesar)==0)
							{
								strcpy(i->estado_jug,"Rechazado");
							}
						}
					}
					
					strcpy(Ide_Ayudante,ver_Ayu);
					strcpy(Year,yearConsultar);
					strcpy(Ide_Kid,ced_Procesar);
					
					InsertarCartaProcesada (ColaCartasProcesadas, Ide_Ayudante, Year, Ide_Kid);
					printf("\n\nLa carta se ha registrado exitosamente.");
				}
			}
			h->contador_cartas++;
		}
		else
		{
			printf("ERROR: la cedula ingresada no se encuentra en el registro de ayudantes");
		}
	}
}




/* ------------------------------------------------------------------ 14. ENTREGA DE JUGUETES ----------------------------------------------------------------- */

int verificarEntregaNodo(char dom [15], Imprimir * ColaKids){
	Kid * k;
		
		for(k = ColaKids->front; k!= NULL; k = k->next){
			 if(strcmp(k->lugar_residencia,dom)==0 && strcmp(k->estado_carta, "Listo para entregar")==0){
			 	return 1;
			 }
		}
	return 0;
}

int ListaNinos (char dom [15], Imprimir * ColaKids){
	Kid * k;
		
		for(k = ColaKids->front; k!= NULL; k = k->next){
			 if(strcmp(k->lugar_residencia,dom)==0 && strcmp(k->estado_carta, "Listo para entregar")==0){
			 	printf("\n%s", k -> nombre);
			 }
		}
	return 0;
}
void entregarJuguetes(Imprimir * ColaKids){
	//Estructuras
	Domicilio * d; 
	Ruta * r;
	Carta * c;
	Kid * k;
	d = inicio;
	int op;
	
	//opciones de entrega
	printf("\n\n-------MENÚ ENTREGA JUGUETES---------");
	printf("\n1. Todas las rutas.");
	printf("\n2. Ruta terrestre.");
	printf("\n3. Ruta marítima.");
	printf("\n4. Ruta aérea.");
	printf("\nOpcion:");
	scanf("%d",op);
	switch(op){
		case 1:
			printf("\n\n------TODAS LAS RUTAS-------");
			while(d != NULL)
			{
				if (verificarEntregaNodo(d -> nombre , ColaKids)==1){
					printf("\n-------- POLO NORTE -> %s ---------", d->nombre);
					dijkstra("Polo Norte", d -> nombre);
					printf("\n\n\n-------- LISTA NINOS EN %s ---------", d->nombre);
					ListaNinos (d -> nombre, ColaKids);
				
				}
				d = d -> siguiente;
			}
			
			break;
		case 2:
			break;
			printf("\n\n------RUTA TERRESTRE-------");
	
				
	
			d = d -> siguiente;
			
		case 3:
			printf("\n\n------RUTA MARITIMA-------");
			break;
		case 4:
			printf("\n\n------RUTA AEREA-------");
			break;
		default:
			printf("\nERROR: opción no válida.");
			break;
		}
		
	}

	






/* ------------------------------------------------------------------ 15. ANALISIS DE DATOS ------------------------------------------------------------------- */


/* ------------------------------------ 15.1 Cantidad de juguetes solicitados por año ------------------------------------- */




/* ------------------------------------ 15.2 Lugar donde se solicitaron más y menos juguetes ------------------------------------- */


/* ------------------------ STRUCT DE LA COLA ------------------------ */

typedef struct LugarP
{
	int cant_juguetes;
	char nombre_lugar [200];
	struct LugarP * next;
}LugarP;


typedef struct TopLugarP
{
	int size;
	LugarP * front;
	LugarP * rear;
}TopLugarP;

/* ----------------------- CREAR NUEVA COLA ----------------------- */

TopLugarP * CrearColaTopLugar(TopLugarP * C)
{
	C= NULL;
	C = (TopLugarP *) malloc(sizeof(TopLugarP));	
	C-> front = NULL;
	C-> rear = NULL;
	return C;
}

/* ----------------------- CREAR NODO ----------------------- */

LugarP * CrearNodoTopLugar(int cant_juguetes, char nombre_lugar [200])
{
	struct LugarP *nuevo;
	nuevo = (LugarP *) malloc(sizeof(LugarP));
	nuevo-> next = NULL;
	
	nuevo->cant_juguetes=cant_juguetes;
	strcpy(nuevo->nombre_lugar,nombre_lugar);
	return nuevo;
}

/* ----------------------- AGREGAR ELEMENTO ----------------------- */

TopLugarP * InsertarTopLugar(TopLugarP * C, int cant_juguetes, char nombre_lugar [200])
{
	C->size = C-> size + 1;
	if(C->front == NULL) 
	{
		C->front = CrearNodoTopLugar(cant_juguetes,nombre_lugar);
		C->rear = C->front;
		return C;
	}
	C->rear->next = CrearNodoTopLugar(cant_juguetes,nombre_lugar);
	C->rear = C->rear->next;
}

/* ----------------------- IMPRIMIR COLA ----------------------- */

void ImprimirColaTopLugar(TopLugarP *C)
{
	LugarP *i;
	i = C->front;
	int contador = 0;
	if (C -> front == NULL)
	{
		printf ("\nERROR: No hay lugares o juguetes registrados");
	}
	else
	{
		printf("\n\n------------------- LUGAR CON MAS Y MENOS JUGUETES ------------------- \n");
		
		printf("\n\nLugar: %s", i->nombre_lugar);
		printf ("\tCantidad de Juguetes: %d", i->cant_juguetes);
		
		while(i!=NULL)
		{
			if (i->next == NULL)
			{
				printf("\n\nLugar: %s", i->nombre_lugar);
				printf ("\tCantidad de Juguetes: %d", i->cant_juguetes);	
			}
			
			i = i->next;
		}
	}
	printf("\n");
}
				
/* ----------------------- ELIMINAR ELEMENTO ----------------------- */

TopLugarP *EliminarTopLugar(TopLugarP * C, char Auxiliar[30])
{
	LugarP *i;
	TopLugarP *C2= CrearColaTopLugar(C2);
	for(i = C->front; i!= NULL; i = i->next)
	{
		if ((strcmp(i->nombre_lugar,Auxiliar)!=0))
		{
			C2= InsertarTopLugar(C2,i->cant_juguetes,i->nombre_lugar);
		}
	}
	return C2;
}

/* ----------------------- ORDENAR POR PRIORIDAD ----------------------- */

TopLugarP *PrioridadTopLugar(TopLugarP * C)
{
	int contador=0;
	TopLugarP * C2= CrearColaTopLugar(C2);
	LugarP *i;
	struct LugarP * menor;
	menor = (LugarP *) malloc(sizeof(LugarP));
	menor-> next = NULL;
	
	for(i = C->front; i!= NULL; i = i->next)
	{
		contador++;	
	}
	while (contador>0)
	{
		menor->cant_juguetes = 0;
		for(i = C->front; i!= NULL; i = i->next)
		{
			if (menor->cant_juguetes <= i->cant_juguetes)
			{
				menor->cant_juguetes = i->cant_juguetes;
				strcpy (menor->nombre_lugar,i->nombre_lugar);
			}	
		}
		C2= InsertarTopLugar(C2,menor->cant_juguetes,menor->nombre_lugar);
		contador--;
		C= EliminarTopLugar(C,menor->nombre_lugar);
	}
	return C2;
}





/* ------------------------------------ 15.7 Top 10 de los juguetes más pedidos  ------------------------------------- */


/* ------------------------ STRUCT DE LA COLA ------------------------ */

typedef struct JuguetesP
{
	int cantidad;
	char juguete [200];
	struct JuguetesP * next;
}JuguetesP;


typedef struct TopJuguetesP
{
	int size;
	JuguetesP * front;
	JuguetesP * rear;
}TopJuguetesP;

/* ----------------------- CREAR NUEVA COLA ----------------------- */

TopJuguetesP * CrearColaTopJuguetes(TopJuguetesP * C)
{
	C= NULL;
	C = (TopJuguetesP *) malloc(sizeof(TopJuguetesP));	
	C-> front = NULL;
	C-> rear = NULL;
	return C;
}

/* ----------------------- CREAR NODO ----------------------- */

JuguetesP * CrearNodoTopJuguetes(int cantidad, char juguete [200])
{
	struct JuguetesP *nuevo;
	nuevo = (JuguetesP *) malloc(sizeof(JuguetesP));
	nuevo-> next = NULL;
	
	nuevo->cantidad=cantidad;
	strcpy(nuevo->juguete,juguete);
	return nuevo;
}

/* ----------------------- AGREGAR ELEMENTO ----------------------- */

TopJuguetesP * InsertarTopJuguetes(TopJuguetesP * C, int cantidad, char juguete [200])
{
	C->size = C-> size + 1;
	if(C->front == NULL) 
	{
		C->front = CrearNodoTopJuguetes(cantidad,juguete);
		C->rear = C->front;
		return C;
	}
	C->rear->next = CrearNodoTopJuguetes(cantidad,juguete);
	C->rear = C->rear->next;
}

/* ----------------------- IMPRIMIR COLA ----------------------- */

void ImprimirColaTopJuguetes(TopJuguetesP *C)
{
	JuguetesP *i;
	i = C->front;
	int contador = 0;
	if (C -> front == NULL)
	{
		printf ("\nERROR: No hay Asignaciones asignadas");
	}
	else
	{
		printf("\n\n------------------- TOP 10 DE JUGUETES MAS SOLICITADOS ------------------- \n");
		
		while (i != NULL)
		{
			printf("\n\nJuguete: %s", i->juguete);
			printf ("\tCantidad: %d", i->cantidad);
			i = i->next;
			contador ++;
			
			if (contador == 10)
			{
				return;
			}
		}
	}
	printf("\n");
}
				
/* ----------------------- ELIMINAR ELEMENTO ----------------------- */

TopJuguetesP *EliminarTopJuguetes(TopJuguetesP * C, char Auxiliar[30])
{
	JuguetesP *i;
	TopJuguetesP *C2= CrearColaTopJuguetes(C2);
	for(i = C->front; i!= NULL; i = i->next)
	{
		if ((strcmp(i->juguete,Auxiliar)!=0))
		{
			C2= InsertarTopJuguetes(C2,i->cantidad,i->juguete);
		}
	}
	return C2;
}

/* ----------------------- ORDENAR POR PRIORIDAD ----------------------- */

TopJuguetesP *PrioridadTopJuguetes(TopJuguetesP * C)
{
	int contador=0;
	TopJuguetesP * C2= CrearColaTopJuguetes(C2);
	JuguetesP *i;
	struct JuguetesP * menor;
	menor = (JuguetesP *) malloc(sizeof(JuguetesP));
	menor-> next = NULL;
	
	for(i = C->front; i!= NULL; i = i->next)
	{
		contador++;	
	}
	while (contador>0)
	{
		menor->cantidad= 0;
		for(i = C->front; i!= NULL; i = i->next)
		{
			if (menor->cantidad<=i->cantidad)
			{
				menor->cantidad=i->cantidad;
				strcpy (menor->juguete,i->juguete);
			}	
		}
		C2= InsertarTopJuguetes(C2,menor->cantidad,menor->juguete);
		contador--;
		C= EliminarTopJuguetes(C,menor->juguete);
	}
	return C2;
}




void contadorArbol(Arbol a, TopJuguetesP * JuguetesPrioridad  )
{
	if(!Vacio(a)) 
	{
		CrearColaTopJuguetes(JuguetesPrioridad);
		
     	JuguetesPrioridad = PrioridadTopJuguetes(InsertarTopJuguetes(JuguetesPrioridad,a->contador,a->nombre));
		
		if(a->izquierdo) contadorArbol(a->izquierdo, JuguetesPrioridad );
		if(a->derecho) contadorArbol(a->derecho, JuguetesPrioridad );
	}
	
	else
	{
		printf("\n\n---------- Catalogo juguetes vacio!! ----------");
		return;	
	}	
}






/* ------------------------------------------------------------------ FUNCION PRINCIPAL ------------------------------------------------------------------ */

int main()
{
	//DECLARACION DE ESTRUCTURAS DE DATOS
	Imprimir * ColaKids = CrearColaKids(ColaKids);
	ImprimirAyudante * ColaAyudantes = CrearColaAyudantes(ColaAyudantes);
	ImprimirComportamiento * ColaComportamientos = CrearColaComportamientos(ColaComportamientos);
	Arbol *a;
	ImprimirCarta * ColaCartas = CrearColaCartas(ColaCartas);
	ImprimirLD *ColaListaDeseos = CrearColaListaDeseos(ColaListaDeseos);
	ImprimirCProcesada *ColaCartasProcesadas = CrearColaCartasProcesadas(ColaCartasProcesadas);
	insertarLugarPolo ("Polo Norte", 000 ,101);
	
	
	TopJuguetesP * JuguetesPrioridad = CrearColaTopJuguetes(JuguetesPrioridad);
	TopLugarP * LugarPrioridad = CrearColaTopLugar(LugarPrioridad);
	
	
	printf ("\n --------------------- BIENVENIDO AL SISTEMA DE REGISTRO Y PROCESAMIENTO DE CARTAS DE SANTA --------------------- \n");
	
	
	//MENU PRINCIPAL DE LA FUNCION
	printf ("\n\n -------------------------- MENU PRINCIPAL -------------------------- \n");
	printf ("\n 1.  Registrar niño.");
	printf ("\n 2.  Modificar informacion de un niño.");
	printf ("\n 3.  Registrar ayudante de Santa.");
	printf ("\n 4.  Modificar informacion de un ayudante de Santa.");
	printf ("\n 5.  Registrar juguete.");
	printf ("\n 6.  Modificar informacion de un juguete.");
	printf ("\n 7.  Eliminar juguete.");
	printf ("\n 8.  Registrar lugar de domicilio en el catalogo.");
	printf ("\n 9.  Modificar lugar de domicilio en el catalogo.");
	printf ("\n 10. Registrar ruta en el catalogo");
	printf ("\n 11. Modificar ruta en el catalogo.");
	printf ("\n 12. Registrar comportamiento de un niño.");
	printf ("\n 13. Registrar carta para Santa.");
	printf ("\n 14. Modificar carta para Santa.");
	printf ("\n 15. Consultar carta para Santa.");
	printf ("\n 16. Procesar carta para Santa.");
	printf ("\n 17. Realizar entrega de juguetes.");
	printf ("\n 18. Analizar datos.");
	printf ("\n 19. Finalizar programa.");
	
	int opcion;
	printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
	scanf_s ("%d", &opcion);
	
	while (opcion != 19)
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
			printf("\n\n\n------CATALOGO JUGUETES-------");
			PreOrden(ArbolInt);
			RegistrarJuguetesMain( );
		}
		
	
		else if (opcion == 6)
		{
			modificarJuguete(ArbolInt);
		}
		
		
		else if (opcion == 7)
		{
			int dat;
			printf("--------------ELIMINAR JUGUETE--------------");
			printf("\nID del juguete que desea eliminar: ");
			scanf("%d",&dat);
			
			if(BuscarCodigo(ArbolInt, dat)==0)
			{
				BorrarJuguete(&ArbolInt, dat);
				printf("\n--BORRADO!!---");		
			}
			else
			{
				printf("ERROR: ID no registrado.");
			}
		}
		
		
		else if (opcion == 8)
		{
			int domicilios, d;
			
			printf("\n\n------------------------ CATALOGO DE DOMICILIOS ------------------------\n\n");
			printf("Ingrese la cantidad domicilios que desea registrar: ");
			scanf("%d",&domicilios);
			
			for(d=0; d<domicilios; d++)
			{
				printf("\n\n-------------- DOMICILIO #%d --------------\n", d+1 );
				insertarLugar ();								
			}	
		}
		
		
		else if (opcion == 9)
		{
			int op;
			printf("\n--------------- MODIFICAR CATALOGO DOMICILIO ---------------\n");
			printf("\n1. Modificar datos domicilio.");
			printf("\n2. Eliminar domicilio.");
			printf("\nInserte el numero de la accion que desea realizar: ");
			scanf("%d", &op);
			if(op>0 && op<3)
			{
				if (op ==1)
				{
					modificarDomicilio();
				}
				
				if (op ==2)
				{
					borrarDomicilio();
				}
			}
			
			else
			{
				printf("ERROR: opcion no disponible");
				return;
			}	
		}
		
		
		else if (opcion == 10)
		{
			printf("\n\n--------------INSERTAR RUTA-----------------\n\n");
			insertarRuta();
		}
		
		
		else if (opcion == 11)
		{
			int op;
			printf("\n--------------- MODIFICAR CATALOGO RUTAS ---------------\n");
			visualizarGrafo();
			printf("\n1. Modificar ruta.");
			printf("\n2. Eliminar ruta.");
			printf("\nInserte el numero de la accion que desea realizar: ");
			scanf("%d", &op);
			if(op>0 && op<3)
			{
				if (op ==1)
				{
					modificarArista();
				}
				if(op ==2)
				{
					eliminarArista();
				}
			}
			else
			{
				printf("ERROR: opcion no disponible");
				return;
			}	
		}
		
		
		else if (opcion == 12)
		{
			RegistrarComportamientoMain(ColaComportamientos, ColaKids);
		}
		
		
		else if (opcion == 13)
		{
			RegistrarCartaMain(ColaCartas, ColaListaDeseos, ColaKids);
		}
		
		
		else if (opcion == 14)
		{
			modificar_carta(ColaCartas, ColaListaDeseos, ColaKids);
		}
		
		
		else if (opcion == 15)
		{
			char verificar_cedula[15];
			char verificar_year[15];
			
			printf("\n------------------------ CONSULTA DE CARTAS ------------------------\n");
			printf ("\nIngrese la cedula del niño al que pertenece la carta: ")	;
			fflush (stdin);
			gets (verificar_cedula);
			printf ("Ingrese el año para el que se solicito la carta: ")	;
			fflush (stdin);
			gets (verificar_year);
			
			ConsultarCartas(ColaCartas, verificar_cedula, verificar_year);
		}
		
		
		else if (opcion == 16)
		{
			procesar_carta(ColaCartasProcesadas, ColaKids, ColaAyudantes, ColaCartas);
		}
		
		
		else if (opcion == 17)
		{
			entregarJuguetes(ColaKids);
		}
		
		
		else if (opcion == 18)
		{
			char opcion_analisis[10];
			
			printf ("\n\n -------------------------- ANALISIS DE DATOS -------------------------- \n");
			printf ("\n 1.  Cantidad de juguetes solicitados por año.");
			printf ("\n 2.  Lugar donde se solicitaron mas y menos juguetes.");
			printf ("\n 3.  Cantidad de niños a los que se les aprobó su carta por año.");
			printf ("\n 4.  Cantidad de niños a los que se les rechazó su carta por año.");
			printf ("\n 5.  Cantidad de comportamientos buenos y malos registrados.");
			printf ("\n 6.  Cantidad de cartas procesadas por ayudante.");
			printf ("\n 7.  Top 10 de los juguetes mas solicitados.");
			printf ("\n\nIngrese el numero del analisis que desea realizar:  ");
			fflush (stdin);
			gets (opcion_analisis);	
			
			if (strcmp(opcion_analisis,"1")==0)
			{
				int juguetes_2017 = 0;
				int juguetes_2018 = 0;
				int juguetes_2019 = 0;
				int juguetes_2020 = 0;
				int juguetes_2021 = 0;
				
				Carta *aux;
				for (aux = ColaCartas->front; aux!= NULL; aux = aux->next)
				{
					juguetes_2017 = juguetes_2017 + aux->contador_2017;
					juguetes_2018 = juguetes_2018 + aux->contador_2018;
					juguetes_2019 = juguetes_2019 + aux->contador_2019;
					juguetes_2020 = juguetes_2020 + aux->contador_2020;
					juguetes_2021 = juguetes_2021 + aux->contador_2021;
				}
				
				printf ("\nCantidad de juguetes solicitados en el 2017: %d", juguetes_2017);
				printf ("\nCantidad de juguetes solicitados en el 2018: %d", juguetes_2018);
				printf ("\nCantidad de juguetes solicitados en el 2019: %d", juguetes_2019);
				printf ("\nCantidad de juguetes solicitados en el 2020: %d", juguetes_2020);
				printf ("\nCantidad de juguetes solicitados en el 2021: %d", juguetes_2021);
			}
			
			else if (strcmp(opcion_analisis,"2")==0)
			
			{
				Domicilio * p;
				p = inicio;
				while(p != NULL)
				{
					LugarPrioridad = PrioridadTopLugar(InsertarTopLugar(LugarPrioridad,p->contador,p->nombre));
					
					p = p -> siguiente;
				}
				
				ImprimirColaTopLugar(LugarPrioridad);	
			}

			else if (strcmp(opcion_analisis,"3")==0)
			{
				int aprobado_2017 = 0;
				int aprobado_2018 = 0;
				int aprobado_2019 = 0;
				int aprobado_2020 = 0;
				int aprobado_2021 = 0;
				
				Carta *n;
				for (n = ColaCartas->front; n!= NULL; n = n->next)
				{
					if ((strcmp(n->year,"2017")==0) && (strcmp(n->estado_jug,"Entregar")==0))
					{
						aprobado_2017 ++;
					}
					if ((strcmp(n->year,"2018")==0) && (strcmp(n->estado_jug,"Entregar")==0))
					{
						aprobado_2018 ++;
					}
					if ((strcmp(n->year,"2019")==0) && (strcmp(n->estado_jug,"Entregar")==0))
					{
						aprobado_2019 ++;
					}
					if ((strcmp(n->year,"2020")==0) && (strcmp(n->estado_jug,"Entregar")==0))
					{
						aprobado_2020 ++;
					}
					if ((strcmp(n->year,"2021")==0) && (strcmp(n->estado_jug,"Entregar")==0))
					{
						aprobado_2021 ++;
					}
				}
				
				printf ("\nCantidad de cartas aprobadas en el 2017: %d", aprobado_2017);
				printf ("\nCantidad de cartas aprobadas en el 2018: %d", aprobado_2018);
				printf ("\nCantidad de cartas aprobadas en el 2019: %d", aprobado_2019);
				printf ("\nCantidad de cartas aprobadas en el 2020: %d", aprobado_2020);
				printf ("\nCantidad de cartas aprobadas en el 2021: %d", aprobado_2021);
			}
			
			else if (strcmp(opcion_analisis,"4")==0)
			{
				int rechazado_2017 = 0;
				int rechazado_2018 = 0;
				int rechazado_2019 = 0;
				int rechazado_2020 = 0;
				int rechazado_2021 = 0;
				
				Carta *n;
				for (n = ColaCartas->front; n!= NULL; n = n->next)
				{
					if ((strcmp(n->year,"2017")==0) && (strcmp(n->estado_jug,"Rechazado")==0))
					{
						rechazado_2017 ++;
					}
					if ((strcmp(n->year,"2018")==0) && (strcmp(n->estado_jug,"Rechazado")==0))
					{
						rechazado_2018 ++;
					}
					if ((strcmp(n->year,"2019")==0) && (strcmp(n->estado_jug,"Rechazado")==0))
					{
						rechazado_2019 ++;
					}
					if ((strcmp(n->year,"2020")==0) && (strcmp(n->estado_jug,"Rechazado")==0))
					{
						rechazado_2020 ++;
					}
					if ((strcmp(n->year,"2021")==0) && (strcmp(n->estado_jug,"Rechazado")==0))
					{
						rechazado_2021 ++;
					}
				}
				
				printf ("\nCantidad de cartas rechazadas en el 2017: %d", rechazado_2017);
				printf ("\nCantidad de cartas rechazadas en el 2018: %d", rechazado_2018);
				printf ("\nCantidad de cartas rechazadas en el 2019: %d", rechazado_2019);
				printf ("\nCantidad de cartas rechazadas en el 2020: %d", rechazado_2020);
				printf ("\nCantidad de cartas rechazadas en el 2021: %d", rechazado_2021);
			}
			
			else if (strcmp(opcion_analisis,"5")==0)
			{
				int comportamiento_bueno = 0;
				int comportamiento_malo = 0;
				
				Kid *i;
				for (i = ColaKids->front; i!= NULL; i = i->next)
				{
					comportamiento_bueno = comportamiento_bueno + i->contador_comportamiento_bueno;
					comportamiento_malo = comportamiento_malo + i->contador_comportamiento_malo;
				}
				
				printf ("\nLa cantidad de comportamientos buenos registrados fue de: %d", comportamiento_bueno);
				printf ("\nLa cantidad de comportamientos malos registrados fue de: %d", comportamiento_malo);
			}
			
			else if (strcmp(opcion_analisis,"6")==0)
			{
				Ayudante *a;
				for (a = ColaAyudantes->front; a!= NULL; a = a->next)
				{
					printf ("\nNombre: %s:", a->nombre);
					printf ("\tCartas procesadas: %d", a->contador_cartas);
				}	
			}
			
			else if (strcmp(opcion_analisis,"7")==0)
			{
				contadorArbol(ArbolInt, JuguetesPrioridad );
				ImprimirColaTopJuguetes(JuguetesPrioridad);	
			}	
			
			else
			{
				printf ("\n\nERROR: La accion solicitada no existe.");
			}
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
			//MENU PRINCIPAL DE LA FUNCION
			printf ("\n\n -------------------------- MENU PRINCIPAL -------------------------- \n");
			printf ("\n 1.  Registrar niño.");
			printf ("\n 2.  Modificar informacion de un niño.");
			printf ("\n 3.  Registrar ayudante de Santa.");
			printf ("\n 4.  Modificar informacion de un ayudante de Santa.");
			printf ("\n 5.  Registrar juguete.");
			printf ("\n 6.  Modificar informacion de un juguete.");
			printf ("\n 7.  Eliminar juguete.");
			printf ("\n 8.  Registrar lugar de domicilio en el catalogo.");
			printf ("\n 9.  Modificar lugar de domicilio en el catalogo.");
			printf ("\n 10. Registrar ruta en el catalogo");
			printf ("\n 11. Modificar ruta en el catalogo.");
			printf ("\n 12. Registrar comportamiento de un niño.");
			printf ("\n 13. Registrar carta para Santa.");
			printf ("\n 14. Modificar carta para Santa.");
			printf ("\n 15. Consultar carta para Santa.");
			printf ("\n 16. Procesar carta para Santa.");
			printf ("\n 17. Realizar entrega de juguetes.");
			printf ("\n 18. Analizar datos.");
			printf ("\n 19. Finalizar programa.");
	
			
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
	

