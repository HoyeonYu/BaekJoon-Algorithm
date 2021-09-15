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
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	return 0;
}