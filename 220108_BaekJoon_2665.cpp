#include <iostream>
#include <queue>
#define MAX_SIZE 50 + 1
#define INF 1e9
#define p pair<int, int>
using namespace std;

int graphSize;
bool graph[MAX_SIZE][MAX_SIZE];
int isVisited[MAX_SIZE][MAX_SIZE];
queue<p> que;

void init();
void BFS();

void dp() {
	cout << "\n";
	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			cout << isVisited[i][j] + 1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> graphSize;

	for (int i = 0; i < graphSize; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < graphSize; j++) {
			graph[i][j] = str[j] - '0';
		}
	}

	init();
	BFS();

	cout << isVisited[graphSize - 1][graphSize - 1];

	return 0;
}

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			isVisited[i][j] = INF;
		}
	}

	isVisited[0][0] = 0;
	que.push({ 0, 0 });
}

void BFS() {
	while (!que.empty()) {
		p curPos = que.front();
		que.pop();

		int dX[4] = { -1, 0, 0, 1 };
		int dY[4] = { 0, -1, 1, 0 };

		for (int i = 0; i < 4; i++) {
			p nextPos = { curPos.first + dY[i], curPos.second + dX[i] };

			if (nextPos.first >= 0 && nextPos.first < graphSize &&
				nextPos.second >= 0 && nextPos.second < graphSize) {
				if (graph[nextPos.first][nextPos.second]) {
					if (isVisited[nextPos.first][nextPos.second] > 
						isVisited[curPos.first][curPos.second]) {
						isVisited[nextPos.first][nextPos.second] = isVisited[curPos.first][curPos.second];
						que.push({ nextPos.first, nextPos.second });
					}
				}

				else if (isVisited[nextPos.first][nextPos.second] > 
					isVisited[curPos.first][curPos.second] + 1) {
					isVisited[nextPos.first][nextPos.second] = isVisited[curPos.first][curPos.second] + 1;
					que.push({ nextPos.first, nextPos.second });
				}
			}
		}
	}
}