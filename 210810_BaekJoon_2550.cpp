#include <iostream>
#include <algorithm>
#include <map>
#define MAX_SIZE 10000 + 1
using namespace std;

int lisArr[MAX_SIZE];
int binarySearch(int left, int right, int val);

int main() {
	int inputNum;
	cin >> inputNum;

	int idxArr[MAX_SIZE];
	int inputArr[MAX_SIZE];
	int changeArr[MAX_SIZE];
	int lisIdx = 0;
	int resArr[MAX_SIZE];
	map<int, int> idxMap;
	map<int, int> resMap;

	for (int i = 0; i < inputNum; i++) {
		cin >> idxArr[i];
		idxMap.insert({ idxArr[i], i + 1 });
	}

	for (int i = 0; i < inputNum; i++) {
		cin >> inputArr[i];
		changeArr[i] = idxMap[inputArr[i]];
		resMap.insert({ changeArr[i], inputArr[i] });
	}

	lisArr[lisIdx] = changeArr[lisIdx];
	resArr[lisIdx] = lisIdx;

	for (int i = 1; i < inputNum; i++) {
		if (lisArr[lisIdx] < changeArr[i]) {
			lisArr[++lisIdx] = changeArr[i];
			resArr[i] = lisIdx;
		}

		else {
			int searchIdx = binarySearch(0, lisIdx, changeArr[i]);
			lisArr[searchIdx] = changeArr[i];
			resArr[i] = searchIdx;
		}
	}

	cout << lisIdx + 1 << "\n";

	int resIdx = lisIdx;
	int resIdxArr[MAX_SIZE];

	for (int i = inputNum - 1; i >= 0; i--) {
		if (resArr[i] == resIdx) {
			resIdxArr[lisIdx - resIdx] = resMap[changeArr[i]];
			resIdx--;
		}
	}

	sort(resIdxArr, resIdxArr + lisIdx + 1);

	for (int i = 0; i < lisIdx + 1; i++) {
		cout << resIdxArr[i] << " ";
	}

	return 0;
}

int binarySearch(int left, int right, int val) {
	while (left < right) {
		int mid = (left + right) / 2;

		if (lisArr[mid] < val) {
			left = mid + 1;
		}

		else {
			right = mid;
		}
	}

	return right;
}