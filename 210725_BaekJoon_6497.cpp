#include <iostream>
#include <vector>
#include <algorithm>
#define pp pair<int, pair<int, int>>
#define MAX_VTX 200000 + 1
using namespace std;

vector<pp> vec;
int parentArr[MAX_VTX];

int findParent(int x);
void makeUnion(int x, int y);
bool isUnion(int x, int y);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (true) {
		vec.clear();

		int vtxNum, edgeNum;
		cin >> vtxNum >> edgeNum;

		if (vtxNum == 0 && edgeNum == 0) {
			break;
		}

		for (int i = 0; i < vtxNum; i++) {
			parentArr[i] = i;
		}

		for (int i = 0; i < edgeNum; i++) {
			int vtx1, vtx2, weight;
			cin >> vtx1 >> vtx2 >> weight;
			vec.push_back({ weight, {vtx1, vtx2} });
		}

		sort(vec.begin(), vec.end());
		long long totalWeightSum = 0;
		long long minWeightSum = 0;

		for (int i = 0; i < edgeNum; i++) {
			totalWeightSum += vec[i].first;

			if (!isUnion(vec[i].second.first, vec[i].second.second)) {
				makeUnion(vec[i].second.first, vec[i].second.second);
				minWeightSum += vec[i].first;
			}
		}

		cout << totalWeightSum - minWeightSum << "\n";
	}

	return 0;
}

int findParent(int x) {
	if (parentArr[x] == x) {
		return x;
	}

	return parentArr[x] = findParent(parentArr[x]);
}

void makeUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		parentArr[y] = x;
	}
}

bool isUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	return x == y;
}