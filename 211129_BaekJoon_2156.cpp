#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[10001];
	int input[10001];

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> input[i];
	}

	int res = 0;

	dp[0] = input[0];
	dp[1] = input[0] + input[1];
	dp[2] = max(input[0] + input[2], max(input[1] + input[2], dp[1]));

	res = max(dp[0], max(dp[1], dp[2]));

	for (int i = 3; i < num; i++) {
		dp[i] = max(dp[i - 3] + input[i - 1] + input[i], max(dp[i - 2] + input[i], dp[i - 1]));

		if (res < dp[i]) {
			res = dp[i];
		}
	}

	cout << res;

	return 0;
}