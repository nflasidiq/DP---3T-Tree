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
//NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, int stats, nodeLLAddress * queueTail, nodeLLAddress * trackedTail);

typedef struct NodeLinkedListPointer* nodeLLPointerAddress;
typedef struct NodeLinkedList* nodeLLAddress;

typedef struct NodeLinkedListPointer{
    NodeUser* trackedAddress;
    nodeLLPointerAddress next;
}NodeQueuePointer;

typedef struct NodeLinkedList{
    int IDcheck;
    nodeLLAddress next;
}NodeQueue;

void intializeQueue(int IDcheck, nodeLLAddress * head, nodeLLAddress * tail);
void insertQueue(int IDcheck, nodeLLAddress * tail);
NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, nodeLLPointerAddress queueHead, int stats,nodeLLPointerAddress * queueTail);


int popQueue(nodeLLAddress* head);
#endif // ridho
