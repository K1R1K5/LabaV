#include "vigenera.h"

char* crypt(const char* message, const char* key)
{
    size_t lengthMessage = strlen(message);
    size_t lengthKey = strlen(key);

    char* result = malloc(sizeof(char) * (lengthMessage + 1));
    result[lengthMessage] = '\0';

    for (size_t i = 0, k = 0; i < lengthMessage; i++, k++)
        result[i] = message[i] + key[k % lengthKey] % 256;

    return result;
}

char* decrypt(const char* message, const char* key)
{
    size_t lengthMessage = strlen(message);
    size_t lengthKey = strlen(key);

    char* result = malloc(sizeof(char) * (lengthMessage + 1));
    result[lengthMessage] = '\0';

    for (size_t i = 0, k = 0; i < lengthMessage; i++, k++)
        result[i] = message[i] - key[k % lengthKey] % 256;

    return result;
}