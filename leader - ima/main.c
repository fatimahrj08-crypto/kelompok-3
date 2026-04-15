#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int role;

    // Cek CLA
    if (argc < 3) {
        printf("Usage: ./program username password\n");
        return 1;
    }

    // Login
    role = login(argv[1], argv[2]);

    if (role == 0) {
        printf("Login gagal!\n");
        return 0;
    }

    int pilihan;

    // ================= ADMIN =================
    if (role == 1) {
        do {
            printf("\n=== MENU ADMIN ===\n");
            printf("1. Tambah Alat\n");
            printf("2. Edit Alat\n");
            printf("3. Hapus Alat\n");
            printf("4. Tampilkan Alat\n");
            printf("0. Exit\n");
            printf("Pilih: ");
            scanf("%d", &pilihan);

            switch (pilihan) {
                case 1: tambahAlat(); break;
                case 2: editAlat(); break;
                case 3: hapusAlat(); break;
                case 4: tampilAlat(); break;
                case 0: printf("Keluar...\n"); break;
                default: printf("Pilihan tidak valid!\n");
            }

        } while (pilihan != 0);
    }

    // ================= USER =================
    else if (role == 2) {
        do {
            printf("\n=== MENU USER ===\n");
            printf("1. Lihat Alat\n");
            printf("2. Pinjam Alat\n");
            printf("3. Lihat Peminjaman\n");
            printf("4. Kembalikan Alat\n");
            printf("0. Exit\n");
            printf("Pilih: ");
            scanf("%d", &pilihan);

            switch (pilihan) {
                case 1: tampilAlat(); break;
                case 2: pinjamAlat(); break;
                case 3: lihatPinjam(); break;
                case 4: kembalikanAlat(); break;
                case 0: printf("Keluar...\n"); break;
                default: printf("Pilihan tidak valid!\n");
            }

        } while (pilihan != 0);
    }

    return 0;
}