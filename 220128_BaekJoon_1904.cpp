#include <iostream>
#define MAX_SIZE 1000000 + 1
#define MOD 15746
using namespace std;

int dp[MAX_SIZE];

int main() {
	int inputNum;
	cin >> inputNum;

	dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= inputNum; i++) {
		dp[i] = (dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
	}

	cout << dp[inputNum];

	return 0;
}