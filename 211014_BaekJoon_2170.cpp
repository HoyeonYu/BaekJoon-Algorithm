#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define p pair<int, int>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int totLine;
	cin >> totLine;

	vector<p> lineVec;

	for (int i = 0; i < totLine; i++) {
		int x, y;
		cin >> x >> y;
		lineVec.push_back({ x, y });
	}

	sort(lineVec.begin(), lineVec.end());

	int startLine = lineVec[0].first;
	int endLine = lineVec[0].second;
	int lenSum = 0;

	for (int i = 1; i < totLine; i++) {
		if (lineVec[i].first <= endLine) {
			endLine = max(endLine, lineVec[i].second);
		}

		else {
			lenSum += (endLine - startLine);
			startLine = lineVec[i].first;
			endLine = lineVec[i].second;
		}
	}

	lenSum += (endLine - startLine);

	cout << lenSum;

	return 0;
}