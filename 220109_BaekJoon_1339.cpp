#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int caseNum;
	cin >> caseNum;

	vector<string> str;
	vector<int> alphaVal;
	char charArray[10][8];

	for (int i = 0; i < 26; i++) {
		alphaVal.push_back(0);
	}

	for (int i = 0; i < caseNum; i++) {
		string inputStr;
		cin >> inputStr;

		str.push_back(inputStr);

		for (int j = 0; j < str.size(); j++) {
			int strLength = inputStr.length();

			if (str[j].length() < strLength) {
				string temp = str[j];
				str[j] = inputStr;
				str[str.size() - 1] = temp;

				break;
			}
		}
	}

	int maxLength = str[0].size();

	for (int i = 0; i < str.size(); i++) {
		int diff = maxLength - str[i].size();

		for (int j = 0; j < diff; j++) {
			charArray[i][j] = ' ';
		}

		for (int j = diff; j < maxLength; j++) {
			charArray[i][j] = str[i][j - diff];
		}
	}

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < maxLength; j++) {
			if (charArray[i][j] != ' ') {
				alphaVal[charArray[i][j] - 'A'] += pow(10, maxLength - 1 - j);
			}
		}
	}

	sort(alphaVal.begin(), alphaVal.end(), greater<int>());

	int count = 0;
	int sum = 0;
	int num = 9;

	while (alphaVal[count] != 0) {
		sum += alphaVal[count] * num;
		num--, count++;
	}

	cout << sum;

	return 0;
}