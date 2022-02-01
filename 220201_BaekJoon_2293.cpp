#include <iostream>
#define MAX_TYPE 100 + 1
#define MAX_AMOUNT 10000 + 1
using namespace std;

int main() {
	int typeNum, totalAmount;
	cin >> typeNum >> totalAmount;

	int typeArr[MAX_TYPE], dp[MAX_AMOUNT] = { 0 };

	for (int i = 0; i < typeNum; i++) {
		cin >> typeArr[i];
	}

	dp[0] = 1;

	for (int i = 0; i < typeNum; i++) {
		for (int j = 1; j <= totalAmount; j++) {
			if (j >= typeArr[i]) {
				dp[j] += dp[j - typeArr[i]];
			}
		}
	}

	cout << dp[totalAmount];

	return 0;
}