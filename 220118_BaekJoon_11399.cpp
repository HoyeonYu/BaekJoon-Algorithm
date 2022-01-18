#include <iostream>
#include <queue>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < inputNum; i++) {
		int time;
		cin >> time;
		pq.push(time);
	}

	int partSum = 0, totalSum = 0;

	for (int i = 0; i < inputNum; i++) {
		partSum += pq.top();
		totalSum += partSum;
		pq.pop();
	}

	cout << totalSum;

	return 0;
}