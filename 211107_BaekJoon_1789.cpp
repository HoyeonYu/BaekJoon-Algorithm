#include <iostream>
using namespace std;

int main() {
	long long sum;
	cin >> sum;

	long long res = 1, calc = 0;

	while (true) {
		calc = (res * (res + 1)) / 2;

		if (calc > sum) {
			cout << res - 1;
			break;
		}

		res++;
	}

	return 0;
}