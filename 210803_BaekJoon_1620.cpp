#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int input, find;
	cin >> input >> find;

	map<int, string> findByIdxMap;
	map<string, int> findByNameMap;

	for (int i = 1; i <= input; i++) {
		string str;
		cin >> str;
		findByIdxMap.insert({ i, str });
		findByNameMap.insert({ str, i });
	}

	for (int i = 1; i <= find; i++) {
		string str;
		cin >> str;

		if (isalpha(str[0])) {
			cout << findByNameMap[str] << "\n";
		}

		else {
			
			cout << findByIdxMap[stoi(str)] << "\n";
		}
	}
}