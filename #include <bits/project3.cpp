#include <bits/stdc++.h>
using namespace std;
#include "Rail_Fence.h"
#include "Hill_Cipher.h"

int main()
{
    string str;
    ifstream fin;
    fin.open("ss.txt");
    while (fin) {
         getline(fin, str);
    }
    fin.close();

    int key[3][3] = {
        { 6, 24, 1 },
        { 13, 16, 10 },
        { 20, 17, 15 }
    };

    cout << "Original text : " << str << endl;

    Hill_Cipher ob1;
    string c1 = ob1.encrypt(str, key);
    cout << "Encrypted text after hill ciphering - " << c1 <<endl;

    Rail_Fence ob2;
    string c2 = ob2.encryptRailFence(c1, 2);
    cout <<endl<< "Encrypted text after Rail fence - " << c2 << endl;

    string c3 = ob2.decryptRailFence(c2, 2);
    cout << "After Rail fence deciphering : " << c3 << endl;

    int inv[3][3];
    ob1.inverseMatrix(key, inv);

    string c4 = ob1.decrypt(c3, inv);
    cout <<endl<< "After hill deciphering : " << c4 << endl;
}

