#include <iostream>
#define MAX_AREA 3000 + 1
using namespace std;

struct area {
	int x, y, radius;
};

void init();
bool isConnected(area a1, area a2);
int findParent(int x);
void setUnion(int x, int y);

int parentArr[MAX_AREA];

int main() {
	int tcNum;
	cin >> tcNum;

	for (int i = 0; i < tcNum; i++) {
		init();
		area areaArr[MAX_AREA];

		int areaNum;
		cin >> areaNum;

		for (int j = 0; j < areaNum; j++) {
			cin >> areaArr[j].x >> areaArr[j].y >> areaArr[j].radius;
		}

		for (int j = 0; j < areaNum; j++) {
			for (int k = 0; k < areaNum; k++) {
				if (isConnected(areaArr[j], areaArr[k])) {
					setUnion(j, k);
				}
			}
		}

		int countParent = 0;

		for (int j = 0; j < areaNum; j++) {
			if (parentArr[j] == j) {
				countParent++;
			}
		}

		cout << countParent << "\n";
	}

	return 0;
}

void init() {
	for (int i = 0; i < MAX_AREA; i++) {
		parentArr[i] = i;
	}
}

bool isConnected(area a1, area a2) {
	int r = (a1.radius + a2.radius) * (a1.radius + a2.radius);
	int d = (a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y);

	return r >= d;
}

int findParent(int x) {
	if (x == parentArr[x]) {
		return x;
	}

	return parentArr[x] = findParent(parentArr[x]);
}

void setUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		parentArr[y] = x;
	}
}