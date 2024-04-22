#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 10

typedef struct 
{
    char coche[100];
    float costo_vehiculo;
    float promedio_uso_meses;
    float consumo;
    float costo;
    float kmgalon;
    float viaje;
    
}

 Cliente;

void imprimirCliente(Cliente cliente) 
{
    printf("| %-20s | %-15.2f | %-20.2f | %-15.2f | %-15.2f | %-15.2f | %-15.2f |\n", 
           cliente.coche, cliente.costo_vehiculo, cliente.promedio_uso_meses, 
           cliente.consumo, cliente.costo, cliente.kmgalon, cliente.viaje);
}

int main() 
{
    Cliente cliente_predeterminado = {"", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    printf("============================================================\n");
    printf("| %-20s | %-15s | %-20s | %-15s | %-15s | %-15s | %-15s |\n", 
           "Coche", "Costo Vehiculo", "Promedio Uso Meses", "Consumo (L/Km)", 
           "Costo Combustible", "Consumo (Km/Galon)", "Viaje (Km)");
    printf("============================================================\n");
    imprimirCliente(cliente_predeterminado);

    Cliente clientes[MAX_CLIENTES];
    char opcion;
    int num_clientes = 0;
    char nombre_archivo[100];
    int anos;

    do 
	{
        printf("\n--- Menu ---\n\n");
        printf("1. Agregar nuevo cliente\n");
        printf("2. Ver detalles de todos los clientes\n");
        printf("3. Modificar datos del ultimo cliente\n");
        printf("4. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion);

        switch(opcion)
		 {
	        case '1':
                if (num_clientes < MAX_CLIENTES) 
				{
                    Cliente nuevo_cliente;

                    printf("\nIngrese los datos del nuevo cliente:\n");

                    printf("Nombre o modelo del coche: ");
                    scanf("%s", nuevo_cliente.coche);

                    printf("Costo del vehiculo: ");
                    scanf("%f", &nuevo_cliente.costo_vehiculo);

                    printf("Promedio de uso en meses: ");
                    scanf("%f", &nuevo_cliente.promedio_uso_meses);

                    printf("Consumo de combustible por kilometro (en litros): ");
                    scanf("%f", &nuevo_cliente.consumo);

                    printf("Costo del combustible por litro: ");
                    scanf("%f", &nuevo_cliente.costo);

                    nuevo_cliente.kmgalon = 1 / (nuevo_cliente.consumo / 3.78541);

                    printf("Distancia del viaje (en kilometros): ");
                    scanf("%f", &nuevo_cliente.viaje);

                    printf("Ingrese la cantidad de anos: ");
                    scanf("%d", &anos);
                    

                    // Multiplicar los valores por la cantidad de años
                    nuevo_cliente.costo_vehiculo *= anos;
                    nuevo_cliente.promedio_uso_meses *= anos;
                    nuevo_cliente.consumo *= anos;
                    nuevo_cliente.costo *= anos;
                    nuevo_cliente.viaje *= anos;

                    // Imprimir los detalles del nuevo cliente
                    printf("\nDetalles del nuevo cliente:\n");
                    printf("============================================================\n");
                    imprimirCliente(nuevo_cliente);

                    // Agregar el nuevo cliente al arreglo de clientes
                    clientes[num_clientes] = nuevo_cliente;
                    num_clientes++;

                    // Preguntar si desea guardar los detalles en un archivo de texto
                    printf("Desea guardar los detalles en un archivo de texto? (s/n): ");
                    char guardar;
                    scanf(" %c", &guardar);
                    if (guardar == 's' || guardar == 'S') 
					{
                        printf("Ingrese el nombre del archivo de texto para guardar los detalles: ");
                        scanf("%s", nombre_archivo);

                        // Asegurar que el nombre del archivo termine en ".txt"
                        strcat(nombre_archivo, ".txt");

                        FILE *archivo;
                        archivo = fopen(nombre_archivo, "w");
                        if (archivo == NULL) 
						{
                            printf("Error al abrir el archivo.");
                            return 1;
                        }

                        // Escribir los detalles de cada cliente en el archivo
                        int i;
						for ( i = 0; i < num_clientes; i++) 
						{
                            fprintf(archivo, "Cliente %d:\n", i + 1);
                            fprintf(archivo, "Coche: %s\n", clientes[i].coche);
                            fprintf(archivo, "Costo Vehiculo: %.2f\n", clientes[i].costo_vehiculo);
                            fprintf(archivo, "Promedio Uso Meses: %.2f\n", clientes[i].promedio_uso_meses);
                        
						    fprintf(archivo, "Consumo (L/Km): %.2f\n", clientes[i].consumo);
                            fprintf(archivo, "Costo Combustible: %.2f\n", clientes[i].costo);
                            fprintf(archivo, "Consumo (Km/Galon): %.2f\n", clientes[i].kmgalon);
                            fprintf(archivo, "Viaje (Km): %.2f\n\n", clientes[i].viaje);
                        }

                        fclose(archivo);

                        printf("Informacion de los clientes guardados en '%s'.\n", nombre_archivo);
                    }
                } else 
				{
                    printf("Estos son todos los clientes permitidos.\n");
                }
                break;
            case '2':
                if (num_clientes > 0) 
				{
                    printf("Detalles de todos los clientes:\n");
                    printf("============================================================\n");
                    printf("| %-20s | %-15s | %-20s | %-15s | %-15s | %-15s | %-15s |\n", 
                           "Coche", "Costo Vehiculo", "Promedio Uso Meses", "Consumo (L/Km)", 
                           "Costo Combustible", "Consumo (Km/Galon)", "Viaje (Km)");
                    printf("============================================================\n");
                    int i;
					for ( i = 0; i < num_clientes; i++) {
                        imprimirCliente(clientes[i]);
                    }
                } 
				else 
				{
                    printf("Aun no se han agregado clientes.\n");
                }
                break;
            case '3':
                printf("Esta opcion aun no ha sido implementada.\n");
                break;
            case '4':
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }

    } while (opcion != '4');

    return 0;
}
