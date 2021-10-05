#include <iostream>
#include <vector>
#define MAX_NUM 100000 + 1
using namespace std;

void dfs(int num);

vector<int> tree[MAX_NUM];
bool isVisited[MAX_NUM] = { false };
int parent[MAX_NUM];

int main() {
	int totNum;
	cin >> totNum;

	for (int i = 0; i < totNum - 1; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}

	dfs(1);

	for (int i = 2; i <= totNum; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}

void dfs(int num) {
	isVisited[num] = true;

	for (int i = 0; i < tree[num].size(); i++) {
		if (!isVisited[tree[num][i]]) {
			parent[tree[num][i]] = num;
			dfs(tree[num][i]);
		}
	}
}