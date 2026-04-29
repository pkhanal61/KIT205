#include "graph.h"

int main(void) {
    Graph G = load_graph("graph.txt");

    if (G.edges == NULL) {
        return 1;
    }

    print_indegrees(&G);
    free_graph(&G);
    return 0;
}