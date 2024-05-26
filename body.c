#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
#include "treeUser.h"


//void menu_lihat_status() {
//    printf("Anda memilih Lihat Status.\n");
//    sleep(2);
//    system("cls");
//    // Isi dengan logika lihat status
//}
//
//void menu_beranda_terinfeksi() {
//    printf("Anda memilih Beranda Terinfeksi.\n");
//    sleep(2);
//    system("cls");
//    // Isi dengan logika beranda terinfeksi
//}
//
//void menu_laporkan_terinfeksi() {
//    printf("Anda memilih Laporkan Terinfeksi.\n");
//    sleep(2);
//    system("cls");
//    // Isi dengan logika laporkan terinfeksi
//}

//void start_session(Session *session) {
//    // Assume that the user and password are stored in the 'users.txt' file
//    // The file format is: <type> <id> <username> <password>\n
//    // Where <type> is either 'U' for basic user or 'A' for admin
//
//    FILE *file = fopen("AllUser.txt", "r");
//    if (!file) {
//        printf("Error: Unable to open users.txt\n");
//        exit(1);
//    }
//
//    fscanf(file, "%d %s %s", &(session->type), session->user.username, session->user.password);
//    fclose(file);
//}
//
//void end_session(Session *session) {
//    memset(session, 0, sizeof(Session));
//}

//UserType get_user_type(Session *session) {
//    return session->type;
//}
//
//int get_user_id(Session *session) {
//    // Not used in this example, but you can implement it if needed
//    return -1;
//}
//
//const char *get_username(Session *session) {
//    return session->user.username;
//}
//
//const char *get_password(Session *session) {
//    return session->user.password;
//}

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

// void selectID(const char *currentUsername) {
//     int selectedID;
//     printf("\nMasukkan ID yang ingin Anda pilih: ");
//     scanf(" %d", &selectedID);

//     // Memanggil fungsi untuk mencetak pesan berdasarkan keberadaan ID di file
//     if (isIDExist(selectedID)) {
//         printf("ID %d berhasil dipilih.\n", selectedID);
//         sleep(2);
//         inputDuration(selectedID); // Memanggil fungsi untuk meminta durasi setelah ID berhasil dipilih
// 	} else {
//         printf("ID %d tidak ditemukan.\n", selectedID);
//         sleep(2);
//     	system("cls");
//     	showUserInformation(currentUsername);
//     }
// }

// void inputDuration(int selectedID) {
//     int duration;
//     system("cls");
//     printf("Masukkan durasi untuk ID %d (dalam menit): ", selectedID);
//     scanf("%d", &duration);
//     sleep(2); system("cls");
// }

// // Fungsi untuk menampilkan informasi pengguna dari file
// void showUserInformation(const char *currentUsername) {
//     FILE *filePointer;
//     char filename[] = "AllUser.txt";
//     char buffer[30]; // Buffer untuk menyimpan baris yang dibaca
//     char username[20]; // Untuk menyimpan username dari setiap baris
// 	int id;

//     // Membuka file AllUser.txt
//     filePointer = fopen(filename, "r");

//     // Memeriksa apakah file berhasil dibuka
//     if (filePointer == NULL) {
//         printf("Gagal membuka file.\n");
//         return; // Keluar dari fungsi jika file tidak dapat dibuka
//     }

//     // Menampilkan informasi pengguna dari file
//     printf("Daftar Kontak:\n");
//     while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
//         // Menggunakan sscanf untuk membaca dua string pertama dari setiap baris
//         sscanf(buffer, "%d %s", &id, username);
//         // Jika username cocok dengan currentUsername, abaikan baris ini
//         if (strcmp(username, currentUsername) == 0) {
//             continue;
//     	}
//         printf("%d %s\n", id, username); // Menampilkan ID dan username
//     }

//     // Menutup file setelah selesai membaca
//     fclose(filePointer);

// 	selectID(currentUsername);
// }


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
    getchar();
    getchar();
}

void print_tree(const char *filename) {
    system(filename);
}

// void login_admin(Session *session) {
//     const char *admin_username = "admin";
//     const char *admin_password = "password";

//     char input_username[20], input_password[20];
//     printf("Enter admin username: ");
//     fgets(input_username, sizeof(input_username), stdin);
//     input_username[strcspn(input_username, "\n")] = '\0';
//     printf("Enter admin password: ");
//     fgets(input_password, sizeof(input_password), stdin);
//     input_password[strcspn(input_password, "\n")] = '\0';

