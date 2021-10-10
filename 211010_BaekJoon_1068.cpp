#include <iostream>
#include <vector>
#define MAX_NODE 50 + 1
using namespace std;

bool isVisited[MAX_NODE] = { false };
vector<int> tree[MAX_NODE];
int leafNode = 0;
int deleteNode;

void dfs(int node);

int main() {
	int nodeNum;
	cin >> nodeNum;

	int root = 0;

	for (int i = 0; i < nodeNum; i++) {
		int curRoot;
		cin >> curRoot;

		if (curRoot == -1) {
			root = i;
			continue;
		}

		tree[i].push_back(curRoot);
		tree[curRoot].push_back(i);
	}

	cin >> deleteNode;
	tree[deleteNode].clear();

	dfs(root);

	cout << leafNode;

	return 0;
}

void dfs(int node) {
	isVisited[node] = true;
	bool isLeaf = true;

	if (node == deleteNode) {
		return;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		if (!isVisited[tree[node][i]] && (tree[node][i] != deleteNode)) {
			dfs(tree[node][i]);
			isLeaf = false;
		}
	}

	if (isLeaf) {
		leafNode++;
	}
}