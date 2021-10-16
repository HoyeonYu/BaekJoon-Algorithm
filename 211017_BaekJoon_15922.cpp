#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_LINE 100000 + 1
#define p pair<int, int>
using namespace std;

int main() {
	int lineNum;
	cin >> lineNum;

	vector<p> lineVec;

	for (int i = 0; i < lineNum; i++) {
		int x, y;
		cin >> x >> y;

		lineVec.push_back({ x, y });
	}

	int startPoint = lineVec[0].first;
	int endPoint = lineVec[0].second;
	int lineLength = 0;

	for (int i = 1; i < lineNum; i++) {
		if (endPoint > lineVec[i].first) {
			endPoint = max(endPoint, lineVec[i].second);
		}

		else {
			lineLength += (endPoint - startPoint);

			startPoint = lineVec[i].first;
			endPoint = lineVec[i].second;
		}
	}

	lineLength += (endPoint - startPoint);
	
	cout << lineLength;

	return 0;
}
