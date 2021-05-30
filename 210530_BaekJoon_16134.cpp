#include <iostream>
#define MOD 1000000007LL
#define MAX 1000000
using namespace std;

long long facArray[MAX + 1];
long long inverseFacArray[MAX + 1];

long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}

	if (b % 2 == 1) {
		return (pow(a, b - 1) * a) % MOD;
	}

	long long half = pow(a, b / 2) % MOD;

	return half * half % MOD;
}

void fac() {
	facArray[0] = 1;

	for (int i = 1; i <= MAX; i++) {
		facArray[i] = facArray[i - 1] * i % MOD;
	}

	inverseFacArray[MAX] = pow(facArray[MAX], MOD - 2);

	for (int i = MAX - 1; i >= 0; i--) {
		inverseFacArray[i] = inverseFacArray[i + 1] * (i + 1) % MOD;
	}
}

int main() {
	fac();

	int n, r;
	cin >> n >> r;

	long long A = facArray[n];
	long long B = (inverseFacArray[r] * inverseFacArray[n - r]) % MOD;
	long long res = (A * B) % MOD;

	cout << res;

	return 0;
}