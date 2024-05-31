#define _CRT_SECURE_NO_WARNINGS

// Макрос максимальной длинны текста при его считывании из файла
#define SIZE_FILE 1024 * 128

#include <stdio.h>
#include <stdlib.h>
#include "vigenera.h"

// Функция для считывания текста из файла. Возвращает нулевой указатель в случае ошибки
char* readFromFile(const char* filename);
// Функция для записи текста в файл. Возвращает нулевой указатель в случае ошибки
char* writeToFile(const char* filename, const char* message);

// Главная функция
int main()
{
    // Включение русской кодировки в консоли
    system("chcp 1251");

    // Имя входного файла
    char filenameIn[256];
    // Имя выходного файла
    char filenameOut[256];

    // Текст до шифрования
    char* message = 0;
    // Текст после шифрования
    char* result = 0;
    // Ключ
    char key[256];

    printf("Введите название файла, с которого взять текст: ");
    scanf("%s", filenameIn);

    // Считывание текста из файла
    message = readFromFile(filenameIn);
    if (message == 0)
    {
        printf("Ошибка считывания текста из файла!\n");

        system("pause");
        return -1;
    }

    printf("Введите название файла, в который нужно записать результат операции: ");
    scanf("%s", filenameOut);

    printf("Введите ключ: ");
    scanf("%s", key);

    int operation = 0;
    printf("Выберите операцию: \n");
    printf("0. Выход\n");
    printf("1. Зашифровать текст\n");
    printf("2. Расшифровать текст\n");
    scanf("%d", &operation);

    // Выбор операции
    switch (operation)
    {
    case 0:
        // Очистка занятой памяти перед выходом
        free(message);
        return 0;
    case 1:
        // Шифрование считанного текста
        result = crypt(message, key);
        break;
    case 2:
        // Дешифрование считанного текста
        result = decrypt(message, key);
        break;
    default:
        printf("Была выбрана некорректная операция");

        system("pause");
        break;
    }

    // Если запись результатов была с ошибкой
    if (writeToFile(filenameOut, result) == 0)
    {
        printf("Ошибка записи результата в файл!");

        system("pause");
        return -1;
    }

    // Очистка занятой памяти
    free(message);
    free(result);

    system("pause");
    return 0;
}

char* readFromFile(const char* filename)
{
    // Открытие файла для чтения
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
        return 0;

    // Перемещаем указатель в конец файла
    fseek(file, 0, SEEK_END);
    // Получаем размер файла
    long fileSize = ftell(file);
    // Возвращаем указатель в начало файла
    rewind(file);

    // Выделяем память под буфер
    char* buffer = malloc(sizeof(char) * fileSize);
    if (buffer == NULL) 
    {
        fclose(file);
        return 0;
    }

    // Считываем весь текст из файла
    fread(buffer, sizeof(char), fileSize - 1, file);
    buffer[fileSize - 1] = '\0';

    // Освобождаем память и закрываем файл
    fclose(file);

    return buffer;
}
char* writeToFile(const char* filename, const char* message)
{
    // Открываем файл для записи
    FILE* file = fopen(filename, "w");
    // Проверяем успешность открытия файла
    if (file == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }

    // Записываем сообщение в файл
    fprintf(file, "%s", message);

    // Закрываем файл
    fclose(file);

    return message;
}