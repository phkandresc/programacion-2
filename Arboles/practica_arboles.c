#include <stdio.h>
#include <stdlib.h>

// Definiciones de colores
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

typedef struct node
{
    struct node *r;
    struct node *l;
    int val;
} node;

// Prototipos
void displayMenu(const char *);
node *createNode(int);

int main()
{
    int opt;
    while (1)
    {
        displayMenu(BLUE);
        if (scanf("%d", &opt) != 1)
        {
            printf("%sERROR: Ingrese un numero valido%s\n", RED, RESET);
            while (getchar() != '\n')
                ;
        }
        else
        {
            switch (opt)
            {
            case 1:
                printf("Opcion 1\n");
                break;

            default:
                printf("%sERROR: Opcion no valida intentelo de nuevo%s\n", RED, RESET);
                break;
            }
        }
    }
}

void displayMenu(const char *color)
{
    printf("%s*********************************************\n", color);
    printf("************* ARBOLES BINARIOS **************\n");
    printf("*********************************************\n");
    printf("%s\n", RESET);
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode != NULL)
    {
        newNode->val = value;
        newNode->l = newNode->r = NULL;
        return newNode;
    }
    else
    {
        printf("%sERROR en la creacion del nodo%s\n", RED, RESET);
        return NULL;
    }
}