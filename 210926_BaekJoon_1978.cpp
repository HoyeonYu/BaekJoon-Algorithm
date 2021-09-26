#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
	int totNum;
	cin >> totNum;

	int sum = 0;

	for (int i = 0; i < totNum; i++) {
		int num;
		cin >> num;

		bool isPrime = true;

		if (num == 1) {
			continue;
		}

		for (int j = 2; j < num; j++) {
			if (num % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			sum++;
		}
	}

	cout << sum;

	return 0;
}