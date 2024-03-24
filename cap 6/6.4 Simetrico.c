#include <stdio.h>

const int MAX = 100;

void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

int main(void) {
    int MAT[MAX][MAX], N, RES;
    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &N);
    } while (N > MAX || N < 1);

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es sim�trico");
    else
        printf("\nEl arreglo bidimensional no es sim�trico");

    return 0;
}

void Lectura(int A[][MAX], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        for (J = 0; J < T; J++) {
            printf("Fila: %d\tColumna: %d ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

int Simetrico(int A[][MAX], int T) {
    int I, J, F = 1;
    for (I = 0; I < T; I++) {
        for (J = 0; J < I; J++) {
            if (A[I][J] != A[J][I]) {
                F = 0;
                break;
            }
        }
        if (!F) {
            break;
        }
    }
    return F;
}
