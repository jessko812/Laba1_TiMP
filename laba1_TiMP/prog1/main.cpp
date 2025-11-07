#include "modAlphaCipher.h"
#include <iostream>
#include <locale>
#include <algorithm>

void check(const std::wstring& Text, const std::wstring& key)
{
    std::wstring cipherText;
    std::wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    std::wcout << L"key=" << key << std::endl;
    std::wcout << L"Original: " << Text << std::endl;
    std::wcout << L"Encrypted: " << cipherText << std::endl;
    std::wcout << L"Decrypted: " << decryptedText << std::endl;

    std::wstring textWithoutSpaces = Text;
    textWithoutSpaces.erase(std::remove(textWithoutSpaces.begin(), textWithoutSpaces.end(), ' '), textWithoutSpaces.end());
    
    for (auto& c : textWithoutSpaces) {
        c = std::towupper(c);
    }

    if(decryptedText == textWithoutSpaces)
        std::wcout << L"Ok\n";
    else
        std::wcout << L"Err\n";
    
    std::wcout << L"-------------------" << std::endl;
}

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    check(L"Привет всем", L"Дота");
    check(L"НОВЫЙ СкЕйТбОрД", L"КоНцЕрТ");
    check(L"меланхоличная песня", L"очень популярная");

    return 0;
}