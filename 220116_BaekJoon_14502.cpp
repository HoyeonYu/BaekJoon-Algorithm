#include <iostream>
#include <vector>
using namespace std;

int row, col;
int orgGraph[8][8];
int adjGraph[8][8];
vector<pair<int, int>> candidatePos;

void init();
void DFS(int yPos, int xPos);
int foundArea();

int main() {
	cin >> row >> col;

	int candNum = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> orgGraph[i][j];
			adjGraph[i][j] = orgGraph[i][j];

			if (orgGraph[i][j] == 0) {
				candidatePos.push_back(make_pair(i, j));
				candNum++;
			}
		}
	}

	int maxCount = 0;

	for (int i = 0; i < candNum - 2; i++) {
		for (int j = i + 1; j < candNum - 1; j++) {
			for (int k = j + 1; k < candNum; k++) {
				adjGraph[candidatePos.at(i).first][candidatePos.at(i).second] = 1;
				adjGraph[candidatePos.at(j).first][candidatePos.at(j).second] = 1;
				adjGraph[candidatePos.at(k).first][candidatePos.at(k).second] = 1;

				for (int l = 0; l < row; l++) {
					for (int m = 0; m < col; m++) {
						if (adjGraph[l][m] == 2) {
							DFS(l, m);
						}
					}
				}

				int count = foundArea();

				if (count > maxCount) {
					maxCount = count;
				}

				init();
			}
		}
	}

	cout << maxCount;

	return 0;
}

void init() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			adjGraph[i][j] = orgGraph[i][j];
		}
	}
}

void DFS(int yPos, int xPos) {
	int dX[4] = { -1, 0, 0, 1 };
	int dY[4] = { 0, -1, 1, 0 };

	for (int i = 0; i < 4; i++) {
		int nextXpos = xPos + dX[i];
		int nextYpos = yPos + dY[i];

		if (nextXpos >= 0 && nextXpos < col && nextYpos >= 0 && nextYpos < row) {
			if (adjGraph[nextYpos][nextXpos] == 0) {
				adjGraph[nextYpos][nextXpos] = 2;
				DFS(nextYpos, nextXpos);
			}
		}
	}
}

int foundArea() {
	int count = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (adjGraph[i][j] == 0) {
				count++;
			}
		}
	}

	return count;
}