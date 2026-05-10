#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList *edges;
} Graph;

// function prototypes from week8
void add_edge(Graph *self, int from, int to, int w);
Graph load_graph(const char *filename);
void print_indegrees(Graph *G);
void free_graph(Graph *G);

//Added Page rank for week9
void calculate_pagerank(Graph *G, int iterations);

#endif