#include <iostream>
#include <algorithm>
#define MAX_2D_SIZE 4000 + 1
#define MAX_1D_SIZE (4000 * 4000) + 1
using namespace std;

int inputArr[MAX_2D_SIZE][4];
int A[MAX_1D_SIZE], B[MAX_1D_SIZE];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> inputArr[i][j];
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i * size + j] = inputArr[i][0] + inputArr[j][1];
			B[i * size + j] = inputArr[i][2] + inputArr[j][3];
		}
	}

	sort(A, A + size * size);
	sort(B, B + size * size);

	int pointerA = 0, pointerB = size * size - 1;
	long long resCount = 0;

	while (pointerA < size * size && pointerB >= 0) {
		int valA = A[pointerA];
		int valB = B[pointerB];
		int sum = valA + valB;

		if (sum == 0) {
			long long innerCountA = 0, innerCountB = 0;
			
			while (A[pointerA] == valA && pointerA < size * size) {
				pointerA++;
				innerCountA++;
			}

			while (B[pointerB] == valB && pointerB >= 0) {
				pointerB--;
				innerCountB++;
			}

			resCount += innerCountA * innerCountB;
		}

		else if (sum < 0) {
			pointerA++;
		}

		else {
			pointerB--;
		}
	}

	cout << resCount;

	return 0;
}