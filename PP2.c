# include <stdio.h>
# include <stdlib.h>
# include <string.h>	
#include <unistd.h>
#include <time.h>


/* ------------------------------------------------------------------ REGISTRAR NIÑO ------------------------------------------------------------------ */






/* ----------------------------------------------------------- MODIFICAR INFORMACION DE UN NIÑO -------------------------------------------------------- */






/* ------------------------------------------------------------- REGISTRAR AYUDANTE DE SANTA ------------------------------------------------------------ */






/* ------------------------------------------------------- MODIFICAR INFORMACION DE UN AYUDANTE DE SANTA ------------------------------------------------- */






/* ------------------------------------------------------------------ REGISTRAR JUGUETE ------------------------------------------------------------------ */






/* ----------------------------------------------------------- MODIFICAR INFORMACION DE UN JUGUETE -------------------------------------------------------- */






/* -------------------------------------------------------------- REGISTRAR LUGAR DE DOMICILIO ------------------------------------------------------------ */






/* -------------------------------------------------------------- MODIFICAR LUGAR DE DOMICILIO ------------------------------------------------------------ */






/* ----------------------------------------------------------- REGISTRAR COMPORTAMIENTO DE UN NIÑO -------------------------------------------------------- */






/* --------------------------------------------------------------- REGISTRAR CARTA PARA SANTA ------------------------------------------------------------- */






/* --------------------------------------------------------------- MODIFICAR CARTA PARA SANTA ------------------------------------------------------------- */






/* --------------------------------------------------------------- CONSULTAR CARTA PARA SANTA ------------------------------------------------------------- */






/* ---------------------------------------------------------------- PROCESAR CARTA PARA SANTA ------------------------------------------------------------- */






/* ------------------------------------------------------------------ ENTREGA DE JUGUETES ----------------------------------------------------------------- */






/* ------------------------------------------------------------------ ANALISIS DE DATOS ------------------------------------------------------------------- */














/* ------------------------------------------------------------------ FUNCION PRINCIPAL ------------------------------------------------------------------ */

int main()
{
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
			return 0;
		}
		
		else if (opcion == 2)
		{
			return 0;
		}
		
		else if (opcion == 3)
		{
			return 0;		
		}
		
		else if (opcion == 4)
		{
			return 0;
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
		
		else
		{
			printf("\nERROR: La opcion solicitada no se encuentra disponible");
		}	
		
		int opcion_p;

		printf ("\n\nDijite 1 si desea continuar con el programa: ");
		scanf_s ("%d", &opcion_p);
		
		if (opcion_p ==1)
		{
			printf ("\n -------------------------- MENU -------------------------- \n");
			printf ("\n 1.  Consultar miembros de equipo.");
			printf ("\n 2.  Agregar requerimiento.");
			printf ("\n 3.  Modificar requerimiento.");
			printf ("\n 4.  Calificar requerimiento.");
			printf ("\n 5.  Consultar requerimiento.");
			printf ("\n 6.  Crear una asignacion.");
			printf ("\n 7.  Consultar asignaciones de un miembro del equipo.");
			printf ("\n 8.  Cancelar asignacion.");
			printf ("\n 9.  Atender asignacion.");
			printf ("\n 10. Registrar incidente.");
			printf ("\n 11. Consultar incidentes.");
			printf ("\n 12. Analizar datos.");
			printf ("\n 13. Cerrar Sesion.");
			printf ("\n\nSi desea realizar otra accion ingrese el numero:  ");
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
	


