#include <iostream>
#include <cmath>
#define MAX_SIZE 500 + 1
using namespace std;

int graphSize;
int graph[MAX_SIZE][MAX_SIZE];
int dpGraph[MAX_SIZE][MAX_SIZE];
int maxCount = 1;

int dX[4] = { -1, 0, 0, 1 };
int dY[4] = { 0, -1, 1, 0 };

int dfs(int row, int col);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> graphSize;

	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			cin >> graph[i][j];
			dpGraph[i][j] = -1;
		}
	}

	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			if (dpGraph[i][j] == -1) {
				dfs(i, j);
			}
		}
	}
	
	cout << maxCount;

	return 0;
}

int dfs(int row, int col) {
	if (dpGraph[row][col] != -1) {
		return dpGraph[row][col];
	}
	
	dpGraph[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dY[i];
		int nextCol = col + dX[i];

		if (nextRow >= 0 && nextRow < graphSize && nextCol >= 0 && nextCol < graphSize) {
			if (graph[nextRow][nextCol] > graph[row][col]) {
				int count = dfs(nextRow, nextCol) + 1;
				dpGraph[row][col] = max(dpGraph[row][col], count);
				maxCount = max(maxCount, dpGraph[row][col]);
			}
		}
	}

	return dpGraph[row][col];
}