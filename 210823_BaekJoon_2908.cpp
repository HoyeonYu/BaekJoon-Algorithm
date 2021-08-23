#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num1, num2;
	cin >> num1 >> num2;

	int rev1 = (num1 % 10) * 100 + (num1 / 10 % 10) * 10 + (num1 / 100);
	int rev2 = (num2 % 10) * 100 + (num2 / 10 % 10) * 10 + (num2 / 100);

	cout << max(rev1, rev2);

	return 0;
}