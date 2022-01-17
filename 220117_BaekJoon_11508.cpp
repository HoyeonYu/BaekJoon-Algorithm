#include <iostream>
#include <queue>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	priority_queue<int> pricePq;

	for (int i = 0; i < inputNum; i++) {
		int inputPrice;
		cin >> inputPrice;
		pricePq.push(inputPrice);
	}

	int priceSum = 0;

	for (int i = 0; i < inputNum; i++) {
		if (i % 3 == 2) {
			pricePq.pop();
			continue;
		}

		priceSum += pricePq.top();
		pricePq.pop();
	}

	cout << priceSum;

	return 0;
}