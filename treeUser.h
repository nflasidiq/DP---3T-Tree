#ifndef ridho

#include <stdio.h>
#include <stdlib.h>

//node untuk non binary tree
typedef struct Node* nodeAddress;

typedef struct Node{
    int ID;
    nodeAddress parent, firstSon, nextBrother;

}NodeUser;

int deserializeTree(char* username_input, int IDuser);


#endif // ridho
