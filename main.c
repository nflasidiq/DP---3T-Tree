<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "header.h"
#include "ridho.h"

#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

int main() {
	Session session;
    int choice;

    while (true) {
    	system("cls");
        printf("=== Menu ===\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Keluar program\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
            	system("cls");
                loginAllUser(&session);
                break;
            case 2:
            	register_menu:
            	system("cls");
                printf("=== Register ===\n");
                printf("1. Register sebagai pengguna\n");
                printf("2. Register sebagai admin\n");
                printf("3. Kembali\n");
                printf("Masukkan pilihan: ");
                int registerChoice;
                scanf("%d", &registerChoice);



				switch (registerChoice){
					case 1:
						system("cls");
						registerUser();
						break;
					case 2:
						system("cls");
						registerAdmin();
						break;
					case 3:
						break;
					default:
						printf("Pilihan salah. Ulangi lagi!");
						sleep(2);
						system("cls");
						goto register_menu;
				}
				break;
            case 3:
                exit(0);
                break;
            default:
                printf("Pilihan salah. Masukkan pilihan dengan benar!");
                sleep(2);
                system("cls");
                break;

        }
    }
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "header.h"
#include "treeUser.h"

#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

int main() {
	Session session;
    int choice;

    while (true) {
    	system("cls");
        printf("=== Menu ===\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Keluar program\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
            	system("cls");
                loginAllUser(&session);
                break;
            case 2:
            	register_menu:
            	system("cls");
                printf("=== Register ===\n");
                printf("1. Register sebagai pengguna\n");
                printf("2. Register sebagai admin\n");
                printf("3. Kembali\n");
                printf("Masukkan pilihan: ");
                int registerChoice;
                scanf("%d", &registerChoice);

				switch (registerChoice){
					case 1:
						system("cls");
						registerUser();
						break;
					case 2:
						system("cls");
						registerAdmin();
						break;
					case 3:
						break;
					default:
						printf("Pilihan salah. Ulangi lagi!");
						sleep(2);
						system("cls");
						goto register_menu;
				}
				break;
            case 3:
                exit(0);
                break;
            default:
                printf("Pilihan salah. Masukkan pilihan dengan benar!");
                sleep(2);
                system("cls");
                break;

        }
    }
    return 0;
}
>>>>>>> naufal
