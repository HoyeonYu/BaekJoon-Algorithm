#include <iostream>
#include <queue>
#define MAX_FLOOR 1000000 + 1
using namespace std;

int floorBFS[MAX_FLOOR];
bool isVisited[MAX_FLOOR];

int main() {
	int totalFloor, curFloor, goalFloor, up, down;
	cin >> totalFloor >> curFloor >> goalFloor >> up >> down;

	fill_n(floorBFS, MAX_FLOOR, -1);
	fill_n(isVisited, MAX_FLOOR, false);

	queue<int> floorQue;
	floorQue.push(curFloor);
	floorBFS[curFloor] = 0;
	isVisited[curFloor] = true;

	while (!floorQue.empty()) {
		int current = floorQue.front();
		floorQue.pop();

		int upper = current + up;
		if (upper <= totalFloor && !isVisited[upper]) {
			floorQue.push(upper);
			floorBFS[upper] = floorBFS[current] + 1;
			isVisited[upper] = true;
		}

		int lower = current - down;
		if (lower >= 1 && !isVisited[lower]) {
			floorQue.push(lower);
			floorBFS[lower] = floorBFS[current] + 1;
			isVisited[lower] = true;
		}

		if (current == goalFloor) {
			break;
		}
	}

	if (floorBFS[goalFloor] == -1) {
		cout << "use the stairs";
	}

	else {
		cout << floorBFS[goalFloor];
	}

	return 0;
}