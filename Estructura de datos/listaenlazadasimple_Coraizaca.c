#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *sig;
} nodo;

nodo *crear_nodo(int valor);
nodo *insertarFinal(nodo *head, int valor);
nodo *ingresarDatos(nodo *head);
void recorrerLista(nodo *head);
nodo *buscarNodo(nodo *head);

int main(){
	nodo *head = NULL;
	
	int opcion;
    while (1)
    {
    	printf("____________________________\n");
	    printf("\tMenu de Opciones:\n");
	    printf("____________________________\n");
	    printf("1. Ingresar\n");
	    printf("2. Recorrer\n");
	    printf("3. Buscar\n");
	    printf("4. Eliminar\n");
	    printf("5. Salir\n");
	    printf("\n");
	    printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            printf("Error: Ingrese un numero valido.\n");
            while (getchar() != '\n'); // Limpia el búfer de entrada
        }
        else
        {
            while (getchar() != '\n'); // Limpia el búfer de entrada
            switch (opcion)
            {
            case 1:
                printf("Ha seleccionado la opcion 1.\n");
                head = ingresarDatos(head);
                break;
            case 2:
                printf("Ha seleccionado la opcion 2.\n");
                if (head==NULL){
                	printf("ERROR: Primero ingrese datos a la lista ligada\n");
				}else recorrerLista(head);
                break;
            case 3:
                printf("Ha seleccionado la opcion 3.\n");
                if (head==NULL){
                	printf("ERROR: Primero ingrese datos a la lista ligada\n");
				}else head = buscarNodo(head);
                break;
            case 4:
                printf("Ha seleccionado la opcion 4.\n");
                break;
            case 5:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
            }
        }
    }
}

nodo *ingresarDatos(nodo *head){
	int i;
	while(i!=-1){
		if (scanf("%d", &i) != 1)
    	{
	        printf("Error: Ingrese un numero valido.\n");
	        while (getchar() != '\n'); // Limpia el búfer de entrada
   		}else{
	    	while (getchar() != '\n'); // Limpia el búfer de entrada
	    	head = insertarFinal(head, i);
		}
	}
	return head;
}

nodo *crear_nodo(int valor)
{
    /*
    new_node va a almacenar la direccion de memoria de un nodo nuevo
    */
    nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
    if (nuevo_nodo == NULL)
    {
        printf("ERROR: No se ha podido asignar memoria para el nodo\n");
    }
    nuevo_nodo->valor = valor;
    nuevo_nodo->sig = NULL;
    printf("NODO CREADO, valor: %d\n", nuevo_nodo->valor);
    return nuevo_nodo; // retorna la direccion de memoria del nodo creado
                     // recordemos que este nodo es un nodo "suelto"
                     // todavia no esta enlazado a ninguna lista
}

nodo* insertarFinal(nodo *head, int valor)
{
    // creamos un puntero a un nodo
    // almacenamos la direccion del nodo creado
    nodo *nuevo_nodo = crear_nodo(valor);
    if (head == NULL)
    {
        // Evaluamos si head apunta a NULL lo que quiere decir es que
        // si head apunta a NULL estariamos creando el primero elemento
        // de la lista
        // entonces retornamos la direccion del nodo correspondiente
        // al primer elemento de la lista
        return nuevo_nodo;
    }
    // Si head no apunta a NULL quiere decir que ya hay mas nodos en la lista
    // por lo que vamos a recorrer la lista hasta encontrar el ultimo empezando desde el head que siempre apunta al primer elemento
    // elemento
    nodo *actual = head; // puntero a la direccion de memoria a la que apunta head, osea current apunta al primer nodo de la lista
    while (actual->sig != NULL){
        actual=actual->sig;
    }
    //cuando encontremos el ultimo elemento de la lista current-> va a ser NULL
    //entonces almacenamos en el nodo la direccion de memoria del siguiente nodo
    actual->sig=nuevo_nodo;
    //head no cambia y es el acceso a la lista, asi que no se debe perder y debe retornar para ser
    //reutilizado
    return head;
}

void recorrerLista(nodo *head){
    nodo *actual = head;
    while (actual->sig!=NULL)
    {
        printf("[%d]\n", actual->valor);
        actual=actual->sig;
    }
    printf("[%d]\n", actual->valor);
}

void limpiarLista(nodo *head){
    while (head!=NULL)
    {
        //vamos a eliminar desde el primer elemento hasta el ultimo
        nodo *actual = head;//almacenamos la direccion del primer nodo en un puntero
        head=head->sig;//ahora head va a apuntar al siguiente elemento de la lista
        free(actual);//podemos eliminar el elemento que antes era el head
        //y asi hasta que head apunte a NULL
    }
    printf("Lista limpiada correctamente.\n");
}

nodo *buscarNodo(nodo *head){
	int val_buscar, flag;
	flag=0;
	printf("Cual es valor que desea buscar: ");
	scanf("%d", &val_buscar);
	printf("\n");
	nodo *actual = head;
	while (actual->sig!=NULL && flag==0)
    {
        if(actual->valor==val_buscar){
        	printf("Nodo encontrado\n");
        	flag=1;
		}
		actual=actual->sig;
    }
    if(flag==0){
    	printf("Nodo no encontrado\n");
	}
    return head;
}


