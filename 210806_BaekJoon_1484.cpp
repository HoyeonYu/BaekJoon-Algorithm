#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;

	int root = sqrt(num);
	vector<int> vec;

	for (int i = 1; i <= root; i++) {
		if (num % i == 0) {
			if ((num / i) == i) {
				break;
			}

			vec.push_back(i);
			vec.push_back(num / i);
		}
	}

	vector<int> resVec;

	for (int i = 0; i < vec.size(); i+=2) {
		if ((vec[i] + vec[i + 1]) % 2 == 0) {
			resVec.push_back((vec[i] + vec[i + 1]) / 2);
		}
	}

	sort(resVec.begin(), resVec.end());

	if (resVec.size() == 0) {
		cout << -1;
	}

	for (int i = 0; i < resVec.size(); i++) {
		cout << resVec[i] << "\n";
	}

	return 0;
}