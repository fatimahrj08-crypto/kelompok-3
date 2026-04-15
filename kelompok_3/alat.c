#include <stdio.h>
#include "alat.h"
#include "file.h"

typedef struct {
    int id;
    char nama[50];
    char merek[50];
    char model[50];
    int tahun;
    int jumlah;
} Alat;

void tambahAlat() {
    FILE *fp = bukaFile("alat.txt", "a");
    if(fp == NULL) return;

    Alat a;

    printf("ID: "); scanf("%d", &a.id);
    printf("Nama: "); scanf("%49s", a.nama);
    printf("Merek: "); scanf("%49s", a.merek);
    printf("Model: "); scanf("%49s", a.model);
    printf("Tahun: "); scanf("%d", &a.tahun);
    printf("Jumlah: "); scanf("%d", &a.jumlah);

    fprintf(fp, "%d %s %s %s %d %d\n",
        a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);

    fclose(fp);
}

void tampilAlat() {
    FILE *fp = bukaFile("alat.txt", "r");
    if(fp == NULL) return;

    Alat a;

    printf("\n=== DATA ALAT ===\n");

    while(fscanf(fp, "%d %49s %49s %49s %d %d",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        printf("%d | %s | %s | %s | %d | %d\n",
            a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(fp);
}

void hapusAlat() {
    FILE *fp = bukaFile("alat.txt", "r");
    FILE *temp = bukaFile("temp.txt", "w");

    if(fp == NULL || temp == NULL) return;

    int idhapus;
    Alat a;

    printf("Masukkan ID yang ingin dihapus: ");
    scanf("%d", &idhapus);

    while(fscanf(fp, "%d %49s %49s %49s %d %d",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if(a.id != idhapus) {
            fprintf(temp, "%d %s %s %s %d %d\n",
                a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    printf("Data berhasil dihapus.\n");
}