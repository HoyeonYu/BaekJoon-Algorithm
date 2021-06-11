#include <iostream>
#include <queue>
#define p pair<int, int>
#define MAX_NUM 200000 + 1
using namespace std;

struct cmp {
	bool operator() (p a, p b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}

		return a.first < b.first;
	}
};

int pos(int num);
bool isEmpty(int num);

int isVisited[MAX_NUM];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	priority_queue<p, vector<p>, cmp> pq;
	fill_n(isVisited, MAX_NUM, -1);

	for (int i = 0; i < num; i++) {
		int dead, cup;
		cin >> dead >> cup;
		pq.push({ dead, cup });
	}

	int sum = 0;

	while (!pq.empty()) {
		p res = pq.top();
		pq.pop();

		if (isEmpty(res.first)) {
			sum += res.second;
		}
	}

	cout << sum;

	return 0;
}

int pos(int num) {
	if (isVisited[num] < 0) {
		return num;
	}

	return pos(isVisited[num]);
}

bool isEmpty(int num) {
	num = pos(num);

	if (num == 0) {
		return false;
	}

	isVisited[num] = pos(num - 1);

	return true;
}