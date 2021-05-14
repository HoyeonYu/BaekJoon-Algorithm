#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MOD_VAL 1000000007
typedef long long ll;

using namespace std;

int totalNum, changeNum, prodNum;
vector<int> inputNumVec;
vector<int> treeVec;

ll init(int node, int start, int end);
ll update(int node, int start, int end, int index, ll changeNum);
ll getProd(int node, int start, int end, int left, int right);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> totalNum >> changeNum >> prodNum;

    for (int i = 0; i < totalNum; i++) {
        int inputNum;
        cin >> inputNum;
        inputNumVec.push_back(inputNum);
    }

    int treeHeight = (int)ceil(log2(totalNum));
    int treeSize = (1 << (treeHeight + 1));
    treeVec.resize(treeSize);

    init(1, 0, totalNum - 1);

    for (int i = 0; i < changeNum + prodNum; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            inputNumVec[b - 1] = c;
            update(1, 0, totalNum - 1, b - 1, c);
        }

        else {
            cout << getProd(1, 0, totalNum - 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}

ll init(int node, int start, int end) {
    if (start == end) {
        return treeVec[node] = inputNumVec[start];
    }

    int mid = (start + end) / 2;
    int leftProd = init(node * 2, start, mid);
    int rightProd = init(node * 2 + 1, mid + 1, end);

    treeVec[node] = (leftProd * rightProd) % MOD_VAL;

    return treeVec[node];
}

ll update(int node, int start, int end, int index, ll changeNum) {
    if (index < start || index > end) {
        return treeVec[node];
    }

    if (start == end) {
        return treeVec[node] = changeNum;
    }

    int mid = (start + end) / 2;
    int leftProd = update(node * 2, start, mid, index, changeNum);
    int rightProd = update(node * 2 + 1, mid + 1, end, index, changeNum);

    treeVec[node] = (leftProd * rightProd) % MOD_VAL;
    
    return treeVec[node];
}

ll getProd(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }

    if (left <= start && end <= right) {
        return treeVec[node];
    }

    int mid = (start + end) / 2;
    int leftProd = getProd(node * 2, start, mid, left, right);
    int rightProd = getProd(node * 2 + 1, mid + 1, end, left, right);

    return (leftProd * rightProd) % MOD_VAL;
}