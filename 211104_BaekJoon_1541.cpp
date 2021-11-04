#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;

	int val = 0, sum = 0;
	bool isMinusExist = false;

	for (int i = 0; i < input.length(); i++) {
		if (isalnum(input[i])) {
			val = val * 10 + (input[i] - '0');
		}

		else {
			sum = (isMinusExist ? sum - val : sum + val);
			val = 0;

			if (input[i] == '-') {
				isMinusExist = true;
			}
		}
	}

	sum = (isMinusExist ? sum - val : sum + val);
	cout << sum;

	return 0;
}