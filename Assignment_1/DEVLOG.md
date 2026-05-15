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

Many to many


I changed the BST node because before it only stored one artist name. That would not work for many-to-many. So I added a linked list called ArtistListBST inside each song node so it can hold multiple artists. Had to make sure ArtistListBST is defined before SongNode in the header otherwise it would not compile.

Implemented the basic BST functions. Made create_song_node and insert_song. Insert goes left if the title is smaller and right if bigger. If the same title is already there it just ignores it. Tested it and it worked fine.

Finished the rest of the BST. Added find_song, add_artist_to_bst_song, inorder_songs and print_bst_with_global. The most important one was print_bst_with_global. I needed this because without it shared songs like What Makes You Beautiful were only showing one artist. The fix was to look up each song in a global BST so all artists show up correctly.

Implemented the linked list for storing artists. Each artist node has a name and a pointer to their own BST of songs. Made create, insert, find and print functions. This is the outer structure for Prototype 1.

Put Prototype 1 together by connecting the linked list and BST. Added a global all_songs BST inside Proto1DB. When I add a song it checks the global BST first. If the song is not there it creates it. Then it adds the artist to that shared node. It also adds the song to the artist's own BST so I can still print songs by artist.

I decided to remove main.c and make two separate files instead. Made proto1main.c for testing Prototype 1 and proto2main.c for testing Prototype 2. This is easier because I do not have to keep commenting and uncommenting code when switching between prototypes. 

Tested Prototype 1 with One Direction members as artists. I picked One Direction because they are a good real example of many-to-many. All three members share songs like Steal My Girl and What Makes You Beautiful. I also added solo songs for each member to test one-to-one at the same time.

Found a bug where shared songs were showing No artists for some members. The problem was each artist had their own separate BST so the same song was a different node in each tree. Fixed it by making all artists write to the same global song node. After fixing it all three members showed up correctly on shared songs.
Result is like this:

ARTISTS 

Artists:
Liam Payne
Zayn Malik
Harry Styles


SONGS Zayn Malik

Songs by Zayn Malik:
Dusk Till Dawn - Zayn Malik
I Don't Wanna Live Forever - Zayn Malik
Steal My Girl - Liam Payne, Harry Styles, Zayn Malik
What Makes You Beautiful - Liam Payne, Harry Styles, Zayn Malik


SONGS (Harry Styles)

Songs by Harry Styles:
As It Was - Harry Styles
Steal My Girl - Liam Payne, Harry Styles, Zayn Malik
Watermelon Sugar - Harry Styles
What Makes You Beautiful - Liam Payne, Harry Styles, Zayn Malik


SONGS (Liam Payne) 

Songs by Liam Payne:
Stack It Up - Liam Payne
Steal My Girl - Liam Payne, Harry Styles, Zayn Malik
Strip That Down - Liam Payne
What Makes You Beautiful - Liam Payne, Harry Styles, Zayn Malik