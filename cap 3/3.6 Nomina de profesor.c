#include <stdio.h>

/* Nomina de profesor.
El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.

I: variables de tipo entero.
SAL, NOM y PRO: variables de tipo real. */

void main(void)
{
	int I = 0;
	float SAL, PRO, NOM = 0;
	printf("Ingrese el salario del profesor:\t");
	
	/* Observa que al menos se necesita ingresar el salario de un profesor para que
	no ocurra un erro de ejecucion del programa. */
	scanf("%f, &SAL");
{
	NOM = NOM + SAL;
	I = I + 1;
	printf("Ingrese el salario del profewsor -0 para terminar- :\t");
	scanf("%f", &SAL);
}

	while (SAL);
	PRO = NOM / I;
	printf("\nNomina: %.2f \t promedio de salarios: %.2f", NOM, PRO);
}
