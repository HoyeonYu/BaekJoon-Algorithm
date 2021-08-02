#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VTX 100000 + 1
using namespace std;

int parentArr[MAX_VTX];
int totalArr[MAX_VTX];
int vtxNum, edgeNum;

int getParent(int x);
void setUnion(int info, int x, int y);

int main() {
	cin >> vtxNum >> edgeNum;

	for (int i = 1; i <= vtxNum; i++) {
		parentArr[i] = i;
		cin >> totalArr[i];
	}

	for (int i = 0; i < edgeNum; i++) {
		int info, vtx1, vtx2;
		cin >> info >> vtx1 >> vtx2;

		setUnion(info, vtx1, vtx2);
	}

	int count = 0;
	vector<int> resVec;

	for (int i = 1; i <= vtxNum; i++) {
		if (parentArr[i] == i && totalArr[i] > 0) {
			count++;
			resVec.push_back(totalArr[i]);
		}
	}

	sort(resVec.begin(), resVec.end());
	cout << count << "\n";

	for (int i = 0; i < count; i++) {
		cout << resVec[i] << " ";
	}

	return 0;
}

int getParent(int x) {
	if (x == parentArr[x]) {
		return x;
	}

	return parentArr[x] = getParent(parentArr[x]);
}

void setUnion(int info, int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		if (info == 1) {
			parentArr[y] = x;
			totalArr[x] += totalArr[y];
		}

		else {
			if (totalArr[x] < totalArr[y]) {
				parentArr[x] = y;
				totalArr[y] -= totalArr[x];
			}

			else {
				parentArr[y] = x;
				totalArr[x] -= totalArr[y];
			}
		}
	}
}