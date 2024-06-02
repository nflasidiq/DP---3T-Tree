#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>

// Definisi warna
#define RESET "\033[0m" // Reset semua gaya dan warna teks ke default.
#define BOLD "\033[1m" // Bold (tebal).
#define REDUP "\033[2m" // teks jadi redup.
#define ITALIC "\033[3m" // Italic (miring).
#define Uline "\033[4m" // Underline (garis bawah).
#define KEDIP "\033[5m" // teks kedap-kedip.
#define BCOLOR "\033[7m" // background menyesuaikan warna teks.
#define GONE "\033[8m" // Menghilangkan teks.
#define CORET "\033[9m" // Mencoret teks.
#define BLACK "\033[30m" // Warna teks hitam.
#define RED "\033[31m" // Warna teks merah.
#define GREEN "\033[32m" // Warna teks hijau.
#define LGREEN "\033[92m" //Warna teks hijau terang.
#define YELLOW "\033[93m" //Warna teks kuning.
#define ORANGE "\033[33m" // Warna teks Jingga.
#define BLUE "\033[34m" // Warna teks biru.
#define LBLUE "\033[94m" // Warna teks biru terang.
#define PURPLE "\033[35m" // Warna teks ungu.
#define CYAN "\033[36m" // Warna teks cyan/biru muda.
#define WHITE "\033[37m" // Warna teks putih.
#define BBLACK "\033[40m" // Warna latar belakang hitam.
#define BRED "\033[41m" // Warna latar belakang merah.
#define BGREEN "\033[42m" // Warna latar belakang hijau.
#define BYELLOW "\033[43m" // Warna latar belakang kuning.
#define BBLUE "\033[44m" // Warna latar belakang biru.
#define BPURPLE "\033[45m" // Warna latar belakang ungu.
#define BCYAN "\033[46m" // Warna latar belakang cyan.
#define BWHITE "\033[47m"  // Warna latar belakang putih.

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
void print_menu(char **choices, int highlight, int n_choices);
const char* getColor(int index);

#endif // HEADER_H
