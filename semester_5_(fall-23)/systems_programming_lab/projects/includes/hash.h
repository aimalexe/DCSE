#include <stdint.h>
#include <string.h>
#include <stdio.h>

/**
 * A function to create a hash for a string.

 * @param input: the string you want a hash for.
 * @param hash: the hash of the input is stored here.

 * @return void
*/
void generateHash(const char *input, char *hash)
{
    uint32_t value = 0;
    char temp[9];

    for (unsigned int i = 0; i < strlen(input); i++)
        value = ((value << 5) + value) + input[i]; // hash * 33 + c

    // Convert the 32-bit hash value to a hexadecimal string
    snprintf(temp, sizeof(temp), "%08x", value);

    strncpy(hash, temp, sizeof(temp));
    hash[sizeof(temp)] = '\0';
}

/**
 * A function which extracts the password hash from first line of a file and compare it with the provided key.

 * @param file a file whose first line contain the hash of a password
 * @param key the key which is to be compared with the password in file.
 *
 * @return 0 for unmatched else 1 for matched password.
 */
int isKeyMatched(const int file, const char *key)
{
    char password[9],
        hash[9];
    int i = 0;
    char ch;

    while (read(file, &ch, 1) > 0)
    {
        if (ch == '\n')
            break; // End of password line

        if (i < sizeof(password) - 1)
        {
            password[i] = ch; // Store the character in the password array
            i++;
        }
        else
        {
            fprintf(stderr, "Password exceeds buffer size.\n");
            exit(1);
        }
    }

    password[i] = '\0';
    generateHash(key, hash);

    if (strcmp(password, hash))
        return 0;

    return 1;
}