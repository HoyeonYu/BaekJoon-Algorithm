#include <iostream>
#include <queue>
#define MAX_SIZE 1000 + 1
#define p pair<int, int>
using namespace std;

int rowSize, colSize, targetRow, targetCol;
int graph[MAX_SIZE][MAX_SIZE];
queue<p> que;

void bfs();
void dp();

int main() {
	cin >> rowSize >> colSize;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cin >> graph[i][j];

			if (graph[i][j] == 2) {
				targetRow = i;
				targetCol = j;
				graph[i][j] = 0;
			}

			else if (graph[i][j] == 1) {
				graph[i][j] = 0;
			}

			else {
				graph[i][j] = -1;
			}
		}
	}

	que.push({ targetRow, targetCol });
	graph[targetRow][targetCol] = 1;
	bfs();
	dp();

	return 0;
}

void bfs() {
	while (!que.empty()) {
		int curRow = que.front().first;
		int curCol = que.front().second;
		que.pop();

		int dY[4] = { -1, 0, 0, 1 };
		int dX[4] = { 0, -1, 1, 0 };

		for (int i = 0; i < 4; i++) {
			int nextRow = curRow + dY[i];
			int nextCol = curCol + dX[i];

			if (nextRow >= 0 && nextRow < rowSize && nextCol >= 0 && nextCol < colSize) {
				if (graph[nextRow][nextCol] == 0) {
					graph[nextRow][nextCol] = graph[curRow][curCol] + 1;
					que.push({ nextRow, nextCol });
				}
			}
		}
	}
}

void dp() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (graph[i][j] == -1) {
				cout << 0 << " ";
			}

			else if (graph[i][j] == 0) {
				cout << -1 << " ";
			}

			else {
				cout << graph[i][j] - 1 << " ";
			}
		}
		cout << "\n";
	}
}