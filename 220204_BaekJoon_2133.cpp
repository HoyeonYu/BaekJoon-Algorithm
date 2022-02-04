#include <iostream>
#define MAX_SIZE 30 + 1
using namespace std;

int main() {
	int sizeNum;
	cin >> sizeNum;

	int dp[MAX_SIZE] = { 0 };
	dp[0] = 1, dp[2] = 3;

	for (int i = 3; i <= sizeNum; i++) {
		dp[i] = dp[i - 2] * 3;

		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[sizeNum];

	return 0;
}