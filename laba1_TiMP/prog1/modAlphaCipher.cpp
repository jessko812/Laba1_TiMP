#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <algorithm>

modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(toUpperCase(skey));
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work;
    std::wstring upperText = toUpperCase(open_text);
    for (auto c : upperText) {
        if (c != ' ') {
            work.push_back(alphaNum[c]);
        }
    }
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    std::wstring result = convert(work);
    return result;
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}

std::wstring modAlphaCipher::toUpperCase(const std::wstring& s)
{
    std::wstring result = s;
    for (auto& c : result) {
        c = std::towupper(c);
    }
    return result;
}