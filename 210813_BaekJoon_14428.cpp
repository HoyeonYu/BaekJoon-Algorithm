#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100000;
int input[MAX + 1];
int tree[MAX * 4 + 1];

int minIndex(int x, int y) {
	if (x == -1) {
		return y;
	}

	if (y == -1) {
		return x;
	}

	if (input[x] == input[y]) {
		return x < y ? x : y;
	}

	return input[x] <= input[y] ? x : y;
}

int init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = start;
	}

	int mid = (start + end) / 2;

	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index) {
	if (start > index || end < index) {
		return tree[node];
	}

	if (start == end) { 
		return tree[node]; 
	}

	int mid = (start + end) / 2;

	return tree[node] = minIndex(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int query(int start, int end, int node, int left, int right) {
	if (start > right || end < left) {
		return -1;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return minIndex(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	cin >> m;

	init(1, n, 1);

	for (int i = 0; i < m; i++)	{
		int cmd, index, v, left, right;
		cin >> cmd;

		if (cmd == 1) {
			cin >> index >> v;
			input[index] = v;
			update(1, n, 1, index);
		}

		if (cmd == 2) {
			cin >> left >> right;
			cout << query(1, n, 1, left, right) << '\n';
		}
	}
}