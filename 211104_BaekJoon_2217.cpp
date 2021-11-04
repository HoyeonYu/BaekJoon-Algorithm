#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int ropeNum;
	cin >> ropeNum;

	vector<int> ropeVec;

	for (int i = 0; i < ropeNum; i++) {
		int toler;
		cin >> toler;
		ropeVec.push_back(toler);
	}

	sort(ropeVec.begin(), ropeVec.end());
	int res = 0;

	for (int i = 0; i < ropeNum; i++) {
		res = max(res, ropeVec[i] * (ropeNum - i));
	}

	cout << res;

	return 0;
}