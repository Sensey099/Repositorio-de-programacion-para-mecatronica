#include <stdio.h>

/* Cuenta-numeros.
El programa, al recibir como datos un arreglo unidimencional de tipo
entero y un numero entero, determina cuantas veces se muestra el
numero en el areglo. */

void main(void)
{
	int I, NUM, CUE = 0;
	int ARRE[100];
	for (I=0; I<100; I++)			/*Declaracion del areglo */
 {
 	printf("Ingrese el elemento %d del areglo: ", I+1);
 	scanf("%d", &ARRE[I]);			/* Lectura -asignacion-- del arreglo */
 }
 printf("\n\nIngrese el numero que se va a buscar en el arreglo: ");
 scanf("%d", &NUM);
 for (I=0; I<100; I++)
 if (ARRE[I] == NUM)	/* Comparacion del numero con los elementos del arreglo */
 CUE++;
 printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
}
