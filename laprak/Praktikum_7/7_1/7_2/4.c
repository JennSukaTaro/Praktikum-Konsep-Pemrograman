#include <stdio.h>
#include <string.h>

static unsigned char hurufKecilAscii(unsigned char karakter)
{
    if (karakter >= 'A' && karakter <= 'Z') {
        return (unsigned char)(karakter + ('a' - 'A'));
    }

    return karakter;
}

int strcmpi(const char string1[], const char string2[])
{
    size_t i = 0;

    while (string1[i] != '\0' && string2[i] != '\0') {
        unsigned char karakter1 =
            hurufKecilAscii((unsigned char)string1[i]);
        unsigned char karakter2 =
            hurufKecilAscii((unsigned char)string2[i]);

        if (karakter1 < karakter2) {
            return -1;
        }
        if (karakter1 > karakter2) {
            return 1;
        }

        i++;
    }

    unsigned char karakter1 =
        hurufKecilAscii((unsigned char)string1[i]);
    unsigned char karakter2 =
        hurufKecilAscii((unsigned char)string2[i]);

    if (karakter1 < karakter2) {
        return -1;
    }
    if (karakter1 > karakter2) {
        return 1;
    }
    return 0;
}

void tampilkanHasil(const char namaFungsi[], int hasil)
{
    printf("%s mengembalikan nilai %d: ", namaFungsi, hasil);

    if (hasil == 0) {
        printf("kedua string sama.\n");
    } else if (hasil < 0) {
        printf("string pertama lebih kecil secara leksikografis.\n");
    } else {
        printf("string pertama lebih besar secara leksikografis.\n");
    }
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

    printf("\nPerbandingan \"%s\" dan \"%s\":\n", string1, string2);
    tampilkanHasil("strcmp()", strcmp(string1, string2));
    tampilkanHasil("strcmpi()", strcmpi(string1, string2));

    return 0;
}