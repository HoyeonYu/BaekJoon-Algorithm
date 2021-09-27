#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}

		return a > b;
	}
};

int main() {
	int totNum;
	cin >> totNum;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < totNum; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}

			else {
				cout << 0 << "\n";
			}
		}

		else {
			pq.push(num);
		}
	}

	return 0;
}