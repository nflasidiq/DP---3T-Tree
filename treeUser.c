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
            while(i < level)
            {
                printf("--|");
                i++;
            }
            printf("%d\n", currentNode->ID);
            lewat = false;
        }
        else if(currentNode->nextBrother  != NULL){
            currentNode = currentNode->nextBrother;
            while(i < level)
            {
                printf("--|");
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
    int tracked = 0;
    int IDuserFromAllUser = IDuser;
    char usernameFile[100], passwordFile[100];
    int jump = 0;
    while(queueHead != NULL){
        FILE *AllUserFile = fopen("AllUser.txt", "r");
        while(fscanf(AllUserFile, "%d %s %s", &IDuserFromAllUser, usernameFile, passwordFile) != EOF){
            if(IDuserFromAllUser == levelInsert->ID){
                strcpy(username_input, usernameFile);
                break;
            }
            else
                continue;
        }

        if(jump == 0)
        {
            //nodeAddress addressPop = popQueuePointer(&queueHead);
        }
        else{
            tracked = checkTracked(trackHead, levelInsert->ID);

        }

        if(tracked == 0)
        {
            strncat(username_input, ".txt", 5);
            FILE *userFile = fopen(username_input, "r");
            char fileContent;
            char timeStampBuffer[50];
            int status = 0;

            while(fscanf(userFile, "%d %s", &IDuser, timeStampBuffer) != EOF){
                    if(jump != 0){
                        if(IDuser != levelInsert->parent->ID){
                            levelInsert = insertLevelOrder(levelInsert, IDuser,queueHead, status, &queueTail);
                            status = 1;
                        }
                        else
                            continue;
                    }
                    else{
                        levelInsert = insertLevelOrder(levelInsert, IDuser,queueHead, status, &queueTail);
                        status = 1;
                    }

            }
            fclose(userFile);
            nodeAddress addressPop = popQueuePointer(&queueHead);
            if(queueHead == NULL){
                break;
            }
            levelInsert = queueHead->trackedAddress;
            insertQueue(addressPop->ID, &trackTail);

        }
        else{
            nodeLLAddress IDpop;
            IDpop = popQueuePointer(&queueHead);
            if(queueHead == NULL){
                break;
            }
            levelInsert = queueHead->trackedAddress;
        }

        jump++;
    }

    printTreePreOrder(root);


    return 0;
}

int countTendency(nodeAddress root, int IDdiagnosed){
    NodeUser *currentNode = root;
    int level = 0, traverseStatus = 1, foundDiagnosed = 0;
    bool lewat = false;

    printf("%d\n", currentNode->ID);

    while(traverseStatus == 1 &&  foundDiagnosed == 0){
        if(currentNode->ID == IDdiagnosed)
            break;

        int i = 0;
        if(currentNode->firstSon != NULL && !lewat){
            level++;
            currentNode = currentNode->firstSon;
            while(i < level)
            {
                printf("--|");
                i++;
            }
            printf("%d\n", currentNode->ID);
            lewat = false;
        }
        else if(currentNode->nextBrother  != NULL){
            currentNode = currentNode->nextBrother;
            while(i < level)
            {
                printf("--|");
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

    return level;
}

int treeDiagnoseStatus(char* username_input, int IDuser, int IDdiagnosed){
    nodeAddress root = NULL;
    nodeAddress levelInsert = NULL;

    root = intializeTree(IDuser);
    levelInsert = root;
    nodeLLPointerAddress queueHead = NULL, queueTail = NULL;
    nodeLLAddress trackHead = NULL, trackTail = NULL;

    intializeQueuePointer(root, &queueHead, &queueTail);
    intializeQueue(IDuser, &trackHead, &trackTail);
    int tracked = 0, thereisUser = 0;
    int IDuserFromAllUser = IDuser;
    char usernameFile[100], passwordFile[100];
    int jump = 0, found = 0;
    while(queueHead != NULL && found == 0){
        FILE *AllUserFile = fopen("AllUser.txt", "r");
        while(fscanf(AllUserFile, "%d %s %s", &IDuserFromAllUser, usernameFile, passwordFile) != EOF){
            if(IDuserFromAllUser == levelInsert->ID){
                strcpy(username_input, usernameFile);
                break;
            }
            else
                continue;
        }

        if(jump == 0)
        {
            //nodeAddress addressPop = popQueuePointer(&queueHead);
        }
        else{
            tracked = checkTracked(trackHead, levelInsert->ID);

        }

        if(tracked == 0)
        {
            strncat(username_input, ".txt", 5);
            FILE *userFile = fopen(username_input, "r");
            char fileContent;
            char timeStampBuffer[50];
            int status = 0;

            while(fscanf(userFile, "%d %s", &IDuser, timeStampBuffer) != EOF){
                    if(jump != 0){
                        if(IDuser != levelInsert->parent->ID){
                            levelInsert = insertLevelOrder(levelInsert, IDuser,queueHead, status, &queueTail);
                            status = 1;
                        }
                        else
                            continue;

                    }
                    else{
                        levelInsert = insertLevelOrder(levelInsert, IDuser,queueHead, status, &queueTail);
                        status = 1;
                    }

                    if(IDuser == IDdiagnosed){
                        thereisUser = 1;
                        found = 1;
                        break;
                    }
                    else
                        continue;

            }
            fclose(userFile);
            nodeAddress addressPop = popQueuePointer(&queueHead);
            if(queueHead == NULL){
                break;
            }
            levelInsert = queueHead->trackedAddress;
            insertQueue(addressPop->ID, &trackTail);



        }
        else{
            nodeLLAddress IDpop;
            IDpop = popQueuePointer(&queueHead);
            if(queueHead == NULL){
                break;
            }
            levelInsert = queueHead->trackedAddress;
        }

        jump++;
    }

    return thereisUser == 1 ? countTendency(root, IDdiagnosed) : MAX;
}

int diagnoseInfectionStatus(int IDdiagnose){
    FILE *fileTerinfeksi = fopen("userTerinfeksi.txt", "r");
    int IDtraced;
    char username[100], password[100];
    int statusDiagnose, pastStatusDiagnose = MAX;
    while(fscanf(fileTerinfeksi, "%d %s", &IDtraced, username) != EOF){
        if(IDtraced != IDdiagnose){
            int temp = treeDiagnoseStatus(username, IDtraced, IDdiagnose);
            statusDiagnose = temp < pastStatusDiagnose ?  temp : pastStatusDiagnose;
            pastStatusDiagnose = statusDiagnose;
        }
        else
            return 0;
    }



    return statusDiagnose;

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
printf("\nKlik Enter untuk melanjutkan");
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
    printf("\nKlik Enter untuk kembali ke menu");
    scanf("%c", &terminator);

}