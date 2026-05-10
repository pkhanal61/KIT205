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
    //read number of vertices
    fscanf(file, "%d", &G.V);

//initialising the edge list for the graph
    G.edges = malloc(G.V * sizeof(EdgeList));

    for (int i = 0; i < G.V; i++) {
        G.edges[i].head = NULL;
    }

    int from, to, weight;
    char line[256];

    while (fgets(line, sizeof(line), file)) {

        // for weighted graph format
        if (sscanf(line, "%d,%d,%d", &from, &to, &weight) == 3) {
            add_edge(&G, from, to, weight);
        }

        //for unweighted graph format
        else if (sscanf(line, "%d,%d", &from, &to) == 2) {
            add_edge(&G, from, to, 1);
        }
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

//Calculating pagerank
void calculate_pagerank(Graph *G, int iterations) {
    double d = 0.85;

    //sums array 
    double *sums = calloc(G->V, sizeof(double));

    //pagerank array
    double *PR = malloc(G->V * sizeof(double));

    //out degree array
    int *out_degree = calloc(G->V, sizeof(int));

    //initialising all the pageranks to 1
    for (int i = 0; i < G->V; i++) {
        PR[i] = 1.0;
    }

    //calculating out degrees
    for (int v = 0; v < G->V; v++) {
        EdgeNodePtr current = G->edges[v].head;
        while (current != NULL) {
            out_degree[v]++;
            current = current->next;
        }
    }

    // iterations
    for (int it = 0; it < iterations; it++) {

        //resetting sums to zero for every vertics
        for (int i = 0; i < G->V; i++) {
            sums[i] = 0;
        }

        // calculating sum
        for (int j = 0; j < G->V; j++) {
            EdgeNodePtr current = G->edges[j].head;
            while (current != NULL) {
                int i = current->edge.to_vertex;
                if (out_degree[j] > 0) {
                    sums[i] += PR[j] / out_degree[j];
                }
                current = current->next;
            }
        }

        // updating pageranks by applying the damping factor as d
        for (int i = 0; i < G->V; i++) {
            PR[i] = (1 - d) + d * sums[i];
        }
    }

    /* print pageranks */
    printf("\nPageRanks:\n");
    for (int i = 0; i < G->V; i++) {
        printf("Vertex %d: %.4f\n", i, PR[i]);
    }

    free(sums);
    free(PR);
    free(out_degree);
}

//Free graph memory
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