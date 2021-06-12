#include <iostream>
#include <queue>
#define p pair<int, int>
#define MAX_LEN 1000 + 1
using namespace std;

int main() {
	bool isFilled[MAX_LEN] = { false };
	int num;
	cin >> num;

	priority_queue<p, vector<p>, less<p>> pq;

	for (int i = 0; i < num; i++) {
		int dead, score;
		cin >> dead >> score;
		pq.push({ score, dead });
	}

	int sum = 0;

	while (!pq.empty()) {
		p res = pq.top();
		pq.pop();

		for (int i = res.second; i > 0; i--) {
			if (!isFilled[i]) {
				isFilled[i] = true;
				sum += res.first;
				break;
			}
		}
	}

	cout << sum;

	return 0;
}