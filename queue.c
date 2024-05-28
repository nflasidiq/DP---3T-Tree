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

void intializeQueuePointer(nodeLLPointerAddress pointerCheck, nodeLLPointerAddress * head, nodeLLPointerAddress * tail){
    nodeLLPointerAddress Q = (NodeQueuePointer*)malloc(sizeof(NodeQueuePointer));
    if(Q == NULL)
        exit(1);

    Q->trackedAddress = pointerCheck;
    Q->next = NULL;
    (*head) = Q;
    (*tail) = Q;

}

void insertQueue(int IDcheck, nodeLLAddress * tail){
    nodeLLAddress Q = (NodeQueue*)malloc(sizeof(NodeQueue));
    if(Q == NULL)
        exit(1);

    Q->IDcheck = IDcheck;
    Q->next = NULL;
    (*tail)->next = Q;
    (*tail) = (*tail)->next;
}

void insertQueueAddress(nodeLLPointerAddress pointerCheck, nodeLLAddress * tail){
    nodeLLPointerAddress Q = (NodeQueuePointer*)malloc(sizeof(NodeQueuePointer));
    if(Q == NULL)
        exit(1);

    Q->trackedAddress = pointerCheck;
    Q->next = NULL;
    (*tail)->next = Q;
    (*tail) = (*tail)->next;
}

int popQueue(nodeLLAddress * head){
    int tempValue = (*head)->IDcheck;
    nodeLLAddress P = *head;

    /**if((*head)->next != NULL){
        (*head) = (*head)->next;
        free(P);
        printf("dequee\n");
    }
    else{
        printf("%d Sudah Queue terakhir\n", tempValue);
        //(*head) = NULL;
        free(P);
        *head = NULL;
        printf("%x\n", *head);
        if(*head == NULL)
            printf("head sudah NULL\n");
        printf("free berhasil\n");
        return -1;
    }**/

    (*head) = (*head)->next;
    free(P);
    printf("dequee\n");

    return tempValue;

}

nodeLLAddress popQueuePointer(nodeLLPointerAddress * head){
    nodeLLAddress tempValue = (*head)->trackedAddress;
    nodeLLPointerAddress P = *head;
    printf("Dequeue value = %d\n", (*head)->trackedAddress->ID);

    /**if((*head)->next != NULL){
        (*head) = (*head)->next;
        free(P);
        printf("dequee\n");
    }
    else{
        printf("%d Sudah Queue terakhir\n", tempValue);
        //(*head) = NULL;
        free(P);
        *head = NULL;
        printf("%x\n", *head);
        if(*head == NULL)
            printf("head sudah NULL\n");
        printf("free berhasil\n");
        return -1;
    }**/

    (*head) = (*head)->next;
    free(P);

    if((*head) == NULL)
        return -1;

    printf("dequee\n");

    return tempValue;

}



void printQueue(nodeLLAddress head){
    printf("Head first: %d\n", head->IDcheck);

    printf("Isi dari queue: ");
    while(head != NULL){
        printf("%d ", head->IDcheck);
        head = head->next;
    }
}

void printAddressQueue(nodeLLPointerAddress head){
    printf("Head first: %d\n", head->trackedAddress);

    printf("Isi dari address queue: ");
    while(head != NULL){
        printf("%d ", head->trackedAddress);
        head = head->next;
    }
}

int checkTracked(nodeLLAddress head, int IDtracked){
    while(head != NULL){
        if(IDtracked == head->IDcheck)
            return 1;
        else
            head = head->next;
    }
    return 0;
}
