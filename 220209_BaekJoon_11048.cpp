#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000 + 1
using namespace std;

int graph[MAX_SIZE][MAX_SIZE];

int main() {
	int rowSize, colSize;
	cin >> rowSize >> colSize;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i < rowSize; i++) {
		graph[i][0] += graph[i - 1][0];
	}

	for (int i = 1; i < colSize; i++) {
		graph[0][i] += graph[0][i - 1];
	}

	for (int i = 1; i < rowSize; i++) {
		for (int j = 1; j < colSize; j++) {
			graph[i][j] += max(max(graph[i - 1][j], graph[i][j - 1]), graph[i - 1][j - 1]);
		}
	}

	cout << graph[rowSize - 1][colSize - 1];

	return 0;
}