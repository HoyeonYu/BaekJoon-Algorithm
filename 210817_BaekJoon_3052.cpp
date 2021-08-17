#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> modMap;

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		modMap.insert({ num % 42, 0 });
	}

	cout << modMap.size();

	return 0;
}