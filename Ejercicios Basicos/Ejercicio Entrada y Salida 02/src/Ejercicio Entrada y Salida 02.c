/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : 26/03/20122
 Copyright   : Your copyright notice
 Description : Ejericio de entrada y salida 02
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char nombreIngresado[20];

	printf("Ingrese su nombre, un maximo de 20 caracteres:");
	scanf("%s",&nombreIngresado);
	printf("Su nombre es: ");
	printf("%s",nombreIngresado);
	return EXIT_SUCCESS;
}
