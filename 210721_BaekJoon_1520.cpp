#include <iostream>
#define MAX_SIZE 500 + 1
using namespace std;

int DFS(int row, int col);

int graph[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int graphRow, graphCol;

int dX[4] = { 1, 0, 0, -1 };
int dY[4] = { 0, 1, -1, 0 };

int main() {
	cin >> graphRow >> graphCol;

	for (int i = 0; i < graphRow; i++) {
		for (int j = 0; j < graphCol; j++) {
			cin >> graph[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(0, 0);

	return 0;
}

int DFS(int row, int col) {
	if (row == graphRow - 1 && col == graphCol - 1) {
		return 1;
	}
	
	int& ret = dp[row][col];
	if (ret != -1) {
		return ret;
	}
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dY[i];
		int nextCol = col + dX[i];

		if (nextRow >= 0 && nextRow < graphRow && nextCol >= 0 && nextCol < graphCol) {
			if (graph[nextRow][nextCol] < graph[row][col]) {
				ret += DFS(nextRow, nextCol);
			}
		}
	}

	return ret;
}