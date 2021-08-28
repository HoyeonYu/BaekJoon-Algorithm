#include <iostream>
#include <cmath>
#define MAX_LEN 500000 + 1
using namespace std;

int piNum;
string str;
int pi[MAX_LEN] = { 0 };

void getPi();

int main() {
	long long num;
	cin >> str >> num;

	long long strLen = str.length();
	getPi();
	cout << strLen + (strLen - piNum) * (num - 1);

	return 0;
}

void getPi() {
	int j = 0;

	for (int i = 1; i < str.length(); i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}

		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}

	piNum = pi[str.length() - 1];
}