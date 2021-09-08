#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 1000 + 1
#define p pair<int, int>
#define pp pair<int, p>
using namespace std;

int getParent(int x);
void setUnion(int x, int y);

int parent[MAX_SIZE];
bool type[MAX_SIZE];

int main() {
	int schoolNum, edgeNum;
	cin >> schoolNum >> edgeNum;

	for (int i = 1; i <= schoolNum; i++) {
		char typeChar;
		cin >> typeChar;
		
		type[i] = (typeChar == 'M');
		parent[i] = i;
	}

	vector<pp> vec;

	for (int i = 0; i < edgeNum; i++) {
		int num1, num2, weight;
		cin >> num1 >> num2 >> weight;

		if (type[num1] != type[num2]) {
			vec.push_back({ weight, {num1, num2} });
		}
	}

	sort(vec.begin(), vec.end());

	int weightSum = 0;
	int weightCount = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (weightCount == schoolNum - 1) {
			break;
		}

		if (getParent(vec[i].second.first) != getParent(vec[i].second.second)) {
			setUnion(vec[i].second.first, vec[i].second.second);
			weightSum += vec[i].first;
			weightCount++;
		}
	}

	if (weightCount < schoolNum - 1) {
		weightSum = -1;
	}

	cout << weightSum;

	return 0;
}

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = getParent(parent[x]);
}

void setUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		parent[y] = x;
	}
}