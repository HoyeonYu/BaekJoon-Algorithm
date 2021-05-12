#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 2e9

using namespace std;

int totalNum, queryNum;
vector<int> inputNumVec;
vector<int> minTree, maxTree;

int minInit(int node, int start, int end);
int maxInit(int node, int start, int end);
int getMin(int node, int start, int end, int left, int right);
int getMax(int node, int start, int end, int left, int right);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> totalNum >> queryNum;

    for (int i = 0; i < totalNum; i++) {
        int inputNum;
        cin >> inputNum;
        inputNumVec.push_back(inputNum);
    }

    int treeHeight = (int)ceil(log2(totalNum));
    int treeSize = (1 << (treeHeight + 1));
    minTree.resize(treeSize);
    maxTree.resize(treeSize);

    minInit(1, 0, totalNum - 1);
    maxInit(1, 0, totalNum - 1);

    for (int i = 0; i < queryNum; i++) {
        int startIdx, endIdx;
        cin >> startIdx >> endIdx;

        cout << getMin(1, 0, totalNum - 1, startIdx - 1, endIdx - 1) << " ";
        cout << getMax(1, 0, totalNum - 1, startIdx - 1, endIdx - 1) << "\n";
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

int maxInit(int node, int start, int end) {
    if (start == end) {
        return maxTree[node] = inputNumVec[start];
    }

    int mid = (start + end) / 2;
    int leftMax = maxInit(node * 2, start, mid);
    int rightMax = maxInit(node * 2 + 1, mid + 1, end);

    maxTree[node] = max(leftMax, rightMax);

    return maxTree[node];
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

int getMax(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return maxTree[node];
    }

    int mid = (start + end) / 2;
    int leftMax = getMax(node * 2, start, mid, left, right);
    int rightMax = getMax(node * 2 + 1, mid + 1, end, left, right);

    return max(leftMax, rightMax);
}