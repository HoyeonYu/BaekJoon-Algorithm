#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}

		for (int j = i; j < 2 * num - 1 - i; j++) {
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}