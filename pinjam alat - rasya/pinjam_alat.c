#include <stdio.h>
int main() {
int jumlah_alat, lama_pinjam, total_biaya;
printf("masukkan_jumlah alat yang dipinjam: ");
scanf("%d", &jumlah_alat);
printf("masukkan lama pinjam (dalam hari): ");
scanf("%d", &lama_pinjam);
total_biaya = jumlah_alat * lama_pinjam * 5000;
printf("total biaya pinjam alat: %d\n", total_biaya);
return 0;
}