#include <cstdio>
#pragma warning (disable: 4996)

int num, bitArr[1 << 20] = { 0 };

int main() {
	while (scanf("%d", &num) != -1) {
		int num1 = num / 32;
		int num2 = 1 << (num % 32);

		if (!(bitArr[num1] & num2)) {
			bitArr[num1] += num2;
			printf("%d ", num);
		}
	}

	return 0;
}