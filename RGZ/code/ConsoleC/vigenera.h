#pragma once

#include <stdlib.h>
#include <string.h>

// ������� ��� ���������� ������ � ������ ������� ��������
char* crypt(const char* message, const char* key);

// ������� ��� ������������ ������ � ������ ������� ��������
char* decrypt(const char* message, const char* key);