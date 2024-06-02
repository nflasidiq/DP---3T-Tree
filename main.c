#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "header.h"
#include "treeUser.h"

void print_menu_awal(int highlight) {
    const char *choices[] = { "Login", "Register", "Keluar program" };
    int n_choices = sizeof(choices) / sizeof(char *);
    system("cls");
    printf("=== Menu ===\n");
    int i;
    for(i = 0; i < n_choices; ++i) {    
        if(highlight == i + 1) {
            printf("-> %s\n", choices[i]);
        } else {
            printf("   %s\n", choices[i]);
        }
    }
}

void print_register_menu(int highlight) {
    const char *choices[] = { "Register sebagai pengguna", "Register sebagai admin", "Kembali" };
    int n_choices = sizeof(choices) / sizeof(char *);
    system("cls");
    printf("=== Register ===\n");
    int i;
	for(i = 0; i < n_choices; ++i) {    
        if(highlight == i + 1) {
            printf("-> %s\n", choices[i]);
        } else {
            printf("   %s\n", choices[i]);
        }
    }
}

int main() {
    Session session;
    int choice = 1;
    int registerChoice = 1;
    bool exit_program = false;
    char c;

    while (!exit_program) {
        print_menu_awal(choice);
        c = _getch();
        switch(c) {
            case 72: // Arrow up
                if(choice == 1)
                    choice = 3;
                else
                    --choice;
                break;
            case 80: // Arrow down
                if(choice == 3)
                    choice = 1;
                else 
                    ++choice;
                break;
            case 13: // Enter key
                switch(choice) {
                    case 1:
                        system("cls");
                        loginAllUser(&session);
                        break;
                    case 2:
                        while (true) {
                            print_register_menu(registerChoice);
                            c = _getch();
                            switch(c) {
                                case 72: // Arrow up
                                    if(registerChoice == 1)
                                        registerChoice = 3;
                                    else
                                        --registerChoice;
                                    break;
                                case 80: // Arrow down
                                    if(registerChoice == 3)
                                        registerChoice = 1;
                                    else
                                        ++registerChoice;
                                    break;
                                case 13: // Enter key
                                    switch(registerChoice) {
                                        case 1:
                                            system("cls");
                                            registerUser();
                                            break;
                                        case 2:
                                            system("cls");
                                            registerAdmin();
                                            break;
                                        case 3:
                                            goto main_menu; // Break out of the registration menu loop
                                    }
                                    break;
                            }
                        }
                        main_menu: // Label to return to main menu
                        break;
                    case 3:
                        exit_program = true;
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
