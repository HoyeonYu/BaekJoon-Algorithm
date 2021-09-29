#include <iostream>
using namespace std;

int main() {
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++) {
			if ((((i + j) % 2) == 0) && (str[j] != '.')) {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}