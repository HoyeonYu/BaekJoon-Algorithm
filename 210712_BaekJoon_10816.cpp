#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	map<int, int> cardMap;
	int cardNum;
	cin >> cardNum;
	
	for (int i = 0; i < cardNum; i++) {
		int input;
		cin >> input;

		if (cardMap.find(input) == cardMap.end()) {
			cardMap.insert({ input, 1 });
		}

		else {
			cardMap.find(input)->second++;
		}
	}

	int findNum;
	cin >> findNum;

	for (int i = 0; i < findNum; i++) {
		int input;
		cin >> input;

		if (cardMap.find(input) == cardMap.end()) {
			cout << 0 << " ";
		}

		else {
			cout << cardMap.find(input)->second << " ";
		}
	}

	return 0;
}