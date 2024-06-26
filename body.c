#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "header.h"
#include "treeUser.h"


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


// Function to get the terminal width on Windows


//    int additional_lines = sizeof(additional_art) / sizeof(additional_art[0]);
const int status_lines = sizeof(status_asciiArt) / sizeof(status_asciiArt[0]);

const int userTree_lines = sizeof(userTreeArt) / sizeof(userTreeArt[0]);

const int daftarTerinfeksiArt_lines = sizeof(daftarTerinfeksiArt) / sizeof(daftarTerinfeksiArt[0]);

const int handshake_lines = sizeof(handshakeArt) / sizeof(handshakeArt[0]);


bool isIDExist(int id) {
    FILE *filePointer;
    char filename[] = "AllUser.txt";
    int existingID;
    bool found = false;

    // Membuka file AllUser.txt
    filePointer = fopen(filename, "r");

    // Memeriksa apakah file berhasil dibuka
    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return false; // Keluar dari fungsi jika file tidak dapat dibuka
    }

    // Membaca file baris per baris
    char line[100];
    while (fgets(line, sizeof(line), filePointer) != NULL) {
        // Membaca ID dari setiap baris
        sscanf(line, "%d", &existingID);
        // Memeriksa apakah ID cocok dengan yang dicari
        if (existingID == id) {
            found = true; // ID ditemukan di file
            break; // Keluar dari loop jika ID ditemukan
        }
    }

    // Menutup file setelah selesai membaca
    fclose(filePointer);

    return found; // Mengembalikan hasil pencarian ID
}



void print_all_users() {
    FILE *file = fopen("AllUser.txt", "r");
    if (!file) {
        printf("Error: file AllUser.txt tidak dapat dibuka\n");
        exit(1);
    }

    printf("%-20s %-20s %-20s\n", "ID", "Nama", "Password");
    printf("------------------------------------------------------------\n");

    char ID[20], name[20], password[30];
    while (fscanf(file, "%s %s %s", ID, name, password) == 3) {
        printf("%-20s %-20s %-20s\n", ID, name, password);
    }

    fclose(file);
    printf("\nKlik Enter untuk kembali ke menu");getchar();
}

void print_tree(const char *filename) {
    system(filename);
}


bool isFileExist(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return true;
    }
    return false;
}

bool isUsernameUsed(const char *username) {
    char filename[20];
    sprintf(filename, "%s.txt", username);
    FILE *filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        return false; // File tidak ditemukan, username belum digunakan
    } else {
        fclose(filePointer);
        return true; // File ditemukan, username sudah digunakan
    }
}

bool isIDUsed(int id, const char *username) {
    char filename[20];
    sprintf(filename, "%s.txt", username);
    FILE *filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        return false; // File tidak ditemukan, ID belum digunakan
    } else {
        int existingID;
        fscanf(filePointer, "%d", &existingID); // Membaca ID yang ada di file
        fclose(filePointer);
        return existingID == id; // Mengembalikan true jika ID sudah digunakan
    }
}

int generateID() {
    return rand() % 100 + 0;
}

int generateUniqueID(User newUser) {
    int id;
    do {
        id = generateID();
    } while (isIDUsed(id, newUser.username));
    return id;
}

// Fungsi untuk membuat file .txt untuk pengguna baru
void createUserFile(User newUser) {
    FILE *filePointer;
    char filename[20];
	char filename2[20];

    strcpy(filename, newUser.username);
    strcat(filename, ".txt"); //file agar.txt

    // Membuka file dengan mode "w" (menulis)
    filePointer = fopen(filename, "a");

    // Memeriksa apakah file berhasil dibuka
    if (filePointer == NULL) {
        printf("Gagal membuat file.\n");
    } else {
        // Menulis informasi pengguna ke dalam file
        // fprintf(filePointer, "%d ", newUser.id);
        // fprintf(filePointer, "%s ", newUser.username);
        // fprintf(filePointer, "%s", newUser.password);
        printf("File %s berhasil dibuat untuk pengguna baru.\n", newUser.username);
        fclose(filePointer);
    }

	// Membuat nama file kedua sebagai "AllUser.txt"
	strcpy(filename2, "AllUser.txt");

	// Membuka file kedua dengan mode "a" (append)
	filePointer = fopen(filename2, "a");

	// Memeriksa apakah file berhasil dibuka
	if (filePointer == NULL) {
	    printf("Gagal membuat file.\n");
	} else {
	    // Menulis informasi pengguna ke dalam file kedua
	    fprintf(filePointer, "%d ", newUser.id);
	    fprintf(filePointer, "%s ", newUser.username);
	    fprintf(filePointer, "%s\n", newUser.password); // tambahkan newline untuk pemisah antar pengguna
//	    printf("File %s berhasil dibuat untuk pengguna baru.\n", filename2);
	    fclose(filePointer);
	}

}

