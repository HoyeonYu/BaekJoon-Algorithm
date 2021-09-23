#include <iostream>
#include <stack>
using namespace std;

int main() {
	int totNum;
	cin >> totNum;

	stack<int> stk;

	for (int i = 0; i < totNum; i++) {
		int num;
		cin >> num;

		if (num != 0) {
			stk.push(num);
		}

		else {
			stk.pop();
		}
	}

	int stkSum = 0;

	while (!stk.empty()) {
		stkSum += stk.top();
		stk.pop();
	}

	cout << stkSum;

	return 0;
}