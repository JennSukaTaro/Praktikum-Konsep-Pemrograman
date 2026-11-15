#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];

    printf("Masukkan string: ");
    if (fgets(string, sizeof string, stdin) == NULL) {
        fprintf(stderr, "Input string tidak berhasil dibaca.\n");
        return 1;
    }

    string[strcspn(string, "\n")] = '\0';
    printf("Panjang string: %zu karakter\n", strlen(string));

    return 0;
}