//     if (strcmp(admin_username, input_username) == 0 && strcmp(admin_password, input_password) == 0) {
//         // Admin login successful
//         printf("Welcome, admin!\n");
//         print_all_users();
//         print_tree("admin.txt");
//     } else {
//         // Admin login failed
//         printf("Invalid admin credentials\n");
//     }
// }

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
    char contactUsername[90];
    int duration;
    
    // Meminta input username kontak
    printf("Enter contact username: ");
    scanf("%s", contactUsername);
    
    // Meminta input durasi kontak dalam menit
    printf("Enter contact duration (minutes): ");
    scanf("%d", &duration);

    // Jika durasi lebih dari 10 menit, log kontak
    if (duration > 10) {
        char filename[90 + 4];
        sprintf(filename, "%s.txt", contactUsername);
        
        // Membuka file dalam mode append
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }

        // Menambahkan ID pengguna saat ini ke file kontak
        fprintf(file, "%02d\n", currentSession->id);
        fclose(file);
        printf("Contact logged successfully.\n");
    } else {
        printf("Contact duration too short to log.\n");
    }
}

void reportInfection(User *currentSession) {
    char choice;
    printf("Apakah anda yakin ingin melanjutkan? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *file = fopen("userTerinfeksi.txt", "a");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }
        fprintf(file, "%d %s\n", currentSession->id, currentSession->username);
        fclose(file);
        printf("Infection reported successfully.\n");
    } else {
        printf("Infection report canceled.\n");
    }
}

void loginAllUser(Session *session) {
    char input_username[20], input_password[20];
    int isAdmin = 0; // Flag untuk menandakan apakah yang login adalah admin

    printf("Masukkan username: ");
    scanf("%s", input_username);
    printf("Masukkan password: ");
    scanf("%s", input_password);

    // Cek apakah yang login adalah admin atau bukan
        FILE *fileAdmin = fopen("admin.txt", "r");
    if (fileAdmin != NULL) {
        char username[20], password[20];
        while (fscanf(fileAdmin, "%s %s", username, password) != EOF) {
            if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
                // Admin login successful
                system("cls");
                printf("Selamat Datang, %s (Admin)!", input_username);
				sleep(2);

                // Menetapkan sesi admin
                strcpy(session->user.username, input_username);
                strcpy(session->user.password, input_password);
                session->type = ADMIN_USER;

                // Menampilkan menu admin
                int pilihan;
                do {
                	system("cls");
                    printf("Menu:\n");
                    printf("1. Tampilkan Semua User\n");
                    printf("2. Tampilkan Tree\n");
                    printf("3. Keluar\n");
                    printf("Pilih menu: ");
                    scanf("%d", &pilihan);

                    switch(pilihan) {
                        case 1:
                            printf("Daftar pengguna:\n");
                            print_all_users();
                            break;
                        case 2:
                            adminLihatTreeUser();
                            break;
                        case 3:
                            printf("Anda memilih Keluar. Terima kasih!\n");
                            sleep(2);
                            break;
                        default:
                            printf("Pilihan tidak valid. Silakan pilih lagi.\n");
                            sleep(2);
                    }
                } while(pilihan != 3);

                fclose(fileAdmin);
                return;
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
                printf("Selamat Datang, %s!", input_username);
				sleep(2);
                // Menetapkan sesi user
                strcpy(session->user.username, input_username);
                strcpy(session->user.password, input_password);
                session->user.id = id;
                session->type = BASIC_USER;

                // Menampilkan menu user
                int pilihan;
                do {
                	system("cls");
                    printf("Menu:\n");
                    printf("1. Melakukan kontak\n");
                    printf("2. Lihat Status\n");
                    printf("3. Beranda Terinfeksi\n");
                    printf("4. Laporkan Terinfeksi\n");
                    printf("5. Keluar\n");
                    printf("Pilih menu: ");
                    scanf("%d", &pilihan);

                    switch(pilihan) {
                        case 1:
                            system("cls");
                			logContact(&session->user);// Panggil fungsi untuk menampilkan informasi pengguna
                            break;
                        case 2:
			                printf("Anda memilih Lihat Status.\n");
			                sleep(2);
			                system("cls");
                            break;
                        case 3:
			                printf("Anda memilih Beranda Terinfeksi.\n");
			            	sleep(2);
			                system("cls");
                            break;
                        case 4:
                            system("cls");
			                reportInfection(&session->user);
                            break;
                        case 5:
                            printf("Anda memilih Keluar. Terima kasih!\n");
                            break;
                        default:
                            printf("Pilihan tidak valid. Silakan pilih lagi.\n");
                            sleep(2);
                    }
                } while(pilihan != 5);

                fclose(fileUser);
                return;
            }
        }
        fclose(fileUser);
    }
    // Jika login tidak berhasil
    printf("Login gagal\n");
    sleep(2);
}

