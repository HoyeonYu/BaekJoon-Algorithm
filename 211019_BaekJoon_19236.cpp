#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FISH_NUM 16
#define GRAPH_SIZE 4
#define p pair<int, int>
using namespace std;

struct Fish {
	int dir;
	p pos;
};

struct Shark {
	int dir;
	p pos;
};

p moveDir[8] = {
	{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}
};

int maxSum = 0;

void sharkMove(int fishSum, int graph[GRAPH_SIZE][GRAPH_SIZE], Shark shark, Fish fish[FISH_NUM], p prev);

int main() {
	Fish fish[FISH_NUM];
	Shark shark;
	int graph[GRAPH_SIZE][GRAPH_SIZE];

	for (int i = 0; i < FISH_NUM; i++) {
		int idx, dir;
		cin >> idx >> dir;
		idx--, dir--;
		fish[idx].dir = dir;
		fish[idx].pos = { (i / 4), (i % 4) };
		graph[i / 4][i % 4] = idx;
	}

	shark.pos = { 0, 0 };

	sharkMove(0, graph, shark, fish, { 0, 0 });
	cout << maxSum;

	return 0;
}

void sharkMove(int fishSum, int graph[GRAPH_SIZE][GRAPH_SIZE], Shark shark, Fish fish[FISH_NUM], p prev) {
	int copyGraph[GRAPH_SIZE][GRAPH_SIZE];
	Fish copyFish[FISH_NUM];
	Shark copyShark;

	for (int i = 0; i < GRAPH_SIZE; i++) {
		for (int j = 0; j < GRAPH_SIZE; j++) {
			copyGraph[i][j] = graph[i][j];
		}
	}

	for (int i = 0; i < FISH_NUM; i++) {
		copyFish[i] = fish[i];
	}

	copyShark = shark;
	int newfishIdx = copyGraph[copyShark.pos.first][copyShark.pos.second];

	copyGraph[prev.first][prev.second] = -2;
	copyGraph[copyShark.pos.first][copyShark.pos.second] = -1;

	copyShark.dir = copyFish[newfishIdx].dir;
	copyFish[newfishIdx].dir = -1;

	maxSum = max(maxSum, fishSum + newfishIdx + 1);

	for (int i = 0; i < FISH_NUM; i++) {
		if (copyFish[i].dir != -1) {	// FISH DIR == -1 -> DEAD FISH
			int initDir = copyFish[i].dir;
			int curPosY = copyFish[i].pos.first;
			int curPosX = copyFish[i].pos.second;

			while (true) {
				int nextPosY = moveDir[copyFish[i].dir].first + curPosY;
				int nextPosX = moveDir[copyFish[i].dir].second + curPosX;

				if (nextPosY >= 0 && nextPosY < GRAPH_SIZE && nextPosX >= 0 && nextPosX < GRAPH_SIZE
					&& copyGraph[nextPosY][nextPosX] != -1) {		// GRAPH IDX == -1 -> SHARK
					if (copyGraph[nextPosY][nextPosX] != -2) {		// GRAPH IDX == -2 -> BLANK SPACE
						copyFish[copyGraph[nextPosY][nextPosX]].pos = copyFish[i].pos;
					}

					copyFish[i].pos = { nextPosY, nextPosX };

					copyGraph[curPosY][curPosX] = copyGraph[nextPosY][nextPosX];
					copyGraph[nextPosY][nextPosX] = i;

					break;
			}

				else {
					copyFish[i].dir = (copyFish[i].dir + 1) % 8;
				}

				if (copyFish[i].dir == initDir) {
					break;
				}
			}
		}
	}

	int initDir = copyShark.dir;
	int curPosY = copyShark.pos.first;
	int curPosX = copyShark.pos.second;

	for (int i = 0; i < GRAPH_SIZE - 1; i++) {
		int nextPosY = (moveDir[initDir].first	* (i + 1)) + curPosY;
		int nextPosX = (moveDir[initDir].second * (i + 1)) + curPosX;

		copyShark.pos = { nextPosY, nextPosX };

		if (nextPosY >= 0 && nextPosY < GRAPH_SIZE && nextPosX >= 0 && nextPosX < GRAPH_SIZE) {
			if (copyGraph[nextPosY][nextPosX] >= 0) {
				sharkMove(fishSum + newfishIdx + 1, copyGraph, copyShark, copyFish, { curPosY, curPosX });
			}
		}

		else {
			return;
		}
	}

	return;
}