DevLog - Week9
Prasanna Khanal
760832

Commit 1: Added graph.h
Started by setting up the header file. Reused the same structs from week 8 (Edge, EdgeNode, EdgeList, Graph) and added the new calculate_pagerank function prototype at the bottom.

Commit 2: Added graph.c - load_graph, add_edge and calculate_pagerank
Copied add_edge from week 8, it was the same. For load_graph I had a problem - the week 9 input file uses from,to format (no weight) but my week 8 code only read from,to,weight so it wasnt reading any edges. Fixed it by using fgets and sscanf so it tries weighted format first then falls back to unweighted.

Implemented the PageRank function following the pseudocode from the tutorial. Created three arrays - PR[], sums[], and out_degree[]. Initialised all PageRanks to 1. The three loops inside the iteration are kept separate as required.

Added a check for out_degree > 0 before dividing to avoid division by zero. Vertices 14 and 18 have no outgoing edges so without this it would crash.

Commit 3: Added main.c and graph.txt, tested output
Wrote main to load the graph, print in-degrees to check it loaded correctly, then run PageRank for 20 iterations.
Tested with the 20 vertex social network from the tutorial and checked the output against what I worked out by hand from the diagram.

Vertex 3 got highest PageRank (3.3889) because it has 17 incoming edges
Vertex 11 was second (3.3771) with 13 incoming edges
Vertices 14 and 18 got 0.1500 which is exactly 1 - 0.85, the minimum possible score since nothing links to them.

Commit 4: Added DevLog

