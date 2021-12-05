#include <iostream>
#define MAX_ARR 500 + 1
using namespace std;

int getSize(int startIdx, int endIdx);
int arrSize[MAX_ARR][2], dp[MAX_ARR][MAX_ARR];

int main() {
	int arrNum;
	cin >> arrNum;

	for (int i = 0; i < arrNum; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arrSize[i][j];
		}
	}

    cout << getSize(0, arrNum - 1);

	return 0;
}

int getSize(int startIdx, int endIdx) {
	int res = 0;

    if (startIdx == endIdx) {
        return 0;
    }

    if (dp[startIdx][endIdx]) {
        return dp[startIdx][endIdx];
    }

    if (endIdx == startIdx + 1) {
        res = arrSize[startIdx][0] * arrSize[startIdx][1] * arrSize[endIdx][1];
        dp[startIdx][endIdx] = res;

        return dp[startIdx][endIdx];
    }

    for (int i = startIdx; i < endIdx; ++i) {
        res = getSize(startIdx, i) + getSize(i + 1, endIdx)
            + arrSize[startIdx][0] * arrSize[i][1] * arrSize[endIdx][1];
        
        if (!dp[startIdx][endIdx] || res < dp[startIdx][endIdx]) {
            dp[startIdx][endIdx] = res;
        }
    }

    return dp[startIdx][endIdx];
}