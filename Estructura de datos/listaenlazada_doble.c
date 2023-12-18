#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *anterior;
    struct nodo *siguiente;
} nodo;

typedef struct listadoble
{
    struct nodo *primerNodo;
} listadoble;

void liberarLista(listadoble *lista);
void imprimirLista(listadoble lista);
nodo *crearNodo(int dato);
void agregarAlFinal(listadoble *lista, int dato);

int main()
{
    listadoble lista_ligada_doble;
    lista_ligada_doble.primerNodo = NULL;
    // Agregar nodos al final de la lista
    agregarAlFinal(&lista_ligada_doble, 10);
    agregarAlFinal(&lista_ligada_doble, 20);
    agregarAlFinal(&lista_ligada_doble, 30);

    // Imprimir la lista
    imprimirLista(lista_ligada_doble);

    // Liberar la memoria utilizada por la lista
    liberarLista(&lista_ligada_doble);
}

// Función para crear un nuevo nodo
nodo *crearNodo(int dato)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = dato;
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

// Función para agregar un nodo al final de la lista
void agregarAlFinal(listadoble *lista, int dato)
{
    nodo *nuevoNodo = crearNodo(dato);
    if (nuevoNodo != NULL)
    {
        // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
        if (lista->primerNodo == NULL)
        {
            lista->primerNodo = nuevoNodo;
        }
        else
        {
            // Encontrar el último nodo y agregar el nuevo nodo al final
            nodo *ultimo = lista->primerNodo;
            while (ultimo->siguiente != NULL)
            {
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevoNodo;
            nuevoNodo->anterior = ultimo;
        }
    }
}

// Función para imprimir la lista en ambos sentidos
// Función para imprimir la lista en ambos sentidos
void imprimirLista(listadoble lista)
{
    nodo *actualAdelante = lista.primerNodo;

    printf("Recorrido hacia adelante: ");
    while (actualAdelante != NULL)
    {
        printf("%d -> ", actualAdelante->dato);
        actualAdelante = actualAdelante->siguiente;
    }
    printf("NULL\n");

    // Almacenar el último nodo para imprimir en sentido inverso
    nodo *ultimo = NULL;
    nodo *actualAtras = lista.primerNodo;
    while (actualAtras != NULL)
    {
        ultimo = actualAtras;
        actualAtras = actualAtras->siguiente;
    }

    printf("Recorrido hacia atrás: ");
    while (ultimo != NULL)
    {
        printf("%d -> ", ultimo->dato);
        ultimo = ultimo->anterior;
    }
    printf("NULL\n");
}

// Función para liberar la memoria utilizada por la lista
void liberarLista(listadoble *lista)
{
    nodo *actual = lista->primerNodo;
    nodo *siguiente = NULL;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    lista->primerNodo = NULL;
}