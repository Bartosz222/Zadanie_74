#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 200;
ifstream wejscie;
ofstream wyjscie;
void z1() {
    string napis;
    bool check = true;
    int suma = 0;
    wejscie.open("hasla.txt");
    for (int i = 1; i <= SIZE; i++) {
        wejscie >> napis;
        for (int j = 0; j <= napis.length(); j++) {
            if (napis[j] >= 'a' && napis[j] <= 'z' || napis[j] >= 'A' && napis[j] <= 'Z') check = false;
        }
        if (check) suma++;
        check = true;
    }
    wejscie.close();
    cout << "Zadanie 1: " << suma << endl;
    wyjscie << "Zadanie 1: " << suma << endl;
}
void z2() {
    string tab[SIZE];
    string napis;
    wejscie.open("hasla.txt");
    bool check = false;
    for (int i = 0; i < SIZE; i++) {
        wejscie >> napis;
        tab[i] = napis;
    }
    wejscie.close();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE - i; j++) {
            if (tab[j - 1].length() > tab[j].length()) swap(tab[j - 1], tab[j]);
        }
    }
    cout << "Zadanie 2: " << endl;
    wyjscie << "Zadanie 2: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE-i; j++) {
            if (tab[i] == tab[i + j]) check = true;
        }
        if (check) {
            cout << tab[i] << endl;
            wyjscie << tab[i] << endl;
        }
        check = false;
    }
}
bool checkInt(string x) {
    bool check = true;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] >= '0' && x[i] <= '9') check = false;
    }
    if (!check) return true;
    else return false;
}
bool checkDownLetter(string x) {
    bool check = true;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] >= 'a' && x[i] <= 'z') check = false;
    }
    if (!check) return true;
    else return false;
}
bool checkUpLetter(string x) {
    bool check = true;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] >= 'A' && x[i] <= 'Z') check = false;
    }
    if (!check) return true;
    else return false;
}
void z4() {
    string napis;
    int suma = 0;
    wejscie.open("hasla.txt");
    bool check = true;
    cout << "Zadanie 4:" << endl;
    wyjscie << "Zadanie 4:" << endl;
    for (int i = 0; i < SIZE; i++) {
        wejscie >> napis;
        if (checkInt(napis) && checkDownLetter(napis) && checkUpLetter(napis)) {
            suma++;
        }
        check = true;
    }
    cout << suma <<endl;
    wyjscie << suma<< endl;
    wejscie.close();
}
int main(){
    wyjscie.open("wynik.txt");
    z1();
    z2();
    z4();
    wyjscie.close();
    return 0;
}
