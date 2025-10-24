#include "modAlphaCipher.h"

#include <iostream>
#include <locale>

void check(const std::wstring& Text, const std::wstring& key)
{
    std::wstring cipherText;
    std::wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    std::wcout << L"key=" << key << std::endl;
    std::wcout << Text << std::endl;
    std::wcout << cipherText << std::endl;
    std::wcout << decryptedText << std::endl;
    if(Text == decryptedText)
        std::wcout << L"Ok\n";
    else
        std::wcout << L"Err\n";
}

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    check(L"ПРИВЕТ", L"ДОТА");
    check(L"ПРОГРАММИРОВАНИЕ", L"КОМПЬЮТЕР");
    check(L"ШИФРОВАНИЕ", L"ИНТЕРНЕТ");

    return 0;
}
