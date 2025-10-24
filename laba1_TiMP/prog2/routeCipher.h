#pragma once
#include <algorithm>
#include <string>
#include <vector>

class routeCipher
{
private:
    int key; // количество столбцов таблицы

public:
    routeCipher() = delete; // запретим конструктор без параметров
    routeCipher(int k);     // конструктор для инициализации ключом

    // зашифрование
    std::string encrypt(const std::string& open_text);
    // расшифрование
    std::string decrypt(const std::string& cipher_text);
};