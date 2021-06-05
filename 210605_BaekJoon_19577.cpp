#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000 + 1
using namespace std;

long long getEulerPhi(int num);

int main() {
	int n;
	cin >> n;

	vector<int> candVec;

	for (int i = 1; i * i < n; i++) {
		if (n % i == 0) {
			candVec.push_back(i);
			candVec.push_back(n / i);
		}
	}

	sort(candVec.begin(), candVec.end());

	int resIdx = -1;

	if (n == 1) {
		resIdx = 1;
	}

	if (n % 2 == 0) {
		for (int i = 0; i < candVec.size(); i++) {
			long long res = getEulerPhi(candVec[i]) * candVec[i];

			if (res == n) {
				resIdx = candVec[i];
				break;
			}
		}
	}

	cout << resIdx;

	return 0;
}

long long getEulerPhi(int num) {
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

	return res;
}