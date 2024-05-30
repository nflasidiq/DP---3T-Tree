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

NodeUser* insertLevelOrder(NodeUser * parent, int IDcontact, nodeLLPointerAddress queueHead, int stats,nodeLLPointerAddress * queueTail){
    nodeAddress C = newNode(IDcontact);
    if(C == NULL)
        exit(1);

    /**
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
            Pr = insertLevelOrder(C, IDuser, stats, &(*queueTail), &(*trackedTail));
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
    }**/
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

    insertQueueAddress(C, &(*queueTail));
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
    nodeAddress root = NULL;
    nodeAddress levelInsert = NULL;

    root = intializeTree(IDuser);
    levelInsert = root;
    nodeLLPointerAddress queueHead = NULL, queueTail = NULL;
    nodeLLAddress trackHead = NULL, trackTail = NULL;

    intializeQueuePointer(root, &queueHead, &queueTail);
    intializeQueue(IDuser, &trackHead, &trackTail);
    printf("Hasil inisiasi queue = %x\n", queueHead->trackedAddress);
    int tracked = 0;
    int IDuserFromAllUser = IDuser;
    char usernameFile[100], passwordFile[100];
    int jump = 0;
    while(queueHead != NULL){
        FILE *AllUserFile = fopen("AllUser.txt", "r");
        while(fscanf(AllUserFile, "%d %s %s", &IDuserFromAllUser, usernameFile, passwordFile) != EOF){
            if(IDuserFromAllUser == queueHead->trackedAddress->ID){
                strcpy(username_input, usernameFile);
                break;
            }
            else
                continue;
        }

        if(jump == 0)
        {
            printf("jump\n");
            //nodeAddress addressPop = popQueuePointer(&queueHead);
        }
        else{
            tracked = checkTracked(trackHead, IDuserFromAllUser);
            printf("Tracked = %d\n", tracked);
        }

        if(tracked == 0)
        {
            strncat(username_input, ".txt", 5);
            FILE *userFile = fopen(username_input, "r");
            char fileContent;
            int status = 0;

            printf("sekarang sedang melakukan read terhadap file: %s\n", username_input);
            while(fscanf(userFile, "%d", &IDuser) != EOF){
                    printf("Hasil read file %d\n", IDuser);
                    levelInsert = insertLevelOrder(levelInsert, IDuser,queueHead, status, &queueTail);
                    status = 1;
            }
            printTreePreOrder(root);
            fclose(userFile);
            nodeAddress addressPop = popQueuePointer(&queueHead);
            levelInsert = queueHead->trackedAddress;
            printf("Node yang selanjutnya ter-attach: %x value %d\n",levelInsert,levelInsert->ID);
            if(queueHead == NULL){
                printf("queue kosong\n");
                break;
            }
            insertQueue(addressPop->ID, &trackTail);
            printQueue(trackHead);


            printAddressQueue(queueHead);

        }
        else{
            printAddressQueue(queueHead);
            nodeLLAddress IDpop;
            IDpop = popQueuePointer(&queueHead);
            if(queueHead == NULL){
                printf("berhasil dequee akhir\n");
                break;
            }

            printf("%x Sudah dikunjungi\n", IDpop);

        }

        jump++;
    }

    printf("sudah bisa sampe sini\n");
    printQueue(trackHead);

    printf("Address root: %x\n", root);
    printTreePreOrder(root);


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

    printf("\nTree dari user mana yang ingin dilihat?\nID = ");
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
	getchar();
    scanf("%c", &terminator);

}
