#include <iostream>
#include <vector>
#include <cmath>
#define MAX_RAT 100 + 1
#define p pair<double, double>
using namespace std;

int ratNum, caveNum, eagleTime, ratSpeed;
vector<int> posVec[MAX_RAT];
vector<p> ratPosVec, cavePosVec;
bool isVisited[MAX_RAT];
int decided[MAX_RAT];

bool isNearer(int ratIdx, int caveIdx);
bool dfs(int num);

int main() {
	cin >> ratNum >> caveNum >> eagleTime >> ratSpeed;

	for (int i = 0; i < ratNum; i++) {
		double x, y;
		cin >> x >> y;
		ratPosVec.push_back({ x, y });
	}

	for (int i = 0; i < caveNum; i++) {
		double x, y;
		cin >> x >> y;
		cavePosVec.push_back({ x, y });
	}

	for (int i = 0; i < ratNum; i++) {
		for (int j = 0; j < caveNum; j++) {
			if (isNearer(i, j)) {
				posVec[i].push_back(j);
			}
		}
	}

	int runRat = 0;
	fill_n(decided, MAX_RAT, -1);

	for (int i = 0; i < ratNum; i++) {
		fill_n(isVisited, MAX_RAT, false);

		if (dfs(i)) {
			runRat++;
		}
	}

	cout << ratNum - runRat;

	return 0;
}

bool isNearer(int ratIdx, int caveIdx) {
	p ratPos = ratPosVec[ratIdx];
	p cavePos = cavePosVec[caveIdx];

	double x = ratPos.first - cavePos.first;
	double y = ratPos.second - cavePos.second;

	return (sqrt(pow(x, 2) + pow(y, 2)) / (double)ratSpeed) <= (double)eagleTime;
}

bool dfs(int num) {
	for (int i = 0; i < posVec[num].size(); i++) {
		int posIdx = posVec[num][i];

		if (isVisited[posIdx]) {
			continue;
		}

		isVisited[posIdx] = true;

		if (decided[posIdx] == -1 || dfs(decided[posIdx])) {
			decided[posIdx] = num;
			return true;
		}
	}

	return false;
}