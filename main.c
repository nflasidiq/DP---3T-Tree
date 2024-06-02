#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "header.h"
#include "treeUser.h"



    // The DP-3T logo as an array of strings
    const char *dp3t_logo[] = {
        "                                                                                                      ",
        "                                                                                                      ",
        "                     =========                                                                        ",
        "                     =======      ******                                                              ",
        "              ==     =====       **********                                                           ",
        "             ===     ===       **************                                                         ",
        "               .     ==      ******************                                                       ",
        "        ===                *********************=                                                     ",
        "       =====-            ************************.                                                    ",
        "      =========        ***************************                                                    ",
        "     ==========        ****************************                                                   ",
        "    =========            ***************************                                                  ",
        "    ========               *************************                                                  ",
        "    =====            ==       ***********************                                                  ",
        "    ====      ==     ====      **********************                                                  ",
        "   .==      ====     ======      .*******************                                                  ",
        "          ======     ========       *****************                                                  ",
        "        ========     ==========       **************.                                                  ",
        "      ==========     ========.      ****************                                                   ",
        "     ===========     ======.      ******************                                                   ",
        "      ==========     =====      *******************                                                    ",
        "       =========     ===      ********************                                                     ",
        "        ========     :      *********************                                                      ",
        "         =======          **********************       =====                                           ",
        "           =====         *********************         =====                                           ",
        "             ===       *********************           =====                **********   ====          ",
        "                     ********************              =====                ********   .=====          ",
        "                   .*****************          .====   =====         ****       ****   .=====          ",
        "                                            .=============== ***************.  ****** ============     ",
        "                                           ================= *****************   *****.===========     ",
        "                                          =======    ======= *******    *******   **** .=====          ",
        "                                          =====        ===== ******       ***********  .=====          ",
        "                                         .=====        ===== ******       *********    .=====          ",
        "                                          =====        ===== ******       ******       .=====          ",
        "                                          =======    ======= *******    *******        .=====          ",
        "                                           ================= *****************          ==========     ",
        "                                             =============== *****.*********             =========     ",
        "                                                 -=          ******   .*                    .=.        ",
        "                                                             ******                                   ",
        "                                                             ******                                   ",
        "                                                             ******                                   ",
        "                                                             ******                                   ",
        "                                                                                                      ",
        "                                                                                                      "
    };
