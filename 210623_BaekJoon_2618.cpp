#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#define MAX_EVENT 1000 + 1
#define p pair<int, int>
using namespace std;

int getRes(int idxA, int idxB);
int getDist(p curPos, p targetPos);

int graphSize, eventNum;
vector<p> vec;
int dp[MAX_EVENT][MAX_EVENT];
int trace[MAX_EVENT][MAX_EVENT];

int main() {
	cin >> graphSize >> eventNum;

	vec.push_back({ 1, 1 });
	vec.push_back({ graphSize, graphSize });

	for (int i = 0; i < eventNum; i++) {
		int inputRow, inputCol;
		cin >> inputRow >> inputCol;
		vec.push_back({ inputRow, inputCol });
	}

	memset(dp, -1, sizeof(dp));
	cout << getRes(0, 1) << "\n";

	int idxA = 0, idxB = 1;

	for (int i = 0; i < eventNum; i++) {
		cout << trace[idxA][idxB] << "\n";
		int curIdx = max(idxA, idxB);
		(trace[idxA][idxB] == 1) ? idxA = curIdx + 1 : idxB = curIdx + 1;
	}

	return 0;
}

int getRes(int idxA, int idxB) {
	int curIdx = max(idxA, idxB) + 1;

	if (curIdx == eventNum + 2) {
		return 0;
	}

	if (dp[idxA][idxB] != -1) {
		return dp[idxA][idxB];
	}

	int getA = getRes(curIdx, idxB) + getDist(vec[idxA], vec[curIdx]);
	int getB = getRes(idxA, curIdx) + getDist(vec[idxB], vec[curIdx]);

	trace[idxA][idxB] = (getA < getB ? 1 : 2);
	dp[idxA][idxB] = min(getA, getB);

	return dp[idxA][idxB];
}

int getDist(p curPos, p targetPos) {
	return abs(curPos.first - targetPos.first) + abs(curPos.second - targetPos.second);
}