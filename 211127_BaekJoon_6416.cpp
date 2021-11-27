#include <iostream>
#include <map>
using namespace std;

map<int, int> M, indegree;

int main() {
    int testCases = 0;

    while (true) {
        bool ans = true;
        int inVtx, outVtx, edgeCnt = 0, nodeCnt = 0;
        M.clear();
        indegree.clear();

        while (true) {
            cin >> inVtx >> outVtx;

            if (inVtx == 0 && outVtx == 0) {
                break;
            }

            if (inVtx == -1 && outVtx == -1) {
                return 0;
            }

            edgeCnt++;

            if (M.find(inVtx) == M.end()) {
                M.insert({ inVtx, nodeCnt++ });
            }

            if (M.find(outVtx) == M.end()) {
                M.insert({ outVtx, nodeCnt++ });
            }

            if (indegree.find(outVtx) == indegree.end())
                indegree.insert({ outVtx, 0 });

            else ans = false;
        }

        if (edgeCnt > 0 && M.size() != edgeCnt + 1) {
            ans = false;
        }

        if (ans) {
            printf("Case %d is a tree.\n", ++testCases);
        }

        else {
            printf("Case %d is not a tree.\n", ++testCases);
        }
    }

    return 0;
}

