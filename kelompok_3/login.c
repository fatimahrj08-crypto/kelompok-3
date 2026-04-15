#include <stdio.h>
#include <string.h>
#include "login.h"
#include "file.h"

int login(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Gunakan: ./program username password\n");
        return 0;
    }

    FILE *fp = bukaFile("akun.txt", "r");
    if(fp == NULL) return 0;

    char user[50], pass[50], role[10];

    while(fscanf(fp, "%49s %49s %9s", user, pass, role) != EOF) {
        if(strcmp(user, argv[1]) == 0 && strcmp(pass, argv[2]) == 0) {
            fclose(fp);
            if(strcmp(role, "admin") == 0) return 1;
            else return 2;
        }
    }

    fclose(fp);
    return 0;
}