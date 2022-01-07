#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int increasedN = N;

	while (true) {
		int cnt = 0, tmpN = increasedN;

		while (tmpN > 0) {
			cnt += (tmpN % 2);
			tmpN /= 2;
		}

		if (cnt <= K) {
			cout << (increasedN - N);
			break;
		}

		increasedN++;
	}

	return 0;
}