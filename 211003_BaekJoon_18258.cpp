#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int totNum;
	cin >> totNum;

	deque<int> deq;

	for (int i = 0; i < totNum; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			deq.push_back(num);
		}

		else if (str == "pop") {
			if (deq.empty()) {
				cout << "-1\n";
			}

			else {
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}

		else if (str == "size") {
			cout << deq.size() << "\n";
		}

		else if (str == "empty") {
			cout << deq.empty() << "\n";
		}

		else if (str == "front") {
			if (deq.empty()) {
				cout << "-1\n";
			}

			else {
				cout << deq.front() << "\n";
			}
		}

		else if (str == "back") {
			if (deq.empty()) {
				cout << "-1\n";
			}

			else {
				cout << deq.back() << "\n";
			}
		}
	}

	return 0;
}