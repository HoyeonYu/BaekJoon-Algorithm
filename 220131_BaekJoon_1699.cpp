#include <iostream>
#include <cmath>
#define MAX_SIZE 100000 + 1
using namespace std;


int main() {
	int num;
	cin >> num;

	int dp[MAX_SIZE];

	for (int i = 0; i <= num; i++) {
		dp[i] = i;
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[num];

	return 0;
}