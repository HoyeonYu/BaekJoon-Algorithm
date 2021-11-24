#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 10000 + 1
#define MAX_SUM 10000 * 5000 + 1
using namespace std;

bool find(int mid);

int arrNum, partNum;
vector<int> arrVec;

int main() {
	cin >> arrNum >> partNum;

	int arrSum = 0;

	for (int i = 0; i < arrNum; i++) {
		int num;
		cin >> num;

		arrVec.push_back(num);
		arrSum += num;
	}

	int minMaxDiff = MAX_SUM, mid, left = 0, right = arrSum;
	int whileCnt = 0;

	while (left <= right) {
		mid = (left + right) / 2;

		if (find(mid)) {
			right = mid - 1;
			minMaxDiff = min(minMaxDiff, mid);
		}
	
		else {
			left = mid + 1;
		}
	}

	cout << minMaxDiff;

	return 0;
}

bool find(int mid) {
	int maxVal, minVal, partCnt = 1;
	maxVal = minVal = arrVec[0];

	for (int i = 0; i < arrNum; i++) {
		minVal = min(minVal, arrVec[i]);
		maxVal = max(maxVal, arrVec[i]);

		if ((maxVal - minVal) > mid) {
			partCnt++;
			maxVal = minVal = arrVec[i];
		}
	}

	return partCnt <= partNum;
}