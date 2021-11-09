#include <iostream>
using namespace std;

char star[3500][6500];
string partStar[3] = {
	"  *  ",
	" * * ",
	"*****"
};

void draw(int n, int y, int x);

int main() {
	int num;
	cin >> num;

	draw(num / 3, 0, 0);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 2 * num - 1; j++) {
			cout << (star[i][j] == '*' ? '*' : ' ');
		}

		cout << "\n";
	}

	return 0;
}

void draw(int n, int y, int x) {
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				star[i + y][j + x] = partStar[i][j];
			}
		}

		return;
	}

	draw(n / 2, y, x + 3 * n / 2);
	draw(n / 2, y + 3 * n / 2, x);
	draw(n / 2, y + 3 * n / 2, x + 3 * n);
}