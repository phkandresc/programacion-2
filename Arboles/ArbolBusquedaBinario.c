#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *r;
    struct node *l;
    int val;
} node;

node *createNode(int value);
void insertNode(node *current, int value);
void insert(node **root, int value);
bool contains(node *root, int value);
node *findParent(node *root, int value);
bool delete(node **root, int value);
node *findNode(node *root, int value);
int numberNodes(node *root);

int main()
{
    /*
    Puntero a un dato tipo nodo
    Se "inicializa el arbol"
    */
    node *root = NULL;
    insert(&root, 23);
    insert(&root, 31);
    insert(&root, 14);
    insert(&root, 17);
    insert(&root, 7);
    insert(&root, 9);
    printf("Arbol ingresado\n");
    bool located = contains(root, 1);
    if (!delete (&root, 22))
    {
        printf("no se ha podido eliminar el nodo\n");
    }
    else
    {
        printf("se ha eliminado el nodo\n");
    }

    system("pause");
    return 0;
}

void insert(node **root, int value)
{
    if (*root == NULL)
    {
        *root = createNode(value);
    }
    else
    {
        insertNode(*root, value);
    }
}

void insertNode(node *current, int value)
{
    if (value < current->val)
    {
        if (current->l == NULL)
        {
            current->l = createNode(value);
        }
        else
        {
            insertNode(current->l, value);
        }
    }
    else
    {
        if (current->r == NULL)
        {
            current->r = createNode(value);
        }
        else
        {
            insertNode(current->r, value);
        }
    }
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = value;
    newNode->l = newNode->r = NULL;
    return newNode;
}
/*
 Funcion para realizar la busqueda de un valor dentro del arbol, recibe como parametros un puntero a la raiz del arbol. No es un puntero de un puntero ya que no se necesita hacer cambios en el root.
*/
bool contains(node *root, int value)
{
    if (root == NULL)
    {
        printf("Valor no encontrado\n");
        return false;
    }
    if (root->val == value)
    {
        printf("Valor encontrado\n");
        return true;
    }
    else if (value < root->val)
    {
        return contains(root->l, value);
    }
    else
    {
        return contains(root->r, value);
    }
}

// funcion que permite remover un nodo
bool delete(node **root, int value)
{
    int count = numberNodes(*root);
    node *nodetoRemove = findNode(*root, value);
    if (nodetoRemove == NULL)
    {
        // El valor no ha sido encontrado en el arbol
        return false;
    }
    node *parent = findParent(*root, value);
    if (count == 1)
    {
        *root = NULL;
    }
    else if (nodetoRemove->l == NULL && nodetoRemove->r == NULL)
    {
        if (nodetoRemove->val < parent->val)
        {
            parent->l = NULL;
        }
        else
        {
            parent->r = NULL;
        }
    }
    else if (nodetoRemove->l == NULL && nodetoRemove->r != NULL)
    {
        if (nodetoRemove->val < parent->val)
        {
            parent->l = nodetoRemove->r;
        }
        else
        {
            parent->r = nodetoRemove->r;
        }
    }
    else if (nodetoRemove->l != NULL && nodetoRemove->r == NULL)
    {
        if (nodetoRemove->val < parent->val)
        {
            parent->l = nodetoRemove->l;
        }
        else
        {
            parent->r = nodetoRemove->l;
        }
    }
    else
    {
        // case 4
        node *largestValue = nodetoRemove->l;
        while (largestValue->r != NULL)
        {
            largestValue = largestValue->r;
        }
        parent = findParent(*root, largestValue->val);
        parent->r = NULL;
        nodetoRemove->val = largestValue->val;
    }
    return true;
}

// Funcion que retorna un puntero al nodo padre de un nodo con el valor buscado
node *findParent(node *root, int value)
{
    if (value == root->val)
    {
        return NULL;
    }
    if (value < root->val)
    {
        if (root->l == NULL)
        {
            return NULL;
        }
        else if (root->l->val == value)
        {
            return root;
        }
        else
        {
            return findParent(root->l, value);
        }
    }
    else
    {
        if (root->r == NULL)
        {
            return NULL;
        }
        else if (root->r->val == value)
        {
            return root;
        }
        else
        {
            return findParent(root->r, value);
        }
    }
}

// Funcion que busca un nodo en el arbol y retorna un puntero a dicho nodo
node *findNode(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == value)
    {
        return root;
    }
    else if (value < root->val)
    {
        return findNode(root->l, value);
    }
    else
    {
        return findNode(root->r, value);
    }
}

// Función para contar el número de nodos en un árbol
int numberNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Contar los nodos en el subárbol izquierdo y derecho
        int left = numberNodes(root->l);
        int right = numberNodes(root->r);

        // Sumar el nodo actual y los nodos en los subárboles
        return 1 + left + right;
    }
}