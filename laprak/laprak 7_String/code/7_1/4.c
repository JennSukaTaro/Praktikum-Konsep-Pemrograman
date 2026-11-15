#include <stdio.h>
#include <string.h>

void copystr(const char asal[], char tujuan[])
{
    size_t i = 0;

    while (asal[i] != '\0') {
        tujuan[i] = asal[i];
        i++;
    }

    tujuan[i] = '\0';
}

int main(void)
{
    char asal[100];
    char tujuan[100];

    printf("Masukkan string: ");
    if (fgets(asal, sizeof asal, stdin) == NULL) {
        fprintf(stderr, "Input string tidak berhasil dibaca.\n");
        return 1;
    }

    asal[strcspn(asal, "\n")] = '\0';
    copystr(asal, tujuan);

    printf("String asal   : %s\n", asal);
    printf("String tujuan : %s\n", tujuan);
    return 0;
}