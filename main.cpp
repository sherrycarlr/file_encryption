#include <iostream>
#include "encryption.h"

using namespace std;
int main (){
    string filename;
    char mode;
    cout << "Enter the name of the file: ";
    getline(cin >> ws, filename);

    cout << "Encrypt or Decrypt? (E/D)?: ";
    cin >> mode;

    if (mode == 'e' || mode == 'E'){
        if (encrypt(filename, true)) {
            cout << "File encrypted successfully" << endl;
        } else {
            cerr << "Error encrypting file" << endl;
        };
    } else if (mode == 'd' || mode == 'D'){
        if(encrypt(filename, false)){
            cout << "File decrypted successfully" << endl;
        } else {
            cerr << "Error decrypting file" << endl;
        };
    } else {
        cout << "Invalid mode" << endl;
    }
    return 0;
} // namespace std;
