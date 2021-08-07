#include <iostream>
#define MAX_SIZE 100000 + 1
using namespace std;

int binarySearch(int left, int right, int val);
int lisArr[MAX_SIZE];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int num;
	cin >> num;

	int lisIdx = 0;

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;

		if (i == 0) {
			lisArr[0] = input;
		}

		else {
			if (lisArr[lisIdx] < input) {
				lisArr[++lisIdx] = input;
			}

			else {
				int idx = binarySearch(0, lisIdx + 1, input);
				lisArr[idx] = input;
			}
		}
	}

	cout << num - (lisIdx + 1);

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