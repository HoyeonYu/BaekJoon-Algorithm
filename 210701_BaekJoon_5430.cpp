#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tcNum;
	cin >> tcNum;

	for (int i = 0; i < tcNum; i++) {
		string cmd;
		cin >> cmd;

		int inputNum;
		cin >> inputNum;

		string inputStr;
		cin >> inputStr;

		int deqInput = 0;
		deque<int> deq;

		for (int j = 0; j < inputStr.length(); j++) {
			if (isalnum(inputStr[j])) {
				deqInput = deqInput * 10 + (inputStr[j] - '0');
			}

			else if (deqInput != 0) {
				deq.push_back(deqInput);
				deqInput = 0;
			}
		}

		bool isReverse = false;
		bool isError = false;

		for (int j = 0; j < cmd.length(); j++) {
			if (cmd[j] == 'R') {
				isReverse = !isReverse;
			}

			else {
				if (deq.empty()) {
					isError = true;
					break;
				}

				if (isReverse) {
					deq.pop_back();
				}

				else {
					deq.pop_front();
				}
			}
		}

		string output = "[";

		while (!deq.empty()) {
			if (isReverse) {
				output += to_string(deq.back()) + ",";
				deq.pop_back();
			}

			else {
				output += to_string(deq.front()) + ",";
				deq.pop_front();
			}
		}

		if (output.length() > 1) {
			output = output.substr(0, output.length() - 1);
		}

		output += "]";

		if (isError) {
			cout << "error\n";
		}

		else {
			cout << output << "\n";
		}
	}

	return 0;
}