#include <iostream>
#define MAX_LEN 100
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	for (int i = L; i <= MAX_LEN; i++) {
		int Lx = N - (i * (i + 1) / 2);
		
		if (Lx % i == 0) {
			int x = Lx / i + 1;

			if (x >= 0) {
				for (int j = 0; j < i; j++) {
					cout << x + j << " ";
				}

				return 0;
			}
		}
	}

	cout << -1;

	return 0;
}