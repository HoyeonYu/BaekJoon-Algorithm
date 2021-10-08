#include <iostream>
#include <vector>
#include <string.h>
#define MAX_NODE 100000 + 1
using namespace std;

vector<pair<int, int>> node[MAX_NODE];
bool visited[MAX_NODE] = { false };
int result = 0;
int endPoint = 0;

void dfs(int p, int len);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nodeNum;
    cin >> nodeNum;

    for (int i = 0; i < nodeNum - 1; i++) {
        int parent;
        cin >> parent;

        while (true) {
            int child, length;
            cin >> child;

            if (child == -1) {
                break;
            }

            cin >> length;

            node[parent].push_back({ child, length });
            node[child].push_back({ parent, length });
        }
    }

    dfs(1, 0);

    result = 0;
    memset(visited, false, sizeof(visited));

    dfs(endPoint, 0);

    cout << result;
}

void dfs(int p, int len) {
    if (visited[p]) {
        return;
    }

    visited[p] = true;

    if (result < len) {
        result = len;
        endPoint = p;
    }

    for (int i = 0; i < node[p].size(); i++) {
        dfs(node[p][i].first, len + node[p][i].second);
    }
}
