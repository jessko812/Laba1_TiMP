#include <iostream>
#include <string>
#include "routeCipher.h"

using namespace std;

void displayMenu() {
    cout << "=== Шифр табличной маршрутной перестановки ===" << endl;
    cout << "1. Зашифровать текст" << endl;
    cout << "2. Расшифровать текст" << endl;
    cout << "3. Тестовый пример" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите операцию: ";
}

void testExample() {
    try {
        RouteCipher cipher(3);
        string text = "HELLOWORLD";
        
        cout << "Тестовый пример:" << endl;
        cout << "Ключ (столбцов): 3" << endl;
        cout << "Исходный текст: " << text << endl;
        
        string encrypted = cipher.encrypt(text);
        cout << "Зашифрованный: " << encrypted << endl;
        
        string decrypted = cipher.decrypt(encrypted);
        cout << "Расшифрованный: " << decrypted << endl;
        
        // Убираем возможные заполнители 'X' для сравнения
        string cleanDecrypted;
        for (char c : decrypted) {
            if (c != 'X') cleanDecrypted += c;
        }
        
        cout << "Очищенный результат: " << cleanDecrypted << endl;
        cout << (text == cleanDecrypted ? "Успех!" : "Ошибка!") << endl;
        
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

int main() {
    int choice;
    int key;
    string text;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // очистка буфера
        
        switch (choice) {
            case 1: {
                cout << "Введите ключ (количество столбцов): ";
                cin >> key;
                cin.ignore();
                
                cout << "Введите текст для шифрования: ";
                getline(cin, text);
                
                try {
                    RouteCipher cipher(key);
                    string result = cipher.encrypt(text);
                    cout << "Зашифрованный текст: " << result << endl;
                } catch (const exception& e) {
                    cout << "Ошибка при шифровании: " << e.what() << endl;
                }
                break;
            }
            
            case 2: {
                cout << "Введите ключ (количество столбцов): ";
                cin >> key;
                cin.ignore();
                
                cout << "Введите текст для расшифрования: ";
                getline(cin, text);
                
                try {
                    RouteCipher cipher(key);
                    string result = cipher.decrypt(text);
                    cout << "Расшифрованный текст: " << result << endl;
                } catch (const exception& e) {
                    cout << "Ошибка при расшифровании: " << e.what() << endl;
                }
                break;
            }
            
            case 3:
                testExample();
                break;
                
            case 0:
                cout << "Выход из программы." << endl;
                break;
                
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
        cout << endl;
        
    } while (choice != 0);
    
    return 0;
}