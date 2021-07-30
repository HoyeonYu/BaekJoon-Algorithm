#include <iostream>
#include <vector>
#define MAX_VTX 50 + 1
using namespace std;

int parentArr[MAX_VTX];
int graph[MAX_VTX][MAX_VTX];
vector<int> partyVec[MAX_VTX];
vector<int> truthVec;

int getParent(int x);
void setUnion(int x, int y);

int main() {
	int vtxNum, edgeNum;
	cin >> vtxNum >> edgeNum;

	int truthNum;
	cin >> truthNum;

	for (int i = 0; i < truthNum; i++) {
		int truthIdx;
		cin >> truthIdx;
		truthVec.push_back(truthIdx);
	}

	for (int i = 1; i <= vtxNum; i++) {
		parentArr[i] = i;
	}

	for (int i = 0; i < edgeNum; i++) {
		int personNum, prevPersonIdx;
		cin >> personNum;
		
		for (int j = 0; j < personNum; j++) {
			int personIdx;
			cin >> personIdx;
			partyVec[i].push_back(personIdx);

			if (j == 0) {
				prevPersonIdx = personIdx;
			}

			setUnion(prevPersonIdx, personIdx);
			prevPersonIdx = personIdx;
		}
	}

	int resCount = 0;
		
	for (int i = 1; i <= vtxNum; i++) {
		parentArr[i] = getParent(i);
	}

	for (int i = 0; i < edgeNum; i++) {
		bool isAvail = true;

		for (int j = 0; j < partyVec[i].size(); j++) {
			for (int k = 0; k < truthNum && isAvail; k++) {
				if (parentArr[partyVec[i][j]] == parentArr[truthVec[k]]) {
					isAvail = false;
					break;
				}
			}
		}

		if (isAvail) {
			resCount++;
		}
	}

	cout << resCount;

	return 0;
}

int getParent(int x) {
	if (parentArr[x] == x) {
		return x;
	}

	return parentArr[x] = getParent(parentArr[x]);
}

void setUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		parentArr[x] = y;
	}
}