#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int num;
	cin >> num;

	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;

		if (input == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}

			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}

		else {
			pq.push(input);
		}
	}

	return 0;
}