/*
 ============================================================================
 Name        : sábados_clase_01_ejercicio_01_03.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : 26/03/2022
 Copyright   : 
 Description : Ejercicio 3 de la Clase 1 de los Sábados.
 ============================================================================
 */

/*Enunciado:
Realizar el algoritmo que permita ingresar los datos de los alumnos
de una división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	//variables de ingreso;
	int 	numeroLegajoIngresado;
	char 	tipoDeCursada;
	int		cantidadMateriasIngresadas;
	char 	generoIngresado;
	int 	notaPromedioIngresada;
	int 	edadIngreda;
	char	confirmarVueltas;

	//variables internas
	int		contadorMasculino;
	int		contadorFemenino;
	int		contadorNoBinario;
	int		banderaMejorPromedioFemenino;
	float	mejorPromedioFemenino;
	int		legajoMejorPromedioFemenino;
	int		banderaMasculinoMasJoven;
	int		edadMasculinoJoven;
	int		legajoMasculinoJoven;
	int		acumuladorNotaMasculino;
	int		acumuladorNotaFemenino;
	int		acumuladorNotaNoBinario;
	float 	promedioNotaMasculino;
	float	promedioNotaFemenino;
	float	promedioNotaNoBinario;
	int		banderaMasMaterias;
	int		materiasDeBandera;
	int		edadMasMaterias;
	int		legajoMasMaterias;


	//Inicialización de las variables
	confirmarVueltas='s';
	contadorMasculino=0;
	contadorFemenino=0;
	contadorNoBinario=0;
	banderaMejorPromedioFemenino=1;
	banderaMasculinoMasJoven=1;
	acumuladorNotaMasculino=0;
	acumuladorNotaFemenino=0;
	acumuladorNotaNoBinario=0;
	banderaMasMaterias=1;

	printf("\n BIENVENIDOS AL PROGRAMA DE LEGAJOS DE UTNFRA \n");

	while(confirmarVueltas=='s')
	{
		printf("Ingrese el numero de legajo:");
		scanf("%d", &numeroLegajoIngresado);
		while(numeroLegajoIngresado<1||numeroLegajoIngresado>1000)
		{
			printf("Error, un numero de legajo mayor a 1 \n");
			printf("Reingrese el numero de legajo:");
			scanf("%d", &numeroLegajoIngresado);
		}
		__fpurge(stdin);
		printf("Ingrese el tipo de cursada del alumno:");
		scanf("%c", &tipoDeCursada);
		while(tipoDeCursada!='L'&&tipoDeCursada!='P'&&tipoDeCursada!='R')
		{
			__fpurge(stdin);
			printf("Error, ingrese: L = libre, P= presencial, R= remoto \n");
			printf("Reingrese un tipo de cursada valida:");
			scanf("%c", &tipoDeCursada);
		}
		printf("Ingrese la cantidad de materias:");
		scanf("%d", &cantidadMateriasIngresadas);
		while(cantidadMateriasIngresadas<1||cantidadMateriasIngresadas>8)
		{
			printf("Error, debe ingresar un número de materias entre 1 y 8 \n");
			printf("Reingrese el numero de materias:");
			scanf("%d", &cantidadMateriasIngresadas);
		}
		__fpurge(stdin);
		printf("Ingrese el género del alumno:");
		scanf("%c", &generoIngresado);
		while(generoIngresado!='M'&&generoIngresado!='F'&&generoIngresado!='O')
		{
			__fpurge(stdin);
			printf("Error, ingrese: M = masculino, F= femenino, O= no binario \n");
			printf("Reingrese el género del alumno:");
			scanf("%c", &generoIngresado);
		}
		printf("Ingrese la nota promedio:");
		scanf("%d", &notaPromedioIngresada);
		while(notaPromedioIngresada<0||notaPromedioIngresada>10)
		{
			printf("Error, debe ingresar una nota entre 0 y 10 \n");
			printf("Reingrese la nota promedio:");
			scanf("%d", &notaPromedioIngresada);
		}
		printf("Ingrese la edad del alumno:");
		scanf("%d", &edadIngreda);
		while(edadIngreda<18||edadIngreda>100)
		{
			printf("Error, debe ingresar una edad entre 18 y 100 \n");
			printf("Reingrese la edad del alumno:");
			scanf("%d", &edadIngreda);
		}
		switch(generoIngresado)
		{
		case 'M':
			contadorMasculino=contadorMasculino+1;
			acumuladorNotaMasculino=acumuladorNotaMasculino+notaPromedioIngresada;
			if(banderaMasculinoMasJoven==1)
			{
				edadMasculinoJoven=edadIngreda;
				legajoMasculinoJoven=numeroLegajoIngresado;
				banderaMasculinoMasJoven=0;
			}
			else
			{
				if(edadMasculinoJoven<edadIngreda)
				{
					edadMasculinoJoven=edadIngreda;
					legajoMasculinoJoven=numeroLegajoIngresado;
				}
			}
		break;
		case 'F':
			contadorFemenino=contadorFemenino+1;
			acumuladorNotaFemenino=acumuladorNotaFemenino+notaPromedioIngresada;
			if(banderaMejorPromedioFemenino==1)
			{
				mejorPromedioFemenino=notaPromedioIngresada;
				legajoMejorPromedioFemenino=numeroLegajoIngresado;
				banderaMejorPromedioFemenino=0;
			}
			else
			{
				if(notaPromedioIngresada>mejorPromedioFemenino)
				{
					mejorPromedioFemenino=notaPromedioIngresada;
					legajoMejorPromedioFemenino=numeroLegajoIngresado;
				}
			}
		break;
		default :
			contadorNoBinario=contadorNoBinario+1;
			acumuladorNotaNoBinario=acumuladorNotaNoBinario+notaPromedioIngresada;
		break;
		}
		if(banderaMasMaterias==1)
		{
			materiasDeBandera=cantidadMateriasIngresadas;
			legajoMasMaterias=numeroLegajoIngresado;
			edadMasMaterias=edadIngreda;
			banderaMasMaterias=0;
		}
		else
		{
			if(cantidadMateriasIngresadas<materiasDeBandera)
			{
				materiasDeBandera=cantidadMateriasIngresadas;
				legajoMasMaterias=numeroLegajoIngresado;
				edadMasMaterias=edadIngreda;
			}
		}
		__fpurge(stdin); //stdin es standard input, entrada estandard
		printf("¿desean continuar? s/n: \n");
		scanf("%c", &confirmarVueltas);
	}
	if(contadorMasculino>0)
	{
		printf("La edad del masculino más jóven es:: %d \n",edadMasculinoJoven);
		printf("Corresponde al legajo: %d \n",legajoMasculinoJoven);
		if(contadorMasculino>1)
		{
			promedioNotaMasculino=(float)acumuladorNotaMasculino/contadorMasculino;
			printf("El promedio de notas de los alumnos sexo masculino es: %2.f \n",promedioNotaMasculino);
		}
		else
		{
			printf("No se cargaron alumnos masculino suficientes para mostrar el promedio de notas. \n");
		}
	}
	else
	{
		printf("No se cargaron alumnos masculino para mostrar el más jóven. \n");
		printf("No se cargaron alumnos masculino para mostrar el promedio de notas. \n");
	}
	if(contadorFemenino>0)
	{
		printf("El mejor promedio Femenino es de: %.2f \n",mejorPromedioFemenino);
		printf("Corresponde al legajo: %d \n",legajoMejorPromedioFemenino);
		if(contadorFemenino>1)
		{
			promedioNotaFemenino=(float)acumuladorNotaFemenino/contadorFemenino;
			printf("El promedio de notas de los alumnos sexo femenino es: %2.f \n",promedioNotaFemenino);
		}
		else
		{
			printf("No se cargaron alumnos femeninos suficientes para mostrar el promedio de notas. \n");
		}
	}
	else
	{
		printf("No se cargaron alumnos femeninos para la alumna con mejor nota. \n");
		printf("No se cargaron alumnos femeninos para mostrar el promedio de notas. \n");
	}
	if(contadorNoBinario>1)
	{
		promedioNotaNoBinario=(float)acumuladorNotaNoBinario/contadorNoBinario;
		printf("El promedio de notas de los alumnos sexo no binario es: %2.f \n",promedioNotaNoBinario);
	}
	else
	{
		printf("No se cargaron alumnos no binarios suficientes para mostrar el promedio para mostrar el promedio de notas. \n");
	}

	printf("El número de legajo con más materias es: %d \n", legajoMasMaterias);
	printf("La edad del alumno con más materias es: %d \n", edadMasMaterias);
	printf("La cantidad de materias del alumno es: %d \n", materiasDeBandera);

	printf("\n FINALIZO EL PROGRAMA");
	return EXIT_SUCCESS;
}
