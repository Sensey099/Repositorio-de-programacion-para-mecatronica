#include <stdio.h>

#define MAX 100

void Lectura(int A[], int T);
int Busca(int A[], int T, int K);

int main() {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);  /* Se verifica que el tama�o del arreglo sea correcto. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);  /* Se llama a la funci�n que busca en el arreglo. */

    if (RES) {  /* Si RES tiene un valor verdadero (diferente de 0), se escribe la posici�n en la que se encontr� el elemento. */
        printf("\nEl elemento se encuentra en la posici�n %d", RES);
    } else {
        printf("\nEl elemento no se encuentra en el arreglo");
    }

    return 0;
}

void Lectura(int A[], int T) {
    int I;

    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int K) {
    int I = 0, BAN = 0, RES;

    while (I < T && !BAN) {
        if (A[I] == K) {
            BAN++;
        }
        I++;
    }

    if (BAN) {
        RES = I;  /* Se asigna I debido a que las posiciones en el arreglo comienzan desde cero. */
    } else {
        RES = BAN;
    }

    return RES;
}
