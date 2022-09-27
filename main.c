#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"

// AES128 / ECB encryption, decryption algorithm 이용함
int main(void)
{
    char *input = (char *)malloc(1024 * sizeof(char)); // memory allocation up to 1024 byte
    int init_len = 0;
    int length = 0;
    int i = 0;

    struct AES_ctx ctx;

    //AES128 암호화 공개키 고정값
    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

    AES_init_ctx(&ctx, key);
    printf("Type the string for encrypting (up to 1024 byte): ");

    fgets(input, 1024, stdin);

    init_len = strlen(input);

    printf("original string: \t");
    for (i = 0; i < init_len; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
    length = strlen(input) + 1;
    AES_ECB_encrypt(&ctx, (uint8_t *)input);

    printf("encrypted input: \t");
    for (i = 0; i < length; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");

    printf("decrypt the encrypted input: \t");
    AES_ECB_decrypt(&ctx, (uint8_t *)input);
    for (i = 0; i < init_len; i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    free(input); // free memory

    return 0;
}