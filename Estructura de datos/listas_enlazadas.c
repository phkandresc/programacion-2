#include <stdio.h>
#include <stdlib.h>
/*
Primero, definimos un nodo
typedef permite simplificar el codigo para usar el nombre de la estructura
como un tipo de dato

Un nodo debe tener un valor, y un puntero hacia un dato tipo nodo, para asi
ir enlazando y crear una lista ligada.

*/

// ESTRUCTURA TIPO NODO
typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t *create_node(int value); // prototipo de funcion
node_t *insertAtEnd(node_t *head, int value);
void printList(node_t *head);
void freeList(node_t *head);

int main()
{
    node_t *head = NULL; // inicializamos como NULL ya que todavia no tenemos ningun nodo al que apuntar
    
    for(int i=0 ; i<=10; i++){
        head= insertAtEnd(head, i);
    }
    printList(head);
    freeList(head);
    system("pause");
}

// PROCEDIMIENTO PARA CREAR UN NODO
/*
Declaramos una funcion que cree un nuevo nodo en la memoria
heap, y nos devuelva la direccion de memoria del nodo creado

Para esto utilizaremos una funcion que devuelva un puntero de
tipo nodo.
*/
node_t *create_node(int value)
{
    /*
    new_node va a almacenar la direccion de memoria de un nodo nuevo
    */
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("ERROR: No se ha podido asignar memoria para el nodo\n");
    }
    new_node->value = value;
    new_node->next = NULL;
    printf("NODO CREADO, valor: %d\n", new_node->value);
    return new_node; // retorna la direccion de memoria del nodo creado
                     // recordemos que este nodo es un nodo "suelto"
                     // todavia no esta enlazado a ninguna lista
}

node_t *insertAtEnd(node_t *head, int value)
{
    // creamos un puntero a un nodo
    // almacenamos la direccion del nodo creado
    node_t *new_node = create_node(value);
    if (head == NULL)
    {
        // Evaluamos si head apunta a NULL lo que quiere decir es que
        // si head apunta a NULL estariamos creando el primero elemento
        // de la lista
        // entonces retornamos la direccion del nodo correspondiente
        // al primer elemento de la lista
        return new_node;
    }
    // Si head no apunta a NULL quiere decir que ya hay mas nodos en la lista
    // por lo que vamos a recorrer la lista hasta encontrar el ultimo empezando desde el head que siempre apunta al primer elemento
    // elemento
    node_t *current = head; // puntero a la direccion de memoria a la que apunta head, osea current apunta al primer nodo de la lista
    while (current->next != NULL){
        current=current->next;
    }
    //cuando encontremos el ultimo elemento de la lista current-> va a ser NULL
    //entonces almacenamos en el nodo la direccion de memoria del siguiente nodo
    current->next=new_node;
    //head no cambia y es el acceso a la lista, asi que no se debe perder y debe retornar para ser
    //reutilizado
    return head;
}

void printList(node_t *head){
    node_t *current = head;
    while (current->next!=NULL)
    {
        printf("[%d]\n", current->value);
        current=current->next;
    }
    printf("[%d]\n", current->value);
}
void freeList(node_t *head){
    while (head!=NULL)
    {
        //vamos a eliminar desde el primer elemento hasta el ultimo
        node_t *current = head;//almacenamos la direccion del primer nodo en un puntero
        head=head->next;//ahora head va a apuntar al siguiente elemento de la lista
        free(current);//podemos eliminar el elemento que antes era el head
        //y asi hasta que head apunte a NULL
    }
    printf("Lista limpiada correctamente.\n");
}