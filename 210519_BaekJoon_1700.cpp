#include <iostream>
#include <vector>
#include <cmath>
#define p pair<int, int>
#define INF 9999
using namespace std;

int main() {
	int tabNum, inputNum;
	cin >> tabNum >> inputNum;

	vector<p> initIdxVec;
	
	for (int i = 0; i < inputNum; i++) {
		int input;
		cin >> input;

		initIdxVec.push_back({ i, input });
	}

	vector<p> nextIdxVec;

	for (int i = 0; i < inputNum; i++) {
		int val = initIdxVec[i].second;
		nextIdxVec.push_back({ val, INF });

		for (int j = i + 1; j < initIdxVec.size(); j++) {
			if (initIdxVec[j].second == val) {
				nextIdxVec[i].second = j;
				break;
			}
		}
	}

	for (int i = 0; i < tabNum; i++) {
		for (int j = i + 1; j < tabNum; j++) {
			if (nextIdxVec[i].first == nextIdxVec[j].first) {
				nextIdxVec[i] = nextIdxVec[j];
				nextIdxVec.erase(nextIdxVec.begin() + j);
				j--;
			}
		}
 	}

	int res = 0;

	for (int i = tabNum; i < nextIdxVec.size(); i++) {
		bool isExist = false;
		int maxVal = 0;
		int maxIdx = 0;
		int existIdx = 0;

		for (int j = 0; j < tabNum; j++) {
			if (nextIdxVec[j].first == nextIdxVec[i].first) {
				existIdx = j;
				isExist = true;
			}

			if (maxVal < nextIdxVec[j].second) {
				maxVal = nextIdxVec[j].second;
				maxIdx = j;
			}
		}

		if (isExist) {
			nextIdxVec[existIdx] = nextIdxVec[i];
		}

		if (!isExist) {
			nextIdxVec[maxIdx] = nextIdxVec[i];
			res++;
		}
	}

	cout << res;

	return 0;
}