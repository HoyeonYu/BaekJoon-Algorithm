#include <iostream>
#include <vector>
#define MAX_PPL 1000 + 1
using namespace std;

vector<int> workVec[MAX_PPL];
bool isVisited[MAX_PPL];
int decided[MAX_PPL];

bool dfs(int num);

int main() {
	int pplNum, workNum, penalty;
	cin >> pplNum >> workNum >> penalty;

	for (int i = 0; i < pplNum; i++) {
		int personWork;
		cin >> personWork;

		for (int j = 0; j < personWork; j++) {
			int workIdx;
			cin >> workIdx;
			workVec[i].push_back(workIdx);
		}
	}

	int workCount = 0;
	fill_n(decided, MAX_PPL, -1);

	for (int i = 0; i < pplNum; i++) {
		fill_n(isVisited, MAX_PPL, false);

		if (dfs(i)) {
			workCount++;
		}
	}

	for (int i = 0; (i < pplNum) && (penalty > 0); i++) {
		fill_n(isVisited, MAX_PPL, false);

		if (dfs(i)) {
			workCount++;
			penalty--;
			i--;
		}
	}

	cout << workCount;

	return 0;
}

bool dfs(int num) {
	for (int i = 0; i < workVec[num].size(); i++) {
		int workIdx = workVec[num][i];

		if (isVisited[workIdx]) {
			continue;
		}

		isVisited[workIdx] = true;

		if (decided[workIdx] == -1 || dfs(decided[workIdx])) {
			decided[workIdx] = num;
			return true;
		}
	}

	return false;
}