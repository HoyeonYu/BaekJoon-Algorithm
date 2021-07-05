#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> stk;

	for (int i = 0; i < str.length(); i++) {
		stk.push(str[i]);

		if (!stk.empty() && stk.size() >= 4) {
			string cmp = "";

			for (int j = 0; j < 4; j++) {
				cmp = stk.top() + cmp;
				stk.pop();
			}

			if (cmp == "PPAP") {
				stk.push('P');
			}

			else {
				for (int j = 0; j < 4; j++) {
					stk.push(cmp[j]);
				}
			}
		}
	}

	bool isPPAP = false;

	if (stk.size() == 1 && stk.top() == 'P') {
		isPPAP = true;
	}

	cout << (isPPAP ? "PPAP" : "NP");

	return 0;
}