#include <stdio.h>
#include <stdlib.h>
/*
Que es un arbol binario?

Un arbol binario es una estructura de datos en la cual nada nodo puede tener dos hijos, uno a la izquierda y otro a la derecha.
*/

// Definir un nodo de un arbol binario
typedef struct nodo
{
    // Puntero a un nodo a la izquierda
    struct nodo *izq;
    // Dato del nodo
    int dato;
    // Puntero a un nodo a la derecha
    struct nodo *der;

} nodo;

// Funcion para mostrar un menu al usuario
void mostrarMenu();
// Funcion para crear un nodo independiente
nodo *crearNodo(int);
// Funcion para configurar el arbol
int setCriterio();
// Funcion para agregar un nodo creado previamente al arbol
nodo *agregaralArbol(nodo *nuevoNodo, nodo *root, int conf);

int main()
{
    /*
    Cada arbol tiene un nodo raiz
    Debemos inicializar este nodo para posteriormente darle sus valores respectivos
    */
    nodo *root = NULL;
    // Declarar una variable int que la pasaremos a la funcion crearNodo
    int n;
    // Declarar una variable para control del menu
    int opc;
    // Declarar una variable para establecer la configuracion del arbol elegida por el usuario
    int conf;
    /*
    Crear un nodo para despues agregarlo al arbol
    Este nodo independiente debe apuntar a NULL en sus dos direcciones izquierda y derecha
    */
    while (1)
    {
        mostrarMenu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            if (conf == 1 || conf == 2)
            {
                printf("Ingrese un numero entero: ");
                scanf("%d", &n);
                nodo *nuevoNodo = crearNodo(n);
                root = agregaralArbol(nuevoNodo, root, conf);
                break;
            }
            else
            {
                printf("Antes de ingresar datos, configure el arbol correctamente\n");
                break;
            }

        case 2:
            conf = setCriterio();
            break;
        case 3:
            printf("Saliendo del programa...");
            return 0;
        default:
            printf("ERROR: Ingrese una opcion valida del menu\n");
            break;
        }
    }
}

nodo *crearNodo(int dato)
{
    // Se crea un puntero al nuevo nodo.
    nodo *nuevoNodo = malloc(sizeof(nodo));
    // Se valida que nodo haya sido creado correctamente.
    if (nuevoNodo == NULL)
    {
        printf("No se ha podido crear el nodo\n");
        return NULL;
    }
    // Si se crea correctamente el nodo, se le asigna el valor del dato, y los punteros a la izquierda y derecha se les da el valor NULL ya que todavia no apuntan a ningun otro nodo
    nuevoNodo->dato = dato;
    nuevoNodo->der = nuevoNodo->izq = NULL;
    // Finalmente se devuelve a la funcion main la direccion del nodo creado
    printf("Nodo creado exitosamente\n");
    return nuevoNodo;
}

nodo *agregaralArbol(nodo *nuevoNodo, nodo *root, int conf)
{
    /*
    Evaluar si root es igual a NULL, esto nos quiere decir que el arbol aun no tiene nodos, por lo que el primer nodo que se cree va a ser la raiz del arbol
    */
    if (root == NULL)
    {
        root = nuevoNodo;
        printf("Raiz del arbol establecida\n");
        return root;
    }
    // Ordenar los datos en el arbol segun la configuracion
    // Ordenar numeros menores a la derecha, mayores a la izquierda
    // Ordenar numeros menores a la izquierda, mayores a la derecha
    int dir = (conf == 1 && nuevoNodo->dato < root->dato) || (conf == 2 && nuevoNodo->dato >= root->dato);
    /*
    Si dir es verdadero, entonces el dato ingresado se ordenara a la derecha.
    Si dir es falso, entonces el dato ingresado se ordenara a la izquierda.
    Esto para simplificar el codigo.
    */
    if (dir)
    {
        if (root->der == NULL)
        {
            root->der = nuevoNodo;
            printf("Nodo insertado a la derecha\n");
            return root;
        }
        else
            agregaralArbol(nuevoNodo, root->der, conf);
    }
    else
    {
        if (root->izq == NULL)
        {
            root->izq = nuevoNodo;
            printf("Nodo insertado a la izquierda\n");
            return root;
        }
        else
            agregaralArbol(nuevoNodo, root->izq, conf);
    }
}

int setCriterio()
{
    int n;
    while (1)
    {
        printf("\tC O N F I G U R A C I O N\n");
        printf("1. Ordenar numeros menores a la derecha\n");
        printf("2. Ordenar numeros menores a la izquierda\n");
        printf("Elija una opcion. ");
        scanf("%d", &n);
        if (n == 1 || n == 2)
        {
            printf("Configuracion realizada\n");
            break;
        }
        else
            printf("Ingrese una opcion valida\n");
    }
    return n;
}

void mostrarMenu()
{
    printf("\tM E N U  D E  O P C I O N E S\n");
    printf("1. Ingresar datos\n");
    printf("2. Configurar arbol\n");
    printf("3. Salir\n");
    printf("Elija una opcion: ");
}