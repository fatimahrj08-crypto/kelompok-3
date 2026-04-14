#include <stdio.h>
#include <string.h>
#include "login.h"

int main(int argc, char *argv[]) {
    char role[20];

    // VALIDASI CLA
    if (argc != 3) {
        printf("Cara pakai: ./program username password\n");
        return 1;
    }

    // PROSES LOGIN
    if (login(argv[1], argv[2], role)) {
        printf("Login berhasil!\n");
        printf("Role: %s\n", role);

        // BEDAKAN ROLE
        if (strcmp(role, "admin") == 0) {
            printf("Masuk sebagai ADMIN\n");
        } else if (strcmp(role, "user") == 0) {
            printf("Masuk sebagai USER\n");
        } else {
            printf("Role tidak dikenali\n");
        }

    } else {
        printf("Login gagal! Username/password salah\n");
    }

    return 0;
}