#include <stdio.h>
#include <string.h>

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
    strcpy(tujuan, asal);

    printf("String asal   : %s\n", asal);
    printf("String tujuan : %s\n", tujuan);
    return 0;
}