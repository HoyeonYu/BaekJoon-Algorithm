#include <iostream>
#include <vector>
#include <cmath>
#define MAX_WEIGHT 9999
#define MAX_VTX 50 + 1
using namespace std;

int main() {
	int vtxNum;
	cin >> vtxNum;

	int graph[MAX_VTX][MAX_VTX];

	for (int i = 1; i <= vtxNum; i++) {
		for (int j = 1; j <= vtxNum; j++) {
			graph[i][j] = MAX_WEIGHT;
		}
	}

	while (true) {
		int vtx1, vtx2;
		cin >> vtx1 >> vtx2;

		if (vtx1 == -1 && vtx2 == -1) {
			break;
		}

		graph[vtx1][vtx2] = graph[vtx2][vtx1] = 1;
	}

	int maxScore = MAX_WEIGHT;

	for (int k = 1; k <= vtxNum; k++) {
		for (int i = 1; i <= vtxNum; i++) {
			for (int j = 1; j <= vtxNum; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int minScore = MAX_WEIGHT;
	vector<int> candVec;

	for (int i = 1; i <= vtxNum; i++) {
		int maxWeight = 0;

		for (int j = 1; j <= vtxNum; j++) {
			if (i != j) {
				maxWeight = max(maxWeight, graph[i][j]);
			}
		}

		if (maxWeight == minScore) {
			candVec.push_back(i);
		}

		else if (maxWeight < minScore) {
			minScore = maxWeight;
			candVec.clear();
			candVec.push_back(i);
		}
	}

	cout << minScore << " " << candVec.size() << "\n";

	for (int i = 0; i < candVec.size(); i++) {
		cout << candVec[i] << " ";
	}

	return 0;
}