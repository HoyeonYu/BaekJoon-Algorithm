#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define p pair<int, int>
using namespace std;

vector<p> vec;
priority_queue<int> pq;

int main() {
	int oilNum;
	cin >> oilNum;

	for (int i = 0; i < oilNum; i++) {
		int oilDist, oilAmount;
		cin >> oilDist >> oilAmount;

		vec.push_back({ oilDist, oilAmount });
	}

	sort(vec.begin(), vec.end());

	int totalDist, curAmount;
	cin >> totalDist >> curAmount;

	int idx = 0, count = 0;

	while (curAmount < totalDist) {
		while (vec[idx].first <= curAmount) {
			if (idx >= oilNum) {
				break;
			}

			pq.push(vec[idx++].second);
		}

		if (pq.empty()) {
			break;
		}

		count++;
		curAmount += pq.top();
		pq.pop();
	}

	if (curAmount < totalDist) {
		count = -1;
	}

	cout << count;

	return 0;
}