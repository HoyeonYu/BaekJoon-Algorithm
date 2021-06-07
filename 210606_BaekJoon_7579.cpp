#include <iostream>
#include <cmath>
#define MAX_SUM_COST 100 * 100 + 1
#define MAX_ITEM 100 + 1
using namespace std;

int knapsack[MAX_ITEM][MAX_SUM_COST] = { 0 };
int memArr[MAX_ITEM];
int costArr[MAX_ITEM];

int main() {
	int itemNum, minMem;
	cin >> itemNum >> minMem;

	for (int i = 1; i <= itemNum; i++) {
		cin >> memArr[i];
	}

	int sumCost = 0;

	for (int i = 1; i <= itemNum; i++) {
		cin >> costArr[i];
		sumCost += costArr[i];
	}

	for (int i = 1; i <= itemNum; i++) {
		for (int j = 0; j <= sumCost; j++) {
			if (costArr[i] <= j) {
				knapsack[i][j] = max(memArr[i] + knapsack[i - 1][j - costArr[i]], knapsack[i - 1][j]);
			}

			else {
				knapsack[i][j] = knapsack[i - 1][j];
			}
		}
	}
	
	for (int i = 0; i <= sumCost; i++) {
		if (knapsack[itemNum][i] >= minMem) {
			cout << i;
			break;
		}
	}

	return 0;
}