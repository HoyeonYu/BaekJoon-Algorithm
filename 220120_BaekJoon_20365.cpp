#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int inputLen;
	cin >> inputLen;

	string inputStr;
	cin >> inputStr;

	inputStr = '0' + inputStr;

	map<char, int> continueMap;
	continueMap['B'] = continueMap['R'] = 0;

	for (int i = 1; i <= inputLen; i++) {
		if (inputStr[i] != inputStr[i - 1]) {
			continueMap[inputStr[i]]++;
		}
	}

	int minLen = min(continueMap['B'], continueMap['R']);

	cout << minLen + 1;

	return 0;
}