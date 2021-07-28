#include <iostream>
#include <vector>
#define MAX_VTX 10000 + 1
using namespace std;

int costArr[MAX_VTX];
int parentArr[MAX_VTX];

int getParent(int x);
void setUnion(int x, int y);

int main() {
	int vtxNum, edgeNum, totalCost;
	cin >> vtxNum >> edgeNum >> totalCost;

	for (int i = 1; i <= vtxNum; i++) {
		parentArr[i] = i;
		cin >> costArr[i];
	}

	for (int i = 1; i <= edgeNum; i++) {
		int vtx1, vtx2;
		cin >> vtx1 >> vtx2;
		setUnion(vtx1, vtx2);
	}

	int needCost = 0;

	for (int i = 1; i <= vtxNum; i++) {
		if (parentArr[i] == i) {
			needCost += costArr[i];
		}
	}

	if (totalCost < needCost) {
		cout << "Oh no";
	}

	else {
		cout << needCost;
	}

	return 0;
}

int getParent(int x) {
	if (parentArr[x] == x) {
		return x;
	}

	return parentArr[x] = getParent(parentArr[x]);
}

void setUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		if (costArr[x] < costArr[y]) {
			parentArr[y] = x;
		}

		else {
			parentArr[x] = y;
		}
	}
}