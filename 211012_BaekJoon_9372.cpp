#include <iostream>
using namespace std;

int main() {
	int caseNum;
	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		int nodeNum, edgeNum;
		cin >> nodeNum >> edgeNum;

		for (int j = 0; j < edgeNum; j++) {
			int node1, node2;
			cin >> node1 >> node2;
		}

		cout << nodeNum - 1 << "\n";
	}

	return 0;
}