#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	long long res = 1;

	while (num >= 5) {
		res = (3 * res) % 10007;
		num -= 3;
	}

	cout << (res * num) % 10007 << endl;
}