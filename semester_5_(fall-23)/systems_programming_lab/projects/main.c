/**
    @author: Aimal Khan.
    @author: Hamza Khan.
    @author: Sarwat Ikram.
    A project for encrypting a file in c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "./includes/crypt.h"

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s [-e | -d] [inputFile] [outputFile] [key]\n", argv[0]);
        return 1;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    const char *key = argv[4];

    if (!strcmp(operation, "-e"))
    {
        printf("Starting encryption.\n");

        encryptFile(inputFileName, outputFileName, key);
        
        printf("Encryption completed.\n");
    }
    else if (!strcmp(operation, "-d"))
    {
        printf("Starting decryption.\n");
        decryptFile(inputFileName, outputFileName, key);
        printf("Decryption completed.\n");
    }
    else
    {
        fprintf(stderr, "Invalid operation. Use '-e' for encryption or '-d' decryption.\n");
        return 1;
    }

    return 0;
}