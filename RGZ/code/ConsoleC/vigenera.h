#pragma once

#include <stdlib.h>
#include <string.h>

// Функция для шифрования текста с ключом методом Вижинера
char* crypt(const char* message, const char* key);

// Функция для дешифрования текста с ключом методом Вижинера
char* decrypt(const char* message, const char* key);