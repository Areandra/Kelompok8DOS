#include <iostream>
#include <string>
#include "DOS.hpp"

using namespace std;

int main() {
    cout << "Kelompok 8" << endl;
    cout << "Nama Anggota:" << endl;
    cout << "1. Muh. Ariel (F55124049)" << endl;
    cout << "2. Surya Kusuma Pamungkas (F55124062)" << endl;
    cout << "3. Latifah Putri Fakhruddin (F55124067)" << endl;
    cout << "4. Aul Zikri (F55124046)" << endl << endl;
    
    string cmd, arg;
    while (true) {
        cout << curentDir(DOS.current) << ">";
        cin >> cmd;

        if (cmd == "mkdir") {
            cin >> arg;
            mkdir(arg);
        } else if (cmd == "rmdir") {
            cin >> arg;
            rmdir(arg);
        } else if (cmd == "cd") {
            cin >> arg;
            cd(arg);
        } else if (cmd == "dir") {
            dir();
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "Perintah tidak dikenali.\n";
        }
    }
    
    return 0;
}