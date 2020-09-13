#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "personas.h"
#include "nodos.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo *) malloc(sizeof(nodo));

    (*aux).dato = dato;

    (*aux).siguiente = NULL;

    return aux; // Estoy retornando la dir de memoria que almacena el ptro. aux (que sería la dir de la variable anonima generada con malloc)
}

nodo * agregarNodoPpioLista(nodo * lista, nodo * nuevoNodo) //debo pasar parametro por valor ya que necesito la dir de memoria a la que apuntan esos punteros, y no la dir de memoria de esos punteros.
{
    if(lista == NULL)
    {
        lista = nuevoNodo; // asigno a lista una nueva dir de memoria que es a la que apunta nuevoNodo (que seria de la variable anonima donde tenemos los datos a agregar)
    }
    else
    {
        (*nuevoNodo).siguiente = lista; // asigno a la varable anonima que apunta nuevoNodo, a la variable siguiente de su struct, la dir de memoria a la que apuntaba lista.
        lista = nuevoNodo;
    }

    return lista; // retorno la nueva dir de memoria a la que apunta lista
}

nodo * buscarUltimoNodo(nodo * lista) //podría trabajar directamente con la variable declarada en parametro pero para mejor visualizacion creo un ptro ultimo y trabajo con este.
{
    nodo * ultimo = lista; // le asigno al ptro. ultimo la dir a la que apunta la lista

    if(ultimo != NULL)
    {
        while(ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;
        }
    }

    return ultimo;
}

nodo * buscarNodoPorNombre(nodo * lista,  char nombre[20])
{
    nodo * nodoActual; //representa el nodo en el que estamos parados revisando el nombre

    nodoActual = lista; //le asigno la dir de memoria a la que apunta lista que es el 1er nodo de la lista

    while( (nodoActual != NULL) && (strcmp(nombre, nodoActual->dato.nombre)!=0) ) //reviso que mi puntero nodoActual este apuntando a un nodo y si dsp el nombre es igual al buscado, si no lo es sigo el ciclo
    {
        nodoActual = nodoActual->siguiente;
    }

    return nodoActual;
}

nodo * agregarNodoFinalLista(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimoNodo(lista);
        ultimo->siguiente = nuevoNodo; // modifico el valor del puntero "siguiente" del ultimo nodo de la lista, de esta manera pasa a apuntar a el nuevoNodo
    }

    return lista;
}

nodo * borrarNodoPorNombre(nodo * lista, char nombre[20])
{
    nodo * nodoActual; //nodo en el que estoy parado
    nodo * nodoAnterior; //nodo anterior al que estoy parado

    if((lista!=NULL) && strcmp(nombre, lista->dato.nombre)==0) //Reviso si el 1er nodo es el correcto, si es asi ejecuto las sentencias siguientes
    {
        nodoActual = lista;
        lista = lista->siguiente; // aca hago que la lista apunte al nodo siguiente del actual, que en este caso seria el primero de la lista
        free(nodoActual); // elimino la informacion del espacio de memoria usado para ese nodo y lo habilito para futuros usos
    }
    else
    {
        nodoActual = lista;

        while( (nodoActual!=NULL) && (strcmp(nombre, nodoActual->dato.nombre)!=0) ) // si nodoActual apunta a un nodo y ese nodo al que apunta no es igual al nombre buscado entonces sigo avanzando
        {
            nodoAnterior = nodoActual; // aca guardo la dir de memoria del nodoActual que pasara a ser anterior ya que voy a avanzar a otro noto
            nodoActual = nodoActual->siguiente; // cambio la dir de memoria a la que apunta nodoActual por la del siguiente nodo
        }

        if(nodoActual!=NULL) //cheque que si sali del while anterior no haya sido porque termine de revisar toda la lista y no encontré nada
        {
            nodoAnterior->siguiente = nodoActual->siguiente; //asigno al puntero siguiente del nodo anterior el valor de la dir de memoria del nodo al que apuntaba el nodoActual que ahora vamos a borrar.
            free(nodoActual);
        }
    }

    return lista;
}

