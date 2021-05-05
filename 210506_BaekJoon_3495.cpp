#include <iostream>
using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	double area = 0;

	for (int i = 0; i < row; i++) {
		string inputStr;
		cin >> inputStr;

		int slashNum = 0;

		for (int j = 0; j < col; j++) {
			if (inputStr[j] == '/' || inputStr[j] == '\\') {
				area += 0.5;
				slashNum++;
			}

			else if (slashNum % 2) {
				area++;
			}
		}
	}

	cout << area;

	return 0;
}