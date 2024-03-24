#include <stdio.h>

/* Prueba de parametros por referencia. */

void f1(int *);
/* Prototipo de funcion. El parametro es de tipo entero y por referencia
observa el uso del operador de indiereccion. */

int main(void)
{
	int I, K = 4;
	for (I = 1; I <= 3; I++)
{
printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
printf("\nValor de K despues de llamar a la funcion: %d", (&K));
/* Llamada a la funcion f1. se pasa la direccion de la variable K,
por medio del operador de direccion: &	*/
}
return 0;
}
void f1(int *R)
/* La funcion recibe f1 un parametro por referencia. Cada vez que el
parametro se utliza en la funcion debe ir promedio por el operador
de indireccion. */
{
	*R += *R;
}
