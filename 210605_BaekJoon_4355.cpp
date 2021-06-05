#include <iostream>
using namespace std;

int main() {
	long long num;
	cin >> num;

	while (num != 0) {
		long long prime = 2;
		long long res = num;

		while (prime * prime <= num) {
			if (num % prime == 0) {
				res = (res / prime) * (prime - 1);
			}

			while (num % prime == 0) {
				num /= prime;
			}

			prime++;
		}

		if (num != 1) {
			res = (res / num) * (num - 1);
		}

		cout << res << "\n";
		cin >> num;
	}

	return 0;
}