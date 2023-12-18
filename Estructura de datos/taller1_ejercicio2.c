#include <stdio.h>
#include <stdlib.h>

typedef struct numero
{
    int entero;
    float decimal;
} numero;

typedef struct nodo
{
    struct numero numero;
    struct nodo *siguiente;
} nodo;

typedef struct lista
{
    struct nodo *primerNodo;
} lista;
nodo *crearNodo(numero nuevo_numero);
nodo *insertarFinal(lista *listaEnteros, lista *listaReales, numero nuevo_numero);
void recorrerLista(lista *listaEnteros, lista *listaReales);

int main()
{
    numero nuevo_numero;
    lista listaEnteros;
    lista listaReales;
    listaReales.primerNodo = NULL;
    listaEnteros.primerNodo = NULL;
    printf("Ingrese un numero real:\n");
    scanf("%f", &nuevo_numero.decimal);
    nuevo_numero.entero = (int)nuevo_numero.decimal;
    nuevo_numero.decimal = nuevo_numero.decimal - nuevo_numero.entero;
    if (nuevo_numero.decimal == 0)
    {
        listaEnteros.primerNodo = insertarFinal(&listaEnteros, &listaReales, nuevo_numero);
    }
    else
    {
        listaReales.primerNodo = insertarFinal(&listaEnteros, &listaReales, nuevo_numero);
    }
    recorrerLista(&listaEnteros, &listaReales);
    return 0;
}

nodo *crearNodo(numero nuevo_numero)
{
    nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
    if (nuevo_nodo == NULL)
    {
        printf("ERROR: No se ha podido asignar memoria para el nodo\n");
    }
    nuevo_nodo->numero = nuevo_numero;
    nuevo_nodo->siguiente = NULL;

    return nuevo_nodo;
}

nodo *insertarFinal(lista *listaEnteros, lista *listaReales, numero nuevo_numero)
{
    nodo *nuevo_nodo = crearNodo(nuevo_numero);

    if (listaEnteros->primerNodo == NULL || listaReales->primerNodo == NULL)
    {
        return nuevo_nodo;
    }
    if (nuevo_nodo->numero.decimal == 0)
    {
        nodo *actual = listaEnteros->primerNodo;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        return listaEnteros->primerNodo;
    }
    else
    {
        nodo *actual = listaReales->primerNodo;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        return listaReales->primerNodo;
    }
}

void recorrerLista(lista *listaEnteros, lista *listaReales)
{

    nodo *actual1 = listaEnteros->primerNodo;
    printf("Lista de Enteros\n");
    while (actual1 != NULL)
    {
        printf("[%d]\n", actual1->numero.entero);
        actual1 = actual1->siguiente;
    }
    nodo *actual2 = listaReales->primerNodo;
    printf("Lista de Reales\n");
    while (actual2 != NULL)
    {
        printf("[%f]\n", actual2->numero.decimal);
        actual2 = actual2->siguiente;
    }
}