#pragma once
#include <algorithm>
#include <string>
#include <vector>

class routeCipher
{
private:
    int key;

public:
    routeCipher() = delete;
    routeCipher(int k);

    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};