#include <iostream>
#define MAX_LEN 40 + 1
using namespace std;

string dp[MAX_LEN][MAX_LEN];

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = "";
			}

			else {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
				}

				else {
					dp[i][j] = (dp[i - 1][j].length() < dp[i][j - 1].length() ? 
								dp[i][j - 1] : dp[i - 1][j]);
				}
			}
		}
	}

	cout << dp[str1.length()][str2.length()];

	return 0;
}