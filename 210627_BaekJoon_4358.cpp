#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string treeName;
	map<string, int> treeMap;
	int totalCount = 0;

	while (getline(cin, treeName)) {
		if (treeMap.find(treeName) == treeMap.end()) {
			treeMap.insert({ treeName, 1 });
		}

		else {
			treeMap[treeName]++;
		}

		totalCount++;
	}

	for (auto it : treeMap) {
		float rate = (int)((it.second * 100 / (float)totalCount) * 10000 + 0.5) / 10000.0;
		cout << it.first;
		printf(" %.4f\n", rate);
	}

	return 0;
}