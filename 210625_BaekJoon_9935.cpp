#include <iostream>
#include <deque>
using namespace std;

int main() {
	string testStr, eraseStr;
	cin >> testStr >> eraseStr;

	deque<char> stk;
	int testStrLen = testStr.length();
	int eraseStrLen = eraseStr.length();

	for (int i = 0; i < testStrLen; i++) {
		stk.push_back(testStr[i]);

		if (stk.size() >= eraseStrLen) {
			string cmpStr = "";

			for (int j = 0; j < eraseStrLen; j++) {
				cmpStr = stk.back() + cmpStr;
				stk.pop_back();
			}

			if (cmpStr != eraseStr) {
				for (int j = 0; j < eraseStrLen; j++) {
					stk.push_back(cmpStr[j]);
				}
			}
		}
	}

	if (stk.empty()) {
		cout << "FRULA";
	}

	else {
		while (!stk.empty()) {
			cout << stk.front();
			stk.pop_front();
		}
	}

	return 0;
}