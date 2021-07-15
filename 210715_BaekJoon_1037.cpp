#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;

	vector<long long> vec;

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	cout << vec[0] * vec[num - 1];

	return 0;
}