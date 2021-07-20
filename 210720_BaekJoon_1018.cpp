#include <iostream>
#include <cmath>
#define MAX_SIZE 50 + 1
using namespace std;

int check(int x, int y);
int chess[MAX_SIZE][MAX_SIZE];

int main() {
	int row, col;
	int res = 2500;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < col; j++) {
			chess[i][j] = (str[j] == 'W');
		}
	}

	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {
			res = min(res, check(i, j));
		}
	}

	cout << res;
}

int check(int x, int y) {
	int cnt1 = 0, cnt2 = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == chess[i][j]) {
				cnt1++;
			}

			if ((i + j + 1) % 2 == chess[i][j]) {
				cnt2++;
			}
		}
	}

	return min(cnt1, cnt2);
}