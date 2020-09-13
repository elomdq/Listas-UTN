#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "personas.h"

persona subprogramaCrearPersona()
{
    persona aux;

    printf("\nCreando persona");
    printf("\n");
    printf("\n- Ingrese el nombre:");
    fflush(stdin);
    gets(aux.nombre);
    printf("- Ingrese la edad:");
    scanf("%d", &aux.edad);

    return aux;
}

void mostrarPersona(persona p)
{
    printf("\n");
    printf("--------------------------------");
    printf("\nNombre: %s", p.nombre);
    printf("\nEdad: %d", p.edad);
    printf("\n--------------------------------");

    return;
}
