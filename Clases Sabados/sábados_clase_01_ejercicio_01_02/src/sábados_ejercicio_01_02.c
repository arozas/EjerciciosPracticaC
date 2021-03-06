/*
 ============================================================================
 Name        : sábados_ejercicio_01_02.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : 26/03/2022
 Copyright   : 
 Description : Division H
 ============================================================================
 */

/*
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int contadorVueltas;
	int banderaPrimero;
	int numeroMaximo;
	int numeroMinimo;
	int ordenIngresoMaximo;
	int ordenIngresoMinimo;

	contadorVueltas = 0;
	banderaPrimero=1;
	printf("ESTE PROGRAMA DETERMINA MAXIMOS Y MININIMOS INGRESADOS \n");
	printf("Y EL ORDEN EN QUE FUERON INGRESADOS \n");
	while(contadorVueltas<5)
	{
		printf("Ingrese un numero:");
		scanf("%d", &numeroIngresado);
		if(banderaPrimero==1)
		{
			numeroMaximo=numeroIngresado;
			numeroMinimo=numeroIngresado;
			banderaPrimero=0;
		}
		else
		{
			if(numeroIngresado>numeroMaximo)
			{
				numeroMaximo=numeroIngresado;
				ordenIngresoMaximo=contadorVueltas+1;
			}
			else
			{
				if(numeroIngresado<numeroMinimo)
				{
					numeroMinimo=numeroIngresado;
					ordenIngresoMinimo=contadorVueltas+1;
				}
			}
		}
		contadorVueltas++;
	}
	printf("El numero máximo es: %d \n",numeroMaximo);
	printf("El numero máximo se ingresó en el orden: %d \n",ordenIngresoMaximo);
	printf("El numero minimo es: %d \n",numeroMinimo);
	printf("El numero minimo se ingresó en el orden: %d \n",ordenIngresoMinimo);

	printf("FINALIZO EL PROGRAMA \n");
	return EXIT_SUCCESS;
}
