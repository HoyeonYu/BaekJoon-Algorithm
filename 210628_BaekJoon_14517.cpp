#include <iostream>
#define MAX_LEN 1000 + 1
#define MOD 10007
using namespace std;

long long palinDP[MAX_LEN][MAX_LEN] = { 0 };

int main() {
	string str;
	cin >> str;

	int strLen = str.length();

	for (int i = strLen - 1; i >= 0; i--) {
		for (int j = i; j < strLen; j++) {
			if (j - i == 0) {
				palinDP[i][j] = 1;
			}

			else if (j - i == 1) {
				palinDP[i][j] = 2 + (str[i] == str[j]);
			}

			else {
				palinDP[i][j] = palinDP[i][j - 1] + palinDP[i + 1][j] - palinDP[i + 1][j - 1] + MOD;

				if (str[i] == str[j]) {
					palinDP[i][j] += palinDP[i + 1][j - 1] + 1;
				}

				palinDP[i][j] %= MOD;
			}
		}
	}

	cout << palinDP[0][strLen - 1];

	return 0;
}