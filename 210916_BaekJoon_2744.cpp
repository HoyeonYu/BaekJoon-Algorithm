#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (isupper(str[i])) {
			cout << char(str[i] - 'A' + 'a');
		}

		else {
			cout << char(str[i] - 'a' + 'A');
		}
	}
}