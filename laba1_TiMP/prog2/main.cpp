#include "routeCipher.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int key;
    string text;
    unsigned op;

    cout << "Route Transposition Cipher is ready. Input key (number of columns): ";
    cin >> key;

    if(key <= 0) {
        cerr << "Error: key must be a positive integer!" << endl;
        return 1;
    }

    cout << "Key loaded successfully!" << endl;
    routeCipher cipher(key);

    do {
        cout << "\nChoose operation (0-exit, 1-encrypt, 2-decrypt): ";
        cin >> op;
        cin.ignore(); // очищаем буфер ввода

        if(op > 2) {
            cout << "Invalid operation!" << endl;
        } else if(op > 0) {
            cout << "Input text: ";
            getline(cin, text);

            if(!text.empty()) {
                if(op == 1) {
                    cout << "Encrypted text: " << cipher.encrypt(text) << endl;
                } else {
                    cout << "Decrypted text: " << cipher.decrypt(text) << endl;
                }
            } else {
                cout << "Error: text cannot be empty!" << endl;
            }
        }
    } while(op != 0);

    cout << "Work completed." << endl;
    return 0;
}