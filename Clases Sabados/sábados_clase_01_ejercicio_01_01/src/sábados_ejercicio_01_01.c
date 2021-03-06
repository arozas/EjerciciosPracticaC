/*
 ============================================================================
 Name        : sábados_ejercicio_01_01.c
 Author      : Alejandro ALberto Martín Rozas
 Version     : 26/03/2022
 Copyright   : Your copyright notice
 Description : División H
 ============================================================================
 */

/*Enuncianciado:
 Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a)El promedio de los números positivos.
b)El promedio de los números negativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	int numeroIngresado;
	int contadorIngresosPositivos;
	int contadorIngresosNegativos;
	int acumuladorNumerosPositivos;
	int acumuladorNumerosNegativos;
	float promedioPositivos;
	float promedioNegativos;
	char confirmarVueltas;

	contadorIngresosPositivos=0;
	contadorIngresosNegativos=0;
	acumuladorNumerosPositivos=0;
	acumuladorNumerosNegativos=0;

	confirmarVueltas='s';

	while(confirmarVueltas=='s')
	{
		printf("Ingrese un numero:");
		scanf("%d", &numeroIngresado);
		if(numeroIngresado>0)
		{
			acumuladorNumerosPositivos=acumuladorNumerosPositivos+numeroIngresado;
			contadorIngresosPositivos=contadorIngresosPositivos+1;
		}
		else
		{
			if(numeroIngresado<0) //estoy excluyendo el 0 de los ingresos, asi no los promedio.
			{
				acumuladorNumerosNegativos=acumuladorNumerosNegativos+numeroIngresado;
				contadorIngresosNegativos=contadorIngresosNegativos+1;
			}
		}
		__fpurge(stdin); //stdin es standard input, entrada estandard
		printf("¿desean continuar? s/n: ");
		scanf("%c", &confirmarVueltas);
	}

	promedioPositivos=(float)acumuladorNumerosPositivos/contadorIngresosPositivos; //casteo, se le informa al sistema que por esta operación el retorno de esa variable es (float) aunque la variable sea integer.
	promedioNegativos=(float)acumuladorNumerosNegativos/contadorIngresosNegativos;

	if(contadorIngresosPositivos>0)
	{
		printf("El promedio de números positivos es: %.2f \n",promedioPositivos);
	}
	else
	{
		printf("No hay números pósitivos para hacer promedio \n");
	}
	if(contadorIngresosNegativos>0)
	{
		printf("El promedio de números negativos es: %.2f \n",promedioNegativos);
	}
	else
	{
		printf("No hay números pósitivos para hacer promedio \n");
	}


	return EXIT_SUCCESS;
}
