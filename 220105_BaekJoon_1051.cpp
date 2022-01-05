#include <iostream>
#include <algorithm>
#define MAX_SIZE 50 + 1
using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	int graph[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < col; j++) {
			graph[i][j] = str[j] - '0';
		}
	}

	for (int s = min(row, col); s >= 0; s--) {
		for (int i = 0; i <= row - s; i++) {
			for (int j = 0; j <= col - s; j++) {
				if (graph[i][j] == graph[i + s - 1][j] && graph[i][j] == graph[i][j + s - 1]
					&& graph[i][j] == graph[i + s - 1][j + s - 1]) {
					cout << s * s;
					return 0;
				}
			}
		}
	}

	return 0;
}