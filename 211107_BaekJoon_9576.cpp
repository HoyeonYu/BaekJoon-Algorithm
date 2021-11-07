#include <iostream>
#include <algorithm>
#define p pair<int, int>
#define MAX_NUM 1000 + 1
using namespace std;

bool cmp(p child, p parent) {
    if (child.second < parent.second) {
        return true;
    }

    else {
        if (child.second == parent.second) {
            if (child.first < parent.first) {
                return true;
            }
        }

        return false;
    }
}

int main() {
    int testCase;
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++) {
        int n, m;
        cin >> n >> m;

        pair<int, int> student[MAX_NUM];
        bool chosen[MAX_NUM] = { false };

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            student[i] = { a, b };
        }

        sort(student, student + m, cmp);
        int max_cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = student[i].first; j <= student[i].second; j++) {
                if (!chosen[j]) {
                    chosen[j] = true;
                    max_cnt++;

                    break;
                }
            }
        }

        cout << max_cnt << "\n";
    }

    return 0;
}
