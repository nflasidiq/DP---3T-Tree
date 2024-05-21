#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "treeUser.h"
#include "boolean.h"


//Fungsi LinkedList untuk queue
void intializeQueue(int IDcheck, nodeLLAddress * head, nodeLLAddress * tail){
    nodeLLAddress Q = (NodeQueue*)malloc(sizeof(NodeQueue));
    if(Q == NULL)
        exit(1);

    Q->IDcheck = IDcheck;
    Q->next = NULL;
    (*head) = Q;
    (*tail) = Q;

}

void insertQueue(int IDcheck, nodeLLAddress * head, nodeLLAddress * tail){

    if(*tail == NULL)
        intializeQueue(IDcheck, &(*head), &(*tail));
    else{
        nodeLLAddress Q = (NodeQueue*)malloc(sizeof(NodeQueue));
        if(Q == NULL)
            exit(1);

        Q->IDcheck = IDcheck;
        Q->next = NULL;
        (*tail)->next = Q;
        (*tail) = (*tail)->next;
    }
}

void popQueue(nodeLLAddress * head){
    nodeLLAddress P = *head;
    (*head) = (*head)->next;
    free(P);
}

void printQueue(nodeLLAddress head){
    printf("Head first: %d\n", head->IDcheck);

    printf("Isi dari queue: ");
    while(head != NULL){
        printf("%d ", head->IDcheck);
        head = head->next;
    }
}

bool checkTracked(nodeLLAddress head, int IDtracked){
    while(head != NULL){
        if(IDtracked == head->IDcheck)
            return true;
        else
            head = head->next;
    }
}
