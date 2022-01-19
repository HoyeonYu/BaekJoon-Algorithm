#include <iostream>
#include <queue>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < inputNum; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	double sum = pq.top();
	pq.pop();

	for (int i = 1; i < inputNum; i++) {
		sum += pq.top() / 2.0;
		pq.pop();
	}

	cout << sum;

	return 0;
}