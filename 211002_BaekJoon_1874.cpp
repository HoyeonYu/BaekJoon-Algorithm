#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int totNum;
	cin >> totNum;

	int curNum = 1;
	stack<int> stk;
	string res = "";

	for (int i = 0; i < totNum; i++) {
		int num;
		cin >> num;

		if (stk.empty() || stk.top() < num) {
			while (stk.empty() || stk.top() < num) {
				stk.push(curNum);
				curNum++;

				res += "+\n";
			}
		}

		else {
			while (stk.top() > num) {
				stk.pop();

				res += "-\n";
			}
		}

		if (stk.top() != num) {
			res = "NO";
			break;
		}

		stk.pop();
		res += "-\n";
	}

	cout << res;

	return 0;
}