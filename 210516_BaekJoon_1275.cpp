#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

int totalNum, turnNum;
vector<ll> inputNumVec;
vector<ll> treeVec;

ll init(int node, int start, int end);
ll getSum(int node, int start, int end, int left, int right);
void update(int node, int start, int end, int index, ll diff);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> totalNum >> turnNum;

    for (int i = 0; i < totalNum; i++) {
        int inputNum;
        cin >> inputNum;
        inputNumVec.push_back(inputNum);
    }

    int treeHeight = (int)ceil(log2(totalNum));
    int treeSize = (1 << (treeHeight + 1));
    treeVec.resize(treeSize);

    init(1, 0, totalNum - 1);

    for (int i = 0; i < turnNum; i++) {
        ll a, b, x, y;
        cin >> x >> y >> a >> b;

        cout << getSum(1, 0, totalNum - 1, min(x, y) - 1, max(x, y) - 1) << "\n";

        ll diff = b - inputNumVec[a - 1];
        inputNumVec[a - 1] = b;
        update(1, 0, totalNum - 1, a - 1, diff);
    }

    return 0;
}

ll init(int node, int start, int end) {
    if (start == end) {
        return treeVec[node] = inputNumVec[start];
    }

    int mid = (start + end) / 2;
    ll leftSum = init(node * 2, start, mid);
    ll rightSum = init(node * 2 + 1, mid + 1, end);

    treeVec[node] = leftSum + rightSum;

    return treeVec[node];
}

ll getSum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return treeVec[node];
    }

    int mid = (start + end) / 2;
    ll leftSum = getSum(node * 2, start, mid, left, right);
    ll rightSum = getSum(node * 2 + 1, mid + 1, end, left, right);

    return leftSum + rightSum;
}

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) {
        return;
    }

    treeVec[node] = treeVec[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}
