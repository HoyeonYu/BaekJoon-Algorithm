#include <iostream>
#define MAX_SIZE 40000 + 1
using namespace std;

int input[MAX_SIZE];
int lisArray[MAX_SIZE];

int binarySearch(int left, int right, int val);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> input[i];
	}

	lisArray[0] = input[0];
	int lisIdx = 0;

	for (int i = 1; i < num; i++) {
		if (lisArray[lisIdx] < input[i]) {
			lisArray[lisIdx + 1] = input[i];
			lisIdx++;
		}

		else {
			int idx = binarySearch(0, lisIdx, input[i]);
			lisArray[idx] = input[i];
		}
	}

	cout << lisIdx + 1;

	return 0;
}

int binarySearch(int left, int right, int val) {
	while (left < right) {
		int mid = (left + right) / 2;

		if (lisArray[mid] < val) {
			left = mid + 1;
		}

		else {
			right = mid;
		}
	}

	return right;
}