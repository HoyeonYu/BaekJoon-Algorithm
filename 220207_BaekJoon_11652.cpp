#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;
	
	map<long long, int> inputMap;
	int maxCnt = 0;
	long long maxInput;

	for (int i = 0; i < inputNum; i++) {
		long long input;
		cin >> input;

		inputMap[input]++;

		if (inputMap[input] > maxCnt) {
			maxCnt = inputMap[input];
			maxInput = input;
		}

		else if (inputMap[input] == maxCnt) {
			maxInput = min(input, maxInput);
		}
	}

	cout << maxInput;

	return 0;
}