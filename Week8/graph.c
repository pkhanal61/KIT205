#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//adding edge, inserting at front
void add_edge(Graph *G, int from, int to, int w) {
    EdgeNodePtr newNode = malloc(sizeof(struct edgeNode));

    newNode->edge.to_vertex = to;
    newNode->edge.weight = w;
    newNode->next = G->edges[from].head;

    G->edges[from].head = newNode;
}
//loading graph from file
Graph load_graph(const char *filename) {
    Graph G;
    G.edges = NULL; 

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return G;
    }

    fscanf(file, "%d", &G.V);
//initialising the edge list for the graph
    G.edges = malloc(G.V * sizeof(EdgeList));

    for (int i = 0; i < G.V; i++) {
        G.edges[i].head = NULL;
    }

    int from, to, weight;

    while (fscanf(file, "%d,%d,%d", &from, &to, &weight) == 3) {
        add_edge(&G, from, to, weight);
    }

    fclose(file);
    return G;
}

//print in-degrees
void print_indegrees(Graph *G) {
    int *in_degree = calloc(G->V, sizeof(int));

    for (int v = 0; v < G->V; v++) {
        EdgeNodePtr current = G->edges[v].head;

        while (current != NULL) {
            in_degree[current->edge.to_vertex]++;
            current = current->next;
        }
    }

    printf("In-degrees:\n");
    for (int i = 0; i < G->V; i++) {
        printf("Vertex %d: %d\n", i, in_degree[i]);
    }

    free(in_degree);
}

//Free memory
void free_graph(Graph *G) {
    for (int v = 0; v < G->V; v++) {
        EdgeNodePtr current = G->edges[v].head;

        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(G->edges);
}