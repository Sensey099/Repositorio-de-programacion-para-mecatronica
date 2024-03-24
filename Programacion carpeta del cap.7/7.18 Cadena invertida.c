#include <stdio.h>

/* Cadena invertida resuelta en forma recursiva. */

void inverso(char *);

void main(void) 
{
    char fra[50];
    printf("\nIngrese la l�nea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0'; // Eliminar el car�cter de nueva l�nea en fra

    printf("Escribe la l�nea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0') 
	{
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}

