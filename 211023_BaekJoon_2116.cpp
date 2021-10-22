#include <iostream>
#include <cmath>
#define MAX_DICE 10000 + 1
using namespace std;

int main() {
	int diceNum;
	cin >> diceNum;

	int dice[MAX_DICE][6];
	int idxMatch[6] = { 5, 3, 4, 1, 2, 0 };

	for (int i = 0; i < diceNum; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dice[i][j];
		}
	}

	int maxSum = 0;

	for (int i = 0; i < 6; i++) {
		int nextUpper = dice[0][i];
		int sum = 0, maxPoint = 0;

		for (int j = 0; j < 6; j++) {
			if (j != i && j != idxMatch[i]) {
				maxPoint = max(maxPoint, dice[0][j]);
			}
		}

		sum += maxPoint;

		for (int j = 1; j < diceNum; j++) {
			int nextBelowIdx = 0; 
			maxPoint = 0;

			for (int k = 0; k < 6; k++) {
				if (dice[j][k] == nextUpper) {
					nextBelowIdx = k;
					break;
				}
			}

			for (int k = 0; k < 6; k++) {
				if (k != nextBelowIdx && k != idxMatch[nextBelowIdx]) {
					maxPoint = max(maxPoint, dice[j][k]);
				}
			}

			nextUpper = dice[j][idxMatch[nextBelowIdx]];
			sum += maxPoint;
		}

		maxSum = max(maxSum, sum);
	} 

	cout << maxSum;

	return 0;
}