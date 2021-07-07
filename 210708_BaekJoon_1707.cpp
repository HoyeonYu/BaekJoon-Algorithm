#include <iostream>
#include <vector>
#include <cstring>
#define MAX_SIZE 20000 + 1
using namespace std;

void dfs(int start, int color);
bool isBipartiteGraph();

vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];
int vtxNum, edgeNum;

int main() {
    int caseNum;
    cin >> caseNum;

    for (int i = 0; i < caseNum; i++) {
        cin >> vtxNum >> edgeNum;

        for (int i = 0; i <= vtxNum; i++) {
            graph[i].clear();
        }

        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < edgeNum; i++) {
            int vtx1, vtx2;
            cin >> vtx1 >> vtx2;

            graph[vtx1].push_back(vtx2);
            graph[vtx2].push_back(vtx1);
        }

        for (int i = 1; i <= vtxNum; i++) {
            if (!visited[i]) {
                dfs(i, 1);
            }
        }

        cout << (isBipartiteGraph() ? "YES\n" : "NO\n");
    }

    return 0;
}

void dfs(int start, int color) {
    if (visited[start] == 0) {
        visited[start] = color;
    }

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (visited[next] == 0) {
            visited[next] = -color;
            dfs(next, -color);
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= vtxNum; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];

            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }

    return true;
}