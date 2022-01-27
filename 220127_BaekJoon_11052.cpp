#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000 + 1
using namespace std;

int main() {
	int cardNum;
	cin >> cardNum;

	int cardPrice[MAX_SIZE], dp[MAX_SIZE] = { 0 };

	for (int i = 1; i <= cardNum; i++) {
		cin >> cardPrice[i];
	}

	for (int i = 1; i <= cardNum; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + cardPrice[j]);
		}
	}

	cout << dp[cardNum];

	return 0;
}