nodo * agregarEnOrdenPorNombre(nodo * lista, nodo * nuevoNodo)
{
    nodo * nodoActual = lista; //nodo en el que estoy parado
    nodo * nodoAnterior; //nodo anterior al que estoy parado

    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmp(nuevoNodo->dato.nombre, lista->dato.nombre)<0) //Reviso el 1er nodo de la lista, para saber si el nombre del nuevo nodo es menor que el 1ero
        {
            lista = agregarNodoPpioLista(lista, nuevoNodo); //llamo a la funcion agregar nodo al principio de lista
        }
        else
        {
            while( (nodoActual!=NULL) && (strcmp(nuevoNodo->dato.nombre,nodoActual->dato.nombre)>0) ) //si el nodoActual apunta a algun nodo y nombre de persona del nuevoNodo es mayor que el del actualNodo, entonces sigo avanzando
            {
                nodoAnterior = nodoActual; //voy guardando la dir de memoria del nodoActual que al avanzar se ira convirtiendo en el anterior
                nodoActual = nodoActual->siguiente; //avanzo al siguiente nodo de la lista
            }

            nuevoNodo->siguiente = nodoActual; //una vez que salgo del ciclo agrego el nuevoNodo, el cual siempre tendra que apuntar al ultimo nodo apuntado en el anterior ciclo
            nodoAnterior->siguiente = nuevoNodo; //con esta sentencia corrigo el puntero del nodo anterior al ex nodoActual para que apunte al recien insertado nuevoNodo
        }
    }

    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * nodoActual = lista; //nodo en el que estoy parado
    nodo * nodoSiguiente; //nodo siguiente al que estoy parado

    while(nodoActual!=NULL)
    {
        nodoSiguiente = nodoActual->siguiente; // guardo la dir de memoria del nodo siguiente al que voy a borrar para no perder el lazo
        free(nodoActual); // borro el nodo
        nodoActual = nodoSiguiente; // actualiza la posicion de mi nodo actual (AKA cambio la dir de memoria)
    }

    return nodoActual; //devuelvo el valor de nodoActual que sera NULL
}

int sumarEdadesLista(nodo * lista)
{
    int suma=0;

    nodo * nodoActual = lista;

    while(nodoActual!=NULL)
    {
        suma = suma + nodoActual->dato.edad;
        nodoActual = nodoActual->siguiente;
    }

    return suma;
}

nodo * eliminarPrimerNodo(nodo * lista)
{
    nodo * nodoActual = lista;

    if(nodoActual!=NULL)
    {
        lista = nodoActual->siguiente;
        free(nodoActual);
    }

    return lista;
}

nodo * eliminarUltimoNodo(nodo * lista)
{
    nodo * nodoActual = lista;
    nodo * nodoAnterior;

    if(nodoActual!=NULL)
    {
        if(nodoActual->siguiente==NULL)
        {
            lista = nodoActual->siguiente;
        }
        else
        {
            while(nodoActual->siguiente!=NULL)
            {
                nodoAnterior = nodoActual;
                nodoActual = nodoActual->siguiente;
            }

            nodoAnterior->siguiente = nodoActual->siguiente;
        }

        free(nodoActual);
    }

    return lista;
}

void mostrarUnNodo(nodo * aux)
{
    printf("\n-----------------------------------");
    printf("\n  Nombre: %s", aux->dato.nombre);
    printf("\n  Edad: %d", aux->dato.edad);
    printf("\n-----------------------------------");

    return;
}

void recorrerYmostrar(nodo * lista)
{
    nodo * nodoActual = lista;

    while(nodoActual!=NULL)
    {
        mostrarUnNodo(nodoActual);
        nodoActual = nodoActual->siguiente;
    }

    return;
}

nodo * desvincularPrimerNodo(nodo **lista) //paso la dir de memoria del puntero lista ¡¡OJO!!
{
    nodo * aux=NULL;

    if((*lista)!=NULL) //chequeo que la lista que pase por parametro no apunte a NULL
    {
        aux = *lista; // mi nodo auxiliar apunta al nodo a desvincular (el primer nodo de la lista)
        *lista = (*lista)->siguiente; // es lo mismo que (**lista).siguiente
        aux->siguiente = NULL; // el nodo desvinculado lo hago apuntar a nada, NULL

    }

    return aux;
}
