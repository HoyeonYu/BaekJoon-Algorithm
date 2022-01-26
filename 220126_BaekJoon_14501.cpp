#include <iostream>
#include <algorithm>
#define MAX_DAY 15 + 1
using namespace std;

int main() {
	int dayNum;
	cin >> dayNum;

	int deadline[MAX_DAY], price[MAX_DAY], dp[MAX_DAY];

	for (int i = 1; i <= dayNum; i++) {
		cin >> deadline[i] >> price[i];
		dp[i] = price[i];
	}

	for (int i = 2; i <= dayNum; i++) {
		for (int j = 1; j < i; j++) {
			if (deadline[j] + j <= i) {
				dp[i] = max(dp[i], price[i] + dp[j]);
			}
		}
	}

	int res = 0;

	for (int i = 1; i <= dayNum; i++) {
		if (i + deadline[i] <= dayNum + 1) {
			res = max(res, dp[i]);
		}
	}

	cout << res;

	return 0;
}