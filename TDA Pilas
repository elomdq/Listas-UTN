#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "personas.h"
#include "nodos.h"
#include "pilaLista.h"

void inicPila(Pila *p)
{
    *p = inicLista();

    return;
}

void apilar(Pila * p, persona aux)
{
    subProgramaAgregarPersonaALista(p, aux);

    return;
}

persona tope(Pila *p)
{
    return (*p)->dato;
}

bool pilaVacia(Pila *p)
{
    bool flag = 1;

    if(*p != NULL)
    {
        flag=0;
    }

    return flag;
}

persona desapilar(Pila *p)
{
    nodo * aux = *p; //guardo la dir de memoria del primer nodo de la lista (tope de pila)
    persona auxPersona = (*p)->dato; //guardo los datos del nodo

    *p = (*p)->siguiente; //cambio la dir de memoria de la lista al nodo siguiente

    free(aux); //elimino el nodo que desapilo

    return auxPersona;
}

void leer(Pila *p)
{
    persona auxPer = subprogramaCrearPersona();
    subProgramaAgregarPersonaALista(p, auxPer);

    return;
}

void mostrar(Pila *p)
{
    printf("\n***********************************");
    printf("\n                TOPE");
    printf("\n***********************************");

    recorrerYmostrar((*p));

    printf("\n***********************************");
    printf("\n                BASE");
    printf("\n***********************************");

    return;
}


// Subprogramas

void subProgramaAgregarPersonaALista(nodo ** lista, persona perAux)
{
    nodo * nodoAux = crearNodo(perAux);
    *lista = agregarNodoPpioLista(*lista, nodoAux);

    return;
}
