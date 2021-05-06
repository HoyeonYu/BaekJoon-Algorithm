#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX_DOT 100000 + 1
typedef long long ll;
using namespace std;

bool isGradComp = false;

struct Dot {
    int x, y;
    int p, q;
    Dot(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

bool comp(const Dot& A, const Dot& B) {
    if (1LL * A.q * B.p != 1LL * A.p * B.q) {
        return 1LL * A.q * B.p < 1LL * A.p * B.q;
    }

    else if (isGradComp) {
        if (A.y != B.y) {
            return A.y > B.y;
        }

        return A.x < B.x;
    }

    if (A.x != B.x) {
        return A.x < B.x;
    }

    return A.y < B.y;
}

ll ccw(const Dot& A, const Dot& B, const Dot& C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

Dot dotArray[MAX_DOT];

int main() {
    int totalDotNum;
    int chDotNum = 0;
    cin >> totalDotNum;

    for (int i = 0; i < totalDotNum; i++) {
        int x, y;
        char isChDot;
        cin >> x >> y >> isChDot;

        if (isChDot == 'Y') {
            dotArray[chDotNum++] = Dot(x, y);
        }
    }

    sort(dotArray, dotArray + chDotNum, comp);

    for (int i = 1; i < chDotNum; i++) {
        dotArray[i].p = dotArray[i].x - dotArray[0].x;
        dotArray[i].q = dotArray[i].y - dotArray[0].y;
    }

    isGradComp = true;
    sort(dotArray + 1, dotArray + chDotNum, comp);

    cout << chDotNum << "\n";

    for (int i = 0; i < chDotNum; i++) {
        cout << dotArray[i].x << " " << dotArray[i].y << "\n";
    }

    return 0;
}