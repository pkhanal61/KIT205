#include "graph.h"

int main(void) {
    Graph G = load_graph("graph.txt");

    if (G.edges == NULL) {
        return 1;
    }
    //Testing the correctness of graph
    print_indegrees(&G);
    //free memory
    free_graph(&G);
    return 0;
}