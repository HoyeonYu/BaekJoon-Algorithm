#include <iostream>
#define MAX_LEN 200000 + 1
using namespace std;

void getPi();
bool kmp();

int pi[MAX_LEN] = { 0 };
string orgStr = "", findStr;

int main() {
	string temp;
	cin >> temp >> findStr;

	for (int i = 0; i < temp.length(); i++) {
		if (isalpha(temp[i])) {
			orgStr += temp[i];
		}
	}

	getPi();
	cout << kmp();

	return 0;
}

void getPi() {
	for (int i = 1, j = 0; i < orgStr.length(); i++) {
		while (j > 0 && orgStr[i] != orgStr[j]) {
			j = pi[j - 1];
		}

		if (orgStr[i] == orgStr[j]) {
			pi[i] = ++j;
		}
	}
}

bool kmp() {
	for (int i = 0, j = 0; i < orgStr.length(); i++) {
		while (j > 0 && orgStr[i] != findStr[j]) {
			j = pi[j - 1];
		}
		
		if (orgStr[i] == findStr[j]) {
			if (j == findStr.length() - 1) {
				return true;
			}

			j++;
		}
	}

	return false;
}