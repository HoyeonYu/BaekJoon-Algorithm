#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 1000 + 1
#define p pair<int, int>
using namespace std;

int colSize, rowSize, res = 0;
int graph[MAX_SIZE][MAX_SIZE];
queue<p> que;

void bfs();
int isCompleted();

int main() {
	cin >> colSize >> rowSize;
	
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (graph[i][j] == 1) {
				que.push({ i, j });
			}
		}
	}

	bfs();

	cout << isCompleted();

	return 0;
}

void bfs() {
	while (!que.empty()) {
		int row = que.front().first;
		int col = que.front().second;
		que.pop();

		int dY[4] = { 0, -1, 1, 0 };
		int dX[4] = { -1, 0, 0, 1 };

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dY[i];
			int nextCol = col + dX[i];

			if (nextRow >= 0 && nextRow < rowSize && nextCol >= 0 && nextCol < colSize) {
				if (graph[nextRow][nextCol] == 0) {
					graph[nextRow][nextCol] = graph[row][col] + 1;
					que.push({ nextRow, nextCol });
				}
			}
		}
	}
}

int isCompleted() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			res = max(res, graph[i][j]);

			if (graph[i][j] == 0) {
				return -1;
			}
		}
	}

	return res - 1;
}