#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int inputNum;
	cin >> inputNum;

	int baseNum;
	cin >> baseNum;

	int sensorPos[10001];
	int posDiff[10001];
	long long totalDiff = 0;
	cin >> sensorPos[0];

	for (int i = 1; i < inputNum; i++) {
		cin >> sensorPos[i];
	}
	sort(sensorPos, sensorPos + inputNum);

	for (int i = 1; i < inputNum; i++) {
		posDiff[i - 1] = abs(sensorPos[i] - sensorPos[i - 1]);
		totalDiff += posDiff[i - 1];
	}

	sort(posDiff, posDiff + inputNum - 1);

	for (int i = 0; i < (baseNum - 1); i++) {
		totalDiff -= posDiff[inputNum - i - 2];
	}

	cout << totalDiff;

	return 0;
}