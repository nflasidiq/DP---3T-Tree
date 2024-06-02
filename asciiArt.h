#ifndef asciiArt_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


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
    const char *status_asciiArt[] = {
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


const char *userTreeArt[] = {
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


    const char* handshakeArt[] = {
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

    void setColorGradient(int line, int totalLines, char pallete);
    int getTerminalWidth();
    void printArt(const char **art, int totalLines, char pallete);

#endif


