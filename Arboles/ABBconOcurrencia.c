#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *right;
    struct node *left;
    int val;
    int ocurrencia;
} node;

int mostrarMenu(int numOpciones, char opciones[][30]);
// Funciones para crear un nodo y agregarlo al arbol
node *createNode(int);
void insert(node **root, int);
void insertNode(node *current, int value);
// Funcion de recorrido
void inOrder(node *root);
// Funcion para buscar un nodo en el arbol
node *findNode(node *root, int value);
// funcion que permite remover un nodo
bool delete(node **root, int value);
// Funcion que retorna un puntero al nodo padre de un nodo con el valor buscado
node *findParent(node *root, int value);

int main()
{
    int numOpciones = 4;
    int opc, value;
    char opciones[][30] = {"Insertar nodo", "Recorrer arbol (InOrder)", "Buscar un nodo", "Eliminar un nodo"};
    // Inicializar el arbol
    node *root = NULL;
    // Mostrar menu de opciones
    do
    {
        opc = mostrarMenu(4, opciones);
        switch (opc)
        {
        case 1:
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &value);
            insert(&root, value);
            break;
        case 2:
            printf("Recorriendo arbol...\n");
            inOrder(root);
            break;
        case 3:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &value);
            if (findNode(root, value) != NULL)
            {
                printf("Se ha encontrado el nodo con valor: %d\n", value);
            }
            else
            {
                printf("No se ha encontrado el nodo\n");
            }
            break;
        case 4:
            printf("Ingrese el valor del nodo a eliminar: ");
            scanf("%d", &value);
            if (delete (&root, value))
            {
                printf("El nodo se ha eliminado correctamente\n");
            }
            else
            {
                printf("ERROR al intentar eliminar el nodo\n");
            }
            break;
        case 5:
            printf("Saliendo ...");
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    } while (opc != 5);

    return 0;
}

int mostrarMenu(int numOpciones, char opciones[][30])
{
    int opcion;
    printf("********** Menu de Opciones **********\n");

    for (int i = 0; i < numOpciones; i++)
    {
        printf("%d. %s\n", i + 1, opciones[i]);
    }

    printf("%d. Salir\n", numOpciones + 1);
    printf("**************************************\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    while (opcion < 1 || opcion > numOpciones + 1)
    {
        printf("Opcion no valida. Intentalo de nuevo.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
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
        if (current->left == NULL)
        {
            current->left = createNode(value);
        }
        else
        {
            insertNode(current->left, value);
        }
    }
    else if (value > current->val)
    {
        if (current->right == NULL)
        {
            current->right = createNode(value);
        }
        else
        {
            insertNode(current->right, value);
        }
    }
    else
    {
        /*
        Al existir un nodo repetido, solo aumenta la ocurrencia del nodo
        */
        current->ocurrencia++;
    }
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    // Ocurrencia con valor por default
    newNode->ocurrencia = 1;
    return newNode;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d-(%d) ", root->val, root->ocurrencia);
        inOrder(root->right);
    }
}

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
        return findNode(root->left, value);
    }
    else
    {
        return findNode(root->right, value);
    }
}

bool delete(node **root, int value)
{
    // Puntero al nodo a eliminar
    node *nodetoRemove = findNode(*root, value);
    // Puntero al nodo padre del nodo a eliminar
    node *parent = findParent(*root, value);

    if (nodetoRemove == NULL)
    {
        // El valor no ha sido encontrado en el arbol
        return false;
    }
    if ((*root)->right == NULL && (*root)->left == NULL)
    {
        if ((*root)->ocurrencia > 1)
        {
            (*root)->ocurrencia--;
        }
        else
        {
            *root = NULL;
        }
    }
    else if (nodetoRemove->ocurrencia == 1)
    {
        if (nodetoRemove->left == NULL && nodetoRemove->right == NULL)
        {
            if (nodetoRemove->val < parent->val)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if (nodetoRemove->left == NULL && nodetoRemove->right != NULL)
        {
            if (nodetoRemove->val < parent->val)
            {
                parent->left = nodetoRemove->right;
            }
            else
            {
                parent->right = nodetoRemove->right;
            }
        }
        else if (nodetoRemove->left != NULL && nodetoRemove->right == NULL)
        {
            if (nodetoRemove->val < parent->val)
            {
                parent->left = nodetoRemove->left;
            }
            else
            {
                parent->right = nodetoRemove->left;
            }
        }
        else
        {
            // case 4
            node *largestValue = nodetoRemove->left;
            while (largestValue->right != NULL)
            {
                largestValue = largestValue->right;
            }
            parent = findParent(*root, largestValue->val);
            parent->right = NULL;
            nodetoRemove->val = largestValue->val;
        }
    }
    else
    {
        nodetoRemove->ocurrencia--;
    }
    return true;
}

node *findParent(node *root, int value)
{
    if (value == root->val)
    {
        return NULL;
    }
    if (value < root->val)
    {
        if (root->left == NULL)
        {
            return NULL;
        }
        else if (root->left->val == value)
        {
            return root;
        }
        else
        {
            return findParent(root->left, value);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            return NULL;
        }
        else if (root->right->val == value)
        {
            return root;
        }
        else
        {
            return findParent(root->right, value);
        }
    }
}
