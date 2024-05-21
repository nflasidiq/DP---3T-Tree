#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "treeUser.h"
#include "queue.h"
#include "header.h"

//int serializeTree(){}
NodeUser* intializeTree(int ID){
    nodeAddress R = (NodeUser*)malloc(sizeof(NodeUser));
    R->ID = ID;
    R->parent = NULL;
    R->nextBrother = NULL;
    return R;
}

NodeUser* newNode(int ID){
    nodeAddress N = (NodeUser*)malloc(sizeof(NodeUser));
    N->ID = ID;
    N->parent = NULL;
    N->nextBrother = NULL;
    N->firstSon = NULL;
    return N;
}

NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, int stats, nodeLLAddress * queueTail, nodeLLAddress * trackedTail){
    nodeAddress C = newNode(IDcontact);
    if(C == NULL)
        exit(1);


    if(C->ID == 16){//demonstrasi tracing lebih lanjut
        FILE *trackFile = fopen("naufal.txt", "r");
        char fileContent;

        int IDuser;
        if(stats == 0){
            C->ID = IDcontact;
            C->parent = parent;
            C->nextBrother = NULL;
            C->firstSon = NULL;
            parent->firstSon = C;
        }
        else{
            NodeUser *linkNextBrother = parent->firstSon;
            while(linkNextBrother->nextBrother != NULL)
                linkNextBrother = linkNextBrother->nextBrother;

            C->ID = IDcontact;
            C->parent = parent;
            C->nextBrother = NULL;
            C->firstSon = NULL;
            linkNextBrother->nextBrother = C;
        }

        nodeAddress Pr = C;
        stats = 0;
        while(fscanf(trackFile, "%d", &IDuser) != EOF){
            Pr = insertLevelOrder(C, IDuser, stats, &queueTail, &trackedTail);
            stats = 1;
        }


    }
    else{
        NodeUser *queue[100];
        if(stats == 0){
            C->ID = IDcontact;
            C->parent = parent;
            C->nextBrother = NULL;
            C->firstSon = NULL;
            parent->firstSon = C;
        }
        else{
            NodeUser *linkNextBrother = parent->firstSon;
            while(linkNextBrother->nextBrother != NULL)
                linkNextBrother = linkNextBrother->nextBrother;

            C->ID = IDcontact;
            C->parent = parent;
            C->nextBrother = NULL;
            C->firstSon = NULL;
            linkNextBrother->nextBrother = C;
        }
    }
    return parent;
}

void printTreePreOrder(NodeUser *tree){
    NodeUser *currentNode = tree;
    int level = 0, traverseStatus = 1;
    bool lewat = false;

    printf("%d\n", currentNode->ID);

    while(traverseStatus == 1){
        int i = 0;
        if(currentNode->firstSon != NULL && !lewat){
            level++;
            currentNode = currentNode->firstSon;
            while(i <= level)
            {
                printf(" ");
                i++;
            }
            printf("%d\n", currentNode->ID);
            lewat = false;
        }
        else if(currentNode->nextBrother  != NULL){
            currentNode = currentNode->nextBrother;
            while(i <= level)
            {
                printf(" ");
                i++;
            }
            printf("%d\n", currentNode->ID);
            lewat = false;
        }
        else{
            level--;
            currentNode = currentNode->parent;
            lewat = true;
            if(currentNode->parent == NULL)
                traverseStatus = 0;
        }
    }

}

int deserializeTree(char* username_input, int IDuser){
    strncat(username_input, ".txt", 5);
    FILE *userFile = fopen(username_input, "r");
    char fileContent;
    int status = 0;
    nodeLLAddress head;


    printf("sekarang sedang melakukan read terhadap file: %s\n", username_input);
    nodeAddress root = NULL;
    root = intializeTree(IDuser);
    nodeLLAddress queueHead = NULL, queueTail = NULL, trackHead = NULL, trackTail = NULL;

    intializeQueue(IDuser, &queueHead, &queueTail);
    intializeQueue(IDuser, &trackHead, &trackTail);
    bool tracked = false;
    while(fscanf(userFile, "%d", &IDuser) != EOF){
        //tracked = checkTracked(IDuser, trackHead);
        if(!(tracked)){
            root = insertLevelOrder(root, IDuser, status, &queueTail, &trackTail);
            status = 1;
        }
    }

    printTreePreOrder(root);

    fclose(userFile);

    return 0;
}


void adminLihatTreeUser(){
    printf("Berikut adalah daftar user:\n\n");
    FILE *userFile = fopen("AllUser.txt", "r");
    if(userFile == NULL)
        exit(1);
    int IDuser, IDinput;
    char usernameFile[20], passwordFile[20], terminator;

    while(fscanf(userFile, "%d %s %s", &IDuser, usernameFile, passwordFile) != EOF){
        printf("%d %s %s\n", IDuser, usernameFile, passwordFile);
    }

    scanf("%c", &terminator);

    printf("Tree dari user mana yang ingin dilihat?\nID = ");
    scanf("%d", &IDinput);


    rewind(userFile);


    while(fscanf(userFile, "%d %s %s", &IDuser, usernameFile, passwordFile) != EOF){
        if(IDinput == IDuser){
            fclose(userFile);
            printf("ID %d berhasil dipilih\n\nBerikut merupakan tree dari user %s\n\n", IDinput, usernameFile);
            deserializeTree(usernameFile, IDinput);
            scanf("%c", &terminator);

        }
    }

    scanf("%c", &terminator);

}




