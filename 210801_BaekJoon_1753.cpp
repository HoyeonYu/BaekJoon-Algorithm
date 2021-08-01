#include <iostream>
#include <queue>
#define MAX_VTX 20000 + 1
#define MAX_EDGE 300000 + 1
#define MAX_WEIGHT 1e9
using namespace std;

struct Vertice {
	int dest, weight;
};

struct cmp {
	bool operator() (Vertice parent, Vertice child) {
		return parent.weight > child.weight;
	}
};

int vtxNum, edgeNum, findVtx;
vector<Vertice> edgeVec[MAX_EDGE];
void dijkstra(int startVtx);

int main() {
	cin >> vtxNum >> edgeNum >> findVtx;

	for (int i = 0; i < edgeNum; i++) {
		int startVtx, endVtx, weight;
		cin >> startVtx >> endVtx >> weight;

		Vertice vertice;
		vertice.dest = endVtx;
		vertice.weight = weight;
		edgeVec[startVtx].push_back(vertice);
	}

	dijkstra(findVtx);

	return 0;
}

void dijkstra(int startVtx) {
	int dp[MAX_VTX];
	fill_n(dp, MAX_VTX, MAX_WEIGHT);
	bool isVisited[MAX_VTX] = { false };
	priority_queue<Vertice, vector<Vertice>, cmp> pq;

	dp[startVtx] = 0;
	pq.push({ startVtx, 0 });

	while (!pq.empty()) {
		Vertice startVtx = pq.top();
		pq.pop();

		if (isVisited[startVtx.dest]) {
			continue;
		}

		isVisited[startVtx.dest] = true;

		for (auto nextEdge : edgeVec[startVtx.dest]) {
			if (nextEdge.weight + dp[startVtx.dest] < dp[nextEdge.dest]) {
				dp[nextEdge.dest] = nextEdge.weight + dp[startVtx.dest];
				pq.push({ nextEdge.dest, dp[nextEdge.dest] });
			}
		}
	}

	for (int i = 1; i <= vtxNum; i++) {
		if (dp[i] != MAX_WEIGHT) {
			cout << dp[i] << "\n";
		}
		
		else {
			cout << "INF\n";
		}
	}
}