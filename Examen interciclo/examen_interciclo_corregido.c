#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct libro
{
    int codigo;
    char autor[20];
    char titulo[20];
} libro;

typedef struct nodo
{
    libro libro;
    struct nodo *sig;
} nodo;

typedef struct lista
{
    nodo *primerNodo;
} lista;

// Prototipo de funciones
void mostrarMenu();
nodo *crearLibro();
void recorrerLibros(lista *listaLibros);
void insertarLibro(lista *listaLibros, nodo **base1, nodo **base2);
nodo *copiaLibro(nodo *original);
void liberarLista(lista *listaLibros);

int main()
{
    // Se inicializa la lista ligada listaLibros
    lista listaLibros;
    listaLibros.primerNodo = NULL;
    // Inicializar punteros a los libros base
    nodo *base1 = NULL;
    nodo *base2 = NULL;
    // Bucle para presentar el menu de opciones al usuario
    int opcion;
    while (1)
    {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1)
        {
            printf("Error: Ingrese un numero valido.\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            while (getchar() != '\n')
                ;
            switch (opcion)
            {
            case 1:
                printf("Ha seleccionado la opcion 1.\n");
                insertarLibro(&listaLibros, &base1, &base2);
                break;
            case 2:
                printf("Ha seleccionado la opcion 2.\n");
                recorrerLibros(&listaLibros);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                liberarLista(&listaLibros);
                exit(0);
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
            }
        }
    }
}

void mostrarMenu()
{
    printf("____________________________\n");
    printf("\tMenu de Opciones:\n");
    printf("____________________________\n");
    printf("1. Ingresar libros\n");
    printf("2. Recorrer libros\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
}

nodo *crearLibro()
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));

    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para crear un nuevo libro\n");
        return NULL;
    }

    while (1)
    {
        // Ingresar datos del libro
        printf("Ingrese codigo del libro:\n");
        if (scanf("%d", &nuevoNodo->libro.codigo) != 1 || nuevoNodo->libro.codigo < 0)
        {
            printf("Error: Ingrese un valor válido para el código del libro.\n");
            continue;
        }

        printf("Ingrese autor del libro:\n");
        if (scanf("%19s", nuevoNodo->libro.autor) != 1)
        {
            printf("Error: Ingrese un valor válido para el autor del libro.\n");
            continue;
        }

        printf("Ingrese titulo del libro:\n");
        if (scanf("%19s", nuevoNodo->libro.titulo) != 1)
        {
            printf("Error: Ingrese un valor válido para el título del libro.\n");
            continue;
        }
        break;
    }
    // Asignar un valor al puntero que apunta al siguiente nodo
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

void insertarLibro(lista *listaLibros, nodo **base1, nodo **base2)
{
    // Crear un nuevo libro
    nodo *nuevoLibro = crearLibro();
    // Validar que los libros base1 y base2 no tengan los mismos códigos
    if (*base1 != NULL && *base2 != NULL && (*base1)->libro.codigo == (*base2)->libro.codigo)
    {
        printf("Error: Los libros base1 y base2 tienen el mismo código.\n");
        free(nuevoLibro); // Liberar memoria del nuevo libro antes de salir
        return;
    }
    if (listaLibros->primerNodo == NULL)
    {
        listaLibros->primerNodo = nuevoLibro;
        *base1 = nuevoLibro;
        printf("BASE 1\n");
    }
    else if (*base2 == NULL)
    {
        // Si base1 ya está asignado pero base2 no, asignamos el nuevo libro a base2
        printf("BASE 2\n");
        *base2 = nuevoLibro;
        (*base1)->sig = nuevoLibro;
    }
    else
    {
        if (nuevoLibro->libro.codigo < (*base2)->libro.codigo && nuevoLibro->libro.codigo > (*base1)->libro.codigo)
        {
            nodo *copianuevoLibro = copiaLibro(nuevoLibro);
            nodo *actual = *base2;
            while (actual->sig != NULL)
            {
                actual = actual->sig;
            }
            actual->sig = nuevoLibro;
            // Caso 2
            copianuevoLibro->sig = listaLibros->primerNodo;
            listaLibros->primerNodo = copianuevoLibro;
        }
        else if (nuevoLibro->libro.codigo < (*base2)->libro.codigo)
        {
            nodo *actual = *base2;
            while (actual->sig != NULL)
            {
                actual = actual->sig;
            }
            actual->sig = nuevoLibro;
        }
        else if (nuevoLibro->libro.codigo > (*base1)->libro.codigo)
        {
            nuevoLibro->sig = listaLibros->primerNodo;
            listaLibros->primerNodo = nuevoLibro;
        }
    }
    printf("Libro agregado a la lista\n");
}

void recorrerLibros(lista *listaLibros)
{
    if (listaLibros == NULL || listaLibros->primerNodo == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    nodo *actual = listaLibros->primerNodo;
    while (actual != NULL)
    {
        printf("Codigo: %d, Autor: %s, Titulo: %s\n", actual->libro.codigo, actual->libro.autor, actual->libro.titulo);
        actual = actual->sig;
    }
}

nodo *copiaLibro(nodo *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    // Crear un nuevo nodo para la copia
    nodo *copia = (nodo *)malloc(sizeof(nodo));
    if (copia == NULL)
    {
        printf("Error: No se pudo asignar memoria para la copia del libro\n");
        return NULL;
    }

    // Copiar los valores individualmente
    copia->libro.codigo = original->libro.codigo;
    strncpy(copia->libro.autor, original->libro.autor, sizeof(original->libro.autor) - 1);
    strncpy(copia->libro.titulo, original->libro.titulo, sizeof(original->libro.titulo) - 1);
    copia->sig = NULL;
    return copia;
}

void liberarLista(lista *listaLibros)
{
    if (listaLibros == NULL || listaLibros->primerNodo == NULL)
    {
        // La lista ya está vacía o es nula
        return;
    }

    nodo *actual = listaLibros->primerNodo;
    nodo *siguiente;

    while (actual != NULL)
    {
        siguiente = actual->sig;
        free(actual);       // Liberar el nodo actual
        actual = siguiente; // Mover al siguiente nodo
    }

    // Establecer el primer nodo de la lista como NULL
    listaLibros->primerNodo = NULL;
}