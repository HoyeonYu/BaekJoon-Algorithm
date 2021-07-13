#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tcNum;
	cin >> tcNum;

	for (int i = 0; i < tcNum; i++) {
		int fileNum;
		cin >> fileNum;

		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (int j = 0; j < fileNum; j++) {
			int size;
			cin >> size;

			pq.push(size);
		}

		long long sum = 0;

		while (pq.size() > 1) {
			long long first = pq.top(); pq.pop();
			long long second = pq.top(); pq.pop();
			pq.push(first + second);
			sum += first + second;
		}

		cout << sum << "\n";
	}

	return 0;
}