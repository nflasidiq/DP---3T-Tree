#ifndef ridho

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeLinkedList* nodeLLAddress;

typedef struct NodeLinkedList{
    int IDcheck;
    nodeLLAddress next;
}NodeQueue;

void intializeQueue(int IDcheck, nodeLLAddress * head, nodeLLAddress * tail);
void insertQueue(int IDcheck, nodeLLAddress * tail, nodeLLAddress * head);
void popQueue(nodeLLAddress * head);

//node untuk non binary tree
typedef struct Node* nodeAddress;

typedef struct Node{
    int ID;
    nodeAddress parent, firstSon, nextBrother;

}NodeUser;

int deserializeTree(char* username_input, int IDuser);
//NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, int stats, nodeLLAddress * queueTail, nodeLLAddress * trackedTail);
NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, int stats, nodeLLAddress * queueTail, nodeLLAddress * trackedTail);
#endif // ridho
