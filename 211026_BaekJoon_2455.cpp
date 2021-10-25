#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int maxPeople = 0;
	int curPeople = 0;

	for (int i = 0; i < 4; i++) {
		int output, input;
		cin >> output >> input;

		curPeople = curPeople + input - output;
		maxPeople = max(maxPeople, curPeople);
	}

	cout << maxPeople;

	return 0;
}