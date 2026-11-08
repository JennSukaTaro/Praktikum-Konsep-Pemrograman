#include <stdio.h>
#include <string.h>

size_t pjgstr(const char string[])
{
    size_t panjang = 0;

    while (string[panjang] != '\0') {
        panjang++;
    }

    return panjang;
}

void balikstr(char string[])
{
    size_t kiri = 0;
    size_t kanan = pjgstr(string);

    if (kanan == 0) {
        return;
    }

    kanan--;
    while (kiri < kanan) {
        char sementara = string[kiri];
        string[kiri] = string[kanan];
        string[kanan] = sementara;
        kiri++;
        kanan--;
    }
}

int main(void)
{
    char input[100];
    size_t panjang;

    printf("Masukkan string: ");
    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "Input string tidak berhasil dibaca.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    panjang = pjgstr(input);
    balikstr(input);

    printf("Panjang string: %zu karakter\n", panjang);
    printf("String setelah dibalik: %s\n", input);
    return 0;
}