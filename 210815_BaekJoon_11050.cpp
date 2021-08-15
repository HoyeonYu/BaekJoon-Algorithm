#include <iostream>
using namespace std;

int fac(int n);

int main() {
	int n, m;
	cin >> n >> m;

	int up = fac(n);
	int down = fac(m) * fac(n - m);

	cout << up / down;

	return 0;
}

int fac(int n) {
	int res = 1;

	for (int i = n; i >= 1; i--) {
		res *= i;
	}

	return res;
}