void registerUser() {
    User newUser;
    srand(time(0));

    // Meminta pengguna untuk memasukkan nama pengguna
    printf("Masukkan nama pengguna: ");
    scanf("%s", newUser.username);

    while (isUsernameUsed(newUser.username)) {
    	system("cls");
        printf("Username sudah digunakan, masukkan username lain: ");
        scanf("%s", newUser.username);
    }

    printf("Masukkan password: ");
    scanf("%s", newUser.password);

    newUser.id = generateUniqueID(newUser);

    // Memanggil fungsi untuk membuat file .txt untuk pengguna baru
    createUserFile(newUser);
    sleep(2);
}

void createAdminFile(User newAdmin) {
    FILE *filePointer;
    char filename[20] = "admin.txt";

    // Membuka file dengan mode "a" (append)
    filePointer = fopen(filename, "a");

    // Memeriksa apakah file berhasil dibuka
    if (filePointer == NULL) {
        printf("Gagal membuat file.\n");
    } else {
        // Menulis informasi admin ke dalam file
        fprintf(filePointer, "%s %s\n", newAdmin.username, newAdmin.password);
        printf("Admin %s berhasil didaftarkan.\n", newAdmin.username);
        fclose(filePointer);
    }
}

//Register Admin
void registerAdmin() {
    User newAdmin;
    srand(time(0));

    // Meminta admin untuk memasukkan nama pengguna
    printf("Masukkan nama pengguna admin: ");
    scanf("%s", newAdmin.username);

    while (isUsernameUsed(newAdmin.username)) {
    	system("cls");
        printf("Username sudah digunakan, masukkan username lain: ");
        scanf("%s", newAdmin.username);
    }

    printf("Masukkan password: ");
    scanf("%s", newAdmin.password);

    // Memanggil fungsi untuk membuat file .txt untuk admin baru
    createAdminFile(newAdmin);
}

