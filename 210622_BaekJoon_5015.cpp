#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	string pattern;
	cin >> pattern;

	queue<string> strQue;
	bool isFrontAster = true;
	bool isBackAster = true;

	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '*') {
			continue;
		}

		else {
			if (i == 0) {
				isFrontAster = false;
			}

			if (i == pattern.length() - 1) {
				isBackAster = false;
			}
		}

		string input = "";

		while (i < pattern.length() && pattern[i] != '*') {
			input += pattern[i++];
		}

		strQue.push(input);
	}

	int checkNum;
	cin >> checkNum;

	for (int i = 0; i < checkNum; i++) {
		string checkStr, checkStrCopy;
		cin >> checkStr;
		checkStrCopy = checkStr;

		queue<string> strQueCopy = strQue;

		for (int j = 0; j < checkStr.length(); j++) {
			if (strQueCopy.empty()) {
				break;
			}

			if (strQueCopy.size() == strQue.size() && !isFrontAster) {
				if (checkStr.substr(0, strQueCopy.front().length()) != strQueCopy.front()) {
					break;
				}
			}

			else if (strQueCopy.size() == 1 && !isBackAster) {
				if (checkStr.substr(checkStr.length() - strQueCopy.front().length()) 
					!= strQueCopy.front()) {
					break;
				}
			}

			if (checkStr.substr(j, strQueCopy.front().length()) == strQueCopy.front()) {
				checkStrCopy = checkStrCopy.substr(strQueCopy.front().length());
				j += strQueCopy.front().length() - 1;
				strQueCopy.pop();
			}
		}

		if (strQueCopy.empty()) {
			cout << checkStr << "\n";
		}
	}

	return 0;
}