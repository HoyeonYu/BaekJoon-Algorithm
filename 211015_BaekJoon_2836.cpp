#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define p pair<int, int>
#define MAX_LINE 300000 + 1
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int lineNum, maxPoint;
	cin >> lineNum >> maxPoint;

	vector<p> lineVec;

	for (int i = 0; i < lineNum; i++) {
		int point1, point2;
		cin >> point1 >> point2;

		if (point1 > point2) {
			lineVec.push_back({ point2, point1 });
		}
	}

	sort(lineVec.begin(), lineVec.end());
	long long lineSum = 0;
	int startPoint = lineVec[0].first;
	int endPoint = lineVec[0].second;

	for (int i = 1; i < lineVec.size(); i++) {
		if (lineVec[i].first < endPoint) {
			endPoint = max(endPoint, lineVec[i].second);
		}

		else {
			lineSum += (endPoint - startPoint);
			startPoint = lineVec[i].first;
			endPoint = lineVec[i].second;
		}
	}

	lineSum += (endPoint - startPoint);
	lineSum *= 2;
	lineSum += maxPoint;

	cout << lineSum;

	return 0;
}