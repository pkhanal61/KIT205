DevLog -
Prasanna Khanal
760832

Designed a simple music database system using a linked list for storing artists and a binary search tree for storing songs. This structure was chosen to allow efficient insertion and traversal of dynamic music data while maintaining sorted order for song retrieval.

Implemented binary search tree for song storage including node creation, recursive insertion, and inorder traversal. This allows songs to be stored in alphabetical order and retrieved efficiently.

Implemented linked list for managing artists, including functions to insert new artists, search for existing artists, and print all artists in the system.

Integrated linked list and binary search tree by associating each artist node with a BST of songs. This allows each artist to maintain their own sorted collection of songs.

Developed a main test program to verify functionality of both data structures. Debugged function parameter mismatches and corrected header definitions to ensure proper compilation and execution.

Completed Prototype 1 of the music database system. The system successfully supports insertion and retrieval of artists and songs, with songs stored in sorted order using BST and artists managed via linked list.

Ouput looks like :
Artists List:
Drake
TaylorSwift
EdSheeran

Songs by Drake:
GodsPlan - Drake
HotlineBling - Drake
OneDance - Drake

Songs by TaylorSwift:
BlankSpace - TaylorSwift
LoveStory - TaylorSwift

Developed Prototype 2 of the music database system using a hash table for storing artists and an AVL tree for storing songs. This structure was chosen to improve search efficiency for artists and maintain balanced performance for song storage.

Both Prototype 1 and Prototype 2 produce the same output results, but use different data structures internally. Prototype 2 improves performance by using a hash table for faster artist lookup and an AVL tree for balanced and efficient song insertion and retrieval.


Implemented performance evaluation to compare Prototype 1 and Prototype 2 using generated music records. Testing measured insertion and retrieval operations for artists and songs. Results showed that Prototype 2 performed significantly faster than Prototype 1 due to the use of hash tables and AVL trees for efficient data access and balanced storage.

Performance Results:

Prototype 1 Time: 0.083929 seconds
Prototype 2 Time: 0.000617 seconds
