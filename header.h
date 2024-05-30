<<<<<<< HEAD
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct dataUser *address;
typedef struct dataUser {
    char username[20];
    char password[20];
    int id;
    address fs, nb, pr;
} User;

typedef enum {
    BASIC_USER,
    ADMIN_USER
} UserType;

typedef struct session {
    User user;
    UserType type;
} Session;

void registerAdmin();
void registerUser();
void showUserInformation(const char *currentUsername);
bool isFileExist(const char *filename);
bool isUsernameUsed(const char *username);
bool isIDUsed(int id, const char *username);
bool isIDExist(int id);
void inputDuration(int selectedID);
int generateID();
int generateUniqueID(User newUser);
void createUserFile(User newUser);
void loginAllUser(Session *session);

#endif // HEADER_H
=======
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct dataUser *address;
typedef struct dataUser {
    char username[20];
    char password[20];
    int id;
    address fs, nb, pr;
} User;

typedef enum {
    BASIC_USER,
    ADMIN_USER
} UserType;

typedef struct session {
    User user;
    UserType type;
} Session;

void registerAdmin();
void registerUser();
// void showUserInformation(const char *currentUsername);
void logContact(User *currentSession); //Sama seperti showUserInformation
bool isFileExist(const char *filename);
bool isUsernameUsed(const char *username);
bool isIDUsed(int id, const char *username);
bool isIDExist(int id);
// void inputDuration(int selectedID);
int generateID();
int generateUniqueID(User newUser);
void createUserFile(User newUser);
void loginAllUser(Session *session);
void reportInfection(User *currentSession);

#endif // HEADER_H
>>>>>>> naufal
