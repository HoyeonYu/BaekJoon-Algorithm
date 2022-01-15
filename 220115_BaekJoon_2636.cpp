#include <iostream>
#include <queue>
#define MAX_SIZE 100 + 1
#define p pair<int, int>
using namespace std;

int rowSize, colSize, trialCnt, residueCnt;
int graph[MAX_SIZE][MAX_SIZE], copyGraph[MAX_SIZE][MAX_SIZE];
queue<p> que;

void input();
void init();
void searchHole();
void bfsAir(int spaceCnt);
void melt();
bool isDone();

int main() {
	input();
	trialCnt = 0;

	while (!isDone()) {
		init();
		searchHole();
		melt();
		trialCnt++;
	}

	cout << trialCnt << "\n" << residueCnt;

	return 0;
}

void input() {
	cin >> rowSize >> colSize;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cin >> graph[i][j];

			if (graph[i][j]) {
				graph[i][j] = -1;
			}
		}
	}
}

void init() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			copyGraph[i][j] = graph[i][j];
		}
	}
}

void searchHole() {
	int spaceCnt = 1;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (copyGraph[i][j] == 0) {
				que.push({ i, j });
				bfsAir(spaceCnt++);
			}
		}
	}
}

void bfsAir(int spaceCnt) {
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
				if (copyGraph[nextRow][nextCol] == 0) {
					copyGraph[nextRow][nextCol] = spaceCnt;
					que.push({ nextRow, nextCol });
				}
			}
		}
	}
}

void melt() {
	for (int i = 1; i < rowSize - 1; i++) {
		for (int j = 1; j < colSize - 1; j++) {
			if (copyGraph[i][j] == -1 &&
				(copyGraph[i - 1][j] == 1 || copyGraph[i][j - 1] == 1 ||
					copyGraph[i + 1][j] == 1 || copyGraph[i][j + 1] == 1)) {
				graph[i][j] = 0;
			}
		}
	}
}

bool isDone() {
	int newResidueCnt = 0;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (graph[i][j] == -1) {
				newResidueCnt++;
			}
		}
	}

	if (newResidueCnt != 0) {
		residueCnt = newResidueCnt;
	}

	return (newResidueCnt == 0);
}