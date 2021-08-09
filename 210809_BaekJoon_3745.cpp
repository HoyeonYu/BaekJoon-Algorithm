#include <iostream>
#define MAX_SIZE 100000 + 1
using namespace std;

int binarySearch(int left, int right, int val);

int lisArr[MAX_SIZE];

int main() {
	int inputNum;

	while (cin >> inputNum) {
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

		cout << lisIdx + 1 << "\n";
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