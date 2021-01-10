# include <stdio.h>
# include <stdlib.h>
# include <string.h>	
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define Domicilio struct domicilio
#define Ruta struct ruta




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
   struct _nodo *izquierdo;
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

 
   while(!Vacio(actual)) {
      if(dat == actual->dato) { 
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

  
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) {
   	printf("Error: juguete ya registrado");
   	return;
   	
   }
   
   //PADRE
   if(Vacio(padre)) {
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

   else if(dat < padre->dato) {
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
   else if(dat > padre->dato) {
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
  printf("----REGISTRADO!!-----");
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
    
	printf("--------------REGISTRO DE JUGUETES---------------\n\n");
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
   while(!Vacio(actual)) {
      if(dat == actual->dato){
      		printf("\n----INFORMACIÓN JUGUETE-----");
      		printf("\nID: %d", actual -> dato);
      		printf("\nNombre: %s", actual -> nombre);
      		printf("\nCategoria: %s", actual -> categoria);
      		printf("\nRango de edad: %d a %d", actual -> edad_minima, actual -> edad_maxima);
      		printf("\nCosto: %d", actual -> costo);	
      		printf("\nDescripcion: %s", actual -> descripcion);	
      		return;
		}
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   printf("Error: No encontrado");
   return; /* No está en árbol */
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
  
   while(!Vacio(actual)) {
      if(dat == actual->dato) { 
         if(EsHoja(actual)) { 
            if(padre) 
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
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
      else { 
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   
}

//MODIFICAR DATOS JUGUETE
modificarJuguete(Arbol a ){
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
	
	
 
   while(!Vacio(actual)) {
      if(dat == actual->dato){
      		
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
							else{
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
   
   if(x==0){
   	printf("Error: juguete no registrado");
   } 
   else{
   	printf("\n--- MODIFICADO!! ---\n\n\n");
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
};

Ruta
{
	char origen [15];
	char destino [15];
	float tiempo;
	float distancia;
	char tipo_ruta [15];
	Domicilio*vrt;
	Ruta*siguiente;
};

Domicilio*inicio = NULL;


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
	
	nuevo -> codigo = codigo;
	
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
	
	strcpy(nuevo-> nombre, nombre);
	
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
	
	nuevo -> postal = postal;
	nuevo -> siguiente = NULL;
	nuevo -> adyacencia = NULL;
	
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
	printf("\n\n--------------- NUEVA RUTA INSERTADA! ---------------");
				
}


//FUNCION AUX DE RUTAS

void insertarRuta()
{
	char ini[15], fin[15], tipo_ruta [15];
	float tiempo, distancia;
	Ruta*nuevo = (Ruta*)malloc(sizeof(Ruta));
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
			scanf("%f", &distancia);
			printf("Ingresar tiempo estimado [min]:");
			scanf("%f", &tiempo);
			printf("Ingresar tipo de ruta:");
			scanf("%s", tipo_ruta);
			agregarRuta(aux, aux2, nuevo,ini,fin,distancia,tiempo, tipo_ruta);
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
			
			return;
		}
		aux = aux -> siguiente;
	}
	
	if(aux == NULL)
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

void borrarDomicilio(){
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
	
	while(aux != NULL){
		if(strcmp(domicilio,aux->nombre)==0){
			if(aux -> adyacencia != NULL){
				vaciar_aristas(aux);
			}
			if(aux == inicio){
				inicio = inicio -> siguiente;
				free(aux);
				printf("\nDomicilio eliminado");
				return;
				
			}else{
				ant -> siguiente = aux -> siguiente;
				free(aux);
				printf("\nDomicilio eliminado");
				return;	
			}
		}
		else{
			ant = aux;
			aux = aux -> siguiente;
		}
	}
	if(aux == NULL){
		printf("\nERROR: Domicilio no encontrado");
	}
}

	

//ELIMINAR ARISTA
void eliminarArista(){
	char ini [15];
	char fin [15];
	Domicilio * aux, *aux2;
	Ruta * q, *r;
	printf("\nIngrese el origen:");
	fflush (stdin);
	gets (ini);
	printf("\nIngrese el final:");
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

//MODIFICAR ARISTA

modificar_ruta_aux(char ini[15], char fin[15], float distancia, float tiempo, char tipo_ruta [15])
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
			scanf("%f",&distancia);
			break;
		case 5:
			printf("Escriba el nuevo tipo de ruta:");
			fflush (stdin);
			gets (tipo_ruta);
			break;		
	}
	
	RutaModificar(ini,fin,distancia, tiempo,tipo_ruta);	
}


modificarArista(){
	char ini [15];
	char fin [15];

	float tiempo;
	float distancia;
	char tipo_ruta [15];
	Domicilio * aux, *aux2;
	Ruta * q, *r;
	

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
	printf("Error: ruta no encontrada");
	return;
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

Kid * CrearKid(char cedula[15], char nombre[200], char nombre_usuario[200],char correo [200], char lugar_residencia [50], char edad [50], char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
{
	struct Kid *nuevo;
	nuevo = (Kid *) malloc(sizeof(Kid));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->nombre,nombre);	
	strcpy(nuevo->nombre_usuario,nombre_usuario);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->lugar_residencia,lugar_residencia);
	strcpy(nuevo->edad,edad);
	strcpy(nuevo->fecha_nacimiento,fecha_nacimiento);
	strcpy(nuevo->necesidades_especiales,necesidades_especiales);
	nuevo->contador_comportamiento_bueno = contador_comportamiento_bueno;
	nuevo->contador_comportamiento_malo = contador_comportamiento_malo;
	return nuevo;
}

/* ----------------------- REGISTRAR NIÑO ----------------------- */

Imprimir * InsertarKid(Imprimir * ColaKids, char cedula[15], char nombre[200], char nombre_usuario[200], char correo [200], char lugar_residencia [50], char edad [50], char fecha_nacimiento [50], char necesidades_especiales [200], int contador_comportamiento_bueno, int contador_comportamiento_malo)
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
	/*Domicilio * a;
	int x = 0;
	while (a -> siguiente != NULL)
	{
		if(strcmp(a ->nombre,residencia_kid)==0){
			x = 1;
		}
		a = a -> siguiente;
	}
	if( x == 1){
		printf("Error: Domicilio no registrado.");
		printf ("Ingrese el lugar de residencia del niño que desea registrar: ");
		fflush (stdin);
		gets (residencia_kid);	
	}*/

	
	printf ("Ingrese la edad del niño que desea registrar: ");
	fflush (stdin);
	gets (edad_kid);
	
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
				
				gets (i->lugar_residencia);				
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
	char juguetes_LD [500];

	struct ListaDeseos * next;	
}ListaDeseos;

typedef struct ImprimirLD
{
	ListaDeseos*front;
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

ListaDeseos * CrearListaDeseos(char cedula[15], char juguetes_LD[500])
{
	struct ListaDeseos *nuevo;
	nuevo = (ListaDeseos *) malloc(sizeof(ListaDeseos));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->juguetes_LD,juguetes_LD);	

	return nuevo;
}

/* ----------------------- REGISTRAR LISTA DE DESEOS ----------------------- */

ImprimirLD * InsertarListaDeseos(ImprimirLD* ColaListaDeseos,char cedula[15], char juguetes_LD[500] )
{
	ColaListaDeseos->size = ColaListaDeseos-> size + 1;
	if(ColaListaDeseos->front == NULL) 
	{
		ColaListaDeseos->front = CrearListaDeseos(cedula, juguetes_LD);
		ColaListaDeseos->rear = ColaListaDeseos->front;
		return ColaListaDeseos;
	}
	ColaListaDeseos ->rear->next = CrearListaDeseos(cedula, juguetes_LD);
	ColaListaDeseos ->rear = ColaListaDeseos->rear->next;
}

/* ----------------------- CONSULTAR LISTA DE DESEOS----------------------- */

int ConsultarListaDeseos(ImprimirLD *ColaListaDeseos)
{
	ListaDeseos *i;
	char verificar_cedula[15];
	char verificar_year[15];
	int contador; 
	
	if (ColaListaDeseos -> front == NULL)
	{
		printf ("\nERROR: No hay listas de deseos registradas.");
		return;
	}
	else
	{
		printf ("\nIngrese la cedula del niño al que pertenece la lista de deseos: ")	;
		fflush (stdin);
		gets (verificar_cedula);

		printf("\nLista de juguetes solicitados");
		for(i = ColaListaDeseos->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,verificar_cedula)==0)
			{
				contador = 1;
				
				printf("\n%s",i->juguetes_LD);
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




/* --------------------------------- CARTA ---------------------------------- */

/* --------------------------- STRUCT DE LA CARTA --------------------------- */

typedef struct Carta
{
	char year[10];
	char cedula [50];
	char juguetes [50];

	struct Carta * next;	
}Carta;

typedef struct ImprimirCarta
{
	Carta*front;
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

Carta * CrearCarta(char cedula[15], char year[10], char juguetes[500])
{
	struct Carta *nuevo;
	nuevo = (Carta *) malloc(sizeof(Carta));
	nuevo -> next = NULL;
	
	strcpy(nuevo->cedula,cedula);
	strcpy(nuevo->year,year);
	strcpy(nuevo->juguetes,juguetes);	

	return nuevo;
}

/* ----------------------- REGISTRAR CARTA ----------------------- */

ImprimirCarta * InsertarCarta(ImprimirCarta * ColaCartas,char cedula[15], char year[10], char juguetes[500] )
{
	ColaCartas->size = ColaCartas-> size + 1;
	if(ColaCartas->front == NULL) 
	{
		ColaCartas->front = CrearCarta(cedula, year, juguetes);
		ColaCartas->rear = ColaCartas->front;
		return ColaCartas;
	}
	ColaCartas ->rear->next = CrearCarta(cedula, year, juguetes);
	ColaCartas ->rear = ColaCartas->rear->next;
}


/* ----------------------- REGISTRAR CARTA EN EL MAIN ----------------------- */

void RegistrarCartaMain(ImprimirCarta *ColaCartas, ImprimirLD *ColaListaDeseos, Imprimir *ColaKids)
{
	char year[10];
	char cedula_kid [50];
	char juguetes [50];
	char juguete_buscado[50];
	char opc_carta[10];
	int cantidad_jug=0;
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
	
	
			printf ("Ingrese el año para el que corresponde la carta [yyyy] : ");
			fflush (stdin);
			gets (year);
			
			printf("\n----------- JUGUETES DISPONIBLES -----------\n\n");
			//Imprimir Arbol con la lista de juguetes
			
			printf ("Ingrese el nombre del juguete que desea buscar: ");
			fflush (stdin);
			gets (juguete_buscado);
			printf ("Los datos del juguete son:\n ");
			//Consultar juguete en el arbol
			
			printf ("\n  OPCIONES DISPONIBLES \n");
			printf ("1. Añadir juguete a la carta\n");
			printf ("2. Añadir juguete a la lista de deseos\n");
		
			printf("\nIngrese el numero de la opcion que desea realizar: ");
			fflush (stdin);
			gets (opc_carta);
					
			if (strcmp(opc_carta,"1")==0)
			{
				if (cantidad_jug > 10)
				{
					printf("ERROR: se ha alcanzado la cantidad máxima de juguetes en la carta.");
				}
				else
				{
					InsertarCarta(ColaCartas, cedula_kid, year, juguete_buscado );
				
					ConsultarCartas(ColaCartas);
					printf("%d",cantidad_jug);
					//Cambiar el estado del juguete
				}
				cantidad_jug ++;
			}
			else if (strcmp(opc_carta,"2")==0)
			{
				InsertarListaDeseos(ColaListaDeseos,cedula_kid, juguete_buscado);
				ConsultarListaDeseos(ColaListaDeseos); //Para realizar las pruebas 
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






/* --------------------------------------------------------------- 12. CONSULTAR CARTA PARA SANTA ------------------------------------------------------------- */



int ConsultarCartas(ImprimirCarta *ColaCartas)
{
	Carta *i;
	char verificar_cedula[15];
	char verificar_year[15];
	int contador; 
	
	if (ColaCartas -> front == NULL)
	{
		printf ("\nERROR: No hay cartas registradas.");
		return;
	}
	
	else
	{
		printf("\n------------------------ CONSULTA DE CARTAS ------------------------\n");
		printf ("\nIngrese la cedula del niño al que pertenece la carta: ")	;
		fflush (stdin);
		gets (verificar_cedula);
		printf ("Ingrese el año para el que se solicito la carta: ")	;
		fflush (stdin);
		gets (verificar_year);
		
		printf("\nLista de juguetes solicitados");
		for(i = ColaCartas->front; i!= NULL; i = i->next)
		{
			if (strcmp(i->cedula,verificar_cedula)==0 && strcmp(i->year,verificar_year)==0)
			{
				contador = 1;
				
				printf("\n%s",i->juguetes);
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




/* ---------------------------------------------------------------- 13. PROCESAR CARTA PARA SANTA ------------------------------------------------------------- */






/* ------------------------------------------------------------------ 14. ENTREGA DE JUGUETES ----------------------------------------------------------------- */






/* ------------------------------------------------------------------ 15. ANALISIS DE DATOS ------------------------------------------------------------------- */


/* ------------------------------------ 15.1 Cantidad de juguetes solicitados por año ------------------------------------- */


/* ------------------------------------ 15.2 Lugar donde se solicitaron más y menos juguetes ------------------------------------- */


/* ------------------------------------ 15.3 Cantidad de niños a los que se les aprobó su carta por año  ------------------------------------- */


/* ------------------------------------ 15.4 Cantidad de niños a los que se les rechazó su carta por año ------------------------------------- */


/* ------------------------------------ 15.5 Cantidad de comportamientos buenos y malos registrados  ------------------------------------- */


/* ------------------------------------ 15.6 Cantidad de cartas procesadas según ayudante. ------------------------------------- */


/* ------------------------------------ 15.7 Top 10 de los juguetes más pedidos  ------------------------------------- */











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
	printf ("\n 10. Registrar comportamiento de un niño.");
	printf ("\n 11. Registrar carta para Santa.");
	printf ("\n 12. Modificar carta para Santa.");
	printf ("\n 13. Consultar carta para Santa.");
	printf ("\n 14. Procesar carta para Santa.");
	printf ("\n 15. Realizar entrega de juguetes.");
	printf ("\n 16. Analizar datos.");
	printf ("\n 17. Finalizar programa.");
	
	int opcion;
	printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
	scanf_s ("%d", &opcion);
	
	while (opcion != 17)
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
			RegistrarJuguetesMain( );
			//imprimir_arbol(a);      //Funcion para probar otras, no la piden	

		}
		
	
		else if (opcion == 6)
		{
			modificarJuguete(ArbolInt);
		
		}
		else if (opcion == 7)
		{
			int dat;
			printf("----ELIMINAR JUGUETE----");
			printf("\nID del juguete que desea eliminar: ");
			scanf("%d",&dat);
			
			if(BuscarCodigo(ArbolInt, dat)==0){
				BorrarJuguete(&ArbolInt, dat);
				printf("\n--BORRADO!!---");
				
			}else{
				printf("Error: ID no registrado.");
			}
			
		
		}
		
		
		else if (opcion == 8)
		{
			int domicilios, d, rutas, r;
			
			printf("\n\n------------------------ CATALOGO DE DOMICILIOS ------------------------\n\n");
			printf("Ingrese la cantidad domicilios que desea registrar: ");
			scanf("%d",&domicilios);
			
			for(d=0; d<domicilios; d++)
			{
				printf("\n\n-------------- DOMICILIO #%d --------------\n", d+1 );
				insertarLugar ();					
			}
			
			printf("\n\nIngrese la cantidad rutas: ");
			scanf("%d", &rutas);
			
			for(r=0; r<rutas; r++)
			{
				printf("\n\n-------------- RUTA #%d --------------\n", r+1 );
				insertarRuta();	
			}
		}
			
			
		else if (opcion == 9)
		{
			int op;
			printf("\n--------------- MODIFICAR CATALOGO DOMICILIO ---------------\n");
			printf("\n1. Modificar datos domicilio.");
			printf("\n2. Eliminar domicilio.");
			printf("\n3. Modificar ruta.");
			printf("\n4. Eliminar ruta.");
			printf("\nInserte el numero de la accion que desea realizar: ");
			scanf("%d", &op);
			if(op>0 && op<5)
			{
				if (op ==1)
				{
					modificarDomicilio();
				}
				
				if (op ==2)
				{
					visualizarGrafo();
					borrarDomicilio();
					visualizarGrafo();
				}
				
				if (op ==3)
				{
					modificarArista();
				}
				if(op ==4){
					visualizarGrafo();
					eliminarArista();
					visualizarGrafo();
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
			RegistrarComportamientoMain(ColaComportamientos, ColaKids);
			//ConsultarKids(ColaKids);   //Funcion para probar otras, no la piden
			//ConsultarComportamientos(ColaComportamientos);   //Funcion para probar otras, no la piden
		}
		
		
		else if (opcion == 11)
		{
			RegistrarCartaMain(ColaCartas, ColaListaDeseos, ColaKids);
		}
		
		
		else if (opcion == 12)
		{
			return 0;
		}
		
		
		else if (opcion == 13)
		{
			ConsultarCartas(ColaCartas);
		}
		
		
		else if (opcion == 14)
		{
			return 0;
		}
		
		
		else if (opcion == 15)
		{
			return 0;
		}
		
		
		else if (opcion == 16)
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
				return 0;
			}
			
			else if (strcmp(opcion_analisis,"2")==0)
			{
				return 0;
			}

			else if (strcmp(opcion_analisis,"3")==0)
			{
				return 0;
			}
			
			else if (strcmp(opcion_analisis,"4")==0)
			{
				return 0;
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
				return 0;
			}
			
			else if (strcmp(opcion_analisis,"7")==0)
			{
				return 0;
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
			printf ("\n\n -------------------------- MENU PRINCIPAL -------------------------- \n");
			printf ("\n 1.  Registrar niño.");
			printf ("\n 2.  Modificar informacion de un niño.");
			printf ("\n 3.  Registrar ayudante de Santa.");
			printf ("\n 4.  Modificar informacion de un ayudante de Santa.");
			printf ("\n 5.  Registrar juguete.");
			printf ("\n 6.  Modificar informacion de un juguete.");
			printf ("\n 7. 	Eliminar juguete.");
			printf ("\n 8.  Registrar lugar de domicilio en el catalogo.");
			printf ("\n 9.  Modificar lugar de domicilio en el catalogo.");
			printf ("\n 10.  Registrar comportamiento de un niño.");
			printf ("\n 11. Registrar carta para Santa.");
			printf ("\n 12. Modificar carta para Santa.");
			printf ("\n 13. Consultar carta para Santa.");
			printf ("\n 14. Procesar carta para Santa.");
			printf ("\n 15. Realizar entrega de juguetes.");
			printf ("\n 16. Analizar datos.");
			printf ("\n 17. Finalizar programa.");
			
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
	

