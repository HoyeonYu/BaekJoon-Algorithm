#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		int applyNum;
		cin >> applyNum;

		vector<p> applyVec;

		for (int i = 0; i < applyNum; i++) {
			int num1, num2;
			cin >> num1 >> num2;
			applyVec.push_back({ num1, num2 });
		}

		sort(applyVec.begin(), applyVec.end());

		int res = 1, minRank = applyVec[0].second;

		for (int i = 1; i < applyNum; i++) {
			if (minRank > applyVec[i].second) {
				res++;
				minRank = applyVec[i].second;
			}
		}

		cout << res << "\n";
	}

	return 0;
}