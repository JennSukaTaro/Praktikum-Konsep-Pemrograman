#include <stdio.h>
#include <string.h>

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
extern char *gets(char *str);
#endif

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

    printf("Masukkan satu baris pendek untuk gets(): ");
    if (gets(inputGets) == NULL) {
        fprintf(stderr, "Input untuk gets() tidak berhasil dibaca.\n");
        return 1;
    }
    printf("Hasil gets(): [%s]\n", inputGets);
    printf("Panjang hasil gets(): %zu karakter\n\n", strlen(inputGets));

    printf("Masukkan satu baris untuk fgets(): ");
    if (fgets(inputFgets, sizeof inputFgets, stdin) == NULL) {
        fprintf(stderr, "Input untuk fgets() tidak berhasil dibaca.\n");
        return 1;
    }
    printf("Hasil fgets(): [%s]", inputFgets);
    printf("Panjang hasil fgets(): %zu karakter\n", strlen(inputFgets));

    return 0;
}