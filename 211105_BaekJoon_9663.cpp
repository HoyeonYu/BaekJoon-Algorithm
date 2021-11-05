#include <iostream>
#include <algorithm>
#define MAX_QUEEN 15
using namespace std;

bool isPromising(int depth);
void dfs(int depth);
int queenNum, res = 0;
int queen[MAX_QUEEN];

int main() {
	cin >> queenNum;
	dfs(0);
	cout << res;
}

bool isPromising(int depth) {
	for (int i = 0; i < depth; i++) {
		if ((queen[depth] == queen[i]) || (abs(queen[depth] - queen[i]) == (depth - i))) {
			return false;
		}
	}

	return true;
}

void dfs(int depth) {
	if (depth == queenNum) {
		res++;
		return;
	}

	for (int i = 0; i < queenNum; i++) {
		queen[depth] = i;
		
		if (isPromising(depth)) {
			dfs(depth + 1);
		}
	}
}