#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX_ISLAND 10000 + 1
using namespace std;

int bfs(int cost);

int islandNum, infoNum;
vector <pair<int, int>> vec[MAX_ISLAND];
bool visited[MAX_ISLAND];
int s, e;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> islandNum >> infoNum;
	int from, to, cost;
	int maxCost = 0;

	for (int i = 0; i < infoNum; i++) {
		cin >> from >> to >> cost;

		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));

		maxCost = max(maxCost, cost);
	}

	cin >> s >> e;

	int low = 0, high = maxCost;

	while (low <= high) {
		fill_n(visited, MAX_ISLAND, false);

		int mid = (low + high) / 2;

		if (bfs(mid)) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	cout << high;

	return 0;
}

int bfs(int cost) {
	queue <int> que;
	que.push(s);
	visited[s] = true;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == e) {
			return true;
		}

		for (int i = 0; i < vec[cur].size(); i++) {
			int ncur = vec[cur][i].first;
			int ncos = vec[cur][i].second;

			if (!visited[ncur] && ncos >= cost) {
				visited[ncur] = 1;
				que.push(ncur);
			}
		}
	}

	return false;
}