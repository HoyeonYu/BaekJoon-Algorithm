#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_VTX 100 + 1
#define p pair<int, int>
#define pp pair<float, p>
using namespace std;

float getDist(p p1, p p2);
int findParent(int x);
void setUnion(int x, int y);
bool isUnion(int x, int y);

int parentArr[MAX_VTX];

int main() {
	int pointNum;
	cin >> pointNum;

	vector<p> pointVec;
	vector<pp> edgeVec;

	for (int i = 0; i < pointNum; i++) {
		float pointX, pointY;
		cin >> pointX >> pointY;
		pointVec.push_back({ pointX, pointY });
	}

	for (int i = 0; i < pointNum; i++) {
		parentArr[i] = i;

		for (int j = i + 1; j < pointNum; j++) {
			edgeVec.push_back({ getDist(pointVec[i], pointVec[j]), {i, j} });
		}
	}

	sort(edgeVec.begin(), edgeVec.end());
	float minWeightSum = 0;

	for (int i = 0; i < edgeVec.size(); i++) {
		if (!isUnion(edgeVec[i].second.first, edgeVec[i].second.second)) {
			setUnion(edgeVec[i].second.first, edgeVec[i].second.second);
			minWeightSum += edgeVec[i].first;
		}
	}

	printf("%.3f", minWeightSum);

	return 0;
}

float getDist(p p1, p p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int findParent(int x) {
	if (parentArr[x] == x) {
		return x;
	}

	return parentArr[x] = findParent(parentArr[x]);
}

void setUnion(int x, int y) {
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

