#include <iostream>
#include <vector>
#define MAX_SEC 100 + 1
using namespace std;

vector<int> fileVec[MAX_SEC];
bool isVisited[MAX_SEC];
int decided[MAX_SEC];

bool dfs(int num);

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int totalFileNum, pplNum;
		cin >> totalFileNum >> pplNum;

		for (int j = 0; j < MAX_SEC; j++) {
			fileVec[j].clear();
		}

		for (int j = 0; j < pplNum; j++) {
			int inTime, outTime, fileNum;
			cin >> inTime >> outTime >> fileNum;

			for (int k = 0; k < fileNum; k++) {
				int partFile;
				cin >> partFile;

				for (int m = inTime; m < outTime; m++) {
					fileVec[m].push_back(partFile);
				}
			}
		}

		fill_n(decided, MAX_SEC, -1);
		int fileCount = 0, minTime = -1;

		for (int j = 0; j < MAX_SEC; j++) {
			fill_n(isVisited, MAX_SEC, false);

			if (dfs(j)) {
				fileCount++;

				if (fileCount == totalFileNum) {
					minTime = j + 1;
					break;
				}
			}
		}

		cout << minTime << "\n";
	}

	return 0;
}

bool dfs(int num) {
	for (int i = 0; i < fileVec[num].size(); i++) {
		int fileIdx = fileVec[num][i];

		if (isVisited[fileIdx]) {
			continue;
		}

		isVisited[fileIdx] = true;

		if (decided[fileIdx] == -1 || dfs(decided[fileIdx])) {
			decided[fileIdx] = num;
			return true;
		}
	}

	return false;
}