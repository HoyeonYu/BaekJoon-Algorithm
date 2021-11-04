#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> que;

	for (int i = 1; i <= n; i++) {
		que.push(i);
	}

	cout << "<";

	while (!que.empty()) {
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}

		cout << que.front();

		if (que.size() > 1) {
			cout << ", ";
		}

		que.pop();
	}

	cout << ">";

	return 0;
}