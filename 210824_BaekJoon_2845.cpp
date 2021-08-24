#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a * b;

	for (int i = 0; i < 5; i++) {
		int d;
		cin >> d;
		cout << d - c << " ";
	}

	return 0;
}