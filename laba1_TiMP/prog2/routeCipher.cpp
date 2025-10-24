#include "routeCipher.h"

#include <algorithm>
#include <string>
#include <vector>

// Конструктор
routeCipher::routeCipher(int k)
    : key(k)
{
    if(key <= 0) {
        key = 1; // минимальное значение ключа
    }
}

// Метод зашифрования
std::string routeCipher::encrypt(const std::string& open_text)
{
    // Удаляем пробелы из текста и преобразуем к верхнему регистру
    std::string text = open_text;
    text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);

    if(text.empty()) {
        return "";
    }

    // Вычисляем количество строк
    int rows = (text.length() + key - 1) / key;

    // Создаем таблицу для записи
    std::vector<std::vector<char>> table(rows, std::vector<char>(key, ' '));

    // Записываем текст в таблицу по горизонтали слева направо, сверху вниз
    int index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            if(index < text.length()) {
                table[i][j] = text[index++];
            }
        }
    }

    // Считываем по маршруту: сверху вниз, справа налево
    std::string result;
    for(int j = key - 1; j >= 0; j--) {
        for(int i = 0; i < rows; i++) {
            if(table[i][j] != ' ') {
                result += table[i][j];
            }
        }
    }

    return result;
}

// Метод расшифрования
std::string routeCipher::decrypt(const std::string& cipher_text)
{
    if(cipher_text.empty()) {
        return "";
    }

    std::string text = cipher_text;
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);

    // Вычисляем количество строк
    int rows = (text.length() + key - 1) / key;

    // Создаем таблицу для расшифрования
    std::vector<std::vector<char>> table(rows, std::vector<char>(key, ' '));

    // Заполняем таблицу по маршруту считывания: сверху вниз, справа налево
    int index = 0;
    for(int j = key - 1; j >= 0; j--) {
        for(int i = 0; i < rows; i++) {
            if(index < text.length()) {
                table[i][j] = text[index++];
            }
        }
    }

    // Читаем по маршруту записи: по горизонтали слева направо, сверху вниз
    std::string result;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            if(table[i][j] != ' ') {
                result += table[i][j];
            }
        }
    }

    return result;
}