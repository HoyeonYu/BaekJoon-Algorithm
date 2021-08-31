#include <iostream>
#define MAX_LEN 360000
using namespace std;

void getPi();
bool kmp();

string orgStr = "", findStr = "";
int pi[MAX_LEN] = { 0 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i < MAX_LEN; i++) {
		orgStr += '0';
		findStr += '0';
	}

	for (int i = 0, input; i < num; i++) {
		cin >> input;
		orgStr[input] = '1';
	}

	for (int i = 0, input; i < num; i++) {
		cin >> input;
		findStr[input] = '1';
	}

	findStr += findStr;

	getPi();
	
	cout << (kmp() ? "possible" : "impossible");

	return 0;
}

void getPi() {
	for (int i = 1, j = 0; i < MAX_LEN; i++) {
		while (j > 0 && orgStr[i] != orgStr[j]) {
			j = pi[j - 1];
		}

		if (orgStr[i] == orgStr[j]) {
			pi[i] = ++j;
		}
	}
}

bool kmp() {
	for (int i = 0, j = 0; i < 2 * MAX_LEN - 1; i++) {
		while (j > 0 && findStr[i] != orgStr[j]) {
			j = pi[j - 1];
		}

		if (findStr[i] == orgStr[j]) {
			if (j == MAX_LEN - 1) {
				return true;
			}

			j++;
		}
	}

	return false;
}