// encryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the message using a substitution cipher
string encrypt(string message, string key) {
    string encrypted_message = message;
    for (char& c : encrypted_message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = key[c - base];
        }
    }
    return encrypted_message;
}

// Function to decrypt the encrypted message using a substitution cipher
string decrypt(string encrypted_message, string key) {
    string decrypted_message = encrypted_message;
    for (char& c : decrypted_message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = 'A' + key.find(c);
            if (islower(c)) {
                c += 'a' - 'A';
            }
        }
    }
    return decrypted_message;
}

int main() {
    string key = "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"; // Substitution key

    string message;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    // Encryption
    string encrypted_message = encrypt(message, key);
    cout << "Encrypted message: " << encrypted_message << endl;

    // Decryption
    string decrypted_message = decrypt(encrypted_message, key);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
