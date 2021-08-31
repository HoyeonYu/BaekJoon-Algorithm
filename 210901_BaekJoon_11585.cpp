#include <iostream>
#define MAX_LEN 1000000 + 1
using namespace std;

int pi[MAX_LEN] = { 0 };
int strLen, res = 0;
string orgStr = "", findStr = "";

void getPi();
void kmp();
void getRes();

int main() {
	cin >> strLen;

	for (int i = 0; i < strLen; i++) {
		string input;
		cin >> input;
		orgStr += input;
	}

	for (int i = 0; i < strLen; i++) {
		string input;
		cin >> input;
		findStr += input;
	}

	findStr += findStr;

	getPi();
	kmp();
	getRes();

	return 0;
}

void getPi() {
	for (int i = 1, j = 0; i < strLen; i++) {
		while (j > 0 && orgStr[i] != orgStr[j]) {
			j = pi[j - 1];
		}

		if (orgStr[i] == orgStr[j]) {
			pi[i] = ++j;
		}
	}
}

void kmp() {
	for (int i = 0, j = 0; i < strLen * 2 - 1; i++) {
		while (j > 0 && findStr[i] != orgStr[j]) {
			j = pi[j - 1];
		}

		if (findStr[i] == orgStr[j]) {
			if (j == strLen - 1) {
				j = pi[j];
				res++;
			}

			else {
				j++;
			}
		}
	}
}

void getRes() {
	int a = res, b = strLen;

	while (a > 0) {
		int temp = b % a;
		b = a;
		a = temp;
	}

	cout << (res / b) << "/" << (strLen / b);
}