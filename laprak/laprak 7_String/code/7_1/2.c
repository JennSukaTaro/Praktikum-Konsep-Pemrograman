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

int main(void)
{
    char input[100];

    printf("Masukkan string: ");
    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "Input string tidak berhasil dibaca.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    printf("Panjang string: %zu karakter\n", pjgstr(input));
    return 0;
}