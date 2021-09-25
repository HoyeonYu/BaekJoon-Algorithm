#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;

	queue<int> que;

	for (int i = 1; i <= num; i++) {
		que.push(i);
	}

	while (!que.empty()) {
		if (que.size() == 1) {
			cout << que.front();
			break;
		}

		que.pop();
		que.push(que.front());
		que.pop();
	}
	
	return 0;
}