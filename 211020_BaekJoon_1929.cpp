#include <iostream>
#include <string.h>
#define MAX_NUM 1000000 + 1
using namespace std;

int main() {
	int min, max;
	cin >> min >> max;

	bool isPalin[MAX_NUM];
	memset(isPalin, true, MAX_NUM);
	isPalin[1] = false;

	for (int i = 2; i <= max; i++) {
		if (isPalin[i]) {
			for (int j = i * 2; j <= max; j += i) {
				isPalin[j] = false;
			}
		}
	}

	for (int i = min; i <= max; i++) {
		if (isPalin[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}