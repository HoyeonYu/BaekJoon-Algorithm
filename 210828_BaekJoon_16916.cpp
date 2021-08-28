#include <iostream>
#define MAX_LEN 1000000 + 1
using namespace std;

void getPi();
bool kmp();

string orgStr, findStr;
int pi[MAX_LEN] = { 0 };

int main() {
	cin >> orgStr >> findStr;
	getPi();
	cout << kmp();

	return 0;
}

void getPi() {
	int j = 0;

	for (int i = 1; i < findStr.length(); i++) {
		while (j > 0 && findStr[i] != findStr[j]) {
			j = pi[j - 1];
		}

		if (findStr[i] == findStr[j]) {
			pi[i] = ++j;
		}
	}
}

bool kmp() {
	int j = 0;

	for (int i = 0; i < orgStr.length(); i++) {
		while (j > 0 && orgStr[i] != findStr[j]) {
			j = pi[j - 1];
		}

		if (orgStr[i] == findStr[j]) {
			j++;

			if (j == findStr.length()) {
				return true;
			}
		}
	}

	return false;
}