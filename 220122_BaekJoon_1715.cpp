#include <iostream>
#include <queue>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < inputNum; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int resSum = 0;

	while (pq.size() > 1) {
		int tempSum = pq.top();
		pq.pop();

		tempSum += pq.top();
		pq.pop();

		resSum += tempSum;
		pq.push(tempSum);
	}

	cout << resSum;

	return 0;
}