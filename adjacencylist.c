#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct AdjNode {
    int vertex;
    struct AdjNode* next;
};

struct Graph {
    int numVertices;
    struct AdjNode** adjLists;
};

struct AdjNode* createNode(int v) {
    struct AdjNode* newNode;
    newNode = (struct AdjNode*) malloc(sizeof(struct AdjNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    int i;
    struct Graph* graph;
    graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct AdjNode**) malloc(vertices * sizeof(struct AdjNode*));

    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjNode* newNode;

    // Add edge from src to dest
    newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int i;
    struct AdjNode* temp;

    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        temp = graph->adjLists[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges, i, src, dest;
    struct Graph* graph;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            addEdge(graph, src, dest);
        } else {
            printf("Invalid edge! Enter again.\n");
            i--;
        }
    }

    printf("\nAdjacency List of Graph:\n");
    printGraph(graph);

    getch();
    return 0;
}
