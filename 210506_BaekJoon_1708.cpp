#include <iostream>
#include <algorithm>
#include <stack>
#define MAX_DOT 100000 + 1
typedef long long ll;
using namespace std;

struct Dot {
    int x, y;
    int p, q;
    Dot(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

bool comp(const Dot& A, const Dot& B) {
    if (1LL * A.q * B.p != 1LL * A.p * B.q) {
        return 1LL * A.q * B.p < 1LL * A.p * B.q;
    }

    if (A.y != B.y) {
        return A.y < B.y;
    }

    return A.x < B.x;
}

ll ccw(const Dot& A, const Dot& B, const Dot& C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

Dot dotArray[MAX_DOT];

int main() {
    int dotNum;
    cin >> dotNum;

    for (int i = 0; i < dotNum; i++) {
        int x, y;
        cin >> x >> y;

        dotArray[i] = Dot(x, y);
    }

    sort(dotArray, dotArray + dotNum, comp);

    for (int i = 1; i < dotNum; i++) {
        dotArray[i].p = dotArray[i].x - dotArray[0].x;
        dotArray[i].q = dotArray[i].y - dotArray[0].y;
    }

    sort(dotArray + 1, dotArray + dotNum, comp);

    stack<int> dotStack;

    dotStack.push(0);
    dotStack.push(1);

    int nextDot = 2;

    while (nextDot < dotNum) {
        while (dotStack.size() >= 2) {
            int firstDot, secondDot;

            secondDot = dotStack.top();
            dotStack.pop();
            firstDot = dotStack.top();

            if (ccw(dotArray[firstDot], dotArray[secondDot], dotArray[nextDot]) > 0) {
                dotStack.push(secondDot);

                break;
            }
        }

        dotStack.push(nextDot++);
    }

    cout << dotStack.size();

    return 0;
}