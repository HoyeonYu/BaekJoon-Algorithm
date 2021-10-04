#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int aNum, bNum;
	cin >> aNum >> bNum;

	vector<int> aVec, bVec;

	for (int i = 0; i < aNum; i++) {
		int num;
		cin >> num;
		aVec.push_back(num);
	}

	for (int i = 0; i < bNum; i++) {
		int num;
		cin >> num;
		bVec.push_back(num);
	}

	int aPoint = 0, bPoint = 0;
	vector<int> mergeVec;

	for (int i = 0; i < aNum + bNum; i++) {
		if (aPoint < aNum && bPoint < bNum) {
			if (aVec[aPoint] < bVec[bPoint]) {
				mergeVec.push_back(aVec[aPoint++]);
			}

			else {
				mergeVec.push_back(bVec[bPoint++]);
			}
		}

		else if (aPoint >= aNum) {
			mergeVec.push_back(bVec[bPoint++]);
		}

		else {
			mergeVec.push_back(aVec[aPoint++]);
		}
	}

	for (auto num : mergeVec) {
		cout << num << " ";
	}

	return 0;
}