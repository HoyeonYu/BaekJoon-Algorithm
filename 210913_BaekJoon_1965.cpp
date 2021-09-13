#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> vec;
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}

	int maxRes = 1;
	vector<int> dp(num, 1);
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				maxRes = max(maxRes, dp[i]);
			}
		}
	}

	cout << maxRes;

	return 0;
}