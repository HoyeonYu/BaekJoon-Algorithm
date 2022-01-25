#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cmdNum;
	cin >> cmdNum;

	long long res = 0;

	for (int i = 0; i < cmdNum; i++) {
		string cmd;
		int val;
		cin >> cmd;

		if (cmd != "all" && cmd != "empty") {			
			cin >> val;
			val--;
		}

		if (cmd == "add") {
			res |= (1 << val);
		}

		else if (cmd == "remove") {
			res &= ~(1 << val);
		}

		else if (cmd == "check") {
			cout << ((res & (1 << val)) ? 1 : 0) << "\n";
		}

		else if (cmd == "toggle") {
			res ^= (1 << val);
		}

		else if (cmd == "all") {
			res = (1 << 21) - 1;
		}

		else if (cmd == "empty") {
			res = 0;
		}
	}

	return 0;
}