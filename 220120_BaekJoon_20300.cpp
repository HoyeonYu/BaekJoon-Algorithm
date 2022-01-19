#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	vector<long long int> vec;

	for (int i = 0; i < inputNum; i++) {
		long long int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	long long int minRes = vec[inputNum - 1];
	inputNum = (inputNum / 2) * 2;

	for (int i = 0; i < inputNum; i++) {
		long long int sum = vec[i] + vec[inputNum - i - 1];
		minRes = max(minRes, sum);
	}

	cout << minRes;

	return 0;
}