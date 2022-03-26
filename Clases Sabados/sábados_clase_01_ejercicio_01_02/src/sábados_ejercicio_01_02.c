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

	contadorVueltas = 0;
	banderaPrimero=1;

	printf("//Este programa determina maximos y minimos enteros//. \n");

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
			}
			else
			{
				if(numeroIngresado<numeroMinimo)
				{
					numeroMinimo=numeroIngresado;
				}
			}
		}
		contadorVueltas++;
	}
	printf("El numero máximo es: %d \n",numeroMaximo);
	printf("El numero minimo es: %d \n",numeroMinimo);

	return EXIT_SUCCESS;
}
