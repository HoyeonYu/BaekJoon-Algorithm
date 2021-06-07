#include <iostream>
#include <cmath>
#define MAX_ITEM 100 + 1
#define MAX_WEIGHT 100000 + 1
#define MAX_VAL 1000 + 1
using namespace std;

int itemNum, maxWeight;
int weightArr[MAX_WEIGHT];
int valArr[MAX_WEIGHT];
int knapsack[MAX_ITEM][MAX_WEIGHT] = { 0 };

int main() {
	cin >> itemNum >> maxWeight;

	for (int i = 1; i <= itemNum; i++) {
		cin >> weightArr[i] >> valArr[i];
	}

	for (int i = 1; i <= itemNum; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (weightArr[i] <= j) {
				knapsack[i][j] = max(valArr[i] + knapsack[i - 1][j - weightArr[i]],
					knapsack[i - 1][j]);
			}

			else {
				knapsack[i][j] = knapsack[i - 1][j];
			}
		}
	}

	cout << knapsack[itemNum][maxWeight];

	return 0;
}