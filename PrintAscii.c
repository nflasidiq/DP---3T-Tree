#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


char *readFile(char *fileName);

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

int main() {
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


    // Status ASCII art from the file
    const char *status_ascii[] = {
        "                                                                                                    ",
        "                                                                                                    ",
        "                                 .XXXXXXXXXX           .XXXXXXXXXx                                  ",
        "                               XXXXXXXXXxXXXXXx      +XXXXXXXXXXXXXXX.                               ",
        "                             XXXXxxxxxxxxxxxXXXX+  xXXXXxxxxxxxxxxxXXXX                              ",
        "                           ;XXXXxxxXXxxxxxxxXXXXXXXXXXXXxxXXxxXxxxXXXXXX;                           ",
        "                          :XXxxxXXxXxxXXXXXXXXxxXxXXxxxxXXXXXxxxXxxxxXxXX+                          ",
        "                          xXXXXXxxxxxXXXXXXXXXXxXXXXxxXXXXXXXXxxxXXXxxXxXx                          ",
        "                         .XXxXXXXxxXxxXxX. XXXxxxXxxXxxXX: xXxxxxxXXxxXxXX.                         ",
        "                          xXxxXxXxXXXXXXX  :XXXXxxXXXXXXX  .XXXXxxxxXXXxXX                          ",
        "                          XXXXXXXXXX .XXX   XXXXXXXX .XXX   XXXXXXxxxxXxXX                          ",
        "                          XXXXXXXXX: :XX.+xX+X XXXX  :XX xxX+X XXXXXXXXXXX                          ",
        "   .   .                   :::: .;: . XX +X     :.. . XX +X     ;:.....+. .                     .   ",
        "                            XXxx++xXX:+X xX. xXXxxXXX:xX +X. ;XXXx++xxXx                            ",
        "                             XXXXXXXXx.:+XXX:xXXXXXXXX .+xXX:xXXXXXXXXX                             ",
        "                              XXXXxXXX+ :XXXXXXXxxxXXX. .XXXXXXXxxXXX+                              ",
        "                               .XXXXXX+ :XXXxxxxxxxXxX+ .XXxXxxxXXXX.                               ",
        "                                 .XXXX; +XXXXxxxXXxXXX+ +XXxxXXXXX                                  ",
        "                                   :XXXXXXxXxXXxxxxxXXXXXXxxXXXX                                     ",
        "                                     .xXXXXXxxxxXXXxxxxXXxXXXx.                                      ",
        "                                        XXXXxxxxxxxxxxxxXXXx                                         ",
        "                                          XXXXxXXxXXXXXXXX:                                          ",
        "                                           .XXXXXxxXXXX++                                            ",
        "                                              +XXXXXX;                                               ",
        "                                                :XX:                                                 ",
        "                                                                                                    ",
        "                                                                                                    ",

    };


const char *userTree[] = {
        "                                                            ",
        "                                                            ",
        "                                                            ",
        "                           x;$$;x                           ",
        "                         ;X&$;;$&X:                         ",
        "                        +;&:    :&x.                        ",
        "              .;$;.      ;&x    X&X      ::$;.              ",
        "            $&&+:x&&     +&&$Xx$&$:     &&x:+&&&            ",
        "           :&$;    &&      :&&&&$      &&    :X&+           ",
        "           +&X:    &&      xx&&;.      &&    .X&;           ",
        "            &&&$x&$&&   &&&&+XXX&&&&   &&&&+$&&&            ",
        "              $Xx&$$&&$&Xx        $X&&&&$X&x$$              ",
        "                   .&&&    &x$&;X    X&:                    ",
        "          .+      :&&     x&&&&&&$     +&        .          ",
        "       :&&&&&$    &&     &&&&&&&&&&     &&    ;&&&&&:       ",
        "     +x&&    &&$ .&$     $$&&&&&&&x      ;  $&&    &&X+     ",
        "     &&&&    &&&&&&x       ;&&&&x        &&&&&&    &&&&     ",
        "     +x&&    &&&&:&$      :  +.  :      X& &$&&    &&$      ",
        "       :&&&&&X    &&   &&&&&&&&&&&&&&   &&    X&&&&&:       ",
        "          +.      .&&.&&&&&&&&&&&&&&&& &&       :;          ",
        "                    &&&&&&&&&&&&&&&&&&&&.                   ",
        "              $+x$X&&&&&&&&&&&&&&&&&&&&&xX$xx$.             ",
        "            x&&&;&&&&  :$&&&&&&&&&&$ & &&&&;$&&$            ",
        "           +&$:    &&      .:$$;       &&    .$&;           ",
        "           ;&X;    &&      x&&&&x      &&    .X&+           ",
        "            &&&;.X&&     ;;&&xx&&x      &&x::&&&            ",
        "              :;X:.      ;&$    x&x       :$;.              ",
        "                        +;&.    .&X.                        ",
        "                         .$&$;;$&$+                         ",
        "                           ;x$$++                           ",
        "                                                            ",
        "                                                            ",
        "                                                            "
    };


    const char *daftarTerinfeksiArt[] = {
        "                                                            ",
        "                                                            ",
        "                                                            ",
        "                       $X          XX                       ",
        "                    XXX              XX$                    ",
        "                  XXX                  XX$                  ",
        "                X$XX                    X$$X                ",
        "               $XXX                      XXX$               ",
        "              XXXXX                      XXXXX              ",
        "              XXXXX                      XXXXX              ",
        "             $XXXXX        $$XXXX        XXXXXX             ",
        "             XXXXXX    XXXXXXXXXXXX$X    XXXXX$             ",
        "             XXXXXXXXXXXXXXXXXXXXXXXXX$ XXXXXXX             ",
        "           $XXXXXXXXXX$XX$        X$X$XXXXXXXXXXX           ",
        "         XXXXXXXXXXXXX$$            $XXXXXXXXXXXXXX         ",
        "       $XXXXXXXXXX$XXXXXXXXXXX$XXX$XXXXXXXXXXXXXXXXXX       ",
        "      XXX$X$     XXXXXX$XXXXX  X$XXX$XXXXXX     XXXXX$      ",
        "     XXXX       X$XXX   XX$      X$X   XXXXX       XXXX     ",
        "    XXX         XXXX$     $$    $X     $XXXX         XXX    ",
        "    XX           XXXX$     XXXXXX     X$XXX           XX    ",
        "    X             $XXXX    XXXXXX    $$XX$             X    ",
        "    X             XXXXXX    $XX$    XXXXX$             X    ",
        "    X               $XXXX$XXXXXXXX$XXXXX               $    ",
        "                     X$XXXXXXXXX$XXXX$$                     ",
        "                        X$XXXXXX$XX$                        ",
        "                          $XXXXXX$                          ",
        "                         XXXXXXXXX$                         ",
        "          $           X$$XXXXXXXXXXXXX           X          ",
        "           XXXX$XXXX$XXXXXXX$XXX$XXXXXX$XXX$XX$XX           ",
        "               XXXXXXXX$XX        XXXXXX$XXX$               "
    };


    const char *handshake[] = {
        "                                                                     ",
        "                                                                     ",
        "                                                                     ",
        "                                @@@@@%                                ",
        "         #*@@@@@#       #%##@@@@% %%#%@@@@@@#%%%%%%%%%%%%      +%@@@@%%",
        "        *@%   %%@%%%%%%%%@%+    ##@@@#     #%@@@@@@@@@@@@#%%##*@%    @@",
        "       *@%  :@@ %%%%%%%=     -###                       #%%%%%%##   @@",
        "     :-*+  :@@             :-#*    :::::::::                  @@   ##-:",
        "    %%#  #*%#            +@%    *###%%%%%%###                ####   @%",
        "       %%# *@@             %%@%   @%%#       #@@@@                @@   @%",
        "       %%# #@@             %*@@@@@*@            %@@@%             @@   @@",
        "        %%# *@@                                      @@.           @@   @@",
        "         %%# *@%                                        @@@%      %%     @@",
        "         *@@@%:@@@@                                       %@@@@@%# @@@@@",
        "                 @@@@ @@@@@*                    =@@        %%*         ",
        "                    @@+  =*#@@#*+           **    *@@%+###*##*         ",
        "                    @@=  #@* ++%#**+       *%#**+     #@@@%=           ",
        "                    #*---=#=+@% *##*=:       +##*=-=---=*=             ",
        "                      #%@#  +@%   =*%++   -+-   +@@%%%%#               ",
        "                       %%*@@%@%  .@% %@#% #%%@@@%%%                    ",
        "                        *%%@@*@@%##   @@@@@@@@@%                      ",
        "                                 :@@@@@=                                ",
        "                                  ***                                  "
    };

    int dp3t_lines = sizeof(dp3t_logo) / sizeof(dp3t_logo[0]);
//    int additional_lines = sizeof(additional_art) / sizeof(additional_art[0]);
    int status_lines = sizeof(status_ascii) / sizeof(status_ascii[0]);

    int userTree_lines = sizeof(userTree) / sizeof(userTree[0]);

    int daftarTerinfeksiArt_lines = sizeof(daftarTerinfeksiArt) / sizeof(daftarTerinfeksiArt[0]);

    int handshake_lines = sizeof(handshake) / sizeof(handshake[0]);
    // Print DP-3T logo
    printArt(dp3t_logo, dp3t_lines, 'n');

    // Print additional ASCII art
//    printArt(additional_art, additional_lines);

    // Print status ASCII art
    printArt(status_ascii, status_lines, 'g');
    printArt(userTree, userTree_lines, 'b');
    printArt(daftarTerinfeksiArt, daftarTerinfeksiArt_lines, 'r');
    printArt(handshake, handshake_lines, 'r');

    return 0;
}



