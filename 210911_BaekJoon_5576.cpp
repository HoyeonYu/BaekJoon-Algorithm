#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec[2];
	for (int i = 0; i < 20; i++) {
		int num;
		cin >> num;
		vec[i / 10].push_back(num);
	}

	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());

	cout << vec[0][7] + vec[0][8] + vec[0][9] << " ";
	cout << vec[1][7] + vec[1][8] + vec[1][9] << " ";

	return 0;
}