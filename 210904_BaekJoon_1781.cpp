#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int totalNum;
	cin >> totalNum;

	vector<pair<int, int>> vec(totalNum + 1);

	for (int i = 1; i <= totalNum; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end());

	priority_queue<int, vector<int>> pq;
	int vecIdx = totalNum;
	long long sum = 0;

	for (int i = totalNum; i > 0; i--) {
		while (vec[vecIdx].first == i && vecIdx > 0) {
			pq.push(vec[vecIdx].second);
			vecIdx--;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}