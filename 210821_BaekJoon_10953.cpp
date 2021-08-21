#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		
		cout << (str[0] - '0') + (str[2] - '0') << "\n";
	}

	return 0;
}