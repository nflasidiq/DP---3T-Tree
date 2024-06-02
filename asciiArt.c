#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "asciiArt.h"
// Function to set the color based on the gradient
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
