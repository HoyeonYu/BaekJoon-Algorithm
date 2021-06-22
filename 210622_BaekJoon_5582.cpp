#include <iostream>
#include <cmath>
#define MAX_LEN 4000 + 1
using namespace std;

int dp[MAX_LEN][MAX_LEN];

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			dp[i][j] = 0;
		}
	}

	int res = 0;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}

	cout << res;

	return 0;
}