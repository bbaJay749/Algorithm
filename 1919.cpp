#include <iostream>
#include <list>
#include <string>
using namespace std;

void count(int alphabets[], char str) {
    switch (str) {
    case 'a': alphabets[0]++; break;
    case 'b': alphabets[1]++; break;
    case 'c': alphabets[2]++; break;
    case 'd': alphabets[3]++; break;
    case 'e': alphabets[4]++; break;
    case 'f': alphabets[5]++; break;
    case 'g': alphabets[6]++; break;
    case 'h': alphabets[7]++; break;
    case 'i': alphabets[8]++; break;
    case 'j': alphabets[9]++; break;
    case 'k': alphabets[10]++; break;
    case 'l': alphabets[11]++; break;
    case 'm': alphabets[12]++; break;
    case 'n': alphabets[13]++; break;
    case 'o': alphabets[14]++; break;
    case 'p': alphabets[15]++; break;
    case 'q': alphabets[16]++; break;
    case 'r': alphabets[17]++; break;
    case 's': alphabets[18]++; break;
    case 't': alphabets[19]++; break;
    case 'u': alphabets[20]++; break;
    case 'v': alphabets[21]++; break;
    case 'w': alphabets[22]++; break;
    case 'x': alphabets[23]++; break;
    case 'y': alphabets[24]++; break;
    case 'z': alphabets[25]++; break;
    }
}

int main() {
    string str;
    int len;
    int alphabets_1[26] = { 0 };
    int alphabets_2[26] = { 0 };

    cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++) {
        count(alphabets_1, str[i]);
    }

    cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++) {
        count(alphabets_2, str[i]);
    }

    int temp = 0;
    for (int i = 0; i < 26; i++) {
        temp += abs(alphabets_1[i] - alphabets_2[i]);
    }

    cout << temp << endl;

    return 0;
}
