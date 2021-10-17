#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define p pair<int, int>
#define pp pair<p, int>
#define MAX_LINE 100000 + 1
using namespace std;

int getParent(int x);
void makeUnion(int x, int y);
bool isUnion(int x, int y);
void lineSet();

int lineNum, questNum;
vector<pp> lineVec;
int parent[MAX_LINE];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> lineNum >> questNum;

	for (int i = 0; i < lineNum; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		lineVec.push_back({ {x1, x2}, i + 1 });
		parent[i + 1] = i + 1;
	}

	sort(lineVec.begin(), lineVec.end());
	lineSet();

	for (int i = 0; i < questNum; i++) {
		int idx1, idx2;
		cin >> idx1 >> idx2;
		cout << isUnion(idx1, idx2) << "\n";
	}

	return 0;
}

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = getParent(parent[x]);
}

void makeUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		parent[y] = x;
	}
}

bool isUnion(int x, int y) {
	return getParent(x) == getParent(y);
}

void lineSet() {
	int startPoint = lineVec[0].first.first;
	int endPoint = lineVec[0].first.second;

	for (int i = 1; i < lineNum; i++) {
		if (lineVec[i].first.first <= endPoint) {
			endPoint = max(endPoint, lineVec[i].first.second);
			makeUnion(lineVec[i - 1].second, lineVec[i].second);
		}

		else {
			startPoint = lineVec[i].first.first;
			endPoint = lineVec[i].first.second;
		}
	}
}
