#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct libro
{
    int codigo;
    char autor[20];
    char titulo[20];
} libro;

typedef struct nodo
{
    struct libro *libro;
    struct nodo *siguiente;
} nodo;

typedef struct lista
{
    struct nodo *primerNodo;
} lista;

// Prototipo de funciones
void mostrarMenu();
libro *crearLibro();
void agregarLibro(lista *listaLibros, libro *nuevoLibro, libro *base1, libro *base2);
bool validarCodigo(lista *listaLibros, int codigo);

int main()
{
    lista listaLibros;
    listaLibros.primerNodo = NULL;
    libro *base1 = NULL;
    libro *base2 = NULL;
    int opcion;
    while (1)
    {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1)
        {
            printf("Error: Ingrese un numero valido.\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            while (getchar() != '\n')
                ;
            switch (opcion)
            {
            case 1:
                printf("Ha seleccionado la opcion 1.\n");
                libro *base1 = crearLibro();
                libro *base2 = crearLibro();
                break;
            case 2:
                printf("Ha seleccionado la opcion 2.\n");
                break;
            case 3:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
            }
        }
    }
}

void mostrarMenu()
{
    printf("____________________________\n");
    printf("\tMenu de Opciones:\n");
    printf("____________________________\n");
    printf("1. Ingresar libros\n");
    printf("2. Recorrer libros\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
}

libro *crearLibro()
{
    libro *nuevoLibro = (libro *)malloc(sizeof(libro));
    printf("Ingrese codigo del libro:\n");
    scanf("%d", nuevoLibro->codigo);
    printf("Ingrese autor del libro:\n");
    scanf("%s", nuevoLibro->autor);
    printf("Ingrese titulo del libro:\n");
    scanf("%s", nuevoLibro->titulo);
    return nuevoLibro;
}

void agregarLibro(lista *listaLibros, libro *nuevoLibro, libro *base1, libro *base2)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nodo *nodoActual = listaLibros->primerNodo;
    nuevoNodo->libro = nuevoLibro;
    nuevoNodo->siguiente = NULL;
}

bool validarCodigo(lista *listaLibros, int codigo)
{
    nodo *nodoActual = listaLibros->primerNodo;
    while (nodoActual->siguiente != NULL)
    {
        if (nodoActual->libro->codigo == codigo)
        {
            return false;
        }
        nodoActual = nodoActual->siguiente;
    }
    return true;
}
