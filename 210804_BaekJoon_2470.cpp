#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	vector<int> vec;

	for (int i = 0; i < inputNum; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int frontPointer = 0, backPointer = inputNum - 1;
	int minSum = 2e9 + 1, minFrontVal = 0, minBackVal = 0;

	while (frontPointer < backPointer) {
		int sum = vec[frontPointer] + vec[backPointer];

		if (abs(sum) < abs(minSum)) {
			minSum = sum;
			minFrontVal = vec[frontPointer];
			minBackVal = vec[backPointer];
		}

		if (sum == 0) {
			break;
		}

		if (sum < 0) {
			frontPointer++;
		}

		else {
			backPointer--;
		}
	}

	cout << minFrontVal << " " << minBackVal;

	return 0;
}