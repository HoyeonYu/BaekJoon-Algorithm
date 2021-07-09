#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>
#define pp pair<p, int>
#define MAX_BALL 200000 + 1
#define MAX_COLOR 200000 + 1
using namespace std;

int resArr[MAX_BALL] = { 0 };
int colorTotal[MAX_COLOR] = { 0 };

int main() {
	int ballNum;
	cin >> ballNum;

	vector<pp> vec;
	int totalSize = 0;

	for (int i = 0; i < ballNum; i++) {
		int color, size;
		cin >> color >> size;

		vec.push_back({ { size, color }, i });
		colorTotal[color] += size;
		totalSize += size;
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < ballNum; i++) {
		pp vecFront = vec[i];

		int size = totalSize - colorTotal[vecFront.first.second];
		colorTotal[vecFront.first.second] -= vecFront.first.first;

		for (int j = i + 1; j < ballNum; j++) {
			if (vecFront.first.first > vec[j].first.first) {
				break;
			}

			else if (vecFront.first.second != vec[j].first.second) {
				size -= vecFront.first.first;
			}
		}

		resArr[vecFront.second] = size;
		totalSize -= vecFront.first.first;
	}

	for (int i = 0; i < ballNum; i++) {
		cout << resArr[i] << "\n";
	}

	return 0;
}