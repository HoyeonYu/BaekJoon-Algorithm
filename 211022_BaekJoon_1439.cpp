#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;

	int type1 = 0, type2 = 0;

	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1]) {
			if (str[i] == '0') {
				type1++;
			}

			else {
				type2++;
			}
		}
	}

	if (str[str.length() - 1] == '0') {
		type2++;
	}

	else {
		type1++;
	}

	cout << min(type1, type2);

	return 0;
}