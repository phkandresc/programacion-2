#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *r;
    struct node *l;
    int val;
} node;

node *createNode(int value);
void insertNode(node *current, int value);
void insert(node **root, int value);
void printInOrder(node *root);

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
    printf("Arbol en orden: ");
    printInOrder(root);
    printf("\n");
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

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->l);
        printf("%d ", root->val);
        printInOrder(root->r);
    }
}