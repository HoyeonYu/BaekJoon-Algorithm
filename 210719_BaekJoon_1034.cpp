#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int row, col, k;
	cin >> row >> col;

	vector<string> stringVec;
	vector<int> zeroVec;

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		stringVec.push_back(str);
		zeroVec.push_back(0);

		for (int j = 0; j < col; j++) {
			if (str[j] == '0') {
				zeroVec[i]++;
			}
		}
	}

	cin >> k;
	int maxVal = 0;

	for (int i = 0; i < row; i++) {
		int sameRow = 0;

		if (zeroVec[i] <= k && (zeroVec[i] % 2 == k % 2)) {
			for (int j = 0; j < row; j++) {
				if (stringVec[i] == stringVec[j]) {
					sameRow++;
				}
			}
		}

		maxVal = max(maxVal, sameRow);
	}

	cout << maxVal;

	return 0;
}