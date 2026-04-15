#include <stdio.h>
#include "login.h"
#include "alat.h"
#include "pinjam.h"

// MENU ADMIN
void menuAdmin() {
    int pilih;
    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Tampilkan Alat\n");
        printf("3. Hapus Alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1:
                tambahAlat();
                break;
            case 2:
                tampilAlat();
                break;
            case 3:
                hapusAlat();
                break;
            case 0:
                printf("Keluar dari menu admin...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilih != 0);
}

// MENU USER
void menuUser() {
    int pilih;
    do {
        printf("\n=== MENU USER ===\n");
        printf("1. Lihat Alat\n");
        printf("2. Pinjam Alat\n");
        printf("3. Lihat Pinjaman\n");
        printf("4. Kembalikan Alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1:
                tampilAlat();
                break;
            case 2:
                pinjamAlat();
                break;
            case 3:
                lihatPinjaman();
                break;
            case 4:
                kembalikanAlat();
                break;
            case 0:
                printf("Keluar dari menu user...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilih != 0);
}

// PROGRAM UTAMA
int main(int argc, char *argv[]) {
    int role;

    // LOGIN
    role = login(argc, argv);

    // CEK ROLE
    if(role == 1) {
        printf("Login sebagai ADMIN berhasil!\n");
        menuAdmin();
    } 
    else if(role == 2) {
        printf("Login sebagai USER berhasil!\n");
        menuUser();
    } 
    else {
        printf("Login gagal! Periksa username/password.\n");
    }

    return 0;
}