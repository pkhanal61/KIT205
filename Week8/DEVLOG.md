 DevLog - Week 8
Prasanna Khanal
760832

Commit 1: Added graph.h
Started with the header file. Set up the four structs - Edge with to_vertex and weight,
EdgeNode for the linked list, EdgeList as the head wrapper, and Graph with V and the
edges array. Added function prototypes for add_edge, load_graph, print_indegrees and
free_graph.

Commit 2: Added graph.c
Implemented add_edge using insert at front like we did in the linked list tutorials.
For load_graph I opened the file, read V, malloced the edges array, set all heads to
NULL then looped through the edges with fscanf. Made a mistake where I used "%d %d %d"
as the format string and it wasnt reading anything. Realised the file uses commas so
changed it to "%d,%d,%d" and it worked.

Commit 3: Added main.c
Wrote main to load the graph and call print_indegrees. Also implemented print_indegrees
using calloc so the array starts at all zeros, then looped through every vertex and every
edge in its list and incremented the count for the to_vertex. 
Also added some comment in the file later.

Commit 4: Added graph.txt and tested output
Added the graph.txt file from the tutorial with the 7 vertices and 14 edges. Ran the
program and checked the output against what I worked out by hand from the diagram.

Vertex 3 has the highest in-degree which makes sense, a lot of vertices
point to it. Vertex 1 has 0 meaning nothing points to it.

Commit 5: Added DevLog