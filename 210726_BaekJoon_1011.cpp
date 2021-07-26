#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tcNum;
	cin >> tcNum;

	for (int i = 0; i < tcNum; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		num2 -= num1;

		int z = 1;
		long long sum = 0;

		while (num2 > sum + z * 2) {
			sum += z * 2;
			z++;
		}

		if (sum + z >= num2) {
			cout << 2 * z - 1 << "\n";
		}

		else {
			cout << 2 * z << "\n";
		}
	}

	return 0;
}