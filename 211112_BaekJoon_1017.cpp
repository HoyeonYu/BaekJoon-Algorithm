#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VAL 1000 + 1
#define MAX_PRIME 2000 + 1
using namespace std;

void getPrime();
bool dfs(int x);

bool isVisited[MAX_VAL], isPrime[MAX_PRIME];
int decided[MAX_VAL], totNum;
vector<int> candVec, primeVec[MAX_VAL];

int main() {
	cin >> totNum;

	for (int i = 0; i < totNum; i++) {
		int num;
		cin >> num;

		candVec.push_back(num);
	}

	getPrime();

	for (int i = 0; i < totNum; i++) {
		for (int j = i + 1; j < totNum; j++) {
			if (isPrime[candVec[i] + candVec[j]]) {
				primeVec[i].push_back(candVec[j]);
				primeVec[j].push_back(candVec[i]);
			}
		}
	}

	vector<int> resVec;

	for (int i = 0; i < primeVec[0].size(); i++) {
		int pairCount = 2;
		fill_n(decided, MAX_VAL, -1);

		for (int j = 1; j < totNum; j++) {
			if (candVec[j] == primeVec[0][i]) {
				continue;
			}

			fill_n(isVisited, MAX_VAL, false);
			isVisited[candVec[0]] = isVisited[primeVec[0][i]] = true;
			decided[candVec[0]] = primeVec[0][i];
			decided[primeVec[0][i]] = candVec[0];

			if (dfs(j)) {
				pairCount++;
			}
		}

		if (pairCount == totNum) {
			resVec.push_back(primeVec[0][i]);
		}
	}

	if (resVec.size() != 0) {
		sort(resVec.begin(), resVec.end());

		for (int i = 0; i < resVec.size(); i++) {
			cout << resVec[i] << " ";
		}
	}

	else {
		cout << -1;
	}

	return 0;
}

void getPrime() {
	fill_n(isPrime, MAX_PRIME, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < MAX_PRIME; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < MAX_PRIME; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

bool dfs(int x) {
	for (int i = 0; i < primeVec[x].size(); i++) {
		int partVal = primeVec[x][i];

		if (isVisited[partVal]) {
			continue;
		}

		isVisited[partVal] = true;

		if (decided[partVal] == -1 || dfs(decided[partVal])) {
			decided[partVal] = x;

			return true;
		}
	}

	return false;
}