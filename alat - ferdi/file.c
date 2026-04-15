#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ===== STRUCT =====
struct Alat {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
};

struct Pinjam {
    char username[50];
    unsigned int id_alat;
    unsigned int jumlah;
};

// ===== GLOBAL ARRAY =====
struct Alat dataAlat[MAX];
struct Pinjam dataPinjam[MAX];

int jumlahAlat = 0;
int jumlahPinjam = 0;

// ===== BACA FILE ALAT =====
void bacaFileAlat() {
    FILE *fp = fopen("alat.txt", "r");
    if (fp == NULL) {
        printf("File alat tidak ditemukan!\n");
        return;
    }

    jumlahAlat = 0;

    while (fscanf(fp, "%u,%[^,],%[^,],%[^,],%u,%u\n",
        &dataAlat[jumlahAlat].id,
        dataAlat[jumlahAlat].nama,
        dataAlat[jumlahAlat].merek,
        dataAlat[jumlahAlat].model,
        &dataAlat[jumlahAlat].tahun,
        &dataAlat[jumlahAlat].jumlah) != EOF) {
        
        jumlahAlat++;
    }

    fclose(fp);
}

// ===== SIMPAN FILE ALAT =====
void simpanFileAlat() {
    FILE *fp = fopen("alat.txt", "w");

    for (int i = 0; i < jumlahAlat; i++) {
        fprintf(fp, "%u,%s,%s,%s,%u,%u\n",
            dataAlat[i].id,
            dataAlat[i].nama,
            dataAlat[i].merek,
            dataAlat[i].model,
            dataAlat[i].tahun,
            dataAlat[i].jumlah);
    }

    fclose(fp);
}

// ===== BACA FILE PINJAM =====
void bacaFilePinjam() {
    FILE *fp = fopen("pinjam.txt", "r");
    if (fp == NULL) {
        printf("File pinjam tidak ditemukan!\n");
        return;
    }

    jumlahPinjam = 0;

    while (fscanf(fp, "%[^,],%u,%u\n",
        dataPinjam[jumlahPinjam].username,
        &dataPinjam[jumlahPinjam].id_alat,
        &dataPinjam[jumlahPinjam].jumlah) != EOF) {
        
        jumlahPinjam++;
    }

    fclose(fp);
}

// ===== SIMPAN FILE PINJAM =====
void simpanFilePinjam() {
    FILE *fp = fopen("pinjam.txt", "w");

    for (int i = 0; i < jumlahPinjam; i++) {
        fprintf(fp, "%s,%u,%u\n",
            dataPinjam[i].username,
            dataPinjam[i].id_alat,
            dataPinjam[i].jumlah);
    }

    fclose(fp);
}

// ===== BACA FILE AKUN =====
void bacaFileAkun() {
    FILE *fp = fopen("akun.txt", "r");
    if (fp == NULL) {
        printf("File akun tidak ditemukan!\n");
        return;
    }

    char username[50], password[50], role[10];

    printf("=== DATA AKUN ===\n");

    while (fscanf(fp, "%[^,],%[^,],%s\n", username, password, role) != EOF) {
        printf("User: %s | Role: %s\n", username, role);
    }

    fclose(fp);
}