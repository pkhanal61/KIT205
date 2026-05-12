DevLog -
Prasanna Khanal
760832

Designed a simple music database system using a linked list for storing artists and a binary search tree for storing songs. This structure was chosen to allow efficient insertion and traversal of dynamic music data while maintaining sorted order for song retrieval.

Implemented binary search tree for song storage including node creation, recursive insertion, and inorder traversal. This allows songs to be stored in alphabetical order and retrieved efficiently.

Implemented linked list for managing artists, including functions to insert new artists, search for existing artists, and print all artists in the system.

Integrated linked list and binary search tree by associating each artist node with a BST of songs. This allows each artist to maintain their own sorted collection of songs.

Developed a main test program to verify functionality of both data structures. Debugged function parameter mismatches and corrected header definitions to ensure proper compilation and execution.

Completed Prototype 1 of the music database system. The system successfully supports insertion and retrieval of artists and songs, with songs stored in sorted order using BST and artists managed via linked list.
