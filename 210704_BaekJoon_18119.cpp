#include <iostream>
#include <vector>
using namespace std;

int main() {
	int strNum, cmdNum;
	cin >> strNum >> cmdNum;

	long long bitSet = ((1 << 27) - 1);
	vector<long long> vec;

	for (int i = 0; i < strNum; i++) {
		string str;
		cin >> str;

		long long strBit = 0;

		for (int j = 0; j < str.length(); j++) {
			strBit |= (1 << (str[j] - 'a'));
		}

		vec.push_back(strBit);
	}

	for (int i = 0; i < cmdNum; i++) {
		int cmdType;
		char cmdChar;
		cin >> cmdType >> cmdChar;

		if (cmdType == 1) {
			bitSet &= ~(1 << (cmdChar - 'a'));
		}

		else {
			bitSet |= (1 << (cmdChar - 'a'));
		}

		int isSetNum = 0;

		for (int j = 0; j < strNum; j++) {
			if ((vec[j] & bitSet) == vec[j]) {
				isSetNum++;
			}
		}

		cout << isSetNum << "\n";
	}

	return 0;
}