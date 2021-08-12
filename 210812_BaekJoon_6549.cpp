#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
#define MAX_SIZE 1000000 + 1
using namespace std;

long long inputNum;
long long seg[MAX_SIZE];
long long res;
long long input[MAX_SIZE];

int initTree(int node, int start, int end);
int segmentTree(int node, int start, int end, int left, int right);
void getMin(long long left, long long right);

int main() {
	while (true) {
		cin >> inputNum;
		res = 0;

		if (inputNum == 0) {
			break;
		}

		for (int i = 0; i < inputNum; i++) {
			cin >> input[i];
		}

		initTree(1, 0, inputNum - 1);
		getMin(0, inputNum - 1);
		cout << res << "\n";
	}

	return 0;
}

int initTree(int node, int start, int end) {
	if (start == end) {
		return seg[node] = start;
	}

	int mid = (start + end) / 2;
	int leftIdx = initTree(2 * node, start, mid);
	int rightIdx = initTree(2 * node + 1, mid + 1, end);

	return seg[node] = (input[leftIdx] < input[rightIdx] ? leftIdx : rightIdx);
}

int segmentTree(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return INF;
	}

	if (left <= start && end <= right) {
		return seg[node];
	}

	int mid = (start + end) / 2;
	int leftIdx = segmentTree(2 * node, start, mid, left, right);
	int rightIdx = segmentTree(2 * node + 1, mid + 1, end, left, right);

	if (leftIdx == INF) {
		return rightIdx;
	}

	if (rightIdx == INF) {
		return leftIdx;
	}

	return (input[leftIdx] < input[rightIdx] ? leftIdx : rightIdx);
}

void getMin(long long left, long long right) {
	if (left > right) {
		return;
	}

	long long idx = segmentTree(1, 0, inputNum - 1, left, right);

	res = max(res, input[idx] * (right - left + 1));

	getMin(left, idx - 1);
	getMin(idx + 1, right);
}