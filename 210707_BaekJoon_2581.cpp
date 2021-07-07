#include <iostream>
#define MAX_NUM 10000 + 1
using namespace std;

int main() {
	bool primeArr[MAX_NUM];

	for (int i = 0; i < MAX_NUM; i++) {
		primeArr[i] = true;
	}

	primeArr[1] = false;

	for (int i = 2; i < MAX_NUM; i++) {
		if (primeArr[i]) {
			for (int j = 2; i * j < MAX_NUM; j++) {
				primeArr[i * j] = false;
			}
		}
	}

	int num1, num2;
	cin >> num1 >> num2;

	int sum = 0;
	int minPrime = 0;

	for (int i = num1; i <= num2; i++) {
		if (primeArr[i]) {
			if (minPrime == 0) {
				minPrime = i;
			}

			sum += i;
		}
	}

	if (sum == 0) {
		cout << -1;
	}

	else {
		cout << sum << "\n" << minPrime;
	}

	return 0;
}