#include "routeCipher.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

RouteCipher::RouteCipher(int key) {
    if (key <= 0) {
        throw std::invalid_argument("Ключ должен быть положительным числом");
    }
    columns = key;
}

std::string RouteCipher::validateText(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    return result;
}

std::string RouteCipher::encrypt(const std::string& text) {
    std::string cleanText = validateText(text);
    if (cleanText.empty()) {
        throw std::invalid_argument("Текст не содержит букв");
    }
    
    int textLength = cleanText.length();
    int rows = (textLength + columns - 1) / columns;
    
    // Создаем таблицу
    std::vector<std::string> table(rows, std::string(columns, ' '));
    
    // Заполняем таблицу по строкам
    int pos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (pos < textLength) {
                table[i][j] = cleanText[pos++];
            } else {
                table[i][j] = 'X'; // заполнитель
            }
        }
    }
    
    // Читаем по столбцам справа налево
    std::string result;
    for (int j = columns - 1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            result += table[i][j];
        }
    }
    
    return result;
}

std::string RouteCipher::decrypt(const std::string& text) {
    std::string cleanText = validateText(text);
    if (cleanText.empty()) {
        throw std::invalid_argument("Текст не содержит букв");
    }
    
    int textLength = cleanText.length();
    int rows = (textLength + columns - 1) / columns;
    
    // Создаем таблицу
    std::vector<std::string> table(rows, std::string(columns, ' '));
    
    // Заполняем таблицу по столбцам справа налево
    int pos = 0;
    for (int j = columns - 1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            if (pos < textLength) {
                table[i][j] = cleanText[pos++];
            }
        }
    }
    
    // Читаем по строкам слева направо
    std::string result;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (table[i][j] != 'X') { // пропускаем заполнители
                result += table[i][j];
            }
        }
    }
    
    return result;
}