void logContact(User *currentSession) {
    char contactUsername[50];
    int duration;

    time_t now;
    struct tm * timeinfo;
    time( &now );
    timeinfo = localtime( &now );
    char nowInfo[50];
    strftime(nowInfo, sizeof(nowInfo), "%x-%I:%M%p", timeinfo);
    printf("Time now before: %s\n", nowInfo);

    // Membuka file AllUser.txt untuk membaca daftar pengguna
    FILE *filePointer;
    char filename[] = "AllUser.txt";
    char buffer[60]; // Buffer untuk menyimpan baris yang dibaca
    char username[50];
    int id;
    bool userFound = false;


    do {
        // Membuka file AllUser.txt
        filePointer = fopen(filename, "r");
        if (filePointer == NULL) {
            printf("Error: Gagal membuka file AllUser.txt.\n");
            return;
        }

        // Menampilkan daftar pengguna kecuali pengguna yang sedang login
        printf("Daftar Pengguna:\n");
        while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
            sscanf(buffer, "%d %s", &id, username);
            if (strcmp(username, currentSession->username) != 0) {
                printf("%d %s\n", id, username);
            }
        }
        fclose(filePointer);

        // Meminta input username kontak
        printf("\nMasukkan username kontak: ");
        scanf("%s", contactUsername);

        // Cek apakah contactUsername sama dengan username yang sedang login
        if (strcmp(contactUsername, currentSession->username) == 0) {
            printf("Tidak boleh kontak diri sendiri. Masukkan nama yang ada didaftar.\n");
            sleep(2);
        }
    } while (strcmp(contactUsername, currentSession->username) == 0);


    // Membuka kembali file AllUser.txt untuk memeriksa keberadaan username
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error: opening AllUser.txt.\n");
        sleep(2);
        return;
    }

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        sscanf(buffer, "%d %s", &id, username);
        if (strcmp(username, contactUsername) == 0) {
            userFound = true;
            break;
        }

    }
    fclose(filePointer);

    // Jika username tidak ditemukan, keluarkan pesan kesalahan
    if (!userFound) {
        printf("Username tidak ada di AllUser.txt.\n");
        sleep(2);
        return;
    }

    // Meminta input durasi kontak dalam menit
    printf("Masukkan durasi kontak (menit): ");
    scanf("%d", &duration);


    // Jika durasi lebih dari 10 menit, log kontak
    if (duration >= 10) {
        char contactFilename[50 + 4];
        sprintf(contactFilename, "%s.txt", currentSession->username); // Menggunakan username pengguna yang sedang login
        char timestampTemp[50];
        int IDtemp, duplicate = 0;
        // Membuka file dalam mode append
        FILE *contactFile = fopen(contactFilename, "r");
        FILE *tempFile = fopen("tempFile.txt", "w");

        if (contactFile == NULL || tempFile == NULL) {
            printf("Error: gagal membuka file.\n");
            sleep(2);
            return;
        }
        while(fscanf(contactFile, "%d %s",&IDtemp, timestampTemp) != EOF){
            if(IDtemp == id){
                fprintf(tempFile, "%d %s\n", IDtemp, nowInfo);
                duplicate = 1;
            }
            else
                fprintf(tempFile, "%d %s\n", IDtemp, timestampTemp);
        }

        if(duplicate == 0)
            fprintf(tempFile, "%d %s\n", id, nowInfo);

        printf("ID B ke A: %d\n", id);

        // Menambahkan ID kontak ke file pengguna yang sedang login
        fclose(contactFile);
        fclose(tempFile);

        //update contactFile dengan cara copy paste dari tempFile
        contactFile = fopen(contactFilename, "w");
        tempFile = fopen("tempFile.txt", "r");


        while(fscanf(tempFile, "%d %s", &IDtemp, timestampTemp) != EOF){
            fprintf(contactFile, "%d %s\n", IDtemp, timestampTemp);
        }

        printf("test\n");

        fclose(contactFile);
        fclose(tempFile);


        // Membuka file user B untuk menambahkan ID user A
        sprintf(contactFilename, "%s.txt", contactUsername);
        contactFile = fopen(contactFilename, "r");
        tempFile = fopen("tempFile.txt", "w");

        if (contactFile == NULL || tempFile == NULL) {
            printf("Error: gagal membuka file.\n");
            sleep(2);
            return;
        }
        while(fscanf(contactFile, "%d %s",&IDtemp, timestampTemp) != EOF){
            if(IDtemp == currentSession->id){
                fprintf(tempFile, "%d %s\n", IDtemp, nowInfo);
                duplicate = 1;
            }
            else
                fprintf(tempFile, "%d %s\n", IDtemp, timestampTemp);
        }

        if(duplicate == 0)
            fprintf(tempFile, "%d %s\n", currentSession->id, nowInfo);

        printf("ID A ke B: %d\n", currentSession->id);

        // Menambahkan ID kontak ke file pengguna yang sedang login
        fclose(contactFile);
        fclose(tempFile);

        //update contactFile dengan cara copy paste dari tempFile
        contactFile = fopen(contactFilename, "w");
        tempFile = fopen("tempFile.txt", "r");


        while(fscanf(tempFile, "%d %s", &IDtemp, timestampTemp) != EOF){
            fprintf(contactFile, "%d %s\n", IDtemp, timestampTemp);
        }

        fclose(contactFile);
        fclose(tempFile);
        printf("User telah berhasil melakukan kontak.\n");

        char pause;
        scanf("%c", &pause);
        scanf("%c", &pause);

        sleep(2);
    } else {
        printf("User telah berhasil melakukan kontak kurang dari 10 menit.\n");
        sleep(2);
    }

    char terminator;
    scanf("%c", &terminator);


}

