#include <stdio.h>
#include <string.h>
#include "login.h"

int login(char username[], char password[], char role[]) {
    FILE *fp;
    char line[100];

    fp = fopen("akun.txt", "r");
    if (fp == NULL) {
        printf("Error: file akun.txt tidak ditemukan!\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *u = strtok(line, ",");
        char *p = strtok(NULL, ",");
        char *r = strtok(NULL, "\n");

        if (u != NULL && p != NULL && r != NULL) {
            if (strcmp(username, u) == 0 && strcmp(password, p) == 0) {
                strcpy(role, r);
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}