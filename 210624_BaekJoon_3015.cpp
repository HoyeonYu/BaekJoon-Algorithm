#include <iostream>
#include <stack>
#define p pair<int, int>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int peopleNum;
    cin >> peopleNum;

    stack<p> stk;

    long long result = 0;

    for (int i = 0; i < peopleNum; i++) {
        int height;
        cin >> height;

        while (!stk.empty() && stk.top().first < height) {
            result += stk.top().second;
            stk.pop();
        }

        if (stk.empty()) {
            stk.push({ height, 1 });
        }

        else {
            if (stk.top().first == height) {
                p cur = stk.top();
                stk.pop();

                result += cur.second;

                if (!stk.empty()) {
                    result++;
                }

                cur.second++;
                stk.push(cur);
            }

            else {
                stk.push({ height, 1 });
                result++;
            }
        }
    }

    cout << result;

    return 0;
}