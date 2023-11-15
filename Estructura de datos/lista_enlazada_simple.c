#include <stdio.h>
#include <stdlib.h>

// Definir los nodos de una estructura ligada
typedef struct node
{
    int data;
    struct node *next;

} node;

// Definir una estructura para una lista ligada
typedef struct list
{
    struct node *primerNodo;
} list;

// Prototipo de funciones
node *crearNodo(int dato);

int main()
{
    // Crear una nueva lista ligada
    list nuevaLista;
    // Primer nodo apunta a NULL ya que la lista esta vacia
    nuevaLista.primerNodo = NULL;
    // Bucle para llenar la lista
    for (int i = 0; i < 10; i++)
    {
        nuevaLista.primerNodo = insertarFinal()
    }
}

node *crearNodo(int dato)
{
    node *nuevoNodo = (node *)malloc(sizeof(node));
    if (nuevoNodo == NULL)
    {
        printf("ERROR: No se ha podido asignar memoria para el nodo\n");
    }
    // Llenar el nodo con informacion
    nuevoNodo->data = dato;
    nuevoNodo->next = NULL;
    // Retornar el puntero al nodo creado
    return nuevoNodo;
}

node *insertarFinal()