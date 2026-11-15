#include <stdio.h>
#include <string.h>

static void hapus_akhir_barisan(char *teks)
{
    size_t panjang = strlen(teks);

    while (panjang > 0 && (teks[panjang - 1] == '\n' || teks[panjang - 1] == '\r')) {
        teks[--panjang] = '\0';
    }
}

int main(void)
{
    char inputScanf[100];
    char inputGets[100];
    char inputFgets[100];
    int karakter;

    printf("Masukkan satu kata untuk scanf(): ");
    if (scanf("%99s", inputScanf) != 1) {
        fprintf(stderr, "Input untuk scanf() tidak berhasil dibaca.\n");
        return 1;
    }

    while ((karakter = getchar()) != '\n' && karakter != EOF) {
    }
    printf("Hasil scanf(): [%s]\n\n", inputScanf);

    printf("Masukkan satu baris pendek untuk input aman (fgets): ");
    if (fgets(inputGets, sizeof inputGets, stdin) == NULL) {
        fprintf(stderr, "Input tidak berhasil dibaca.\n");
        return 1;
    }
    hapus_akhir_barisan(inputGets);
    printf("Hasil input aman: [%s]\n", inputGets);
    printf("Panjang hasil input aman: %zu karakter\n\n", strlen(inputGets));

    printf("Masukkan satu baris untuk fgets(): ");
    if (fgets(inputFgets, sizeof inputFgets, stdin) == NULL) {
        fprintf(stderr, "Input untuk fgets() tidak berhasil dibaca.\n");
        return 1;
    }
    hapus_akhir_barisan(inputFgets);
    printf("Hasil fgets(): [%s]\n", inputFgets);
    printf("Panjang hasil fgets(): %zu karakter\n", strlen(inputFgets));

    return 0;
}