#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#include "./hash.h"
#include "./utils.h"

#define MAX_BUFF_SIZE 256
#define BIT32_HEX 9

/**
 * A function that encode or decode a given file with the provided key using XOR.

 * @param source: the source file to be encoded/decoded
 * @param destination: the destination file which is be encoded/decoded
 * @param key: the key provided by user.

 * @return void.
*/
void encode(const unsigned int source, const unsigned destination, const char *key)
{
    int bytesRead, keyLength = strlen(key);
    char buffer[MAX_BUFF_SIZE];

    while ((bytesRead = read(source, buffer, MAX_BUFF_SIZE)) > 0)
    {
        // Encrypt data using XOR with the key
        for (int i = 0; i < bytesRead; i++)
            buffer[i] ^= key[i % keyLength];

        // Write encrypted data to the output file
        if (write(destination, buffer, bytesRead) == -1)
        {
            perror("Error writing to output file\n");
            exit(1);
        }
    }
    if (bytesRead == -1)
    {
        perror("Error while reading from input file\n");
        exit(1);
    }

    return;
}

/**
 * A void function to encrypt a file with an algorithm.

 * @param inputFileName: path to a file that need to be encrypted.
 * @param outputFileName: path to store the encrypted output file.
 * @param key: a string that is used for encryption.

 * @return void.
*/
void encryptFile(const char *inputFileName, const char *outputFileName, const char *key)
{
    int inputFileFd,
        outputFileFd;
    size_t keyLength = strlen(key);
    char buffer[MAX_BUFF_SIZE],
        hash[BIT32_HEX];

    // open the source for reading only
    inputFileFd = open(inputFileName, O_RDONLY);
    if (inputFileFd == -1)
    {
        fprintf(stderr, "Error opening input file\"%s\" due to %s", inputFileName, strerror(errno));
        exit(1);
    }

    // open the destination for writing only having permissions of reading only.
    outputFileFd = open(outputFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH);
    if (outputFileFd == -1)
    {
        fprintf(stderr, "Error opening output file\"%s\" due to %s", outputFileName, strerror(errno));
        exit(1);
    }

    // write the hash of key in first line of output file.
    generateHash(key, hash);
    char passwordLine[strlen(hash) + 2];
    snprintf(passwordLine, sizeof(passwordLine), "%s\n", hash);
    if (write(outputFileFd, passwordLine, strlen(passwordLine)) == -1)
    {
        perror("Error writing to output file\n");
        exit(1);
    }

    // encode the file with key.
    encode(inputFileFd, outputFileFd, key);

    // Close both the input and output files.
    closeFile(inputFileFd);
    closeFile(outputFileFd);

    return;
}

/**
  * A void function to decrypt a file by underlying algorithm using the key
  * @param inputFileName: path to a file that need to be decrypted.
  * @param outputFileName: path to store the decrypted output file.
  * @param key: the same string that is used for encryption.

  * @returns void.
*/
void decryptFile(const char *inputFileName, const char *outputFileName, const char *key)
{
    int inputFileFd,
        outputFileFd,
        bytesRead;
    size_t keyLength = strlen(key);
    char buffer[MAX_BUFF_SIZE];

    // open the source for reading only
    inputFileFd = open(inputFileName, O_RDONLY);
    if (inputFileFd == -1)
    {
        fprintf(stderr, "Error opening input file\"%s\" due to %s", inputFileName, strerror(errno));
        exit(1);
    }

    // Read the first line(hashed password) and if correct proceed for decryption.
    if (!isKeyMatched(inputFileFd, key))
    {
        perror("Password din't matched. Cannot decrypt file. Try Again.\n");
        closeFile(inputFileFd);
        exit(-1);
    }

    // open the destination for writing only having permissions of reading only.
    outputFileFd = open(outputFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IXUSR | S_IRGRP | S_IROTH);
    if (outputFileFd == -1)
    {
        fprintf(stderr, "Error opening output file\"%s\" due to %s", outputFileName, strerror(errno));
        exit(1);
    }

    encode(inputFileFd, outputFileFd, key);

    closeFile(inputFileFd);
    closeFile(outputFileFd);

    return;
}