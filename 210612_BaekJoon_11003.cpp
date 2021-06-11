#include <iostream>
#include <deque>
#define p pair<int, int>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	deque<p> deq;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (!deq.empty() && deq.front().second <= i - L) {
			deq.pop_front();
		}

		while (!deq.empty() && deq.back().first > input) {
			deq.pop_back();
		}

		deq.push_back({ input, i });

		cout << deq.front().first << " ";
	}

	return 0;
}