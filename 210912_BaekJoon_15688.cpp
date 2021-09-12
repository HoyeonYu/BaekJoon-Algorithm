#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

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
		cout << vec[i] << "\n";
	}

	return 0;
}