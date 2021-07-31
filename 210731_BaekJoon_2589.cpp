#include <iostream>
#include <queue>
#define p pair<int, int>
#define MAX_SIZE 50 + 1
using namespace std;

int row, col;
int graph[MAX_SIZE][MAX_SIZE];
int isVisited[MAX_SIZE][MAX_SIZE];
int visitedStep[MAX_SIZE][MAX_SIZE];
queue<p> que;
int maxVal = 0;

void init();
void BFS();

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < col; j++) {
			graph[i][j] = (str[j] == 'L');
		}
	}

	int maxDiff = 0;
	init();

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (graph[i][j] && visitedStep[i][j] == 0) {
				que.push({ i, j });
				visitedStep[i][j] = 1;
				BFS();
				init();

				int diff = maxVal - 1;
				if (diff > maxDiff) {
					maxDiff = diff;
				}
			}
		}
	}

	cout << maxDiff;

	return 0;
}

void init() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visitedStep[i][j] = 0;
		}
	}
}

void BFS() {
	maxVal = 0;

	while (!que.empty()) {
		int curY = que.front().first;
		int curX = que.front().second;
		que.pop();

		int dY[4] = { -1, 0, 0, 1 };
		int dX[4] = { 0, -1, 1, 0 };

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dY[i];
			int nextX = curX + dX[i];

			if (nextY >= 0 && nextY < row && nextX >= 0 && nextX < col) {
				if (graph[nextY][nextX] && visitedStep[nextY][nextX] == 0) {
					visitedStep[nextY][nextX] = visitedStep[curY][curX] + 1;

					if (maxVal < visitedStep[nextY][nextX]) {
						maxVal = visitedStep[nextY][nextX];
					}

					que.push({ nextY, nextX });
				}
			}
		}
	}
}