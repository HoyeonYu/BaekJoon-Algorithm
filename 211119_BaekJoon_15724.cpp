#include <iostream>
#define MAX_SIZE 1024 + 1
using namespace std;

void getDP();

int rowSize, colSize;
int graph[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> rowSize >> colSize;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cin >> graph[i][j];
			dp[i + 1][j + 1] = graph[i][j];
		}
	}

	getDP();

	int searchNum;
	cin >> searchNum;

	for (int i = 0; i < searchNum; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1] << "\n";
	}

	return 0;
}

void getDP() {
	for (int i = 0; i < rowSize + 1; i++) {
		dp[i][0] = 0;
	}

	for (int i = 0; i < colSize + 1; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i < rowSize + 1; i++) {
		for (int j = 1; j < colSize + 1; j++) {
			dp[i][j] = graph[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}