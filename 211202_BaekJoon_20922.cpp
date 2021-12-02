#include <iostream>
#include <algorithm>
#define MAX_NUM 200000 + 1
using namespace std;

int numArr[MAX_NUM];
int numCount[MAX_NUM];

int main() {
	cin.tie(nullptr); ios::sync_with_stdio(false);

	int inputNum, repeatNum;
	cin >> inputNum >> repeatNum;

	int startIdx = 0, endIdx = 0;
	fill_n(numCount, MAX_NUM, 0);

	for (int i = 0; i < inputNum; i++) {
		cin >> numArr[i];
	}

	int res = 0;

	while ((startIdx <= endIdx) && (endIdx < inputNum)) {
		while (endIdx < inputNum && numCount[numArr[endIdx]] <= repeatNum) {
			if (numCount[numArr[endIdx]] == repeatNum) {
				break;
			}

			numCount[numArr[endIdx]]++;
			res = max(res, endIdx - startIdx + 1);
			endIdx++;
		}

		while (startIdx < endIdx) {
			if (numCount[numArr[startIdx]] == repeatNum) {
				numCount[numArr[startIdx++]]--;

				break;
			}

			numCount[numArr[startIdx++]]--;
		}
	}

	cout << res;

	return 0;
}