#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 2e9

typedef long long ll;
using namespace std;

int totalNum, queryNum;
vector<int> inputNumVec;
vector<int> minTree;

int minInit(int node, int start, int end);
int getMin(int node, int start, int end, int left, int right);
int update(int node, int start, int end, int index, int val);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> totalNum;

    for (int i = 0; i < totalNum; i++) {
        int inputNum;
        cin >> inputNum;
        inputNumVec.push_back(inputNum);
    }

    int treeHeight = (int)ceil(log2(totalNum));
    int treeSize = (1 << (treeHeight + 1));
    minTree.resize(treeSize);

    cin >> queryNum;

    minInit(1, 0, totalNum - 1);

    for (int i = 0; i < queryNum; i++) {
        ll cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 1) {
            inputNumVec[a - 1] = b;
            update(1, 0, totalNum - 1, a - 1, b);
        }

        else {
            cout << getMin(1, 0, totalNum - 1, a - 1, b - 1) << "\n";
        }
    }

    return 0;
}

int minInit(int node, int start, int end) {
    if (start == end) {
        return minTree[node] = inputNumVec[start];
    }

    int mid = (start + end) / 2;
    int leftMin = minInit(node * 2, start, mid);
    int rightMin = minInit(node * 2 + 1, mid + 1, end);

    minTree[node] = min(leftMin, rightMin);

    return minTree[node];
}

int getMin(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }

    if (left <= start && end <= right) {
        return minTree[node];
    }

    int mid = (start + end) / 2;
    int leftMin = getMin(node * 2, start, mid, left, right);
    int rightMin = getMin(node * 2 + 1, mid + 1, end, left, right);

    return min(leftMin, rightMin);
}

int update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) {
        return minTree[node];
    }

    if (start == end) {
        return minTree[node] = val;
    }

    int mid = (start + end) / 2;

    return minTree[node] = min(update(node * 2, start, mid, index, val),
                                update(node * 2 + 1, mid + 1, end, index, val));
}
