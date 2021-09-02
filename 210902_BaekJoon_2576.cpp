#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int minVal = 101;
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;

		if (num % 2) {
			sum += num;
			minVal = min(minVal, num);
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	
	else {
		cout << sum << "\n" << minVal;
	}

	return 0;
}