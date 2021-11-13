#include <iostream>
#include <vector>
#define MAX_PPL (1000 + 1) * 2
using namespace std;

vector<int> workVec[MAX_PPL];
bool isVisited[MAX_PPL];
int decided[MAX_PPL];

bool dfs(int num);

int main() {
	int people, work;
	cin >> people >> work;

	for (int i = 0; i < people; i++) {
		int workNum;
		cin >> workNum;

		for (int j = 0; j < workNum; j++) {
			int idx;
			cin >> idx;

			workVec[i * 2].push_back(idx);
			workVec[i * 2 + 1].push_back(idx);
		}
	}

	fill_n(decided, MAX_PPL, -1);
	
	int res = 0;

	for (int i = 0; i < people * 2; i++) {
		fill_n(isVisited, MAX_PPL, false);

		if (dfs(i)) {
			res++;
		}
	}

	cout << res;

	return 0;
}

bool dfs(int num) {
	for (int i = 0; i < workVec[num].size(); i++) {
		int selectIdx = workVec[num][i];

		if (isVisited[selectIdx]) {
			continue;
		}

		isVisited[selectIdx] = true;

		if (decided[selectIdx] == -1 || dfs(decided[selectIdx])) {
			decided[selectIdx] = num;
			return true;
		}
	}

	return false;
}