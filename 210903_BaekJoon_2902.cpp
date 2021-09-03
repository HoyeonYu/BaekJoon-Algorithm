#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	string res = "";
	res += str[0];

	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] == '-') {
			res += str[i];
		}
	}

	cout << res;

	return 0;
}