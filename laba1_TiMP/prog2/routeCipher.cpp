#include "routeCipher.h"

#include <algorithm>
#include <string>
#include <vector>

routeCipher::routeCipher(int k)
    : key(k)
{
    if(key <= 0) {
        key = 1;
    }
}

std::string routeCipher::encrypt(const std::string& open_text)
{
    if(open_text.empty()) {
        return "";
    }

    std::vector<bool> is_space;
    std::string text_no_spaces;
    
    for(char c : open_text) {
        if(c == ' ') {
            is_space.push_back(true);
        } else {
            is_space.push_back(false);
            text_no_spaces += std::toupper(c);
        }
    }

    if(text_no_spaces.empty()) {
        return "";
    }

    int rows = (text_no_spaces.length() + key - 1) / key;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, ' '));

    int index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            if(index < text_no_spaces.length()) {
                table[i][j] = text_no_spaces[index++];
            }
        }
    }

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

std::string routeCipher::decrypt(const std::string& cipher_text)
{
    if(cipher_text.empty()) {
        return "";
    }

    std::string text = cipher_text;
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);

    int rows = (text.length() + key - 1) / key;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, ' '));

    int index = 0;
    for(int j = key - 1; j >= 0; j--) {
        for(int i = 0; i < rows; i++) {
            if(index < text.length()) {
                table[i][j] = text[index++];
            }
        }
    }


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