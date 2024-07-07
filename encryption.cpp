#include "encryption.h"
#include <fstream>
#include <cctype>
using namespace std;

bool performCipher(string& content, bool encrypt) {
    int shift = encrypt ? 3 : -3;
    for (char& c : content) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = static_cast<char>((c - base + shift + 26) % 26 + base);
        }
    }
    return true;
}

bool encrypt(const string& filename, bool encrypt) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }
    string content(istreambuf_iterator<char>(inFile), {});
    inFile.close();

    if (performCipher(content, encrypt)) {
        ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (outFile) {
            return false;
        }
        outFile << content;
        outFile.close();
        return true;
    }
    return false;
}