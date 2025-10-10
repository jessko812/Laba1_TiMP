#pragma once
#include <string>
#include <vector>

class RouteCipher
{
private:
    int columns;
    std::string validateText(const std::string& text);

public:
    RouteCipher() = delete;
    RouteCipher(int key);
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
};