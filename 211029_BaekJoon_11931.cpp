#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> vec;

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;

		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < num; i++) {
		cout << vec[num - i - 1] << "\n";
	}

	return 0;
}