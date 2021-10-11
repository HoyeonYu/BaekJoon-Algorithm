#include <iostream>
#include <cmath>
#define MAX_NUM 50 + 1
using namespace std;

int main() {
	long long diceNum;
	cin >> diceNum;

	int pos[6], totSum = 0, totMax = 0;

	for (int i = 0; i < 6; i++) {
		cin >> pos[i];
		totSum += pos[i];
		totMax = max(totMax, pos[i]);
	}

	int oneSide = MAX_NUM, twoSide = 0, threeSide = 0, threeMax = 0;

	for (int i = 0; i < 3; i++) {
		threeSide += min(pos[i], pos[5 - i]);
		threeMax = max(threeMax, min(pos[i], pos[5 - i]));
		oneSide = min(oneSide, min(pos[i], pos[5 - i]));
	}

	twoSide = threeSide - threeMax;

	long long res = (long long)(threeSide * 4)
		+ (long long)(twoSide * ((2 * diceNum - 3) * 4))
		+ (long long)(oneSide * ((diceNum - 2) * ((diceNum - 1) * 4) + pow(diceNum - 2, 2)));

	if (diceNum == 1) {
		res = totSum - totMax;
	}

	cout << res;

	return 0;
}