#include <iostream>
#include <queue>
#include <vector>
#define MAX_ROW 100 + 1
#define MAX_COL 100 + 1
#define p pair<int, int>
using namespace std;

void init();
void BFS();
bool isInside(p pos, int idx);

char building[MAX_ROW][MAX_COL];
bool isVisited[MAX_ROW][MAX_COL];
long long keySet = 0;
int rowSize, colSize, resCount;
queue<p> posQue;
vector<p> doorPosVec;
vector<int> doorNameVec;
vector<bool> isVisitedDoor;

int dX[4] = { -1, 0, 0, 1 };
int dY[4] = { 0, -1, 1, 0 };

int main() {
	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> rowSize >> colSize;
		init();

		for (int r = 0; r < rowSize; r++) {
			string inputStr;
			cin >> inputStr;

			for (int c = 0; c < colSize; c++) {
				building[r][c] = inputStr[c];
			}
		}

		string key;
		cin >> key;

		if (key != "0") {
			for (int i = 0; i < key.length(); i++) {
				keySet |= (1 << (key[i] - 'a'));
			}
		}
		
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1) {
					if (!isVisited[i][j] && building[i][j] != '*') {
						if (building[i][j] >= 'A' && building[i][j] <= 'Z') {
							if (!(keySet & (1 << (building[i][j] - 'A')))) {
								doorPosVec.push_back({ i, j });
								doorNameVec.push_back(building[i][j] - 'A');
								isVisitedDoor.push_back(false);

								continue;
							}
						}

						if (building[i][j] == '$') {
							resCount++;
						}

						if (building[i][j] >= 'a' && building[i][j] <= 'z') {
							keySet |= (1 << (building[i][j] - 'a'));
						}

						isVisited[i][j] = true;
						posQue.push({ i, j });
						BFS();
					}
				}
			}
		}

		cout << resCount << "\n";
	}

	return 0;
}

void init() {
	resCount = 0;
	keySet = 0;

	doorPosVec.clear();
	doorNameVec.clear();
	isVisitedDoor.clear();

	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			isVisited[i][j] = false;
		}
	}
}

void BFS() {
	while (!posQue.empty()) {
		p curPos = posQue.front();
		posQue.pop();

		for (int i = 0; i < 4; i++) {
			p nextPos = { curPos.first + dY[i], curPos.second + dX[i] };

			if (isInside(nextPos, i)) {
				if (!isVisited[nextPos.first][nextPos.second] 
					&& building[nextPos.first][nextPos.second] != '*') {
					if (building[nextPos.first][nextPos.second] == '$') {
						resCount++;
					}

					else if (building[nextPos.first][nextPos.second] >= 'A'
						&& building[nextPos.first][nextPos.second] <= 'Z') {
						if (!(keySet & (1 << (building[nextPos.first][nextPos.second] - 'A')))) {
							doorPosVec.push_back(nextPos);
							doorNameVec.push_back(building[nextPos.first][nextPos.second] - 'A');
							isVisitedDoor.push_back(false);

							continue;
						}
					}

					else if (building[nextPos.first][nextPos.second] >= 'a'
						&& building[nextPos.first][nextPos.second] <= 'z') {
						keySet |= (1 << (building[nextPos.first][nextPos.second] - 'a'));
					}

					isVisited[nextPos.first][nextPos.second] = true;
					posQue.push(nextPos);
				}
			}
		}
	}

	for (int i = 0; i < doorNameVec.size(); i++) {
		int doorName = doorNameVec[i];
		p doorPos = doorPosVec[i];

		if (!isVisitedDoor[i]) {
			if (keySet & (1 << doorName)) {
				isVisited[doorPos.first][doorPos.second] = true;
				posQue.push(doorPos);
				isVisitedDoor[i] = true;
			}
		}
	}

	if (!posQue.empty()) {
		BFS();
	}
}

bool isInside(p pos, int idx) {
	return (pos.first + dY[idx] >= 0 && pos.first + dY[idx] < rowSize
		&& pos.second + dX[idx] >= 0 && pos.second + dX[idx] < colSize);
}