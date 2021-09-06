#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_SIZE 10 + 1
#define MAX_ISLAND 6 + 1
#define p pair<int, int>
#define pp pair<int, p>
using namespace std;

void init();
void initDFS();
void DFS(int row, int col, int idx);
void BFS(int idx);
int getParent(int x);
void setUnion(int x, int y);
int MST(int islandIdx);

struct Point {
	int row, col, dir;
};

int graphRow, graphCol;
int inputGraph[MAX_SIZE][MAX_SIZE];
int isVisited[MAX_SIZE][MAX_SIZE];
int islandIdx = 1;
queue<Point> que[MAX_ISLAND];
vector<pp> distVec;
int parent[MAX_ISLAND];

int main() {
	cin >> graphRow >> graphCol;

	for (int i = 0; i < graphRow; i++) {
		for (int j = 0; j < graphCol; j++) {
			cin >> inputGraph[i][j];
		}
	}

	initDFS();

	for (int i = 1; i < islandIdx; i++) {
		init();
		BFS(i);
	}

	cout << MST(islandIdx);

	return 0;
}

void init() {
	for (int i = 0; i < graphRow; i++) {
		for (int j = 0; j < graphCol; j++) {
			isVisited[i][j] = 0;
		}
	}
}

void initDFS() {
	for (int i = 0; i < graphRow; i++) {
		for (int j = 0; j < graphCol; j++) {
			if (inputGraph[i][j] && isVisited[i][j] == 0) {
				isVisited[i][j] = 1;
				inputGraph[i][j] = islandIdx;

				for (int k = 0; k < 4; k++) {
					Point point;
					point.row = i;
					point.col = j;
					point.dir = k;
					que[islandIdx].push(point);
				}

				DFS(i, j, islandIdx++);
			}
		}
	}
}

void DFS(int row, int col, int idx) {
	int dX[4] = { -1, 0, 0, 1 };
	int dY[4] = { 0, -1, 1, 0 };

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dY[i];
		int nextCol = col + dX[i];

		if (nextRow >= 0 && nextRow < graphRow && nextCol >= 0 && nextCol < graphCol) {
			if (inputGraph[nextRow][nextCol] != 0 && isVisited[nextRow][nextCol] == 0) {
				isVisited[nextRow][nextCol] = 1;
				inputGraph[nextRow][nextCol] = idx;

				for (int k = 0; k < 4; k++) {
					Point point;
					point.row = nextRow;
					point.col = nextCol;
					point.dir = k;
					que[idx].push(point);
				}

				DFS(nextRow, nextCol, idx);
			}
		}
	}
}

void BFS(int idx) {
	int dX[4] = { -1, 0, 0, 1 };
	int dY[4] = { 0, -1, 1, 0 };

	while (!que[idx].empty()) {
		Point point = que[idx].front();
		int row = point.row;
		int col = point.col;
		int dir = point.dir;
		que[idx].pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dY[i];
			int nextCol = col + dX[i];

			if (nextRow >= 0 && nextRow < graphRow && nextCol >= 0 && nextCol < graphCol && dir == i) {
				if (inputGraph[nextRow][nextCol] == 0 && isVisited[nextRow][nextCol] == 0) {
					isVisited[nextRow][nextCol] = isVisited[row][col] + 1;

					Point point;
					point.row = nextRow;
					point.col = nextCol;
					point.dir = i;
					que[idx].push(point);
				}

				else if (isVisited[row][col] > 1
					&& inputGraph[nextRow][nextCol] != 0 && inputGraph[nextRow][nextCol] != idx) {
					distVec.push_back({ isVisited[row][col] , {idx, inputGraph[nextRow][nextCol]} });
				}
			}
		}
	}
}

int getParent(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = getParent(parent[x]);
}

void setUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		parent[y] = x;
	}
}

int MST(int islandIdx) {
	int distCount = 0;
	int distSum = 0;
	sort(distVec.begin(), distVec.end());

	for (int i = 0; i < MAX_ISLAND; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < distVec.size(); i++) {
		int weight = distVec[i].first;
		int x = distVec[i].second.first;
		int y = distVec[i].second.second;

		if (getParent(x) != getParent(y)) {
			setUnion(x, y);
			distCount++;
			distSum += weight;
		}

		if (distCount == islandIdx - 2) {
			break;
		}
	}

	if (distCount < islandIdx - 2) {
		distSum = -1;
	}

	return distSum;
}