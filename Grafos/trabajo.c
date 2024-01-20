#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo en la lista ligada de adyacencia
struct Node {
    int data;            // Valor del nodo
    struct Node* next;   // Puntero al siguiente nodo en la lista
};

// Estructura de un grafo con lista ligada de adyacencia
struct Graph {
    int V;               // Número de vértices
    struct Node** adjacencyList;  // Lista ligada de adyacencia para cada vértice
};

// Función para crear un nuevo nodo con el valor dado
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para crear un grafo con el número dado de vértices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Crear una matriz de listas ligadas, cada lista representa los nodos adyacentes a un vértice
    graph->adjacencyList = (struct Node**)malloc((V + 1) * sizeof(struct Node*));

    // Inicializar cada lista como vacía
    for (int i = 1; i <= V; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

// Función para agregar una arista al grafo no dirigido
void addEdge(struct Graph* graph, int src, int dest) {
    // Agregar la arista de src a dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Agregar la arista de dest a src (grafo no dirigido)
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Función para imprimir la lista ligada de adyacencia del grafo
void printGraph(struct Graph* graph) {
    for (int i = 1; i <= graph->V; ++i) {
        printf("Nodo %d: ", i);
        struct Node* temp = graph->adjacencyList[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Función principal
int main() {
    int V = 6; // Número de nodos
    struct Graph* graph = createGraph(V);

    // Agregar aristas al grafo
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 4);
    addEdge(graph, 5, 6);


    // Imprimir la lista ligada de adyacencia del grafo
    printGraph(graph);
    system("pause");
    return 0;
}
