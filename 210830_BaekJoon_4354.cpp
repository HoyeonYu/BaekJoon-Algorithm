#include <iostream>
#include <string.h>
#define MAX_LEN 1000000 + 1
using namespace std;

int pi[MAX_LEN];
string str;

void getPi();

int main() {
    while (true) {
        cin >> str;
        if (str == ".") break;

        getPi();
    }

    return 0;
}

void getPi() {
    int strLen = str.size();
    memset(pi, 0, sizeof(pi));

    for (int i = 1, j = 0; i < strLen; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }

        if (str[i] == str[j]) {
            pi[i] = ++j;
        }
    }

    int subLen = strLen - pi[strLen - 1];

    if (strLen % subLen != 0) {
        subLen = strLen;
    }

    cout << strLen / subLen << "\n";
}