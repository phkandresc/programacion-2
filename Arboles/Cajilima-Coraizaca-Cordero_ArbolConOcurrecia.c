#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
struct Nodo
{
    int dato;
    int ocurrencia; // cantidad de veces que se repite el nodo
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo *crearNodo(int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->ocurrencia = 1; // se iguala a uno porque inicia el contador de recurrencias el cual aumenta o disminuye dependiendo del caso
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nuevo nodo en el árbol
struct Nodo *insertar(struct Nodo *raiz, int valor, int criterio)
{
    if (raiz == NULL)
    {
        return crearNodo(valor);
    }

    if ((criterio == 1 && valor < raiz->dato) || (criterio == 2 && valor >= raiz->dato))
    {
        raiz->izquierda = insertar(raiz->izquierda, valor, criterio);
    }
    else if ((criterio == 1 && valor > raiz->dato) || (criterio == 2 && valor <= raiz->dato))
    {
        raiz->derecha = insertar(raiz->derecha, valor, criterio);
    }
    else
    {
        // Valor encontrado, incrementar la ocurrencia
        raiz->ocurrencia++;
    }

    return raiz;
}

// Función para buscar un nodo en el árbol
struct Nodo *buscar(struct Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        printf("El valor %d no se encuentra en el arbol.\n", valor);
        return raiz;
    }

    if (valor == raiz->dato)
    {
        printf("El valor %d se encuentra en el arbol. Ocurrencias: %d\n", valor, raiz->ocurrencia);
        return raiz;
    }

    if (valor < raiz->dato)
    {
        return buscar(raiz->izquierda, valor);
    }

    return buscar(raiz->derecha, valor);
}

// Función para encontrar el nodo con el valor mínimo en el árbol
struct Nodo *encontrarMinimo(struct Nodo *nodo)
{
    while (nodo->izquierda != NULL)
    {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para eliminar un nodo con un valor dado en el árbol
struct Nodo *eliminar(struct Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    if (valor < raiz->dato)
    {
        raiz->izquierda = eliminar(raiz->izquierda, valor);
    }
    else if (valor > raiz->dato)
    {
        raiz->derecha = eliminar(raiz->derecha, valor);
    }
    else
    {
        // Valor encontrado, decrementar la ocurrencia
        if (raiz->ocurrencia > 1)
        {
            raiz->ocurrencia--;
        }
        else
        {
            // Nodo con un solo hijo o sin hijos
            if (raiz->izquierda == NULL)
            {
                struct Nodo *temp = raiz->derecha;
                free(raiz);
                return temp;
            }
            else if (raiz->derecha == NULL)
            {
                struct Nodo *temp = raiz->izquierda;
                free(raiz);
                return temp;
            }

            // Nodo con dos hijos: obtener el sucesor inorden (nodo mínimo en el subárbol derecho)
            struct Nodo *temp = encontrarMinimo(raiz->derecha);

            // Copiar el contenido del sucesor inorden al nodo actual
            raiz->dato = temp->dato;
            raiz->ocurrencia = temp->ocurrencia;

            // Decrementar la ocurrencia del sucesor inorden
            raiz->derecha = eliminar(raiz->derecha, temp->dato);
        }
    }

    return raiz;
}

// Función para realizar el recorrido inorden del árbol
void inorden(struct Nodo *raiz, int *lastValue, int *consecutiveCount)
{
    if (raiz != NULL)
    {
        inorden(raiz->izquierda, lastValue, consecutiveCount);

        if (*lastValue == raiz->dato)
        {
            (*consecutiveCount)++;
        }
        else
        {
            if (*lastValue != -1)
            {
                printf("(%d, %d veces) ", *lastValue, *consecutiveCount);
            }
            *lastValue = raiz->dato;
            *consecutiveCount = 1;
        }

        inorden(raiz->derecha, lastValue, consecutiveCount);
    }
}

// Función principal
int main()
{
    struct Nodo *raiz = NULL;
    int valor, criterio;
    char opcion;

    do
    {
        printf("Seleccione el criterio de busqueda:\n");
        printf("1. Menores a la izquierda, mayores a la derecha\n");
        printf("2. Mayores a la izquierda, menores a la derecha\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &criterio);
    } while (criterio != 1 && criterio != 2);

    do
    {
        printf("====================================\n");
        printf("      ARBOL BINARIO DE BUSQUEDA     \n");
        printf("====================================\n");
        printf("1. Insertar un nodo\n");
        printf("2. Recorrido inorden\n");
        printf("3. Buscar un nodo\n");
        printf("4. Eliminar un nodo\n");
        printf("5. Salir\n");
        printf("====================================\n");
        printf("Ingrese su opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch (opcion)
        {
        case '1':
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &valor);
            raiz = insertar(raiz, valor, criterio);
            system("cls");
            break;
        case '2':
            printf("Recorrido inorden: ");
            int lastValue = -1;
            int consecutiveCount = 0;
            inorden(raiz, &lastValue, &consecutiveCount);
            if (lastValue != -1)
            {
                printf("(%d, %d veces) ", lastValue, consecutiveCount);
            }
            printf("\n");
            break;
        case '3':
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);
            struct Nodo *resultado = buscar(raiz, valor);
            break;
        case '4':
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &valor);
            raiz = eliminar(raiz, valor);
            break;
        case '5':
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion != '5');

    return 0;
}
