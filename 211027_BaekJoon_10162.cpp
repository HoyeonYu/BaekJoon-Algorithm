#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int a = num / 300;
	num -= a * 300;

	int b = num / 60;
	num -= b * 60;

	int c = num / 10;
	num -= c * 10;

	if (num != 0) {
		cout << -1;
	}

	else {
		cout << a << " " << b << " " << c;
	}

	return 0;
}