#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estudiante
{
    char nombre[20];
    char apellido[20];
    char cedula[20];
    char edad[3];
    char tipo_sangre[5];
} estudiante;

typedef struct nodo
{
    struct estudiante estudiante;
    struct nodo *siguiente;
} nodo;

typedef struct lista
{
    struct nodo *primerNodo;
} lista;

void recorrerLista(lista *listaEstudiantes);
nodo *crear_nodo();
nodo *insertarFinal(lista *listaEstudiantes);

int main()
{
    lista listaEstudiantes;
    listaEstudiantes.primerNodo = NULL;
    listaEstudiantes.primerNodo = insertarFinal(&listaEstudiantes);
    recorrerLista(&listaEstudiantes);
    liberarMemoria(&listaEstudiantes);
    return 0;
}

nodo *crear_nodo()
{
    nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
    if (nuevo_nodo == NULL)
    {
        printf("ERROR: No se ha podido asignar memoria para el nodo\n");
    }
    printf("Ingrese nombre de estudiante:\n");
    scanf("%s", nuevo_nodo->estudiante.nombre);
    printf("Ingrese apellido de estudiante:\n");
    scanf("%s", nuevo_nodo->estudiante.apellido);
    printf("Ingrese cedula de estudiante:\n");
    scanf("%s", nuevo_nodo->estudiante.cedula);
    printf("Ingrese edad de estudiante:\n");
    scanf("%s", nuevo_nodo->estudiante.edad);
    printf("Ingrese tipo de sangre de estudiante:\n");
    scanf("%s", nuevo_nodo->estudiante.tipo_sangre);
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

nodo *insertarFinal(lista *listaEstudiantes)
{
    nodo *nuevo_nodo = crear_nodo();
    if (listaEstudiantes->primerNodo == NULL)
    {
        return nuevo_nodo;
    }
    nodo *actual = listaEstudiantes->primerNodo;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo_nodo;
    return listaEstudiantes->primerNodo;
}

void recorrerLista(lista *listaEstudiantes)
{
    nodo *actual = listaEstudiantes->primerNodo;
    while (actual != NULL)
    {
        printf("[%s]\n", actual->estudiante.nombre);
        printf("[%s]\n", actual->estudiante.apellido);
        printf("[%s]\n", actual->estudiante.edad);
        printf("[%s]\n", actual->estudiante.cedula);
        printf("[%s]\n", actual->estudiante.tipo_sangre);
        actual = actual->siguiente;
    }
}

void liberarMemoria(lista *listaEstudiantes)
{
    nodo *actual = listaEstudiantes->primerNodo;
    while (actual != NULL)
    {
        nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    listaEstudiantes->primerNodo = NULL;
}

void recorrerLista(lista *listaEstudiantes)
{
    nodo *actual = listaEstudiantes->primerNodo;
    while (actual != NULL)
    {
        printf("[%s]\n", actual->estudiante.nombre);
        printf("[%s]\n", actual->estudiante.apellido);
        printf("[%s]\n", actual->estudiante.edad);
        printf("[%s]\n", actual->estudiante.cedula);
        printf("[%s]\n", actual->estudiante.tipo_sangre);
        actual = actual->siguiente;
    }
}