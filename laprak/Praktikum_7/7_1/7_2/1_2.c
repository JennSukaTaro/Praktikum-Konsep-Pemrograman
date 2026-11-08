#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    size_t panjang;
    size_t kiri;

    printf("Masukkan string: ");
    if (fgets(string, sizeof string, stdin) == NULL) {
        fprintf(stderr, "Input string tidak berhasil dibaca.\n");
        return 1;
    }

    string[strcspn(string, "\n")] = '\0';

    panjang = strlen(string);
    for (kiri = 0; kiri < panjang / 2; kiri++) {
        char sementara = string[kiri];
        string[kiri] = string[panjang - kiri - 1];
        string[panjang - kiri - 1] = sementara;
    }

    printf("String setelah dibalik: %s\n", string);
    return 0;
}