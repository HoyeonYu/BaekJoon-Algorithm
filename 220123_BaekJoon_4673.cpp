#include <iostream>
#define MAX_NUM 10000 + 36
#define MAX_SIZE 10000 + 1
using namespace std;

int main() {
	bool resArr[MAX_NUM] = { false };

	for (int i = 1; i < MAX_SIZE; i++) {
		int target = i;
		int nonSelf = target;

		while (target > 0) {
			nonSelf += target % 10;
			target /= 10;
		}

		resArr[nonSelf] = true;
	}


	for (int i = 1; i < MAX_SIZE; i++) {
		if (!resArr[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}