void setColorGradient(int line, int totalLines, char pallete) {
    // Define the RGB values for the gradient colors
    int startColor[3] = {255, 0, 0};     // Red
    int mid1Color[3] = {255, 165, 0};    // Orange
    int mid2Color[3] = {255, 255, 0};    // Yellow
    int mid3Color[3] = {0, 255, 0};      // Green
    int endColor[3] = {0, 0, 255};       // Blue

    int sectionLength = totalLines / 4;

    int r, g, b;

    if(pallete == 'n'){
        if (line < sectionLength) {
            // Interpolate between red and orange
            r = startColor[0] + (mid1Color[0] - startColor[0]) * line / sectionLength;
            g = startColor[1] + (mid1Color[1] - startColor[1]) * line / sectionLength;
            b = startColor[2] + (mid1Color[2] - startColor[2]) * line / sectionLength;
        } else if (line < 2 * sectionLength) {
            // Interpolate between orange and yellow
            int localLine = line - sectionLength;
            r = mid1Color[0] + (mid2Color[0] - mid1Color[0]) * localLine / sectionLength;
            g = mid1Color[1] + (mid2Color[1] - mid1Color[1]) * localLine / sectionLength;
            b = mid1Color[2] + (mid2Color[2] - mid1Color[2]) * localLine / sectionLength;
        } else if (line < 3 * sectionLength) {
            // Interpolate between yellow and green
            int localLine = line - 2 * sectionLength;
            r = mid2Color[0] + (mid3Color[0] - mid2Color[0]) * localLine / sectionLength;
            g = mid2Color[1] + (mid3Color[1] - mid2Color[1]) * localLine / sectionLength;
            b = mid2Color[2] + (mid3Color[2] - mid2Color[2]) * localLine / sectionLength;
        } else {
            // Interpolate between green and blue
            int localLine = line - 3 * sectionLength;
            r = mid3Color[0] + (endColor[0] - mid3Color[0]) * localLine / sectionLength;
            g = mid3Color[1] + (endColor[1] - mid3Color[1]) * localLine / sectionLength;
            b = mid3Color[2] + (endColor[2] - mid3Color[2]) * localLine / sectionLength;
        }
    }
    else if(pallete == 'r'){
        if (line <  3 * sectionLength) {
            // Interpolate between red and orange
            r = startColor[0] + (mid1Color[0] - startColor[0]) * line / sectionLength;
            g = startColor[1] + (mid1Color[1] - startColor[1]) * line / sectionLength;
            b = startColor[2] + (mid1Color[2] - startColor[2]) * line / sectionLength;
        } else{
            // Interpolate between orange and yellow
            int localLine = line - sectionLength;
            r = mid1Color[0] + (mid2Color[0] - mid1Color[0]) * localLine / sectionLength;
            g = mid1Color[1] + (mid2Color[1] - mid1Color[1]) * localLine / sectionLength;
            b = mid1Color[2] + (mid2Color[2] - mid1Color[2]) * localLine / sectionLength;
        }
    }
    else if(pallete == 'g'){
         if (line < 3 * sectionLength) {
            // Interpolate between yellow and green

            r = mid2Color[0] + (mid3Color[0] - mid2Color[0]) * line / sectionLength;
            g = mid2Color[1] + (mid3Color[1] - mid2Color[1]) * line / sectionLength;
            b = mid2Color[2] + (mid3Color[2] - mid2Color[2]) * line / sectionLength;
        } else {
            // Interpolate between green and blue
            int localLine = line - 4 * sectionLength;
            r = mid3Color[0] + (endColor[0] - mid3Color[0]) * localLine / sectionLength;
            g = mid3Color[1] + (endColor[1] - mid3Color[1]) * localLine / sectionLength;
            b = mid3Color[2] + (endColor[2] - mid3Color[2]) * localLine / sectionLength;
        }
    }
    else if(pallete == 'b'){
         if (line < 3 * sectionLength) {
            // Interpolate between yellow and green
            r = mid2Color[0] + (mid3Color[0] - mid2Color[0]) * line / sectionLength;
            g = mid2Color[1] + (mid3Color[1] - mid2Color[1]) * line / sectionLength;
            b = mid2Color[2] + (mid3Color[2] - mid2Color[2]) * line / sectionLength;
        } else {
            // Interpolate between green and blue
            int localLine = line - 4 * sectionLength;
            r = mid3Color[0] + (endColor[0] - mid3Color[0]) * localLine / sectionLength;
            g = mid3Color[1] + (endColor[1] - mid3Color[1]) * localLine / sectionLength;
            b = mid3Color[2] + (endColor[2] - mid3Color[2]) * localLine / sectionLength;
        }
    }



    // Set the color using 256-color mode
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

// Function to get the terminal width on Windows
int getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return columns;
}

void printArt(const char **art, int totalLines, char pallete) {
    int terminalWidth = getTerminalWidth();

    // Calculate padding for centering the art
    int artWidth = strlen(art[0]);
    int padding = (terminalWidth - artWidth) / 2;

    // Print each line of the art with a gradient color
    for (int i = 0; i < totalLines; i++) {
        setColorGradient(i, totalLines, pallete);
        // Print padding spaces
        for (int j = 0; j < padding; j++) {
            printf(" ");
        }
        // Print the art line
        printf("%s\n", art[i]);
    }

    // Reset text color to default
    printf("\033[0m");
}

const int dp3t_lines = sizeof(dp3t_logo) / sizeof(dp3t_logo[0]);

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

    // Print DP-3T logo

    // Print additional ASCII art
//    printArt(additional_art, additional_lines);

    // Print status ASCII art


int main() {
    Session session;
    int choice = 1;
    int registerChoice = 1;
    bool exit_program = false;
    char c, pause;
    printArt(dp3t_logo, dp3t_lines, 'n');
    scanf("%c", &pause);





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
