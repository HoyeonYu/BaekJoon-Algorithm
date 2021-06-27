#include <iostream>
#define MAX_LEN 30 + 1
using namespace std;

int main() {
	string str;
	cin >> str;

	int palinDP[MAX_LEN][MAX_LEN] = { 0 };

	for (int i = str.length() - 1; i >= 0; i--) {
		for (int j = i; j < str.length(); j++) {
			if (j - i == 0) {
				palinDP[i][j] = 1;
			}

			else if (j - i == 1) {
				palinDP[i][j] = 2 + (str[i] == str[j]);
			}

			else {
				palinDP[i][j] = palinDP[i][j - 1] + palinDP[i + 1][j];

				if (str[i] == str[j]) {
					palinDP[i][j]++;
				}

				else {
					palinDP[i][j] -= palinDP[i + 1][j - 1];
				}
			}
		}
	}

	cout << palinDP[0][str.length() - 1];

	return 0;
}