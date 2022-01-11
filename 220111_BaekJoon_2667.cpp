#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 25 + 1
using namespace std;

int graphSize, cnt;
bool graph[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE] = { false };
void DFS(int row, int col);

int main() {
	cin >> graphSize;

	for (int i = 0; i < graphSize; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < graphSize; j++) {
			graph[i][j] = str[j] - '0';
		}
	}

	vector<int> cntVec;

	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			if (!isVisited[i][j] && graph[i][j]) {
				cnt = 1;
				DFS(i, j);
				cntVec.push_back(cnt);
			}
		}
	}

	sort(cntVec.begin(), cntVec.end());

	cout << cntVec.size() << "\n";

	for (int i = 0; i < cntVec.size(); i++) {
		cout << cntVec[i] << "\n";
	}

	return 0;
}

void DFS(int row, int col) {
	isVisited[row][col] = true;

	int dX[4] = { -1, 0, 0, 1 };
	int dY[4] = { 0, -1, 1, 0 };

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dY[i];
		int nextCol = col + dX[i];

		if (nextRow >= 0 && nextRow < graphSize && nextCol >= 0 && nextCol < graphSize) {
			if (!isVisited[nextRow][nextCol] && graph[nextRow][nextCol]) {
				cnt++;
				DFS(nextRow, nextCol);
			}
		}
	}
}