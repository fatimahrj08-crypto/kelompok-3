#include <stdio.h>
#include "file.h"

FILE* bukaFile(const char *nama, const char *mode) {
    FILE *fp = fopen(nama, mode);
    if(fp == NULL) {
        printf("Error: File %s tidak bisa dibuka!\n", nama);
    }
    return fp;
}