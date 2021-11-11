#include <iostream>
#include <vector>
#define MAX_COW 200 + 1
using namespace std;

int cowNum, houseNum;
vector<int> cowHouse[MAX_COW];
bool isVisited[MAX_COW] = { false };
int decidedHouse[MAX_COW];

bool dfs(int x);

int main() {
	cin >> cowNum >> houseNum;

	for (int i = 0; i < houseNum; i++) {
		int personIdx, noteBookIdx;
		cin >> personIdx >> noteBookIdx;

		cowHouse[personIdx].push_back(noteBookIdx);
	}

	int res = 0;
	fill_n(decidedHouse, MAX_COW, -1);

	for (int i = 1; i <= cowNum; i++) {
		fill_n(isVisited, MAX_COW, false);

		if (dfs(i)) {
			res++;
		}
	}

	cout << res;

	return 0;
}

bool dfs(int x) {
	for (int i = 0; i < cowHouse[x].size(); i++) {
		int houseIdx = cowHouse[x][i];

		if (isVisited[houseIdx]) {
			continue;
		}

		isVisited[houseIdx] = true;

		if (decidedHouse[houseIdx] == -1 || dfs(decidedHouse[houseIdx])) {
			decidedHouse[houseIdx] = x;

			return true;
		}
	}

	return false;
}