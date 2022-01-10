#include <iostream>
#include <queue>
using namespace std;

int adjGraph[100][100] = { false };
bool isVisited[100][100] = { false };

int row, col, countDis = 1;

void BFS();

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			adjGraph[i][j] = input[j] - '0';
		}
	}

	BFS();

	cout << adjGraph[row - 1][col - 1];

	return 0;
}

void BFS() {
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	isVisited[0][0] = true;

	while (!que.empty()) {
		int curYPos = que.front().first;
		int curXPos = que.front().second;
		que.pop();

		int dX[4] = { -1, 0, 0, 1 };
		int dY[4] = { 0, -1, 1, 0 };

		for (int i = 0; i < 4; i++) {
			int nextYPos = curYPos + dY[i];
			int nextXPos = curXPos + dX[i];

			if (nextYPos >= 0 && nextYPos < row && nextXPos >= 0 && nextXPos < col) {
				if (adjGraph[nextYPos][nextXPos] && !isVisited[nextYPos][nextXPos]) {
					adjGraph[nextYPos][nextXPos] = adjGraph[curYPos][curXPos] + 1;
					isVisited[nextYPos][nextXPos] = true;
					que.push(make_pair(nextYPos, nextXPos));
				}
			}
		}
	}
}