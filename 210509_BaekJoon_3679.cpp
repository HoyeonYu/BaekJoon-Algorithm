#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#define MAX_DOT 2000 + 1
typedef long long ll;
using namespace std;

bool isGradComp;
int dotNum;

struct Dot {
    int x, y, p, q, idx;
    Dot(int x1 = 0, int y1 = 0, int index = 0) : x(x1), y(y1), p(1), q(0), idx(index) {}
};

bool comp(const Dot& A, const Dot& B) {
    if (1LL * A.q * B.p != 1LL * A.p * B.q) {
        return 1LL * A.q * B.p < 1LL * A.p * B.q;
    }

    else if (isGradComp) {
        return pow(A.p, 2) + pow(A.q, 2) < pow(B.p, 2) + pow(B.q, 2);
    }

    if (A.x != B.x) {
        return A.x < B.x;
    }

    return A.y < B.y;
}

Dot dotArray[MAX_DOT];

int main() {
    int totalDotNum, testCase;
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++) {
        cin >> dotNum;

        for (int i = 0; i < dotNum; i++) {
            int x, y;
            cin >> x >> y;

            dotArray[i] = Dot(x, y, i);
        }

        isGradComp = false;

        sort(dotArray, dotArray + dotNum, comp);

        for (int i = 1; i < dotNum; i++) {
            dotArray[i].p = dotArray[i].x - dotArray[0].x;
            dotArray[i].q = dotArray[i].y - dotArray[0].y;
        }

        isGradComp = true;

        sort(dotArray + 1, dotArray + dotNum, comp);

        int stopIdx = dotNum;

        for (int i = dotNum - 1; i >= 0; i--) {
            if (dotArray[i].p * dotArray[i - 1].q != dotArray[i].q * dotArray[i - 1].p) {
                stopIdx = i - 1;
                break;
            }
        }

        for (int i = 0; i <= stopIdx; i++) {
            cout << dotArray[i].idx << " ";
        }

        for (int i = dotNum - 1; i > stopIdx; i--) {
            cout << dotArray[i].idx << " ";
        }

        cout << "\n";
    }

    return 0;
}
