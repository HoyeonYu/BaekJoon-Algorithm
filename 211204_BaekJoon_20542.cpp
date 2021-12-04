#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSame(int wrongI, int ansJ);
int wrongLen, ansLen;
string wrongStr, ansStr;

int main() {
	cin >> wrongLen >> ansLen >> wrongStr >> ansStr;

	vector<vector<int>> dpVec(wrongLen + 1, vector<int>(ansLen + 1, 0));

	for (int i = 0; i <= max(wrongLen, ansLen); i++) {
		if (i <= wrongLen) {
			dpVec[i][0] = i;
		}

		if (i <= ansLen) {
			dpVec[0][i] = i;
		}
	}

	for (int i = 1; i <= wrongLen; i++) {
		for (int j = 1; j <= ansLen; j++) {
			dpVec[i][j] = dpVec[i - 1][j - 1];

			if (!isSame(i, j)) {
				dpVec[i][j] = min(dpVec[i - 1][j - 1], min(dpVec[i - 1][j], dpVec[i][j - 1])) + 1;
			}
		}
	}

	cout << dpVec[wrongLen][ansLen];

	return 0;
}

bool isSame(int wrongI, int ansJ) {
	wrongI--, ansJ--;

	if ((wrongStr[wrongI] == ansStr[ansJ]) ||
		((wrongStr[wrongI] == 'v') && (ansStr[ansJ] == 'w')) ||
		((wrongStr[wrongI] == 'i') && ((ansStr[ansJ] == 'j') || (ansStr[ansJ] == 'l')))) {
		return true;
	}

	return false;
}