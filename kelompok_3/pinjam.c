#include <stdio.h>
#include "pinjam.h"
#include "file.h"

void pinjamAlat() {
    FILE *fp = bukaFile("pinjam.txt", "a");
    if(fp == NULL) return;

    int id;
    printf("Masukkan ID alat: ");
    scanf("%d", &id);

    fprintf(fp, "%d\n", id);

    fclose(fp);
    printf("Alat berhasil dipinjam.\n");
}

void lihatPinjaman() {
    FILE *fp = bukaFile("pinjam.txt", "r");
    if(fp == NULL) return;

    int id;
    printf("\n=== DATA PINJAMAN ===\n");

    while(fscanf(fp, "%d", &id) != EOF) {
        printf("ID Alat: %d\n", id);
    }

    fclose(fp);
}

void kembalikanAlat() {
    FILE *fp = bukaFile("pinjam.txt", "r");
    FILE *temp = bukaFile("temp.txt", "w");

    if(fp == NULL || temp == NULL) return;

    int id, idkembali;

    printf("Masukkan ID yang dikembalikan: ");
    scanf("%d", &idkembali);

    while(fscanf(fp, "%d", &id) != EOF) {
        if(id != idkembali) {
            fprintf(temp, "%d\n", id);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("pinjam.txt");
    rename("temp.txt", "pinjam.txt");

    printf("Alat berhasil dikembalikan.\n");
}