void reportInfection(User *currentSession) {
    char choice;
    printf("Apakah anda yakin ingin lanjut melaporkan? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *file = fopen("userTerinfeksi.txt", "a");
        if (file == NULL) {
            printf("Error: gagal membuka file.\n");
            sleep(2);
            return;
        }
        fprintf(file, "%d %s\n", currentSession->id, currentSession->username);
        printf("%d sudah di write ke file terinfeksi\n", currentSession->id);
        fclose(file);
        printf("Melaporkan diri terinfeksi berhasil.\n");
        sleep(2);
    } else {
        printf("Batal melaporkan.\n");
        sleep(2);
    }
}

void infectionMenu(User *currentSession) {
    FILE *filePointer;
    char filename[] = "userTerinfeksi.txt";
    char buffer[100];
    int id;
    char username[50];
    bool userFound = false;

    // Membuka file userTerinfeksi.txt
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error: gagal membuka userTerinfeksi.txt\n");
        return;
    }

    // Menampilkan daftar user terinfeksi
    printf("Daftar User Terinfeksi:\n");
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        sscanf(buffer, "%d %s", &id, username);
        // Memeriksa apakah user yang sedang login ada di dalam daftar user terinfeksi
            printf("%d %s\n", id, username);
    }
    fclose(filePointer);

    // Meminta input ID user terinfeksi
    int selectedID;
    printf("\nMasukkan ID yang ingin Anda lihat tree-nya: ");
    scanf("%d", &selectedID);

    // Membuka file kembali untuk memeriksa keberadaan ID
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error: gagal membuka userTerinfeksi.txt.\n");
        sleep(2);
        return;
    }

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        sscanf(buffer, "%d %s", &id, username);
        // Memeriksa apakah ID yang dipilih adalah ID dari user yang sedang login
        if (id == selectedID) {
            userFound = true;
            break;
        }
    }
    fclose(filePointer);
    system("cls");
    // Validasi ID user terinfeksi
    if (userFound) {
        printf("User dengan ID %d dan username %s berhasil dipilih.\n", selectedID, username);
        deserializeTree(username, selectedID);
        char pause;
        scanf("%c", &pause);
        printf("\nKlik enter untuk lanjut ...");getch();

        sleep(2);
    } else {
        printf("ID user terinfeksi tidak ditemukan atau tidak dapat diakses.\n");
        sleep(2);
    }
}

void print_menu(char **choices, int highlight, int n_choices) {
    int i;
	for (i = 0; i < n_choices; ++i) {
        if (i == highlight) {
            printf("-> %s\n", choices[i]);
        } else {
            printf("   %s\n", choices[i]);
        }
    }
}

