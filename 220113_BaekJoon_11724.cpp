#include <iostream>
using namespace std;

void DFS(int xPos);

bool adjGraph[1000][1000] = { false };
bool isVisited[1000] = { false };

int vtxNum;

int main() {
	int edgeNum;
	cin >> vtxNum >> edgeNum;

	for (int i = 0; i < edgeNum; i++) {
		int vtx1, vtx2;
		cin >> vtx1 >> vtx2;
		vtx1--, vtx2--;

		adjGraph[vtx1][vtx2] = true;
		adjGraph[vtx2][vtx1] = true;
	}

	int connectedCompCount = 0;

	for (int i = 0; i < vtxNum; i++) {
		if (!isVisited[i]) {
			DFS(i);
			connectedCompCount++;
		}
	}

	cout << connectedCompCount;

	return 0;
}

void DFS(int xPos) {
	isVisited[xPos] = true;

	for (int i = 0; i < vtxNum; i++) {
		if (adjGraph[xPos][i] && !isVisited[i]) {
			DFS(i);
		}
	}
}