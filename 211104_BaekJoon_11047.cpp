#include <iostream>
#define MAX_COIN 10 + 1
using namespace std;

int main() {
	int coinNum, targetAmount;
	cin >> coinNum >> targetAmount;

	int coinArr[MAX_COIN];

	for (int i = 0; i < coinNum; i++) {
		cin >> coinArr[i];
	}

	int res = 0;

	for (int i = coinNum - 1; i >= 0; i--) {
		if (coinArr[i] <= targetAmount) {
			res += targetAmount / coinArr[i];
			targetAmount %= coinArr[i];
		}
	}

	cout << res;

	return 0;
}