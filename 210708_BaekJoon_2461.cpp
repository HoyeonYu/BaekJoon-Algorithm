#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define p pair<int, int>
#define MAX_STUD 1000 + 1
#define MAX_DIFF 2 * 1e9 + 1
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int classNum, studNum;
	cin >> classNum >> studNum;

	vector<int> vec[MAX_STUD];
	priority_queue<p, vector<p>, greater<p>> pq;
	int maxVal = 0;

	for (int i = 0; i < classNum; i++) {
		for (int j = 0; j < studNum; j++) {
			int val;
			cin >> val;
			vec[i].push_back(val);
		}

		sort(vec[i].begin(), vec[i].end());
		pq.push({ vec[i][0], i });
		maxVal = max(maxVal, vec[i][0]);
	} 

	int pointer[MAX_STUD] = { 0 };
	int minDiff = MAX_DIFF;

	while (!pq.empty()) {
		int idx = pq.top().second;
		int diff = maxVal - pq.top().first;
		minDiff = min(minDiff, diff);
		pq.pop();

		if (pointer[idx] == studNum - 1) {
			break;
		}

		else {
			pointer[idx]++;
			pq.push({ vec[idx][pointer[idx]], idx });
			maxVal = max(maxVal, vec[idx][pointer[idx]]);
		}
	}

	cout << minDiff;

	return 0;
}