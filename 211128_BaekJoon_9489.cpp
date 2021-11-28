#include <iostream>
using namespace std;

int main() {
	while (true) {
		int nodeNum, findNum, a[1111] = { -1 }, p[1111] = { -1 };
		cin >> nodeNum >> findNum;

		if (!nodeNum && !findNum) {
			break;
		}

		int cnt = -1, idx = 0;
		for (int i = 1; i <= nodeNum; i++) {
			scanf("%d", &a[i]);

			if (a[i] == findNum) idx = i;
			if (a[i] != a[i - 1] + 1) cnt++;

			p[i] = cnt;
		}

		int ans = 0;
		for (int i = 1; i <= nodeNum; i++)
			if (p[i] != p[idx] && p[p[i]] == p[p[idx]]) ans++;

		printf("%d\n", ans);
	}

	return 0;
}