void loginAllUser(Session *session) {
    char input_username[20], input_password[20];
    int isAdmin = 0; // Flag untuk menandakan apakah yang login adalah admin

    printf("Masukkan username: ");
    scanf("%s", input_username);
    flush_buffer();
    printf("Masukkan password: ");
    scanf("%s", input_password);
    flush_buffer();

    FILE *fileAdmin = fopen("admin.txt", "r");
    if (fileAdmin != NULL) {
        char username[20], password[20];
        while (fscanf(fileAdmin, "%s %s", username, password) != EOF) {
            if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
                // Admin login successful
                system("cls");
                printf("Selamat Datang, %s (Admin)!\n", input_username);
                sleep(2);

                // Menetapkan sesi admin
                strcpy(session->user.username, input_username);
                strcpy(session->user.password, input_password);
                session->type = ADMIN_USER;

                // Menampilkan menu admin
                char *choices[] = {
                    "Tampilkan Semua User",
                    "Tampilkan Tree",
                    "Keluar"
                };
                int n_choices = sizeof(choices) / sizeof(char *);
                int highlight = 0;

                while (1) {
                    system("cls");
                    print_menu(choices, highlight, n_choices);

                    int c = _getch();
                    if (c == 224) { // Arrow keys
                        switch (_getch()) {
                            case 72: // Up
                                if (highlight == 0)
                                    highlight = n_choices - 1;
                                else
                                    --highlight;
                                break;
                            case 80: // Down
                                if (highlight == n_choices - 1)
                                    highlight = 0;
                                else
                                    ++highlight;
                                break;
                        }
                    } else if (c == 13) { // Enter key
                        switch (highlight) {
                            case 0:
                                system("cls");
                                printf("Daftar pengguna:\n");
                                print_all_users();
                                break;
                            case 1:
                                system("cls");
                                printArt(userTreeArt, userTree_lines, 'b');
                                adminLihatTreeUser();
                                break;
                            case 2:
                                printf("Anda memilih Keluar. Terima kasih!\n");
                                sleep(2);
                                return;
                        }
                    }
                }
            }
        }
        fclose(fileAdmin);
    }

    FILE *fileUser = fopen("AllUser.txt", "r");
    if (fileUser != NULL && !isAdmin) {
        char username[20], password[20];
        int id;
        while (fscanf(fileUser, "%d %s %s", &id, username, password) != EOF) {
            if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
                // User login successful
                system("cls");
                printf("Selamat Datang, %s!\n", input_username);
                sleep(2);

                // Menetapkan sesi user
                strcpy(session->user.username, input_username);
                strcpy(session->user.password, input_password);
                session->user.id = id;
                session->type = BASIC_USER;

                // Menampilkan menu user
                char *choices[] = {
                    "Melakukan kontak",
                    "Lihat Status",
                    "Beranda Terinfeksi",
                    "Laporkan Terinfeksi",
                    "Keluar"
                };
                int n_choices = sizeof(choices) / sizeof(char *);
                int highlight = 0;

                while (1) {
                    system("cls");
                    print_menu(choices, highlight, n_choices);

                    int c = _getch();
                    if (c == 224) { // Arrow keys
                        switch (_getch()) {
                            case 72: // Up
                                if (highlight == 0)
                                    highlight = n_choices - 1;
                                else
                                    --highlight;
                                break;
                            case 80: // Down
                                if (highlight == n_choices - 1)
                                    highlight = 0;
                                else
                                    ++highlight;
                                break;
                        }
                    } else if (c == 13) { // Enter key
                        switch (highlight) {
                            case 0:
                                system("cls");
                                printArt(handshakeArt, handshake_lines, 'r');
                                logContact(&session->user);
                                break;
                            case 1:
                                system("cls");
                                printf("Anda memilih Lihat Status.\n");
                                printArt(status_asciiArt, status_lines, 'g');
                                int levelInfection = diagnoseInfectionStatus(id);
                                printf("Level infeksi %s: %d\n", username, levelInfection);
                                if (levelInfection == 0)
                                    printf("User %s telah terinfeksi\n", username);
                                else if (levelInfection == 1)
                                    printf("User %s kemungkinan besar terinfeksi\n", username);
                                else if (levelInfection == 2)
                                    printf("User %s kemungkinan sedang terinfeksi\n", username);
                                else if (levelInfection == 3)
                                    printf("User %s kemungkinan kecil terinfeksi\n", username);
                                else
                                    printf("Tidak ada tanda-tanda User %s terinfeksi\n", username);

                                printf("Klik (enter) untuk lanjut\n");
                                _getch();
                                break;
                            case 2:
                                system("cls");
                                printArt(daftarTerinfeksiArt, daftarTerinfeksiArt_lines, 'r');
                                infectionMenu(&session->user);
                                break;
                            case 3:
                                system("cls");
                                reportInfection(&session->user);
                                break;
                            case 4:
                                printf("Anda memilih Keluar. Terima kasih!\n");
                                sleep(2);
                                return;
                        }
                    }
                }
            }
        }
        fclose(fileUser);
    }

    printf("Login gagal\n");
    sleep(2);
}

void flush_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

