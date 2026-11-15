#include <stdio.h>
#include <string.h>

int bandingstr1(const char string1[], const char string2[])
{
    return strcmp(string1, string2);
}

int main(void)
{
    char string1[100];
    char string2[100];

    printf("Masukkan string pertama: ");
    if (fgets(string1, sizeof string1, stdin) == NULL) {
        fprintf(stderr, "String pertama tidak berhasil dibaca.\n");
        return 1;
    }

    printf("Masukkan string kedua: ");
    if (fgets(string2, sizeof string2, stdin) == NULL) {
        fprintf(stderr, "String kedua tidak berhasil dibaca.\n");
        return 1;
    }

    string1[strcspn(string1, "\n")] = '\0';
    string2[strcspn(string2, "\n")] = '\0';

    if (bandingstr1(string1, string2) == 0) {
        printf("Kedua string sama.\n");
    } else {
        printf("Kedua string berbeda.\n");
    }

    return 0;
}