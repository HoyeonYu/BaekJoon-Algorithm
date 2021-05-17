#include <iostream>
#include <vector>
#include <cmath>
#define p pair<int, int>
using namespace std;

int totalNum;
vector<int> inputNumVec;
vector<p> treeVec;

p init(int node, int start, int end);
p update(int node, int start, int end, int index, int val);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> totalNum;

    for (int i = 0; i < totalNum; i++) {
        int input;
        cin >> input;
        inputNumVec.push_back(input);
    }

    int treeHeight = (int)ceil(log2(totalNum));
    int treeSize = (1 << (treeHeight + 1));
    treeVec.resize(treeSize);

    init(1, 0, totalNum - 1);
    
    int cmdNum;
    cin >> cmdNum;

    for (int i = 0; i < cmdNum; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int idx, val;
            cin >> idx >> val;

            inputNumVec[idx - 1] = val;
            update(1, 0, totalNum - 1, idx - 1, val);
        }

        else {
            cout << treeVec[1].second << "\n";
        }
    }

    return 0;
}

p init(int node, int start, int end) {
    if (start == end) {
        return treeVec[node] = { inputNumVec[start], start + 1 };
    }

    int mid = (start + end) / 2;
    p leftMin = init(node * 2, start, mid);
    p rightMin = init(node * 2 + 1, mid + 1, end);

    treeVec[node] = (leftMin.first <= rightMin.first ? leftMin : rightMin);

    return treeVec[node];
}

p update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) {
        return treeVec[node];
    }

    if (start == end) {
        return treeVec[node] = { val, start + 1 };
    }

    int mid = (start + end) / 2;
    p leftMin = update(node * 2, start, mid, index, val);
    p rightMin = update(node * 2 + 1, mid + 1, end, index, val);

    treeVec[node] = (leftMin.first <= rightMin.first ? leftMin : rightMin);

    return treeVec[node];
}
