#include <stdio.h>
#include <stdlib.h>
/*
Primero, definimos un nodo
typedef permite simplificar el codigo para usar el nombre de la estructura
como un tipo de dato

Un nodo debe tener un valor, y un puntero hacia un dato tipo nodo, para asi
ir enlazando y crear una lista ligada.

*/
typedef struct node
{
    int value;
    struct node *next;
} node_t;

int main()
{
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    head->value =1;
    head->next = NULL;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->value = 2;
    head->next->next = NULL;
    printf("%d\n", head->value);
    printf("%d\n", head->next->value);
    return 0;
}