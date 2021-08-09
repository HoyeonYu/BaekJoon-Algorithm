#include <iostream>
#define MAX_SIZE 200000 + 1
using namespace std;

int binarySearch(int left, int right, int val);

int lisArr[MAX_SIZE];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int inputNum;
	cin >> inputNum;

	int inputArr[MAX_SIZE];
	int lisIdx = 0;
	cin >> lisArr[lisIdx];

	for (int i = 1; i < inputNum; i++) {
		cin >> inputArr[i];

		if (lisArr[lisIdx] < inputArr[i]) {
			lisArr[++lisIdx] = inputArr[i];
		}

		else {
			int searchIdx = binarySearch(0, lisIdx, inputArr[i]);
			lisArr[searchIdx] = inputArr[i];
		}
	}

	cout << inputNum - (lisIdx + 1);

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