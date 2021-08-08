#include <iostream>
#include <algorithm>
#include <vector>
#define p pair<int, int>
#define MAX_SIZE 100000 + 1
using namespace std;

int lisArr[MAX_SIZE];
int lisIdxArr[MAX_SIZE];
p inputIdx[MAX_SIZE];
vector<int> resVec;
int binarySearch(int left, int right, int val);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int inputNum;
	cin >> inputNum;

	bool visited[MAX_SIZE];

	for (int i = 0; i < inputNum; i++) {
		cin >> inputIdx[i].first >> inputIdx[i].second;
		visited[inputIdx[i].first] = true;
	}

	sort(inputIdx, inputIdx + inputNum);

	lisArr[0] = inputIdx[0].second;
	lisIdxArr[0] = inputIdx[0].first;
	int lisIdx = 0;

	for (int i = 1; i < inputNum; i++) {
		int nextVal = inputIdx[i].second;
		int nextIdx = inputIdx[i].first;

		if (lisArr[lisIdx] < nextVal) {
			lisArr[++lisIdx] = nextVal;
			lisIdxArr[lisIdx] = nextIdx;
		}

		else {
			int idx = binarySearch(0, lisIdx, nextVal);
			resVec.push_back(lisIdxArr[idx]);
			lisArr[idx] = nextVal;
			lisIdxArr[idx] = nextIdx;
		}
	}

	int resNum = inputNum - (lisIdx + 1);
	cout << resNum << "\n";

	for (int i = 0; i < resVec.size(); i++) {
		cout << resVec[i] << "\n";
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