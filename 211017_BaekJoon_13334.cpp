#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define p pair<int, int>
using namespace std;

struct cmpRight {
	bool operator() (p child, p parent) {
		return child.second > parent.second;
	}
};

struct cmpLeft {
	bool operator() (p child, p parent) {
		return child.first > parent.first;
	}
};

int main() {
	int lineNum;
	cin >> lineNum;

	priority_queue<p, vector<p>, cmpRight> pqRight;

	for (int i = 0; i < lineNum; i++) {
		int point1, point2;
		cin >> point1 >> point2;
		pqRight.push({ min(point1, point2), max(point1, point2) });
	}

	int mainLineLength;
	cin >> mainLineLength;

	int result = 0;
	priority_queue<p, vector<p>, cmpLeft> pqLeft;

	while (!pqRight.empty()) {
		p line = pqRight.top();
		pqRight.pop();
		int lineLength = line.second - line.first;

		if (lineLength <= mainLineLength) {
			pqLeft.push(line);
		}
		
		int curLeft = line.second - mainLineLength;

		while (!pqLeft.empty()) {
			if (pqLeft.top().first < curLeft) {
				pqLeft.pop();
			}

			else {
				break;
			}
		}

		result = max(result, (int)pqLeft.size());
	}

	cout << result;

	return 0;
}