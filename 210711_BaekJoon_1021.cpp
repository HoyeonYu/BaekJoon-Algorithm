#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
	int queSize, outSize;
	cin >> queSize >> outSize;

	deque<int> deq;

	for (int i = 0; i < queSize; i++) {
		deq.push_back(i + 1);
	}

	vector<int> outVec;

	for (int i = 0; i < outSize; i++) {
		int out;
		cin >> out;
		outVec.push_back(out);
	}

	int sum = 0;

	for (int i = 0; i < outSize; i++) {
		int toRightCount = 0, toLeftCount = 0;
		deque<int> toRightDeq = deq, toLeftDeq = deq;

		while (toRightDeq.front() != outVec[i]) {
			toRightCount++;
			toRightDeq.push_back(toRightDeq.front());
			toRightDeq.pop_front();
		}

		toRightDeq.pop_front();

		while (toLeftDeq.front() != outVec[i]) {
			toLeftCount++;
			toLeftDeq.push_front(toLeftDeq.back());
			toLeftDeq.pop_back();

			if (toLeftCount > toRightCount) {
				break;
			}
		}

		toLeftDeq.pop_front();

		if (toRightCount < toLeftCount) {
			deq = toRightDeq;
			sum += toRightCount;
		}

		else {
			deq = toLeftDeq;
			sum += toLeftCount;
		}
	}

	cout << sum;

	return 0;
}